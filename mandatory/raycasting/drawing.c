/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 19:45:49 by orakib            #+#    #+#             */
/*   Updated: 2023/09/10 17:13:17 by orakib           ###   ########.fr       */
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
	int		sx;
	int		sy;
	float	err;
	int		e2;
	float	ox;
	float	oy;

	ox = pos1.x;
	oy = pos1.y;
	dx = fabsf(pos2.x - pos1.x);
	dy = fabsf(pos2.y - pos1.y);
	sx = pos1.x < pos2.x ? 1 : -1;
	sy = pos1.y < pos2.x ? 1 : -1;
	err = (dx > dy ? dx : -dy) / 2;
	img = mlx_new_image(mlx, dx, dy);
	if (!img)
		return (1);
	
	while (1)
	{
		mlx_put_pixel(img, pos1.x, pos1.y, 0x20AA15FF);
		if ((int)pos1.x == (int)pos2.x && (int)pos1.y == (int)pos2.y)
			break;
		e2 = err;
		if (e2 > -dx)
		{
			err -= dy;
			pos1.x += sx;
		}
		if (e2 < dy)
		{
			err += dx;
			pos1.y += sy;
		}
	}
	if (ox < pos2.x)
	{
		if (oy < pos2.y)
			mlx_image_to_window(mlx, img, ox + RADIUS, oy + RADIUS);
		else
			mlx_image_to_window(mlx, img, ox + RADIUS, pos2.y + RADIUS);
	}
	else
	{
		if (oy < pos2.y)
			mlx_image_to_window(mlx, img, pos2.x + RADIUS, oy + RADIUS);
		else
			mlx_image_to_window(mlx, img, pos2.x + RADIUS, pos2.y + RADIUS);
	}
	// mlx_image_to_window(mlx, img, ox + RADIUS, oy + RADIUS);
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
