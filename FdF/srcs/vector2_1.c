/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 12:40:51 by kcosta            #+#    #+#             */
/*   Updated: 2017/05/03 12:41:04 by kcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector2.h"

t_uchar			vector2_equals(t_vector2 this, t_vector2 other)
{
	return (this.x == other.x && this.y == other.y);
}

float			vector2_length(t_vector2 this)
{
	return (sqrt(this.x * this.x + this.y * this.y));
}

float			vector2_lengthsqr(t_vector2 this)
{
	return (this.x * this.x + this.y * this.y);
}

t_vector2		vector2_normalize(t_vector2 this)
{
	float		len;
	float		num;

	len = vector2_length(this);
	if (len == 0)
		return (this);
	num = 1.0 / len;
	this.x *= num;
	this.y *= num;
	return (this);
}

t_vector2		vector2_zero(void)
{
	return (new_vector2(0, 0));
}
