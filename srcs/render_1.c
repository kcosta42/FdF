/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 13:14:55 by kcosta            #+#    #+#             */
/*   Updated: 2017/05/15 15:00:51 by kcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void			render_vertex(t_render render, t_vertex vertex)
{
	t_uint		rgb;
	int			index;

	index = (vertex.coord.x + vertex.coord.y * render.width);
	if (vertex.coord.x >= render.width || vertex.coord.y >= render.height
		|| vertex.coord.x < 0 || vertex.coord.y < 0
		|| render.depth_buffer[index] < vertex.coord.z)
		return ;
	render.depth_buffer[index] = vertex.coord.z;
	rgb = mlx_get_color_value(render.mlx_ptr, get_color(vertex.color));
	ft_memcpy(render.img.data
			+ (render.img.bits_per_pixel / 8) * (int)(vertex.coord.x)
			+ render.img.size_line * (int)(vertex.coord.y),
				&rgb, sizeof(rgb));
}

static void		render_edge_1(t_vector2 *err, t_vector2 *delta,
										t_vector3 *v0, t_vector3 *step)
{
	err->y = 2 * err->x;
	if (err->y > -delta->y)
	{
		err->x -= delta->y;
		v0->x += step->x;
	}
	if (err->y < delta->x)
	{
		err->x += delta->x;
		v0->y += step->y;
	}
}

void			render_edge(t_render render, t_vertex start, t_vertex end)
{
	t_vector3	v0;
	t_vector3	v1;
	t_vector3	step;
	t_vector2	delta;
	t_vector2	err;

	v0 = (t_vector3){(int)clamp(start.coord.x, 0, render.width),
		(int)clamp(start.coord.y, 0, render.height), start.coord.z};
	v1 = (t_vector3){(int)clamp(end.coord.x, 0, render.width),
		(int)clamp(end.coord.y, 0, render.height), start.coord.z};
	delta = (t_vector2){fabs(v1.x - v0.x), fabs(v1.y - v0.y)};
	step = (t_vector3){(v0.x < v1.x) ? 1 : -1, (v0.y < v1.y) ? 1 : -1,
		(v1.z - v0.z) / (fmax(delta.x, delta.y) ? fmax(delta.x, delta.y) : 1)};
	err = (t_vector2){delta.x - delta.y, 0};
	end.color = color_mult(color_sub(end.color, start.color),
		1 / (fmax(delta.x, delta.y) ? fmax(delta.x, delta.y) : 1));
	while (1)
	{
		render_vertex(render, new_vertex(v0, start.color));
		v0.z += step.z;
		start.color = color_add(start.color, end.color);
		if ((v0.x == v1.x) && (v0.y == v1.y))
			break ;
		render_edge_1(&err, &delta, &v0, &step);
	}
}

/*
** Need to investigate why render_vertex dont get clean with mode VERTEX
** Instead i will use render_edge with v1 = v2 to draw a point
*/

void			render_face(t_render r, t_camera c, t_face face, t_matrix tm)
{
	face.a = camera_project(c, face.a, tm);
	face.b = camera_project(c, face.b, tm);
	face.c = camera_project(c, face.c, tm);
	if (face.a.coord.y > face.b.coord.y)
		swap_vertex(&(face.a), &(face.b));
	if (face.b.coord.y > face.c.coord.y)
		swap_vertex(&(face.b), &(face.c));
	if (face.a.coord.y > face.b.coord.y)
		swap_vertex(&(face.a), &(face.b));
	if (r.mode == VERTEX)
	{
		render_edge(r, face.a, face.a);
		render_edge(r, face.b, face.b);
		render_edge(r, face.c, face.c);
	}
	else if (r.mode == EDGE)
	{
		render_edge(r, face.a, face.b);
		render_edge(r, face.b, face.c);
		render_edge(r, face.c, face.a);
	}
	else
		render_rasterize(r, (t_face){face.a, face.b, face.c});
}

void			render_mesh(t_render render, t_camera camera, t_mesh mesh)
{
	t_matrix	world_matrix;
	t_matrix	transform_matrix;
	size_t		index;

	world_matrix = matrix_mult(matrix_rotation_ypr(mesh.rotation.y,
													mesh.rotation.x,
													mesh.rotation.z),
								matrix_translation(mesh.position.x,
													mesh.position.y,
													mesh.position.z));
	transform_matrix = matrix_mult(matrix_mult(world_matrix,
								camera.view_matrix), camera.projection_matrix);
	index = -1;
	while (++index < mesh.size)
		render_face(render, camera, mesh.faces[index], transform_matrix);
}
