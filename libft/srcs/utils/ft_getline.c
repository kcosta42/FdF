/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:00:28 by kcosta            #+#    #+#             */
/*   Updated: 2017/05/15 15:33:53 by kcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"
#include "ft_string.h"

int			ft_getline(const int fd, char **line)
{
	char	buff[2];
	char	*dup;
	char	*tmp;
	int		ret;

	dup = ft_strnew(0);
	while ((ret = read(fd, buff, 1)) > 0)
	{
		buff[1] = 0;
		if (!ft_strcmp(buff, "\n"))
			break ;
		tmp = dup;
		dup = ft_strjoin(dup, buff);
		ft_strdel(&tmp);
	}
	*line = ft_strdup(dup);
	ft_strdel(&dup);
	return (ret);
}
