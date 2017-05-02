/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 19:24:11 by kcosta            #+#    #+#             */
/*   Updated: 2017/05/03 00:11:10 by kcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESH_H
# define MESH_H

# include "libft.h"

# include "vector3.h"
# include "color.h"

typedef struct	s_vertex
{
	t_vector3	coord;
	t_color		color;
}				t_vertex;

typedef struct	s_face
{
	t_vertex	a;
	t_vertex	b;
	t_vertex	c;
}				t_face;

typedef struct	s_mesh
{
	t_vector3	position;
	t_vector3	rotation;
	t_face		*faces;
	size_t		size;
}				t_mesh;

typedef struct	s_edge
{
	t_vertex	v1;
	t_vertex	v2;
}				t_edge;

typedef struct	s_span
{
	t_color		color1;
	t_color		color2;
	int			x1;
	int			x2;
	float		z1;
	float		z2;
}				t_span;

t_vertex		new_vertex(t_vector3 coord, t_color color);
t_face			new_face(t_vertex a, t_vertex b, t_vertex c);
t_mesh			new_mesh(size_t size);
t_edge			new_edge(t_vertex v1, t_vertex v2);
t_span			new_span(t_color color1, int x1, float z1, t_color color2, int x2, float z2);

void			mesh_destroy(t_mesh *mesh);

#endif
