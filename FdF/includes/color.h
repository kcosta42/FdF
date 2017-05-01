/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 12:26:43 by kcosta            #+#    #+#             */
/*   Updated: 2017/04/30 19:42:32 by kcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

typedef unsigned char	t_uchar;

typedef struct		s_color
{
	t_uchar			r;
	t_uchar			g;
	t_uchar			b;
}					t_color;

t_color				new_color(t_uchar r, t_uchar g, t_uchar b);
unsigned int		get_color(t_color color);

#endif
