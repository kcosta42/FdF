/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 14:32:48 by kcosta            #+#    #+#             */
/*   Updated: 2017/05/03 17:01:29 by kcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

# include "libft.h"

# include "ft_math.h"
# include "color.h"
# include "vector2.h"
# include "vector3.h"
# include "matrix.h"
# include "camera.h"
# include "mesh.h"
# include "render.h"

int				read_file(char *name, t_mesh *mesh);

#endif