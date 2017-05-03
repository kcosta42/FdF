/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 12:50:04 by kcosta            #+#    #+#             */
/*   Updated: 2017/05/03 12:50:13 by kcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3.h"

t_vector3		vector3_normalize(t_vector3 this)
{
	float		len;
	float		num;

	len = vector3_length(this);
	if (len == 0)
		return (this);
	num = 1.0 / len;
	this.x *= num;
	this.y *= num;
	this.z *= num;
	return (this);
}

t_vector3		vector3_zero(void)
{
	return (new_vector3(0, 0, 0));
}

t_vector3		vector3_up(void)
{
	return (new_vector3(0, 1.0, 0));
}

t_vector3		vector3_transform_coor(t_vector3 vector, t_matrix transform)
{
	t_vector3	new;
	float		w;

	new.x = (vector.x * transform.m[0]) + (vector.y * transform.m[4]) +
			(vector.z * transform.m[8]) + transform.m[12];
	new.y = (vector.x * transform.m[1]) + (vector.y * transform.m[5]) +
			(vector.z * transform.m[9]) + transform.m[13];
	new.z = (vector.x * transform.m[2]) + (vector.y * transform.m[6]) +
			(vector.z * transform.m[10]) + transform.m[14];
	w = (vector.x * transform.m[3]) + (vector.y * transform.m[7]) +
			(vector.z * transform.m[11]) + transform.m[15];
	return (new_vector3(new.x / w, new.y / w, new.z / w));
}

t_vector3		vector3_transform_norm(t_vector3 vector, t_matrix transform)
{
	t_vector3	new;

	new.x = (vector.x * transform.m[0]) + (vector.y * transform.m[4]) +
			(vector.z * transform.m[8]);
	new.y = (vector.x * transform.m[1]) + (vector.y * transform.m[5]) +
			(vector.z * transform.m[9]);
	new.z = (vector.x * transform.m[2]) + (vector.y * transform.m[6]) +
			(vector.z * transform.m[10]);
	return (new);
}
