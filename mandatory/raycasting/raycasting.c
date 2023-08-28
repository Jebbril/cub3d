/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:32:26 by orakib            #+#    #+#             */
/*   Updated: 2023/08/28 18:13:03 by orakib           ###   ########.fr       */
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
	if (draw_minimap(cube))
		return (1);
	mlx_loop(cube->mlx);
	mlx_terminate(cube->mlx);
	return (0);
}
