/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 17:17:20 by orakib            #+#    #+#             */
/*   Updated: 2023/09/11 17:41:47 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	draw_minimap(t_cube *cube)
{
	int			i;
	int			j;

	i = -1;
	j = -1;
	while (cube->p.map[++i])
	{
		while (cube->p.map[i][++j])
		{
			if (cube->p.map[i][j] == '1')
				draw_minirect
					(cube, j * TILE_SIZE, i * TILE_SIZE, 0x000000FF);
			if (cube->p.map[i][j] != '1' && cube->p.map[i][j] != ' ')
				draw_minirect
					(cube, j * TILE_SIZE, i * TILE_SIZE, 0xFFFFFFFF);
		}
		j = -1;
	}
	return (0);
}
