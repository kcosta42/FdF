/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 12:54:06 by kcosta            #+#    #+#             */
/*   Updated: 2017/05/03 12:59:16 by kcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

static float	*matrix_invert_1(float *l, t_matrix this)
{
	l[0] = this.m[0];
	l[1] = this.m[1];
	l[2] = this.m[2];
	l[3] = this.m[3];
	l[4] = this.m[4];
	l[5] = this.m[5];
	l[6] = this.m[6];
	l[7] = this.m[7];
	l[8] = this.m[8];
	l[9] = this.m[9];
	l[10] = this.m[10];
	l[11] = this.m[11];
	l[12] = this.m[12];
	l[13] = this.m[13];
	l[14] = this.m[14];
	l[15] = this.m[15];
	return (l);
}

static float	*matrix_invert_2(float *l)
{
	l[16] = (l[10] * l[15]) - (l[11] * l[14]);
	l[17] = (l[9] * l[15]) - (l[11] * l[13]);
	l[18] = (l[9] * l[14]) - (l[10] * l[13]);
	l[19] = (l[8] * l[15]) - (l[11] * l[12]);
	l[20] = (l[8] * l[14]) - (l[10] * l[12]);
	l[21] = (l[8] * l[13]) - (l[9] * l[12]);
	l[22] = ((l[5] * l[16]) - (l[6] * l[17]))
			+ (l[7] * l[18]);
	l[23] = -(((l[4] * l[16]) - (l[6] * l[19]))
			+ (l[7] * l[20]));
	l[24] = ((l[4] * l[17]) - (l[5] * l[19]))
			+ (l[7] * l[21]);
	l[25] = -(((l[4] * l[18]) - (l[5] * l[20]))
			+ (l[6] * l[21]));
	l[26] = 1.0 / ((((l[0] * l[22]) + (l[1] * l[23]))
			+ (l[2] * l[24])) + (l[3] * l[25]));
	return (l);
}

static float	*matrix_invert_3(float *l)
{
	l[27] = (l[6] * l[15]) - (l[7] * l[14]);
	l[28] = (l[5] * l[15]) - (l[7] * l[13]);
	l[29] = (l[5] * l[14]) - (l[6] * l[13]);
	l[30] = (l[4] * l[15]) - (l[7] * l[12]);
	l[31] = (l[4] * l[14]) - (l[6] * l[12]);
	l[32] = (l[4] * l[13]) - (l[5] * l[12]);
	l[33] = (l[6] * l[11]) - (l[7] * l[10]);
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