/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 12:50:20 by kcosta            #+#    #+#             */
/*   Updated: 2017/05/03 12:50:28 by kcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3.h"

float			vector3_dot(t_vector3 left, t_vector3 right)
{
	return (left.x * right.x + left.y * right.y + left.z * right.z);
}

t_vector3		vector3_cross(t_vector3 left, t_vector3 right)
{
	t_vector3	new;

	new.x = left.y * right.z - left.z * right.y;
	new.y = left.z * right.x - left.x * right.z;
	new.z = left.x * right.y - left.y * right.x;
	return (new);
}

float			vector3_distance(t_vector3 v1, t_vector3 v2)
{
	return (sqrt(vector3_distancesqrt(v1, v2)));
}

float			vector3_distancesqrt(t_vector3 v1, t_vector3 v2)
{
	float		x;
	float		y;
	float		z;

	x = v1.x - v2.x;
	y = v1.y - v2.y;
	z = v1.z - v2.z;
	return ((x * x) + (y * y) + (z * z));
}
