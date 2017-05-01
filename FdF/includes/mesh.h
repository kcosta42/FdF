/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 19:24:11 by kcosta            #+#    #+#             */
/*   Updated: 2017/05/01 16:29:10 by kcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESH_H
# define MESH_H

# include "libft.h"

# include "vector3.h"

typedef struct	s_face
{
	t_vector3	a;
	t_vector3	b;
	t_vector3	c;
}				t_face;

typedef struct	s_mesh
{
	t_vector3	position;
	t_vector3	rotation;
	t_face		*faces;
	size_t		size;
}				t_mesh;

t_face			new_face(t_vector3 a, t_vector3 b, t_vector3 c);

t_mesh			new_mesh(size_t size);
void			mesh_destroy(t_mesh *mesh);

#endif
