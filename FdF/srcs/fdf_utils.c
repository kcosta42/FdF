/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 15:10:24 by kcosta            #+#    #+#             */
/*   Updated: 2017/05/15 15:16:58 by kcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				ft_error(const char *msg, int ft_errnum)
{
	ft_putendl_fd(msg, 2);
	return (ft_errnum);
}

void			free_lst(void *content, size_t content_size)
{
	ft_memdel((void**)(&content));
	content_size = 0;
}

void			set_vertice_value(t_vertex **vertice, char **split, int y)
{
	size_t		x;
	int			z;
	t_color		color;
	t_vector3	coord;

	x = 0;
	while (*split)
	{
		z = ft_atoi(*split);
		color = new_color(255, 255, 255);
		coord = new_vector3(x, y, z);
		vertice[0][x] = new_vertex(coord, color);
		split++;
		x++;
	}
}

t_vector3		get_max_coord(t_vertex **vertice, int *count, int len)
{
	int			y;
	int			x;
	t_vector3	max;

	y = -1;
	max = vector3_zero();
	while (++y < len)
	{
		x = -1;
		while (++x < count[y])
			max = vector3_maximize(max, vertice[y][x].coord);
	}
	return (max);
}

t_vector3		get_min_coord(t_vertex **vertice, int *count, int len)
{
	int			y;
	int			x;
	t_vector3	min;

	y = -1;
	min = vector3_zero();
	while (++y < len)
	{
		x = -1;
		while (++x < count[y])
			min = vector3_minimize(min, vertice[y][x].coord);
	}
	return (min);
}
