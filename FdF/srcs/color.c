/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 12:26:42 by kcosta            #+#    #+#             */
/*   Updated: 2017/04/30 19:42:18 by kcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

t_color 			new_color(t_uchar r, t_uchar g, t_uchar b)
{
	t_color	color;

	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
}

unsigned int		get_color(t_color color)
{
	unsigned int	rgb;

	rgb = 0;
	rgb = (rgb << 8) + color.r;
	rgb = (rgb << 8) + color.g;
	rgb = (rgb << 8) + color.b;
	return (rgb);
}
