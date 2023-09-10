/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:32:26 by orakib            #+#    #+#             */
/*   Updated: 2023/09/10 18:08:53 by orakib           ###   ########.fr       */
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
}

void	rendering(void *param)
{
	t_cube	*cube;

	cube = param;
	printf("%d   %d   %d\n", cube->pl.walkdirection, cube->pl.starfdirection, cube->pl.turndirection);
	update(cube);
	render(cube);
}

int	raycasting(t_cube *cube)
{
	cube->mlx = mlx_init(W_WIDTH, W_HEIGHT, "Cub3d", false);
	if (!cube->mlx)
		return (1);
	if (draw_background(cube))
		return (1);
	initialize(cube);
	draw_minimap(cube);
	// t_pos p1,p2;
	// p1.x = 10;
	// p1.y = 10;
	// p2.x = 50;
	// p2.y = 50;
	// mlx_image_t *img = NULL;
	// draw_line(cube->mlx, img, p1, p2);
	mlx_key_hook(cube->mlx, key_func, cube);
	mlx_loop_hook(cube->mlx, rendering, cube);
	mlx_loop(cube->mlx);
	mlx_terminate(cube->mlx);
	return (0);
}
