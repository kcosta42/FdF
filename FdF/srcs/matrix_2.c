/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 12:54:44 by kcosta            #+#    #+#             */
/*   Updated: 2017/05/03 12:59:33 by kcosta           ###   ########.fr       */
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
	return (result);
}
