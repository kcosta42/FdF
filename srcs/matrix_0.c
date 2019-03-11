/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 14:04:45 by kcosta            #+#    #+#             */
/*   Updated: 2017/05/03 13:00:36 by kcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_matrix		matrix_identity(void)
{
	t_matrix	matrix;

	ft_memmove(matrix.m, (float[16]){
					1, 0, 0, 0,
					0, 1, 0, 0,
					0, 0, 1, 0,
					0, 0, 0, 1
					}, sizeof(float[16]));
	return (matrix);
}

t_matrix		matrix_zero(void)
{
	t_matrix	matrix;

	ft_memmove(matrix.m, (float[16]){
					1, 0, 0, 0,
					0, 1, 0, 0,
					0, 0, 1, 0,
					0, 0, 0, 1
					}, sizeof(float[16]));
	return (matrix);
}

t_matrix		matrix_rotation_x(float angle)
{
	t_matrix	matrix;
	float		s;
	float		c;

	matrix = matrix_zero();
	s = sin(angle);
	c = cos(angle);
	matrix.m[0] = 1.0;
	matrix.m[15] = 1.0;
	matrix.m[5] = c;
	matrix.m[10] = c;
	matrix.m[9] = -s;
	matrix.m[6] = s;
	return (matrix);
}

t_matrix		matrix_rotation_y(float angle)
{
	t_matrix	matrix;
	float		s;
	float		c;

	matrix = matrix_zero();
	s = sin(angle);
	c = cos(angle);
	matrix.m[5] = 1.0;
	matrix.m[15] = 1.0;
	matrix.m[0] = c;
	matrix.m[2] = -s;
	matrix.m[8] = s;
	matrix.m[10] = c;
	return (matrix);
}

t_matrix		matrix_rotation_z(float angle)
{
	t_matrix	matrix;
	float		s;
	float		c;

	matrix = matrix_zero();
	s = sin(angle);
	c = cos(angle);
	matrix.m[10] = 1.0;
	matrix.m[15] = 1.0;
	matrix.m[0] = c;
	matrix.m[1] = s;
	matrix.m[4] = -s;
	matrix.m[5] = c;
	return (matrix);
}
