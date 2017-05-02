/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 19:25:43 by kcosta            #+#    #+#             */
/*   Updated: 2017/05/03 00:10:55 by kcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mesh.h"

t_vertex		new_vertex(t_vector3 coord, t_color color)
{
	t_vertex	vertex;

	vertex.coord = coord;
	vertex.color = color;
	return (vertex);
}

t_face			new_face(t_vertex a, t_vertex b, t_vertex c)
{
	t_face		face;

	face.a = a;
	face.b = b;
	face.c = c;
	return (face);
}

t_mesh			new_mesh(size_t size)
{
	t_mesh		mesh;

	mesh.position = vector3_zero();
	mesh.rotation = vector3_zero();
	mesh.faces = (t_face*)ft_memalloc(sizeof(t_face) * size + 1);
	mesh.size = size;
	return (mesh);
}

t_edge			new_edge(t_vertex v1, t_vertex v2)
{
	t_edge		edge;

	edge.v1 = (v1.coord.y < v2.coord.y) ? v1 : v2;
	edge.v2 = (v1.coord.y < v2.coord.y) ? v2 : v1;
	return (edge);
}

t_span			new_span(t_color color1, int x1, float z1, t_color color2, int x2, float z2)
{
	t_span		span;

	if (x1 < x2)
	{
		span.color1 = color1;
		span.x1 = x1;
		span.z1 = z1;
		span.color2 = color2;
		span.x2 = x2;
		span.z2 = z2;
	}
	else
	{
		span.color1 = color2;
		span.x1 = x2;
		span.z1 = z2;
		span.color2 = color1;
		span.x2  = x1;
		span.z2  = z1;
	}
	return (span);
}

void			mesh_destroy(t_mesh *mesh)
{
	mesh->position = vector3_zero();
	mesh->rotation = vector3_zero();
	ft_memdel((void**)&(mesh->faces));
	mesh->size = 0;
}
