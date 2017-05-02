/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 12:26:42 by kcosta            #+#    #+#             */
/*   Updated: 2017/05/02 18:27:50 by kcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

t_color 		new_color(t_uchar r, t_uchar g, t_uchar b)
{
	t_color		color;

	color.r = r;
	color.g = g;
	color.b = b;
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

t_color			color_mult(t_color this, float factor)
{
	t_color		new;

	new.r = this.r * factor;
	new.g = this.g * factor;
	new.b = this.b * factor;
	return (new);
}

t_color			color_lerp(t_color start, t_color end, float f)
{
	t_color		new;

	if (f == 0)
		return (end);
	new.r = (end.r - start.r) / f;
	new.g = (end.g - start.g) / f;
	new.b = (end.b - start.b) / f;
	return (new);
}