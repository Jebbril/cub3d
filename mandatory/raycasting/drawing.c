/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 16:26:24 by orakib            #+#    #+#             */
/*   Updated: 2023/09/16 23:39:02 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	my_put_pixel(t_cube *cube, float x, float y, uint32_t color)
{
	if (x >= 0 && x < W_WIDTH && y >= 0 && y < W_HEIGHT)
	{
		mlx_put_pixel(cube->img, x, y, color);
	}
}

void	draw_disc(t_cube *cube, int color, float radius)
{
	t_pos	p0;
	t_pos	p;

	p.x = cube->pl.pos.x;
	p.y = cube->pl.pos.y;
	p0.y = -radius;
	while (p0.y <= radius)
	{
		p0.x = -radius;
		while (p0.x <= radius)
		{
			if ((p0.x * p0.x) + p0.y * p0.y <= radius * radius)
				my_put_pixel(cube, p0.x + p.x, p0.y + p.y, color);
			p0.x++;
		}
		p0.y++;
	}
}

void	draw_line(t_cube *cube, int color, t_pos p0, t_pos p1)
{
	int		i;
	float	xinc;
	float	yinc;
	float	steps;

	steps = fmax(fabs(p1.x - p0.x), fabs(p1.y - p0.y));
	xinc = (p1.x - p0.x) / steps;
	yinc = (p1.y - p0.y) / steps;
	i = -1;
	while (++i <= steps)
	{
		my_put_pixel(cube, round(p0.x), round(p0.y), color);
		p0.x += xinc;
		p0.y += yinc;
	}
}

void	draw_minirect(t_cube *cube, float x, float y, int color)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++i < TILE_SIZE)
	{
		while (++j < TILE_SIZE)
		{
			my_put_pixel(cube, j + x, i + y, color);
		}
		j = -1;
	}
}
