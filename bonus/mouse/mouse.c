/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:42:10 by orakib            #+#    #+#             */
/*   Updated: 2023/09/27 15:47:14 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	mouse_enable(t_cube *cube, mlx_key_data_t keydata)
{
	(void)keydata;
	mlx_set_cursor_mode(cube->mlx, MLX_MOUSE_HIDDEN);
	cube->state = MLX_MOUSE_HIDDEN;
}

void	mouse_disable(t_cube *cube, mlx_key_data_t keydata)
{
	(void)keydata;
	mlx_set_cursor_mode(cube->mlx, MLX_MOUSE_NORMAL);
	cube->state = MLX_MOUSE_NORMAL;
}

void	mouse_func(double xpos, double ypos, void *param)
{
	t_cube	*cube;

	cube = param;
	if (cube->state == MLX_MOUSE_NORMAL)
		return ;
	(void)ypos;
	if (xpos > W_WIDTH / 2 + 5)
		cube->pl.turndirection = 1;
	else if (xpos < W_WIDTH / 2 - 5)
		cube->pl.turndirection = -1;
	else
		cube->pl.turndirection = 0;
	mlx_set_mouse_pos(cube->mlx, W_WIDTH / 2, W_HEIGHT / 2);
}
