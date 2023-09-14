/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 21:03:08 by orakib            #+#    #+#             */
/*   Updated: 2023/09/14 22:43:05 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	render_walls(t_cube *cube)
{
	int	i;

	i = -1;
	while (++i < NUM_RAYS)
	{
		float correct_dist = cube->rays[i].distance * cos(cube->rays[i].rayangle - cube->pl.rotationangle);
		float dist_projplane = (W_WIDTH / 2) / tan(cube->fov / 2);
		float projwall_height = (TILE_SIZE / correct_dist) * dist_projplane;
		int wallstrip_height = (int)projwall_height;
		int walltop_pixel = (W_HEIGHT / 2) - (wallstrip_height / 2);
		walltop_pixel = walltop_pixel < 0 ? 0 : walltop_pixel;
		int wallbottom_pixel = (W_HEIGHT / 2) + (wallstrip_height / 2);
		wallbottom_pixel = wallbottom_pixel > W_HEIGHT ? W_HEIGHT : wallbottom_pixel;
		int	y = walltop_pixel;
		while (y++ < wallbottom_pixel)
		{
			if (cube->rays[i].israyfacingup && cube->rays[i].israyfacingright && cube->rays[i].washitvertical)
				my_put_pixel(cube, i, y, 0xFFFFFFFF);
			else if (cube->rays[i].israyfacingup && cube->rays[i].israyfacingright && !cube->rays[i].washitvertical)
				my_put_pixel(cube, i, y, 0x0000FFFF);
			else if (cube->rays[i].israyfacingup && cube->rays[i].israyfacingleft && cube->rays[i].washitvertical)
				my_put_pixel(cube, i, y, 0xFF0000FF);
			else if (cube->rays[i].israyfacingup && cube->rays[i].israyfacingleft && !cube->rays[i].washitvertical)
				my_put_pixel(cube, i, y, 0x0000FFFF);
			else if (cube->rays[i].israyfacingdown && cube->rays[i].israyfacingright && cube->rays[i].washitvertical)
				my_put_pixel(cube, i, y, 0xFFFFFFFF);
			else if (cube->rays[i].israyfacingdown && cube->rays[i].israyfacingright && !cube->rays[i].washitvertical)
				my_put_pixel(cube, i, y, 0x00FF00FF);
			else if (cube->rays[i].israyfacingdown && cube->rays[i].israyfacingleft && cube->rays[i].washitvertical)
				my_put_pixel(cube, i, y, 0xFF0000FF);
			else if (cube->rays[i].israyfacingdown && cube->rays[i].israyfacingleft && !cube->rays[i].washitvertical)
				my_put_pixel(cube, i, y, 0x00FF00FF);
		}
	}
}