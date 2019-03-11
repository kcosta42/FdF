/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 12:35:36 by kcosta            #+#    #+#             */
/*   Updated: 2017/05/03 12:40:50 by kcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector2.h"

t_vector2		new_vector2(float x, float y)
{
	t_vector2	vector2;

	vector2.x = x;
	vector2.y = y;
	return (vector2);
}

t_vector2		vector2_add(t_vector2 this, t_vector2 other)
{
	t_vector2	new;

	new.x = this.x + other.x;
	new.y = this.y + other.y;
	return (new);
}

t_vector2		vector2_sub(t_vector2 this, t_vector2 other)
{
	t_vector2	new;

	new.x = this.x - other.x;
	new.y = this.y - other.y;
	return (new);
}

t_vector2		vector2_negate(t_vector2 this)
{
	t_vector2	new;

	new.x = -this.x;
	new.y = -this.y;
	return (new);
}

t_vector2		vector2_scale(t_vector2 this, float scale)
{
	t_vector2	new;

	new.x = this.x * scale;
	new.y = this.y * scale;
	return (new);
}
