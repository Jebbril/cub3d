/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 10:59:55 by orakib            #+#    #+#             */
/*   Updated: 2023/09/17 22:41:14 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	has_wall(t_cube *cube, float x, float y)
{
	int	mapgridindexx;
	int	mapgridindexy;

	mapgridindexx = floor(x / TILE_SIZE);
	mapgridindexy = floor(y / TILE_SIZE);
	if (mapgridindexy >= cube->rows
		|| mapgridindexx >= ft_strlen(cube->p.map[mapgridindexy]))
		return (1);
	if (cube->p.map[mapgridindexy][mapgridindexx] == '1')
		return (1);
	else
		return (0);
}

int	has_wall2(t_cube *cube, float x, float y, t_pos p)
{
	int	mapgridindexx;
	int	mapgridindexy;
	int	mapgridindexx1;
	int	mapgridindexy1;

	mapgridindexx = floor(x / TILE_SIZE);
	mapgridindexy = floor(y / TILE_SIZE);
	mapgridindexx1 = floor(p.x / TILE_SIZE);
	mapgridindexy1 = floor(p.y / TILE_SIZE);
	if (cube->p.map[mapgridindexy][mapgridindexx] == '1'
		|| cube->p.map[mapgridindexy1][mapgridindexx] == '1')
		return (1);
	else
		return (0);
}

float	normalize_angle(float angle)
{
	angle = fmod(angle, 2 * M_PI);
	if (angle < 0)
		angle = (2 * M_PI) + angle;
	return (angle);
}

float	distancexy(float x1, float y1, float x2, float y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}
