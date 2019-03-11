/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 14:34:37 by kcosta            #+#    #+#             */
/*   Updated: 2017/05/15 15:13:15 by kcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_list	*file_get_content(int fd)
{
	t_list		*content;
	char		*line;

	content = NULL;
	while (ft_getline(fd, &line))
	{
		if (!content)
			content = ft_lstnew(line, ft_strlen(line) + 1);
		else
			ft_lstaddback(&content, ft_lstnew(line, ft_strlen(line) + 1));
		ft_strdel(&line);
	}
	ft_strdel(&line);
	return (content);
}

int				read_file(char *name, t_mesh *mesh)
{
	int			fd;
	t_list		*content;
	t_list		*faces;
	t_vector3	bound[2];

	if ((fd = open(name, O_RDONLY)) == -1)
		return (ft_error("Failed to open file\n", 1));
	if (!(content = file_get_content(fd)))
		return (ft_error("Error while reading file\n", 2));
	faces = NULL;
	if (!(faces = init_face(content, faces, bound)))
		return (ft_error("Error while processing vertex\n", 2));
	*mesh = init_wireframe(faces, bound);
	if (close(fd) == -1)
		ft_error("Failed to close file\n", 3);
	ft_lstdel(&content, &free_lst);
	ft_lstdel(&faces, &free_lst);
	return (0);
}
