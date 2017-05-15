/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 14:32:48 by kcosta            #+#    #+#             */
/*   Updated: 2017/05/15 15:51:28 by kcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

# include "libft.h"

# include "ft_math.h"
# include "color.h"
# include "vector2.h"
# include "vector3.h"
# include "matrix.h"
# include "camera.h"
# include "mesh.h"
# include "render.h"

# define KEY_ESCAPE	53
# define KEY_F1		122
# define KEY_F2		120
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2
# define KEY_W		13
# define KEY_I		34
# define KEY_J		38
# define KEY_K		40
# define KEY_L		37
# define KEY_O		31
# define KEY_P		35
# define KEY_MINUS	78
# define KEY_PLUS	69
# define WIDTH		(640)
# define HEIGHT		(480)

typedef struct		s_param
{
	t_render		render;
	t_camera		camera;
	t_mesh			mesh;
}					t_param;

int					read_file(char *name, t_mesh *mesh);
int					ft_error(const char *msg, int ft_errnum);
void				free_lst(void *content, size_t content_size);
void				set_vertice_value(t_vertex **vertice, char **split, int y);
t_vector3			get_max_coord(t_vertex **vertice, int *count, int len);
t_vector3			get_min_coord(t_vertex **vertice, int *count, int len);
t_list				*init_face(t_list *content, t_list *faces,
															t_vector3 *bound);
t_mesh				init_wireframe(t_list *faces, t_vector3 *bound);

#endif
