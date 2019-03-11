/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 11:56:57 by kcosta            #+#    #+#             */
/*   Updated: 2017/05/03 13:12:20 by kcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

float			clamp(float value, float min, float max)
{
	return (fmax(min, fmin(value, max)));
}

float			interpolate(float min, float max, float gradient)
{
	return (min + (max - min) * clamp(gradient, 0, 1));
}
