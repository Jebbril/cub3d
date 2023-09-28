/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 17:17:20 by orakib            #+#    #+#             */
/*   Updated: 2023/09/27 13:29:01 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	has_wall3(t_cube *cube, float x, float y)
{
	int	mapgridindexx;
	int	mapgridindexy;

	mapgridindexx = floor(x / TILE_SIZE);
	mapgridindexy = floor(y / TILE_SIZE);
	if (mapgridindexy >= cube->rows
		|| mapgridindexx >= cube->max_cols)
		return (1);
	if (cube->p.map[mapgridindexy][mapgridindexx] == '1')
		return (1);
	if (cube->p.map[mapgridindexy][mapgridindexx] == ' ')
		return (2);
	else
		return (0);
}

void	choose_color(t_mini *v, t_cube *cube)
{
	if (v->i >= 0 && v->j >= 0)
	{
		if (has_wall3(cube, v->j, v->i) == 1)
			my_put_pixel(cube, v->jzero, v->izero, 0x000000FF);
		else if (has_wall3(cube, v->j, v->i) == 2)
			my_put_pixel(cube, v->jzero, v->izero, 0x0000FFFF);
		else
			my_put_pixel(cube, v->jzero, v->izero, 0xFFFFFFFF);
	}
	else
		my_put_pixel(cube, v->jzero, v->izero, 0x000000FF);
}

void	draw_minimap(t_cube *cube)
{
	t_mini	v;

	v.i = cube->pl.pos.y - 100;
	v.izero = 0;
	while (v.izero < 200)
	{
		v.j = cube->pl.pos.x - 200;
		v.jzero = 0;
		while (v.jzero < 400)
		{
			choose_color(&v, cube);
			v.j++;
			v.jzero++;
		}
		v.i++;
		v.izero++;
	}
}
