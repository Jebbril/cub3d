/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 17:52:04 by orakib            #+#    #+#             */
/*   Updated: 2023/09/11 20:01:54 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move_right(t_cube *cube, mlx_key_data_t keydata)
{
	if (keydata.action == MLX_PRESS)
		cube->pl.starfdirection = -1;
	else if (keydata.action == MLX_RELEASE)
		cube->pl.starfdirection = 0;
}

void	move_left(t_cube *cube, mlx_key_data_t keydata)
{
	if (keydata.action == MLX_PRESS)
		cube->pl.starfdirection = 1;
	else if (keydata.action == MLX_RELEASE)
		cube->pl.starfdirection = 0;
}
