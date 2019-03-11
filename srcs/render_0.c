/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 19:37:43 by kcosta            #+#    #+#             */
/*   Updated: 2017/05/03 18:35:22 by kcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

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
		mlx_get_data_addr(render.img_ptr, &render.img.bits_per_pixel,
						&render.img.size_line, &render.img.endian);
	render.mode = mode;
	render.depth_buffer = (float*)ft_memalloc(sizeof(float) * (width * height));
	return (render);
}

void			render_destroy(t_render *render)
{
	(void)render;
	return ;
}

void			render_clear(t_render render)
{
	float		x;
	float		y;
	size_t		index;

	y = -1;
	while (++y < render.height)
	{
		x = -1;
		while (++x < render.width)
		{
			index = x + y * render.width;
			if (render.depth_buffer[index] != Z_MAX)
			{
				render.depth_buffer[index] = Z_MAX + 1;
				render_vertex(render, new_vertex(new_vector3(x, y, Z_MAX),
								new_color(0, 0, 0)));
			}
		}
	}
}

void			render_develop(t_render render)
{
	mlx_put_image_to_window(render.mlx_ptr, render.win_ptr, render.img_ptr,
							0, 0);
}
