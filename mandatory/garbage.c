/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 18:14:10 by orakib            #+#    #+#             */
/*   Updated: 2023/08/11 18:41:35 by orakib           ###   ########.fr       */
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
	if (cube->map)
		free_matrix(cube->map);
	if (cube->no)
		free(cube->no);
	if (cube->so)
		free(cube->so);
	if (cube->we)
		free(cube->we);
	if (cube->ea)
		free(cube->ea);
	if (cube->f)
		free(cube->f);
	if (cube->c)
		free(cube->c);
}