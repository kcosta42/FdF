/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 12:30:50 by kcosta            #+#    #+#             */
/*   Updated: 2017/04/30 14:07:34 by kcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3.h"

t_vector3		new_vector3(float x, float y, float z)
{
	t_vector3	vector3;

	vector3.x = x;
	vector3.y = y;
	vector3.z = z;
	return (vector3);
}

t_vector3		vector3_add(t_vector3 this, t_vector3 other)
{
	t_vector3	new;

	new.x = this.x + other.x;
	new.y = this.y + other.y;
	new.z = this.z + other.z;
	return (new);
}

t_vector3		vector3_sub(t_vector3 this, t_vector3 other)
{
	t_vector3	new;

	new.x = this.x - other.x;
	new.y = this.y - other.y;
	new.z = this.z - other.z;
	return (new);
}

t_vector3		vector3_negate(t_vector3 this)
{
	t_vector3	new;

	new.x = -this.x;
	new.y = -this.y;
	new.z = -this.z;
	return (new);
}

t_vector3		vector3_scale(t_vector3 this, float scale)
{
	t_vector3	new;

	new.x = this.x * scale;
	new.y = this.y * scale;
	new.z = this.z * scale;
	return (new);
}

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

t_vector3		vector3_zero()
{
	return (new_vector3(0, 0, 0));
}

t_vector3		vector3_up()
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
	w = 	(vector.x * transform.m[3]) + (vector.y * transform.m[7]) +
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
