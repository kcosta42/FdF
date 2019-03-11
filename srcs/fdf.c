/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 21:23:11 by kcosta            #+#    #+#             */
/*   Updated: 2017/05/25 13:24:50 by kcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_vector3	manage_rotation(int keycode, t_vector3 base)
{
	t_vector3	new;

	new = base;
	if (keycode == KEY_J)
		new = new_vector3(new.x, new.y + 0.05f, new.z);
	else if (keycode == KEY_I)
		new = new_vector3(new.x - 0.05f, new.y, new.z);
	else if (keycode == KEY_L)
		new = new_vector3(new.x, new.y - 0.05f, new.z);
	else if (keycode == KEY_K)
		new = new_vector3(new.x + 0.05f, new.y, new.z);
	else if (keycode == KEY_O)
		new = new_vector3(new.x, new.y, new.z - 0.05f);
	else if (keycode == KEY_P)
		new = new_vector3(new.x, new.y, new.z + 0.05f);
	return (new);
}

static t_vector3	manage_translation(int keycode, t_vector3 base)
{
	t_vector3	new;

	new = base;
	if (keycode == KEY_W)
		new = new_vector3(new.x, new.y + 0.25f, new.z);
	else if (keycode == KEY_D)
		new = new_vector3(new.x - 0.25f, new.y, new.z);
	else if (keycode == KEY_S)
		new = new_vector3(new.x, new.y - 0.25f, new.z);
	else if (keycode == KEY_A)
		new = new_vector3(new.x + 0.25f, new.y, new.z);
	else if (keycode == KEY_MINUS)
		new = new_vector3(new.x, new.y, new.z - 1.0f);
	else if (keycode == KEY_PLUS)
		new = new_vector3(new.x, new.y, new.z + 1.0f);
	return (new);
}

static int			run(int keycode, t_param *param)
{
	render_clear(param->render);
	if (keycode == KEY_ESCAPE)
		exit(0);
	else if (keycode == KEY_F1)
		param->render.mode = EDGE;
	else if (keycode == KEY_F2)
		param->render.mode = RASTERIZE;
	param->mesh.position = manage_translation(keycode, param->mesh.position);
	param->mesh.rotation = manage_rotation(keycode, param->mesh.rotation);
	render_mesh(param->render, param->camera, param->mesh);
	render_develop(param->render);
	return (0);
}

static t_uchar		ft_check_ext(char *filename)
{
	char			*extension;

	extension = ft_strrchr(filename, '.');
	if (!extension)
		return (1);
	if (ft_strcmp(extension, ".fdf"))
		return (2);
	return (0);
}

int					main(int argc, char **argv)
{
	t_param		param;

	if (argc != 2)
		return (1);
	if (ft_check_ext(argv[1]))
		return (2);
	if (read_file(argv[1], &(param.mesh)))
		return (3);
	param.render = new_render(EDGE, WIDTH, HEIGHT, "FdF");
	param.camera = new_camera(WIDTH, HEIGHT);
	param.camera.position = new_vector3(0, 0, 10.0f);
	param.camera.target = param.mesh.position;
	camera_update_view(&(param.camera));
	run(0, &param);
	mlx_key_hook(param.render.win_ptr, &run, &param);
	mlx_loop(param.render.mlx_ptr);
	return (0);
}
