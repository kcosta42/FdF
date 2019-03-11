/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3_4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 17:42:43 by kcosta            #+#    #+#             */
/*   Updated: 2017/05/15 12:27:20 by kcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3.h"

t_vector3		vector3_minimize(t_vector3 left, t_vector3 right)
{
	t_vector3	new;

	new.x = (left.x < right.x) ? left.x : right.x;
	new.y = (left.y < right.y) ? left.y : right.y;
	new.z = (left.z < right.z) ? left.z : right.z;
	return (new);
}

t_vector3		vector3_maximize(t_vector3 left, t_vector3 right)
{
	t_vector3	new;

	new.x = (left.x > right.x) ? left.x : right.x;
	new.y = (left.y > right.y) ? left.y : right.y;
	new.z = (left.z > right.z) ? left.z : right.z;
	return (new);
}
