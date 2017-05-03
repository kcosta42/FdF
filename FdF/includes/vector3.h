/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 12:30:48 by kcosta            #+#    #+#             */
/*   Updated: 2017/05/03 17:43:28 by kcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR3_H
# define VECTOR3_H

# include <math.h>

# include "matrix.h"

typedef unsigned char	t_uchar;
typedef struct s_matrix	t_matrix;

typedef struct	s_vector3
{
	float		x;
	float		y;
	float		z;
}				t_vector3;

t_vector3		new_vector3(float x, float y, float z);
t_vector3		vector3_zero(void);
t_vector3		vector3_up(void);

t_uchar			vector3_equals(t_vector3 this, t_vector3 other);

t_vector3		vector3_add(t_vector3 this, t_vector3 other);
t_vector3		vector3_sub(t_vector3 this, t_vector3 other);
t_vector3		vector3_negate(t_vector3 this);
t_vector3		vector3_scale(t_vector3 this, float scale);
t_vector3		vector3_mult(t_vector3 this, t_vector3 other);
t_vector3		vector3_div(t_vector3 this, t_vector3 other);
t_vector3		vector3_normalize(t_vector3 this);
t_vector3		vector3_transform_coor(t_vector3 vector, t_matrix transform);
t_vector3		vector3_transform_norm(t_vector3 vector, t_matrix transform);
t_vector3		vector3_cross(t_vector3 left, t_vector3 right);
t_vector3		vector3_minimize(t_vector3 left, t_vector3 right);
t_vector3		vector3_maximize(t_vector3 left, t_vector3 right);

float			vector3_length(t_vector3 this);
float			vector3_lengthsqr(t_vector3 this);
float			vector3_dot(t_vector3 left, t_vector3 right);
float			vector3_distance(t_vector3 v1, t_vector3 v2);
float			vector3_distancesqrt(t_vector3 v1, t_vector3 v2);

#endif
