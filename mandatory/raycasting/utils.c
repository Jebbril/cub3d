/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 10:59:55 by orakib            #+#    #+#             */
/*   Updated: 2023/09/13 21:33:32 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	has_wall(t_cube *cube, float x, float y)
{
	int	mapgridindexx;
	int	mapgridindexy;

	if (x < 0 || x > W_WIDTH || y < 0 || y > W_HEIGHT)
		return (1);
	mapgridindexx = floor(x / TILE_SIZE);
	mapgridindexy = floor(y / TILE_SIZE);
	if (cube->p.map[mapgridindexy][mapgridindexx] == '1')
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
