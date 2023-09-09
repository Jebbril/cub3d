/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 19:45:49 by orakib            #+#    #+#             */
/*   Updated: 2023/09/09 17:35:11 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	draw_circle(mlx_t *mlx, mlx_image_t *img, float radius, t_pos pos)
{
	double	x1;
	double	y1;
	double	min_angle;
	double	angle;

	img = mlx_new_image(mlx, radius * 2, radius * 2);
	if (!img)
		return (1);
	angle = 0;
	min_angle = acos(1 - (1 / radius));
	while (angle <= 360)
	{
		x1 = radius * cos(angle);
		y1 = radius * sin(angle);
		mlx_put_pixel(img, radius + x1, radius + y1, 0x20AA15FF);
		mlx_put_pixel(img, radius, radius, 0x000000FF);
		angle += min_angle;
	}
	mlx_image_to_window(mlx, img, pos.x, pos.y);
	return (0);
}

int	draw_line(mlx_t *mlx, mlx_image_t *img, t_pos pos1, t_pos pos2)
{
	float	dx;
	float	dy;
	int		i;
	int		j;

	dx = fabsf(pos1.x - pos2.x);
	dy = fabsf(pos1.y - pos2.y);
	i = -1;
	img = mlx_new_image(mlx, dx, dy);
	if (!img)
		return (1);
	while (++i < dx)
	{
		j = dy * i / dx;
		mlx_put_pixel(img, i, j, 0xFFFFFFFF);
	}
	mlx_image_to_window(mlx, img, pos1.x + RADIUS, pos1.y + RADIUS);
	return (0);
}

mlx_image_t	*draw_rect(mlx_t *mlx, int width, int height, int color)
{
	mlx_image_t	*img;
	int			i;
	int			j;

	img = mlx_new_image(mlx, width, height);
	if (!img)
		return (NULL);
	i = -1;
	j = -1;
	while (++i < width)
	{
		while (++j < height)
		{
			mlx_put_pixel(img, i, j, color);
		}
		j = -1;
	}
	return (img);
}
