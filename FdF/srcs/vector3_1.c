/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 12:49:29 by kcosta            #+#    #+#             */
/*   Updated: 2017/05/03 12:49:39 by kcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3.h"

t_uchar			vector3_equals(t_vector3 this, t_vector3 other)
{
	return (this.x == other.x && this.y == other.y && this.z == other.z);
}

t_vector3		vector3_mult(t_vector3 this, t_vector3 other)
{
	t_vector3	new;

	new.x = this.x * other.x;
	new.y = this.y * other.y;
	new.z = this.z * other.z;
	return (new);
}

t_vector3		vector3_div(t_vector3 this, t_vector3 other)
{
	t_vector3	new;

	new.x = this.x / other.x;
	new.y = this.y / other.y;
	new.z = this.z / other.z;
	return (new);
}

float			vector3_length(t_vector3 this)
{
	return (sqrt(this.x * this.x + this.y * this.y + this.z * this.z));
}

float			vector3_lengthsqr(t_vector3 this)
{
	return (this.x * this.x + this.y * this.y + this.z * this.z);
}
