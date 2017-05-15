/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mesh.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 15:10:22 by kcosta            #+#    #+#             */
/*   Updated: 2017/05/15 15:15:51 by kcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_vertex	**map_vertice(t_vertex **vertice, int *count,
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
			vertice[y][x].color = color_lerp(new_color(255, 0, 0),
				new_color(0, 0, 255), (vertice[y][x].coord.z - bound[1].z) /
										(bound[0].z - bound[1].z));
			vertice[y][x].coord = vector3_sub(vertice[y][x].coord,
									vector3_scale(bound[0], 0.5f));
		}
	}
	return (vertice);
}

static t_vertex	**init_vertice(t_list *content, int **count, t_vector3 *bound)
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

static void		create_face(t_list **faces, t_vertex **vertice, int x, int y)
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
	return (wireframe);
}
