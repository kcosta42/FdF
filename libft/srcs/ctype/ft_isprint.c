/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 16:02:10 by kcosta            #+#    #+#             */
/*   Updated: 2016/11/30 16:13:38 by kcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctype.h"

int		ft_isprint(int c)
{
	return ((c >= 040 && c <= 047) | (c >= 050 && c <= 057) |
			(c >= 060 && c <= 067) | (c >= 070 && c <= 077) |
			(c >= 0100 && c <= 0107) | (c >= 0110 && c <= 0117) |
			(c >= 0120 && c <= 0127) | (c >= 0130 && c <= 0137) |
			(c >= 0140 && c <= 0147) | (c >= 0150 && c <= 0157) |
			(c >= 0160 && c <= 0167) | (c >= 0170 && c < 0177));
}
