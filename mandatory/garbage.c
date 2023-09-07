/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 18:14:10 by orakib            #+#    #+#             */
/*   Updated: 2023/09/07 19:27:31 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_matrix(char **matrice)
{
	int	i;

	i = 0;
	while (matrice[i])
	{
		free(matrice[i]);
		i++;
	}
	free(matrice);
}

void	garbage(t_cube *cube)
{
	if (cube->p.map)
		free_matrix(cube->p.map);
	if (cube->p.mapstr)
		free(cube->p.mapstr);
	if (cube->p.no)
		free(cube->p.no);
	if (cube->p.so)
		free(cube->p.so);
	if (cube->p.we)
		free(cube->p.we);
	if (cube->p.ea)
		free(cube->p.ea);
	if (cube->p.f)
		free(cube->p.f);
	if (cube->p.c)
		free(cube->p.c);
}
