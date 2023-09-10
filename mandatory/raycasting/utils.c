/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 10:59:55 by orakib            #+#    #+#             */
/*   Updated: 2023/09/10 11:36:54 by orakib           ###   ########.fr       */
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
