/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 19:45:49 by orakib            #+#    #+#             */
/*   Updated: 2023/09/07 21:00:58 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	draw_circle(t_cube *cube)
{
	double	x1;
	double	y1;
	double	min_angle;
	double	angle;

	cube->player = mlx_new_image(cube->mlx, cube->pl.radius * 2,
			cube->pl.radius * 2);
	if (!cube->player)
		return (1);
	angle = 0;
	min_angle = acos(1 - (1 / cube->pl.radius));
	while (angle <= 360)
	{
		x1 = cube->pl.radius * cos(angle);
		y1 = cube->pl.radius * sin(angle);
		mlx_put_pixel(cube->player, cube->pl.radius + x1, cube->pl.radius + y1,
			0x20AA15FF);
		mlx_put_pixel(cube->player, cube->pl.radius, cube->pl.radius,
			0x000000FF);
		angle += min_angle;
	}
	return (0);
}
