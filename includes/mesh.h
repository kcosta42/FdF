/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 19:24:11 by kcosta            #+#    #+#             */
/*   Updated: 2017/05/03 17:37:16 by kcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESH_H
# define MESH_H

# include "libft.h"

# include "vector3.h"
# include "matrix.h"
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

t_vertex		new_vertex(t_vector3 coord, t_color color);
t_face			new_face(t_vertex a, t_vertex b, t_vertex c);
t_mesh			new_mesh(size_t size);

void			mesh_destroy(t_mesh *mesh);

#endif
