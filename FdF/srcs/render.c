/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 19:37:43 by kcosta            #+#    #+#             */
/*   Updated: 2017/05/02 21:39:53 by kcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

float			clamp(float value, float min, float max)
{
    return (fmax(min, fmin(value, max)));
}

float			interpolate(float min, float max, float gradient)
{
    return (min + (max - min) * clamp(gradient, 0, 1));
}

void			swap_vertex(t_vertex *v1, t_vertex *v2)
{
	t_vertex	tmp;

	tmp = *v2;
	*v2 = *v1;
	*v1 = tmp;
}

t_render		new_render(int mode, float width, float height, char *name)
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
	render.mode = mode;
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
			render_vertex(render, new_vertex(new_vector3(x, y, 1), new_color_value(0)));
	}
}

void			render_develop(t_render render)
{
	mlx_put_image_to_window(render.mlx_ptr, render.win_ptr, render.img_ptr,
							0, 0);
}

void			render_vertex(t_render render, t_vertex vertex)
{
	t_uint		rgb;

	if (vertex.coord.x >= render.width || vertex.coord.y >= render.height
		|| vertex.coord.x < 0 || vertex.coord.y < 0)
		return ;
	rgb = mlx_get_color_value(render.mlx_ptr, get_color(vertex.color));
	ft_memcpy(	render.img.data
				+ (render.img.bits_per_pixel / 8) * (int)(vertex.coord.x)
				+ render.img.size_line * (int)(vertex.coord.y),
				&rgb, sizeof(rgb));
}

void			render_edge(t_render render, t_vertex start, t_vertex end)
{
    int x0 = (int)start.coord.x;
    int y0 = (int)start.coord.y;
    int x1 = (int)end.coord.x;
    int y1 = (int)end.coord.y;

    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);

    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;
    int err = dx - dy;
	t_color color = color_lerp(start.color, end.color, fmax(dx, dy));
	
    while (1)
	{
		start.color = color_add(start.color, color);
        render_vertex(render, new_vertex(new_vector3(x0, y0, 0), start.color));

        if ((x0 == x1) && (y0 == y1)) break;
        int e2 = 2 * err;
        if (e2 > -dy) { err -= dy; x0 += sx; }
        if (e2 < dx) { err += dx; y0 += sy; }
    }
}


void			render_span(t_render render, int y, t_span span)
{
	int			xdiff;
	float		factor;
	float		factorStep;
	t_color		colordiff;
	t_color		color;
	int			x;

	xdiff = span.x2 - span.x1;
	if(xdiff == 0)
		return;
	colordiff = color_sub(span.color2, span.color1);
	factor = 0.0f;
	factorStep = 1.0f / (float)xdiff;
	x = span.x1 - 1;
	while(++x < span.x2)
	{
		color = color_add(span.color1, color_mult(colordiff, factor));
		render_vertex(render, new_vertex(new_vector3(x, y, 0), color));
		factor += factorStep;
	}
}

void			render_span_edge(t_render render, t_edge e1, t_edge e2)
{
	float		e1ydiff;
	float		e2ydiff;
	float		e1xdiff;
	float		e2xdiff;
	t_color		e1colordiff;
	t_color		e2colordiff;
	float		factor1;
	float		factorStep1;
	float		factor2;
	float		factorStep2;
	int			y;
	t_span		span;

	e1ydiff = e1.v2.coord.y - e1.v1.coord.y;
	e2ydiff = e2.v2.coord.y - e2.v1.coord.y;
	if (e1ydiff == 0.0f || e2ydiff == 0.0f)
        return ;
	e1xdiff = e1.v2.coord.x - e1.v1.coord.x;
	e2xdiff = e2.v2.coord.x - e2.v1.coord.x;
	e1colordiff = color_sub(e1.v2.color, e1.v1.color);
	e2colordiff = color_sub(e2.v2.color, e2.v1.color);
	factor1 = (e2.v1.coord.y - e1.v1.coord.y) / e1ydiff;
	factorStep1 = 1.0f / e1ydiff;
	factor2 = 0.0f;
	factorStep2 = 1.0f / e2ydiff;
	y = (int)e2.v1.coord.y - 1;
	while (++y < (int)e2.v2.coord.y)
	{
		span = new_span(color_add(e1.v1.color, color_mult(e1colordiff, factor1)),
						e1.v1.coord.x + (int)(e1xdiff * factor1),
						color_add(e2.v1.color, color_mult(e2colordiff, factor2)),
						e2.v1.coord.x + (int)(e2xdiff * factor2));
		render_span(render, y, span);
		factor1 += factorStep1;
		factor2 += factorStep2;
	}
}

void			render_rasterize(t_render render, t_face face)
{
	t_edge		edges[3];

    if (face.a.coord.y > face.b.coord.y)
		swap_vertex(&(face.a), &(face.b));
    if (face.b.coord.y > face.c.coord.y)
		swap_vertex(&(face.b), &(face.c));
    if (face.a.coord.y > face.b.coord.y)
		swap_vertex(&(face.a), &(face.b));
	edges[0] = (t_edge){face.a, face.b};
	edges[1] = (t_edge){face.b, face.c};
	edges[2] = (t_edge){face.c, face.a};
	render_span_edge(render, edges[2], edges[0]);
	render_span_edge(render, edges[2], edges[1]);
}

/*
void			process_scan_edge(t_render render, int y, t_vertex *p)
{
	float		gradient1;
	float		gradient2;
	int			sx;
	int			ex;

    gradient1 = p[0].coord.y != p[1].coord.y ?
				(y - p[0].coord.y) / (p[1].coord.y - p[0].coord.y) : 1;
    gradient2 = p[2].coord.y != p[3].coord.y ?
				(y - p[2].coord.y) / (p[3].coord.y - p[2].coord.y) : 1;
            
    sx = (int)interpolate(p[0].coord.x, p[1].coord.x, gradient1);
    ex = (int)interpolate(p[2].coord.x, p[3].coord.x, gradient2);
    float z1 = interpolate(p[0].coord.z, p[1].coord.z, gradient1);
    float z2 = interpolate(p[2].coord.z, p[3].coord.z, gradient2);

    for (int x = sx; x < ex; x++)
    {
        float gradient = (x - sx) / (float)(ex - sx);

        float z = interpolate(z1, z2, gradient);
        render_vertex(render, new_vertex(new_vector3(x, y, z), new_color(255, 0, 0)));
    }
}

void			render_rasterize(t_render render, t_face face)
{
	t_vertex	p1;
	t_vertex	p2;
	t_vertex	p3;
    float		dP1P2;
	float		dP1P3;
	
	p1 = face.a;
	p2 = face.b;
	p3 = face.c;
    if (p1.coord.y > p2.coord.y)
		swap_vertex(&p1, &p2);
    if (p2.coord.y > p3.coord.y)
		swap_vertex(&p2, &p3);
    if (p1.coord.y > p2.coord.y)
		swap_vertex(&p1, &p2);
    if (p2.coord.y - p1.coord.y > 0)
        dP1P2 = (p2.coord.x - p1.coord.x) / (p2.coord.y - p1.coord.y);
    else
        dP1P2 = 0;
    if (p3.coord.y - p1.coord.y > 0)
        dP1P3 = (p3.coord.x - p1.coord.x) / (p3.coord.y - p1.coord.y);
    else
        dP1P3 = 0;
    if (dP1P2 > dP1P3)
    {
        for (int y = (int)p1.coord.y; y <= (int)p3.coord.y; y++)
            if (y < p2.coord.y)
                process_scan_edge(render, y, (t_vertex[4]){p1, p3, p1, p2});
            else
                process_scan_edge(render, y, (t_vertex[4]){p1, p3, p2, p3});
    }
    else
    {
        for (int y = (int)p1.coord.y; y <= (int)p3.coord.y; y++)
            if (y < p2.coord.y)
                process_scan_edge(render, y, (t_vertex[4]){p1, p2, p1, p3});
            else
                process_scan_edge(render, y, (t_vertex[4]){p2, p3, p1, p3});
    }
}
*/

void			render_face(t_render r, t_camera c, t_face f, t_matrix tm)
{
	t_vertex pixelA;
	t_vertex pixelB;
	t_vertex pixelC;

    pixelA = camera_project(c, f.a, tm);
    pixelB = camera_project(c, f.b, tm);
    pixelC = camera_project(c, f.c, tm);

	if (r.mode == VERTEX)
	{
		render_vertex(r, pixelA);
		render_vertex(r, pixelB);
		render_vertex(r, pixelC);
	}
	else if (r.mode == EDGE)
	{
		render_edge(r, pixelA, pixelB);
		render_edge(r, pixelB, pixelC);
		render_edge(r, pixelC, pixelA);
	}
	else
		render_rasterize(r, (t_face){pixelA, pixelB, pixelC});

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