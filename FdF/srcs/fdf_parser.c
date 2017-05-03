/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 14:34:37 by kcosta            #+#    #+#             */
/*   Updated: 2017/05/03 19:39:02 by kcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				ft_error(const char *msg, int ft_errnum)
{
	ft_putendl_fd(msg, 2);
	return (ft_errnum);
}

void			free_lst(void *content, size_t content_size)
{
	ft_memdel((void**)(&content));
	content_size = 0;
}

t_list			*file_get_content(int fd)
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

void			set_vertice_value(t_vertex **vertice, char **split, int y)
{
	size_t		x;
	int			z;
	t_color		color;
	t_vector3	coord;

	x = 0;
	while (*split)
	{
		z = ft_atoi(*split);
		color = new_color(255, 255, 255);
		coord = new_vector3(x, y, z);
		vertice[0][x] = new_vertex(coord, color);
		split++;
		x++;
	}
}

t_vector3		get_max_coord(t_vertex **vertice, int *count, int len)
{
	int			y;
	int			x;
	t_vector3	max;

	y = -1;
	max = vector3_zero();
	while (++y < len)
	{
		x = -1;
		while (++x < count[y])
			max = vector3_maximize(max, vertice[y][x].coord);
	}
	return (max);
}

t_vector3		get_min_coord(t_vertex **vertice, int *count, int len)
{
	int			y;
	int			x;
	t_vector3	min;

	y = -1;
	min = vector3_zero();
	while (++y < len)
	{
		x = -1;
		while (++x < count[y])
			min = vector3_minimize(min, vertice[y][x].coord);
	}
	return (min);
}

t_vertex		**map_vertice(t_vertex **vertice, int *count,
													int len, t_vector3 *bound)
{
	int			y;
	int			x;

	y = -1;
	bound[0] = get_max_coord(vertice, count, len);
	bound[1] = get_min_coord(vertice, count, len);
	while (++y < len)
	{
		x = -1;
		while (++x < count[y])
		{
			vertice[y][x].coord = vector3_sub(vertice[y][x].coord,
									vector3_scale(bound[0], 0.5f));
			vertice[y][x].color = color_lerp(new_color(255, 0, 0), new_color(0, 0, 255), bound[0].z / vertice[y][x].coord.z);
		}
	}
	return (vertice);
}

t_vertex		**init_vertice(t_list *content, int **count, t_vector3 *bound)
{
	char		**split;
	t_vertex	**vertice;
	size_t		y;
	size_t		len;

	len = ft_lstlen(content);
	vertice = (t_vertex**)ft_memalloc(sizeof(t_vertex*) * len);
	*count = (int*)ft_memalloc(sizeof(int) * len);
	y = 0;
	while (content)
	{
		split = ft_strsplit(content->content, ' ');
		vertice[y] = (t_vertex*)ft_memalloc(sizeof(t_vertex)
												* ft_tablen(split));
		(*count)[y] = ft_tablen(split);
		set_vertice_value(&(vertice[y]), split, y);
		content = content->next;
		ft_tabdel(&split);
		y++;
	}
	vertice = map_vertice(vertice, *count, (int)len, bound);
	return (vertice);
}

void			create_face(t_list **faces, t_vertex **vertice, int x, int y)
{
	t_face		face;

	face = new_face(vertice[y][x],
					vertice[y][x + 1],
					vertice[y + 1][x]);
	ft_lstaddback(faces, ft_lstnew(&face, sizeof(t_face)));
	face = new_face(vertice[y + 1][x + 1],
					vertice[y][x + 1],
					vertice[y + 1][x]);
	ft_lstaddback(faces, ft_lstnew(&face, sizeof(t_face)));
}

t_list			*init_face(t_list *content, t_list *faces, t_vector3 *bound)
{
	t_vertex	**vertice;
	int			*count;
	int			v[3];

	vertice = init_vertice(content, &count, bound);
	v[1] = -1;
	v[2] = (int)ft_lstlen(content);
	faces = ft_lstnew(NULL, 0);
	while (++v[1] < v[2] - 1)
	{
		v[0] = -1;
		while (++v[0] < (count[v[1]] - 1))
			create_face(&faces, vertice, v[0], v[1]);
		ft_memdel((void**)(&(vertice[v[1]])));
	}
	ft_memdel((void**)(&(vertice[v[1]])));
	ft_memdel((void**)(&count));
	ft_memdel((void**)(&vertice));
	return (faces);
}

t_mesh			init_wireframe(t_list *faces, t_vector3 *bound)
{
	t_mesh		wireframe;
	size_t		size;
	size_t		index;

	size = ft_lstlen(faces);
	wireframe = new_mesh(size - 1);
	index = -1;
	while (++index < size - 1)
	{
		faces = faces->next;
		ft_memmove(&(wireframe.faces[index]), faces->content, sizeof(t_face));
	}
	wireframe.position = new_vector3(0, 0, -(bound[0].x + bound[0].y + 10));
	wireframe.rotation = new_vector3(-15 * M_PI / 180, 15 * M_PI / 180, M_PI);
	printf("%f %f\n", bound[0].x, bound[0].y);
	return (wireframe);
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
