/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:32:26 by orakib            #+#    #+#             */
/*   Updated: 2023/09/07 20:36:47 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	raycasting(t_cube *cube)
{
	cube->mlx = mlx_init(W_WIDTH, W_HEIGHT, "Cub3d", false);
	if (!cube->mlx)
		return (1);
	if (draw_background(cube))
		return (1);
	cube->pl.radius = 10;
	cube->pl.x = 500;
	cube->pl.y = 500;
	draw_circle(cube);
	mlx_image_to_window(cube->mlx, cube->player, 100, 100);
	// mlx_loop_hook(cube->mlx, render(), cube);
	mlx_loop(cube->mlx);
	mlx_terminate(cube->mlx);
	return (0);
}
