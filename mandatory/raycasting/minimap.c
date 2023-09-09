/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 17:17:20 by orakib            #+#    #+#             */
/*   Updated: 2023/09/09 17:59:33 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	draw_minimap(t_cube *cube)
{
	int			i;
	int			j;
	mlx_image_t	*wall;
	mlx_image_t	*floor;

	i = -1;
	j = -1;
	wall = draw_rect(cube->mlx, TILE_SIZE, TILE_SIZE, 0x000000FF);
	floor = draw_rect(cube->mlx, TILE_SIZE, TILE_SIZE, 0xFFFFFFFF);
	while (cube->p.map[++i])
	{
		while (cube->p.map[i][++j])
		{
			if (cube->p.map[i][j] == '1')
				mlx_image_to_window
					(cube->mlx, wall, j * TILE_SIZE, i * TILE_SIZE);
			if (cube->p.map[i][j] != '1' && cube->p.map[i][j] != ' ')
				mlx_image_to_window
					(cube->mlx, floor, j * TILE_SIZE, i * TILE_SIZE);
		}
		j = -1;
	}
	return (0);
}
