/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 19:35:32 by kcosta            #+#    #+#             */
/*   Updated: 2017/05/01 17:01:45 by kcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include <mlx.h>

# include "libft.h"
# include "color.h"
# include "vector2.h"
# include "vector3.h"
# include "matrix.h"
# include "camera.h"
# include "mesh.h"

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
	float		width;
	float		height;
	char		name[2048];
	t_img		img;
}				t_render;

t_render		new_render(float width, float height, char *name);

void			render_clear(t_render render);
void			render_develop(t_render render);
void			render_vertex(t_render r, t_vector2 v, t_color c);
void			render_edge(t_render render, t_vector2 start,
											t_vector2 end, t_color color);

void			render_face(t_render r, t_camera c, t_face f, t_matrix tm);
void			render_mesh(t_render render, t_camera camera, t_mesh mesh);

#endif
