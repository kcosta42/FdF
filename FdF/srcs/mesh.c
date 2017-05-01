/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 19:25:43 by kcosta            #+#    #+#             */
/*   Updated: 2017/05/01 16:29:00 by kcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mesh.h"

t_face			new_face(t_vector3 a, t_vector3 b, t_vector3 c)
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

void			mesh_destroy(t_mesh *mesh)
{
	mesh->position = vector3_zero();
	mesh->rotation = vector3_zero();
	ft_memdel((void**)&(mesh->faces));
	mesh->size = 0;
}
