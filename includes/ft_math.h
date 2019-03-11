/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 11:56:38 by kcosta            #+#    #+#             */
/*   Updated: 2017/05/03 13:12:02 by kcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_H
# define FT_MATH_H

# include <math.h>

float			clamp(float value, float min, float max);
float			interpolate(float min, float max, float gradient);

#endif
