/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3_0.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 12:30:50 by kcosta            #+#    #+#             */
/*   Updated: 2017/05/03 12:50:19 by kcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3.h"

t_vector3		new_vector3(float x, float y, float z)
{
	t_vector3	vector3;

	vector3.x = x;
	vector3.y = y;
	vector3.z = z;
	return (vector3);
}

t_vector3		vector3_add(t_vector3 this, t_vector3 other)
{
	t_vector3	new;

	new.x = this.x + other.x;
	new.y = this.y + other.y;
	new.z = this.z + other.z;
	return (new);
}

t_vector3		vector3_sub(t_vector3 this, t_vector3 other)
{
	t_vector3	new;

	new.x = this.x - other.x;
	new.y = this.y - other.y;
	new.z = this.z - other.z;
	return (new);
}

t_vector3		vector3_negate(t_vector3 this)
{
	t_vector3	new;

	new.x = -this.x;
	new.y = -this.y;
	new.z = -this.z;
	return (new);
}

t_vector3		vector3_scale(t_vector3 this, float scale)
{
	t_vector3	new;

	new.x = this.x * scale;
	new.y = this.y * scale;
	new.z = this.z * scale;
	return (new);
}
