/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 12:55:15 by kcosta            #+#    #+#             */
/*   Updated: 2017/05/03 13:05:38 by kcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_matrix		matrix_lookat(t_vector3 eye, t_vector3 target, t_vector3 up)
{
	t_matrix	matrix;
	t_vector3	zaxis;
	t_vector3	xaxis;
	t_vector3	yaxis;
	t_vector3	e;

	zaxis = vector3_sub(target, eye);
	zaxis = vector3_normalize(zaxis);
	xaxis = vector3_cross(up, zaxis);
	xaxis = vector3_normalize(xaxis);
	yaxis = vector3_cross(zaxis, xaxis);
	yaxis = vector3_normalize(yaxis);
	e.x = -vector3_dot(xaxis, eye);
	e.y = -vector3_dot(yaxis, eye);
	e.z = -vector3_dot(zaxis, eye);
	ft_memmove(matrix.m, (float[16]){
					xaxis.x, yaxis.x, zaxis.x, 0,
					xaxis.y, yaxis.y, zaxis.y, 0,
					xaxis.z, yaxis.z, zaxis.z, 0,
					e.x, e.y, e.z, 1
					}, sizeof(float[16]));
	return (matrix);
}

t_matrix		matrix_perspective(float width, float height,
									float znear, float zfar)
{
	t_matrix	matrix;

	matrix = matrix_zero();
	matrix.m[0] = (2.0 * znear) / width;
	matrix.m[1] = 0.0;
	matrix.m[2] = 0.0;
	matrix.m[3] = 0.0;
	matrix.m[5] = (2.0 * znear) / height;
	matrix.m[4] = 0.0;
	matrix.m[6] = 0.0;
	matrix.m[7] = 0.0;
	matrix.m[10] = -zfar / (znear - zfar);
	matrix.m[8] = 0.0;
	matrix.m[9] = 0.0;
	matrix.m[11] = 1.0;
	matrix.m[12] = 0.0;
	matrix.m[13] = 0.0;
	matrix.m[15] = 0.0;
	matrix.m[14] = (znear * zfar) / (znear - zfar);
	return (matrix);
}

t_matrix		matrix_perspective_fov(float fov, float aspect,
										float znear, float zfar)
{
	t_matrix	matrix;
	float		t;

	matrix = matrix_zero();
	t = 1.0 / (tan(fov * 0.5));
	matrix.m[0] = t / aspect;
	matrix.m[1] = 0.0;
	matrix.m[2] = 0.0;
	matrix.m[3] = 0.0;
	matrix.m[5] = t;
	matrix.m[4] = 0.0;
	matrix.m[6] = 0.0;
	matrix.m[7] = 0.0;
	matrix.m[8] = 0.0;
	matrix.m[9] = 0.0;
	matrix.m[10] = -zfar / (znear - zfar);
	matrix.m[11] = 1.0;
	matrix.m[12] = 0.0;
	matrix.m[13] = 0.0;
	matrix.m[15] = 0.0;
	matrix.m[14] = (znear * zfar) / (znear - zfar);
	return (matrix);
}

t_matrix		matrix_transpose(t_matrix matrix)
{
	t_matrix	result;

	result.m[0] = matrix.m[0];
	result.m[1] = matrix.m[4];
	result.m[2] = matrix.m[8];
	result.m[3] = matrix.m[12];
	result.m[4] = matrix.m[1];
	result.m[5] = matrix.m[5];
	result.m[6] = matrix.m[9];
	result.m[7] = matrix.m[13];
	result.m[8] = matrix.m[2];
	result.m[9] = matrix.m[6];
	result.m[10] = matrix.m[10];
	result.m[11] = matrix.m[14];
	result.m[12] = matrix.m[3];
	result.m[13] = matrix.m[7];
	result.m[14] = matrix.m[11];
	result.m[15] = matrix.m[15];
	return (result);
}

t_matrix		matrix_rotation_ypr(float yaw, float pitch, float roll)
{
	return (matrix_mult(
		matrix_mult(matrix_rotation_z(roll), matrix_rotation_x(pitch)),
		matrix_rotation_y(yaw)));
}
