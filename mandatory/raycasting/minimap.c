/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 17:07:50 by orakib            #+#    #+#             */
/*   Updated: 2023/08/28 18:24:37 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	draw_tiles(t_cube *cube)
{
	int	i;
	int	j;

	cube->mapwall = mlx_new_image(cube->mlx, TILE_SIZE, TILE_SIZE);
	if (!cube->mapwall)
		return (1);
	i = -1;
	j = -1;
	while (++i < TILE_SIZE)
	{
		while (++j < TILE_SIZE)
			mlx_put_pixel(cube->mapwall, i, j, 0x000000FF);
		j = -1;
	}
	cube->mapzero = mlx_new_image(cube->mlx, TILE_SIZE, TILE_SIZE);
	if (!cube->mapzero)
		return (1);
	i = -1;
	while (++i < TILE_SIZE)
	{
		while (++j < TILE_SIZE)
			mlx_put_pixel(cube->mapzero, i, j, 0xFFFFFFFF);
		j = -1;
	}
	return (0);
}

int	draw_minimap(t_cube *cube)
{
	int	i;
	int	j;

	if (draw_tiles(cube))
		return (1);
	i = -1;
	j = -1;
	while (cube->map[++i])
	{
		while (cube->map[i][++j])
		{
			if (cube->map[i][j] == '1')
				mlx_image_to_window
					(cube->mlx, cube->mapwall, j * TILE_SIZE, i * TILE_SIZE);
			if (cube->map[i][j] != ' ' && cube->map[i][j] != '1')
				mlx_image_to_window
					(cube->mlx, cube->mapzero, j * TILE_SIZE, i * TILE_SIZE);
		}
		j = -1;
	}
	return (0);
}
