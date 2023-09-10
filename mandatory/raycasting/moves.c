/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 11:42:46 by orakib            #+#    #+#             */
/*   Updated: 2023/09/10 13:03:33 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move_up(t_cube *cube, mlx_key_data_t keydata)
{
	if (keydata.action == MLX_PRESS)
		cube->pl.walkdirection = 1;
	else if (keydata.action == MLX_RELEASE)
		cube->pl.walkdirection = 0;
}

void	move_down(t_cube *cube, mlx_key_data_t keydata)
{
	if (keydata.action == MLX_PRESS)
		cube->pl.walkdirection = -1;
	else if (keydata.action == MLX_RELEASE)
		cube->pl.walkdirection = 0;
}

void	turn_right(t_cube *cube, mlx_key_data_t keydata)
{
	if (keydata.action == MLX_PRESS)
		cube->pl.turndirection = 1;
	else if (keydata.action == MLX_RELEASE)
		cube->pl.turndirection = 0;
}

void	turn_left(t_cube *cube, mlx_key_data_t keydata)
{
	if (keydata.action == MLX_PRESS)
		cube->pl.turndirection = -1;
	else if (keydata.action == MLX_RELEASE)
		cube->pl.turndirection = 0;
}
