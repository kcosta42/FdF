/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 12:35:36 by kcosta            #+#    #+#             */
/*   Updated: 2017/04/30 13:00:14 by kcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector2.h"
#include "matrix.h"

t_vector2		new_vector2(float x, float y)
{
	t_vector2	vector2;

	vector2.x = x;
	vector2.y = y;
	return (vector2);
}

t_vector2		vector2_add(t_vector2 this, t_vector2 other)
{
	t_vector2	new;

	new.x = this.x + other.x;
	new.y = this.y + other.y;
	return (new);
}

t_vector2		vector2_sub(t_vector2 this, t_vector2 other)
{
	t_vector2	new;

	new.x = this.x - other.x;
	new.y = this.y - other.y;
	return (new);
}

t_vector2		vector2_negate(t_vector2 this)
{
	t_vector2	new;

	new.x = -this.x;
	new.y = -this.y;
	return (new);
}

t_vector2		vector2_scale(t_vector2 this, float scale)
{
	t_vector2	new;

	new.x = this.x * scale;
	new.y = this.y * scale;
	return (new);
}

t_uchar			vector2_equal(t_vector2 this, t_vector2 other)
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

t_vector2		vector2_zero()
{
	return (new_vector2(0, 0));
}

t_vector2		vector2_minimize(t_vector2 left, t_vector2 right)
{
	t_vector2	new;

	new.x = (left.x < right.x) ? left.x : right.x;
	new.y = (left.y < right.y) ? left.y : right.y;
	return (new);
}

t_vector2		vector2_maximize(t_vector2 left, t_vector2 right)
{
	t_vector2	new;

	new.x = (left.x > right.x) ? left.x : right.x;
	new.y = (left.y > right.y) ? left.y : right.y;
	return (new);
}

t_vector2		vector2_transform(t_vector2 vector, t_matrix transform)
{
	t_vector2	new;

	new.x = (vector.x * tranform.m[0]) + (vector.y * transform.m[4]);
	new.y = (vector.x * tranform.m[1]) + (vector.y * transform.m[5]);
	return (new);
}

float			vector2_distance(t_vector2 v1, t_vector2 v2)
{
	return (sqrt(vector2_distancesqr(v1, v2)));
}

float			vector2_distancesqr(t_vector2 v1, t_vector2 v2)
{
	float		x;
	float		y;

	x = v1.x - v2.x;
	y = v1.y - v2.y;
	return ((x * x) + (y * y));
}
