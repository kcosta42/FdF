/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 18:24:53 by kcosta            #+#    #+#             */
/*   Updated: 2016/11/30 16:07:29 by kcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctype.h"

int		ft_isspace(int c)
{
	return ((c == ' ') | (c == '\n') | (c == '\t') |
			(c == '\v') | (c == '\f') | (c == '\r'));
}
