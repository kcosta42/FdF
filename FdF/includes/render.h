/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 19:35:32 by kcosta            #+#    #+#             */
/*   Updated: 2017/05/02 23:27:28 by kcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include <mlx.h>
# include <math.h>

# include "libft.h"
# include "color.h"
# include "vector2.h"
# include "vector3.h"
# include "matrix.h"
# include "camera.h"
# include "mesh.h"

# define VERTEX		1
# define EDGE		2
# define RASTERIZE	3
# define Z_MAX		10000

typedef unsigned int	t_uint;

typedef struct	s_img
{	
	char		*data;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
}				t_img;

typedef struct	s_render
{
	void		*mlx_ptr;
	void		*img_ptr;
	void		*win_ptr;
	int			mode;
	float		width;
	float		height;
	char		name[2048];
	float		*depthBuffer;
	t_img		img;
}				t_render;

float			interpolate(float min, float max, float gradient);
void			swap_vertex(t_vertex *v1, t_vertex *v2);

t_render		new_render(int mode, float width, float height, char *name);
void			render_destroy(t_render *render);

void			render_clear(t_render render);
void			render_develop(t_render render);
void			render_vertex(t_render render, t_vertex vertex);
void			render_edge(t_render render, t_vertex start, t_vertex end);

/*
** void			process_scan_edge(t_render render, int y, t_vertex *p);
** void			render_rasterize(t_render render, t_face face);
*/

void			render_face(t_render r, t_camera c, t_face f, t_matrix tm);
void			render_mesh(t_render render, t_camera camera, t_mesh mesh);

#endif
