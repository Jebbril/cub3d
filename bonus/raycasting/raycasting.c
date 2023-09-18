/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:32:26 by orakib            #+#    #+#             */
/*   Updated: 2023/09/18 18:13:35 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	key_func(mlx_key_data_t keydata, void *param)
{
	t_cube	*cube;

	cube = param;
	if (mlx_is_key_down(cube->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(cube->mlx);
	if (keydata.key == MLX_KEY_W)
		move_up(cube, keydata);
	else if (keydata.key == MLX_KEY_S)
		move_down(cube, keydata);
	else if (keydata.key == MLX_KEY_D)
		move_right(cube, keydata);
	else if (keydata.key == MLX_KEY_A)
		move_left(cube, keydata);
	else if (keydata.key == MLX_KEY_RIGHT)
		turn_right(cube, keydata);
	else if (keydata.key == MLX_KEY_LEFT)
		turn_left(cube, keydata);
	else if (keydata.key == MLX_KEY_F)
		mouse_enable(cube, keydata);
	else if (keydata.key == MLX_KEY_G)
		mouse_disable(cube, keydata);
}

void	rendering(void *param)
{
	t_cube	*cube;

	cube = param;
	update(cube);
	render(cube);
}

int	raycasting(t_cube *cube)
{
	cube->mlx = mlx_init(W_WIDTH, W_HEIGHT, "Cub3d", false);
	if (!cube->mlx)
		return (1);
	initialize(cube);
	if (load_pngs(cube))
		return (1);
	if (draw_background(cube))
		return (1);
	mlx_key_hook(cube->mlx, key_func, cube);
	mlx_cursor_hook(cube->mlx, mouse_func, cube);
	mlx_loop_hook(cube->mlx, rendering, cube);
	mlx_loop(cube->mlx);
	mlx_terminate(cube->mlx);
	return (0);
}
