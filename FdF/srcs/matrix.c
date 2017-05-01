/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 14:04:45 by kcosta            #+#    #+#             */
/*   Updated: 2017/05/01 14:39:08 by kcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_uchar			matrix_is_identity(t_matrix this)
{
	if (this.m[0] != 1.0 || this.m[5] != 1.0 ||
		this.m[10] != 1.0 || this.m[15] != 1.0)
		return (0);
	if (this.m[1] != 0.0 || this.m[2] != 0.0 || this.m[3] != 0.0 ||
		this.m[4] != 0.0 || this.m[6] != 0.0 || this.m[7] != 0.0 ||
		this.m[8] != 0.0 || this.m[9] != 0.0 || this.m[11] != 0.0 ||
		this.m[12] != 0.0 || this.m[13] != 0.0 || this.m[14] != 0.0)
		return (0);
	return (1);
}

float			matrix_determinant(t_matrix this)
{
	t_vector3	tmp1;
	t_vector3	tmp2;

	tmp1.x = (this.m[10] * this.m[15]) - (this.m[11] * this.m[14]);
	tmp1.y = (this.m[9] * this.m[15]) - (this.m[11] * this.m[13]);
	tmp1.z = (this.m[9] * this.m[14]) - (this.m[10] * this.m[13]);
	tmp2.x = (this.m[8] * this.m[15]) - (this.m[11] * this.m[12]);
	tmp2.y = (this.m[8] * this.m[14]) - (this.m[10] * this.m[12]);
	tmp2.z = (this.m[8] * this.m[13]) - (this.m[9] * this.m[12]);
	return ((((this.m[0] * (((this.m[5] * tmp1.x) - (this.m[6] * tmp1.y)) +
			(this.m[7] * tmp1.z))) - (this.m[1] * (((this.m[4] * tmp1.x) -
			(this.m[6] * tmp2.x)) + (this.m[7] * tmp2.y)))) + (this.m[2] *
			(((this.m[4] * tmp1.y) - (this.m[5] * tmp2.x)) +
			(this.m[7] * tmp2.z)))) - (this.m[3] * (((this.m[4] * tmp1.z) -
			(this.m[5] * tmp2.y)) + (this.m[6] * tmp2.z))));
}

static float	*matrix_invert_1(float *l, t_matrix this)
{
	l[0]= this.m[0];
	l[1]= this.m[1];
	l[2]= this.m[2];
	l[3]= this.m[3];
	l[4]= this.m[4];
	l[5]= this.m[5];
	l[6]= this.m[6];
	l[7]= this.m[7];
	l[8]= this.m[8];
	l[9]= this.m[9];
	l[10]= this.m[10];
	l[11]= this.m[11];
	l[12]= this.m[12];
	l[13]= this.m[13];
	l[14]= this.m[14];
	l[15]= this.m[15];
	return (l);
}

static float	*matrix_invert_2(float *l)
{
	l[16]= (l[10] * l[15]) - (l[11] * l[14]);
	l[17]= (l[9] * l[15]) - (l[11] * l[13]);
	l[18]= (l[9] * l[14]) - (l[10] * l[13]);
	l[19]= (l[8] * l[15]) - (l[11] * l[12]);
	l[20]= (l[8] * l[14]) - (l[10] * l[12]);
	l[21]= (l[8] * l[13]) - (l[9] * l[12]);
	l[22]= ((l[5] * l[16]) - (l[6] * l[17]))
			+ (l[7] * l[18]);
	l[23]= -(((l[4] * l[16]) - (l[6] * l[19]))
			+ (l[7] * l[20]));
	l[24]= ((l[4] * l[17]) - (l[5] * l[19]))
			+ (l[7] * l[21]);
	l[25]= -(((l[4] * l[18]) - (l[5] * l[20]))
			+ (l[6] * l[21]));
	l[26]= 1.0 / ((((l[0] * l[22]) + (l[1] * l[23]))
			+ (l[2] * l[24])) + (l[3] * l[25]));
	return (l);
}

static float	*matrix_invert_3(float *l)
{
	l[27]= (l[6] * l[15]) - (l[7] * l[14]);
	l[28]= (l[5] * l[15]) - (l[7] * l[13]);
	l[29]= (l[5] * l[14]) - (l[6] * l[13]);
	l[30]= (l[4] * l[15]) - (l[7] * l[12]);
	l[31]= (l[4] * l[14]) - (l[6] * l[12]);
	l[32]= (l[4] * l[13]) - (l[5] * l[12]);
	l[33]= (l[6] * l[11]) - (l[7] * l[10]);
	l[34] = (l[5] * l[11]) - (l[7] * l[9]);
	l[35] = (l[5] * l[10]) - (l[6] * l[9]);
	l[36] = (l[4] * l[11]) - (l[7] * l[8]);
	l[37] = (l[4] * l[10]) - (l[6] * l[8]);
	l[38] = (l[4] * l[9]) - (l[5] * l[8]);
	return (l);
}

static t_matrix	matrix_invert_4(float *l, t_matrix this)
{
	this.m[0] = l[22] * l[26];
	this.m[4] = l[23] * l[26];
	this.m[8] = l[24] * l[26];
	this.m[12] = l[25] * l[26];
	this.m[1] = -(((l[1] * l[16]) - (l[2] * l[17])) + (l[3] * l[18])) * l[26];
	this.m[5] = (((l[0] * l[16]) - (l[2] * l[19])) + (l[3] * l[20])) * l[26];
	this.m[9] = -(((l[0] * l[17]) - (l[1] * l[19])) + (l[3] * l[21])) * l[26];
	this.m[13] = (((l[0] * l[18]) - (l[1] * l[20])) + (l[2] * l[21])) * l[26];
	this.m[2] = (((l[1] * l[27]) - (l[2] * l[28])) + (l[3] * l[29])) * l[26];
	this.m[6] = -(((l[0] * l[27]) - (l[2] * l[30])) + (l[3] * l[31])) * l[26];
	this.m[10] = (((l[0] * l[28]) - (l[1] * l[30])) + (l[3] * l[32])) * l[26];
	this.m[14] = -(((l[0] * l[29]) - (l[1] * l[31])) + (l[2] * l[32])) * l[26];
	this.m[3] = -(((l[1] * l[33]) - (l[2] * l[34])) + (l[3] * l[35])) * l[26];
	this.m[7] = (((l[0] * l[33]) - (l[2] * l[36])) + (l[3] * l[37])) * l[26];
	this.m[11] = -(((l[0] * l[34]) - (l[1] * l[36])) + (l[3] * l[38])) * l[26];
	this.m[15] = (((l[0] * l[35]) - (l[1] * l[37])) + (l[2] * l[38])) * l[26];
	return (this);
}

t_matrix		matrix_invert(t_matrix this)
{
	float		*l;

	l = (float*)ft_memalloc(sizeof(float) * 39);
	l = matrix_invert_1(l, this);
	l = matrix_invert_2(l);
	l = matrix_invert_3(l);
	this = matrix_invert_4(l, this);
	ft_memdel((void**)&l);
	return (this);
}

static t_matrix	matrix_mult_1(t_matrix this, t_matrix other)
{
	t_matrix	result;

	result.m[0] = this.m[0] * other.m[0] + this.m[1] * other.m[4]
				+ this.m[2] * other.m[8] + this.m[3] * other.m[12];
	result.m[1] = this.m[0] * other.m[1] + this.m[1] * other.m[5]
				+ this.m[2] * other.m[9] + this.m[3] * other.m[13];
	result.m[2] = this.m[0] * other.m[2] + this.m[1] * other.m[6]
				+ this.m[2] * other.m[10] + this.m[3] * other.m[14];
	result.m[3] = this.m[0] * other.m[3] + this.m[1] * other.m[7]
				+ this.m[2] * other.m[11] + this.m[3] * other.m[15];
	result.m[4] = this.m[4] * other.m[0] + this.m[5] * other.m[4]
				+ this.m[6] * other.m[8] + this.m[7] * other.m[12];
	result.m[5] = this.m[4] * other.m[1] + this.m[5] * other.m[5]
				+ this.m[6] * other.m[9] + this.m[7] * other.m[13];
	result.m[6] = this.m[4] * other.m[2] + this.m[5] * other.m[6]
				+ this.m[6] * other.m[10] + this.m[7] * other.m[14];
	result.m[7] = this.m[4] * other.m[3] + this.m[5] * other.m[7]
				+ this.m[6] * other.m[11] + this.m[7] * other.m[15];
	result.m[8] = this.m[8] * other.m[0] + this.m[9] * other.m[4]
				+ this.m[10] * other.m[8] + this.m[11] * other.m[12];
	return (result);
}

t_matrix		matrix_mult(t_matrix this, t_matrix other)
{
	t_matrix	result;

	result = matrix_mult_1(this, other);
	result.m[9] = this.m[8] * other.m[1] + this.m[9] * other.m[5]
				+ this.m[10] * other.m[9] + this.m[11] * other.m[13];
	result.m[10] = this.m[8] * other.m[2] + this.m[9] * other.m[6]
				+ this.m[10] * other.m[10] + this.m[11] * other.m[14];
	result.m[11] = this.m[8] * other.m[3] + this.m[9] * other.m[7]
				+ this.m[10] * other.m[11] + this.m[11] * other.m[15];
	result.m[12] = this.m[12] * other.m[0] + this.m[13] * other.m[4]
				+ this.m[14] * other.m[8] + this.m[15] * other.m[12];
	result.m[13] = this.m[12] * other.m[1] + this.m[13] * other.m[5]
				+ this.m[14] * other.m[9] + this.m[15] * other.m[13];
	result.m[14] = this.m[12] * other.m[2] + this.m[13] * other.m[6]
				+ this.m[14] * other.m[10] + this.m[15] * other.m[14];
	result.m[15] = this.m[12] * other.m[3] + this.m[13] * other.m[7]
				+ this.m[14] * other.m[11] + this.m[15] * other.m[15];
	return result;
}

t_uchar			matrix_equals(t_matrix this, t_matrix value)
{
	return (this.m[0] == value.m[0] && this.m[1] == value.m[1] &&
			this.m[2] == value.m[2] && this.m[3] == value.m[3] &&
			this.m[4] == value.m[4] && this.m[5] == value.m[5] &&
			this.m[6] == value.m[6] && this.m[7] == value.m[7] &&
			this.m[8] == value.m[8] && this.m[9] == value.m[9] &&
			this.m[10] == value.m[10] && this.m[11] == value.m[11] &&
			this.m[12] == value.m[12] && this.m[13] == value.m[13] &&
			this.m[14] == value.m[14] && this.m[15] == value.m[15]);
}

t_matrix		matrix_identity()
{
	t_matrix	matrix;

	ft_memmove(matrix.m,(float[16]){
					1, 0, 0, 0,
					0, 1, 0, 0,
					0, 0, 1, 0,
					0, 0, 0, 1
					}, sizeof(float[16]));
	return (matrix);
}

t_matrix		matrix_zero()
{
	t_matrix	matrix;

	ft_memmove(matrix.m,(float[16]){
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

t_matrix		matrix_rotation_ypr(float yaw, float pitch, float roll)
{
    return (matrix_mult(
			matrix_mult(matrix_rotation_z(roll), matrix_rotation_x(pitch)),
			matrix_rotation_y(yaw)));
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

t_matrix		matrix_lookat(t_vector3 eye, t_vector3 target, t_vector3 up)
{
	t_matrix	matrix;
	t_vector3	zAxis;
	t_vector3	xAxis;
	t_vector3	yAxis;
	t_vector3	e;

	zAxis = vector3_sub(target, eye);
	zAxis = vector3_normalize(zAxis);
	xAxis = vector3_cross(up, zAxis);
	xAxis = vector3_normalize(xAxis);
	yAxis = vector3_cross(zAxis, xAxis);
	yAxis = vector3_normalize(yAxis);
	e.x = -vector3_dot(xAxis, eye);
	e.y = -vector3_dot(yAxis, eye);
	e.z = -vector3_dot(zAxis, eye);
	ft_memmove(matrix.m, (float[16]){
					xAxis.x, yAxis.x, zAxis.x, 0,
					xAxis.y, yAxis.y, zAxis.y, 0,
					xAxis.z, yAxis.z, zAxis.z, 0,
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
	matrix.m[1] = matrix.m[2] = matrix.m[3] = 0.0;
	matrix.m[5] = (2.0 * znear) / height;
	matrix.m[4] = matrix.m[6] = matrix.m[7] = 0.0;
	matrix.m[10] = -zfar / (znear - zfar);
	matrix.m[8] = matrix.m[9] = 0.0;
	matrix.m[11] = 1.0;
	matrix.m[12] = matrix.m[13] = matrix.m[15] = 0.0;
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
	matrix.m[1] = matrix.m[2] = matrix.m[3] = 0.0;
	matrix.m[5] = t;
	matrix.m[4] = matrix.m[6] = matrix.m[7] = 0.0;
	matrix.m[8] = matrix.m[9] = 0.0;
	matrix.m[10] = -zfar / (znear - zfar);
	matrix.m[11] = 1.0;
	matrix.m[12] = matrix.m[13] = matrix.m[15] = 0.0;
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
};
