/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 12:35:18 by kcosta            #+#    #+#             */
/*   Updated: 2017/04/30 12:59:45 by kcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR2_H
# define VECTOR2_H

# include <math.h>

typedef struct	s_vector2
{
	float		x;
	float		y;
}				t_vector2;

t_vector2		new_vector2(float x, float y);
t_vector2		vector2_zero();

t_uchar			vector2_equal(t_vector2 this, t_vector2 other);

t_vector2		vector2_add(t_vector2 this, t_vector2 other);
t_vector2		vector2_sub(t_vector2 this, t_vector2 other);
t_vector2		vector2_negate(t_vector2 this);
t_vector2		vector2_scale(t_vector2 this, float scale);
t_vector2		vector2_normalize(t_vector2 this);
t_vector2		vector2_minimize(t_vector2 left, t_vector2 right);
t_vector2		vector2_maximize(t_vector2 left, t_vector2 right);
t_vector2		vector2_transform(t_vector2 vector, t_matrix transform);

float			vector2_length(t_vector2 this);
float			vector2_lengthsqr(t_vector2 this);
float			vector2_distance(t_vector2 v1, t_vector2 v2);
float			vector2_distancesqr(t_vector2 v1, t_vector2 v2);

#endif
