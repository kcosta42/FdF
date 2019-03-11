/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 12:57:24 by kcosta            #+#    #+#             */
/*   Updated: 2017/05/03 12:57:32 by kcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_matrix		matrix_rotation_axis(t_vector3 axis, float angle)
{
	t_matrix	matrix;
	float		s;
	float		c;
	float		c1;

	s = sin(-angle);
	c = cos(-angle);
	c1 = 1 - c;
	axis = vector3_normalize(axis);
	matrix = matrix_zero();
	matrix.m[0] = (axis.x * axis.x) * c1 + c;
	matrix.m[1] = (axis.x * axis.y) * c1 - (axis.z * s);
	matrix.m[2] = (axis.x * axis.z) * c1 + (axis.y * s);
	matrix.m[3] = 0.0;
	matrix.m[4] = (axis.y * axis.x) * c1 + (axis.z * s);
	matrix.m[5] = (axis.y * axis.y) * c1 + c;
	matrix.m[6] = (axis.y * axis.z) * c1 - (axis.x * s);
	matrix.m[7] = 0.0;
	matrix.m[8] = (axis.z * axis.x) * c1 - (axis.y * s);
	matrix.m[9] = (axis.z * axis.y) * c1 + (axis.x * s);
	matrix.m[10] = (axis.z * axis.z) * c1 + c;
	matrix.m[11] = 0.0;
	matrix.m[15] = 1.0;
	return (matrix);
}

t_matrix		matrix_scaling(float x, float y, float z)
{
	t_matrix	matrix;

	matrix = matrix_zero();
	matrix.m[0] = x;
	matrix.m[5] = y;
	matrix.m[10] = z;
	matrix.m[15] = 1.0;
	return (matrix);
}

t_matrix		matrix_translation(float x, float y, float z)
{
	t_matrix	matrix;

	matrix = matrix_identity();
	matrix.m[12] = x;
	matrix.m[13] = y;
	matrix.m[14] = z;
	return (matrix);
}
