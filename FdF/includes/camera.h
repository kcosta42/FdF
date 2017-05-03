/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 19:22:45 by kcosta            #+#    #+#             */
/*   Updated: 2017/05/03 14:24:13 by kcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "vector2.h"
# include "vector3.h"
# include "color.h"
# include "mesh.h"

typedef struct	s_camera
{
	t_vector3	position;
	t_vector3	target;
	t_matrix	view_matrix;
	t_matrix	projection_matrix;
	float		width;
	float		height;
}				t_camera;

t_camera		new_camera(float width, float height);
void			camera_update_view(t_camera *camera);
void			camera_update_projection(t_camera *camera,
											float fov, float near, float far);
t_vertex		camera_project(t_camera camera, t_vertex vertex, t_matrix m);

#endif
