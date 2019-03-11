/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 12:26:43 by kcosta            #+#    #+#             */
/*   Updated: 2017/05/03 11:58:39 by kcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include <math.h>

# include "ft_math.h"

typedef unsigned char	t_uchar;
typedef unsigned int	t_uint;

typedef struct	s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

float			clamp(float value, float min, float max);

t_color			new_color(int r, int g, int b);
t_color			new_color_value(t_uint rgb);

t_color			color_add(t_color this, t_color other);
t_color			color_sub(t_color this, t_color other);
t_color			color_mult(t_color this, float factor);
t_color			color_lerp(t_color start, t_color end, float f);

t_uint			get_color(t_color color);

#endif
