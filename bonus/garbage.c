/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 18:14:10 by orakib            #+#    #+#             */
/*   Updated: 2023/09/17 19:56:49 by orakib           ###   ########.fr       */
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

void	free_matrix2(int **matrice)
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

void	garbage2(t_cube *cube)
{
	if (cube->no)
		mlx_delete_texture(cube->no);
	if (cube->so)
		mlx_delete_texture(cube->so);
	if (cube->ea)
		mlx_delete_texture(cube->ea);
	if (cube->we)
		mlx_delete_texture(cube->we);
	if (cube->no_tab)
		free_matrix2(cube->no_tab);
	if (cube->so_tab)
		free_matrix2(cube->so_tab);
	if (cube->ea_tab)
		free_matrix2(cube->ea_tab);
	if (cube->we_tab)
		free_matrix2(cube->we_tab);
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
	garbage2(cube);
}
