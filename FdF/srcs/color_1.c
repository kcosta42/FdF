/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 12:42:15 by kcosta            #+#    #+#             */
/*   Updated: 2017/05/03 12:42:37 by kcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

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
	new.r = interpolate(end.r, start.r, f);
	new.g = interpolate(end.g, start.g, f);
	new.b = interpolate(end.b, start.b, f);
	return (new);
}
