/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 20:56:38 by kcosta            #+#    #+#             */
/*   Updated: 2017/05/15 11:35:44 by kcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

t_camera		new_camera(float width, float height)
{
	t_camera	camera;

	camera.position = vector3_zero();
	camera.target = vector3_zero();
	camera.width = width;
	camera.height = height;
	camera.view_matrix =
				matrix_lookat(camera.position, camera.target, vector3_up());
	camera.projection_matrix =
				matrix_perspective_fov(0.78, width / height, 0.01, 1.0);
	return (camera);
}

void			camera_update_view(t_camera *camera)
{
	camera->view_matrix =
				matrix_lookat(camera->position, camera->target, vector3_up());
}

void			camera_update_projection(t_camera *camera,
											float fov, float near, float far)
{
	camera->projection_matrix =
		matrix_perspective_fov(fov, camera->width / camera->height, near, far);
}

t_vertex		camera_project(t_camera camera, t_vertex vertex, t_matrix m)
{
	t_vertex	new;
	t_vector3	point;

	point = vector3_transform_coor(vertex.coord, m);
	new.coord.x = point.x * camera.width + camera.width / 2.0f;
	new.coord.y = -point.y * camera.height + camera.height / 2.0f;
	new.coord.z = point.z;
	new.color = vertex.color;
	return (new);
}
