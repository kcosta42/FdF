/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 13:26:35 by kcosta            #+#    #+#             */
/*   Updated: 2017/05/03 14:21:08 by kcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void			process_scan_edge(t_render render, int y, t_vertex *p)
{
	int			x[3];
	float		gradient[3];
	float		z[3];
	t_color		colordiff[2];

	gradient[1] = (p[0].coord.y != p[1].coord.y) ?
				(y - p[0].coord.y) / (p[1].coord.y - p[0].coord.y) : 1;
	gradient[2] = (p[2].coord.y != p[3].coord.y) ?
				(y - p[2].coord.y) / (p[3].coord.y - p[2].coord.y) : 1;
	x[1] = (int)interpolate(p[0].coord.x, p[1].coord.x, gradient[1]);
	x[2] = (int)interpolate(p[2].coord.x, p[3].coord.x, gradient[2]);
	z[1] = interpolate(p[0].coord.z, p[1].coord.z, gradient[1]);
	z[2] = interpolate(p[2].coord.z, p[3].coord.z, gradient[2]);
	colordiff[1] = color_lerp(p[1].color, p[0].color, gradient[1]);
	colordiff[0] = color_lerp(p[3].color, p[2].color, gradient[2]);
	x[0] = x[1] - 1;
	while (++x[0] < x[2])
	{
		gradient[0] = (x[0] - x[1]) / (float)(x[2] - x[1]);
		z[0] = interpolate(z[1], z[2], gradient[0]);
		p[0].color = color_lerp(colordiff[0], colordiff[1], gradient[0]);
		render_vertex(render,
					new_vertex(new_vector3(x[0], y, z[0]), p[0].color));
	}
}

void			render_rasterize(t_render render, t_face face)
{
	float		dp1p2;
	float		dp1p3;
	int			y;

	dp1p2 = (face.b.coord.y - face.a.coord.y > 0) ?
	(face.b.coord.x - face.a.coord.x) / (face.b.coord.y - face.a.coord.y) : 0;
	dp1p3 = (face.c.coord.y - face.a.coord.y > 0) ?
	(face.c.coord.x - face.a.coord.x) / (face.c.coord.y - face.a.coord.y) : 0;
	y = (int)face.a.coord.y - 1;
	if (dp1p2 > dp1p3)
		while (++y <= (int)face.c.coord.y)
			if (y < face.b.coord.y)
				process_scan_edge(render, y,
								(t_vertex[4]){face.a, face.c, face.a, face.b});
			else
				process_scan_edge(render, y,
								(t_vertex[4]){face.a, face.c, face.b, face.c});
	else
		while (++y <= (int)face.c.coord.y)
			if (y < face.b.coord.y)
				process_scan_edge(render, y,
								(t_vertex[4]){face.a, face.b, face.a, face.c});
			else
				process_scan_edge(render, y,
								(t_vertex[4]){face.b, face.c, face.a, face.c});
}
