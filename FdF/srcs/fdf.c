/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 21:23:11 by kcosta            #+#    #+#             */
/*   Updated: 2017/05/01 17:42:20 by kcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

#define MAX_CUBE 5

t_render	render;
t_camera	camera;
t_mesh		mesh[MAX_CUBE];

t_mesh	init_cube(float value)
{
	t_mesh cube = new_mesh(12);

	t_vector3 a = new_vector3(-value, value, value);
	t_vector3 b = new_vector3(value, value, value);
	t_vector3 c = new_vector3(-value, -value, value);
	t_vector3 d = new_vector3(value, -value, value);
	t_vector3 e = new_vector3(-value, value, -value);
	t_vector3 f = new_vector3(value, value, -value);
	t_vector3 g = new_vector3(value, -value, -value);
	t_vector3 h = new_vector3(-value, -value, -value);

	cube.faces[0] = new_face(a, b, c);
	cube.faces[1] = new_face(b, c, d);
	cube.faces[2] = new_face(b, d, g);
	cube.faces[3] = new_face(b, f, g);
	cube.faces[4] = new_face(a, b, e);
	cube.faces[5] = new_face(b, e, f);

	cube.faces[6] = new_face(c, d, h);
	cube.faces[7] = new_face(d, g, h);
	cube.faces[8] = new_face(a, c, h);
	cube.faces[9] = new_face(a, e, h);
	cube.faces[10] = new_face(e, f, g);
	cube.faces[11] = new_face(e, g, h);

	return (cube);
}

int		run(void)
{
    render_clear(render);

	for (size_t i = 0; i < MAX_CUBE; i++)
	{
		mesh[i].rotation = new_vector3(mesh[i].rotation.x + 0.01f * i, mesh[i].rotation.y + 0.01f * i, mesh[i].rotation.z);
		render_mesh(render, camera, mesh[i]);
	}

    render_develop(render);
	return (0);
}

int		main(void)
{
	render = new_render(640, 480, "FdF");
	camera = new_camera(640, 480);
	float value = 0.25;
	for (size_t i = 0; i < MAX_CUBE; i++, value += 0.25)
		mesh[i] = init_cube(value);
	camera.position = new_vector3(0, 0, 10.0f);
	camera_update_view(&camera);
	mlx_key_hook(render.win_ptr, &run, NULL);
	mlx_loop(render.mlx_ptr);
}