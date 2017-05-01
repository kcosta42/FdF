/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 14:04:46 by kcosta            #+#    #+#             */
/*   Updated: 2017/04/30 19:29:39 by kcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# include <math.h>

# include "libft.h"

typedef unsigned char	t_uchar;

typedef struct	s_matrix
{
	float		m[16];
}				t_matrix;

# include "vector3.h"

t_matrix		matrix_identity();
t_matrix		matrix_zero();
t_matrix		matrix_rotation_x(float angle);
t_matrix		matrix_rotation_y(float angle);
t_matrix		matrix_rotation_z(float angle);
t_matrix		matrix_scaling(float x, float y, float z);
t_matrix		matrix_translation(float x, float y, float z);

t_matrix		matrix_rotation_axis(t_vector3 axis, float angle);
t_matrix		matrix_rotation_ypr(float yaw, float pitch, float roll);
t_matrix		matrix_lookat(t_vector3 eye, t_vector3 target, t_vector3 up);
t_matrix		matrix_perspective(float width, float height,
									float znear, float zfar);
t_matrix		matrix_perspective_fov(float fov, float aspect,
										float znear, float zfar);

t_uchar			matrix_is_identity(t_matrix this);
t_uchar			matrix_equals(t_matrix this, t_matrix value);

float			matrix_determinant(t_matrix this);

t_matrix		matrix_invert(t_matrix this);
t_matrix		matrix_mult(t_matrix this, t_matrix other);
t_matrix		matrix_transpose(t_matrix matrix);

#endif
