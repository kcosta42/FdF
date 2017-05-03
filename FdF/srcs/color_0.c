/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 12:26:42 by kcosta            #+#    #+#             */
/*   Updated: 2017/05/03 12:43:49 by kcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

t_color			new_color(int r, int g, int b)
{
	t_color		color;

	color.r = clamp(r, 0, 255);
	color.g = clamp(g, 0, 255);
	color.b = clamp(b, 0, 255);
	return (color);
}

t_color			new_color_value(t_uint rgb)
{
	t_color		color;

	color.r = (0xFF0000 & rgb) >> 16;
	color.g = (0x00FF00 & rgb) >> 8;
	color.b = (0x0000FF & rgb);
	return (color);
}

t_uint			get_color(t_color color)
{
	t_uint		rgb;

	rgb = 0;
	rgb = (rgb << 8) + color.r;
	rgb = (rgb << 8) + color.g;
	rgb = (rgb << 8) + color.b;
	return (rgb);
}

t_color			color_add(t_color this, t_color other)
{
	t_color		new;

	new.r = this.r + other.r;
	new.g = this.g + other.g;
	new.b = this.b + other.b;
	return (new);
}

t_color			color_sub(t_color this, t_color other)
{
	t_color		new;

	new.r = this.r - other.r;
	new.g = this.g - other.g;
	new.b = this.b - other.b;
	return (new);
}
