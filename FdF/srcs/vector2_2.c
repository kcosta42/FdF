/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 12:40:27 by kcosta            #+#    #+#             */
/*   Updated: 2017/05/03 12:40:37 by kcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector2.h"

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

	new.x = (vector.x * transform.m[0]) + (vector.y * transform.m[4]);
	new.y = (vector.x * transform.m[1]) + (vector.y * transform.m[5]);
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
