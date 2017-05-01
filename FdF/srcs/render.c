/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 19:37:43 by kcosta            #+#    #+#             */
/*   Updated: 2017/05/01 17:26:36 by kcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

t_render		new_render(float width, float height, char *name)
{
	t_render	render;

	render.width = width;
	render.height = height;
	ft_memset(render.name, 0, 2048);
	ft_strncpy(render.name, name, 2047);
	render.mlx_ptr = mlx_init();
	render.img_ptr = mlx_new_image(render.mlx_ptr, width, height);
	render.win_ptr = 
		mlx_new_window(render.mlx_ptr, width, height, render.name);
	render.img.data =
		mlx_get_data_addr(	render.img_ptr, &render.img.bits_per_pixel,
							&render.img.size_line, &render.img.endian);
	return (render);
}

void			render_clear(t_render render)
{
	float		x;
	float		y;

	y = -1;
	while (++y < render.height)
	{
		x = -1;
		while (++x < render.width)
			render_vertex(render, new_vector2(x, y), new_color(0, 0, 0));
	}
}

void			render_develop(t_render render)
{
	mlx_put_image_to_window(render.mlx_ptr, render.win_ptr, render.img_ptr,
							0, 0);
}

void			render_vertex(t_render r, t_vector2 v, t_color c)
{
	unsigned int	rgb;

	if (v.x >= r.width || v.y >= r.height || v.x < 0 || v.y < 0)
		return ;
	rgb = mlx_get_color_value(r.mlx_ptr, get_color(c));
	ft_memcpy(r.img.data + (r.img.bits_per_pixel / 8) * (int)(v.x)
			+ r.img.size_line * (int)(v.y), &rgb, sizeof(rgb));
}

void			render_edge(t_render render, t_vector2 start,
											t_vector2 end, t_color color)
{
    int x0 = (int)start.x;
    int y0 = (int)start.y;
    int x1 = (int)end.x;
    int y1 = (int)end.y;
            
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;
    int err = dx - dy;

    while (1)
	{
        render_vertex(render, new_vector2(x0, y0), color);

        if ((x0 == x1) && (y0 == y1)) break;
        int e2 = 2 * err;
        if (e2 > -dy) { err -= dy; x0 += sx; }
        if (e2 < dx) { err += dx; y0 += sy; }
    }
}

void			render_face(t_render r, t_camera c, t_face f, t_matrix tm)
{
	t_vector2 pixelA;
	t_vector2 pixelB;
	t_vector2 pixelC;

    pixelA = camera_project(c, f.a, tm);
    pixelB = camera_project(c, f.b, tm);
    pixelC = camera_project(c, f.c, tm);

    render_edge(r, pixelA, pixelB, new_color(255, 0 , 0));
    render_edge(r, pixelB, pixelC, new_color(255, 0 , 0));
    render_edge(r, pixelC, pixelA, new_color(255, 0 , 0));
}

void			render_mesh(t_render render, t_camera camera, t_mesh mesh)
{
	t_matrix	worldMatrix;
	t_matrix	transformMatrix;
	size_t		index;
	
	worldMatrix = matrix_mult(	matrix_rotation_ypr(mesh.rotation.y,
													mesh.rotation.x,
													mesh.rotation.z),
								matrix_translation(	mesh.position.x,
													mesh.position.y,
													mesh.position.z));
	transformMatrix = matrix_mult(matrix_mult(worldMatrix, camera.viewMatrix),
								camera.projectionMatrix);
	index = -1;
	while (++index < mesh.size - 1)
		render_face(render, camera, mesh.faces[index], transformMatrix);
}