/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:32:26 by orakib            #+#    #+#             */
/*   Updated: 2023/09/09 18:33:04 by orakib           ###   ########.fr       */
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
	initialize(cube);
	cube->pl.radius = RADIUS;
	cube->pl.pos.x = 500;
	cube->pl.pos.y = 500;
	t_pos ps;
	ps.x = 120;
	ps.y = 320;
	draw_minimap(cube);
	draw_circle(cube->mlx, cube->pl.player, cube->pl.radius, cube->pl.pos);
	draw_line(cube->mlx, cube->pl.line, cube->pl.pos, ps);
	// mlx_loop_hook(cube->mlx, render(), cube);
	mlx_loop(cube->mlx);
	mlx_terminate(cube->mlx);
	return (0);
}
