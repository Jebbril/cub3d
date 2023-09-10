/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 14:41:03 by orakib            #+#    #+#             */
/*   Updated: 2023/09/10 18:01:04 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <math.h>
# include <stdlib.h>
# include "../gnl/get_next_line.h"
# include "../MLX42/include/MLX42/MLX42.h"

# define W_WIDTH 1920
# define W_HEIGHT 1080
# define TILE_SIZE 32
# define FOV 60
# define RADIUS 5
# define NUM_RAYS W_WIDTH

typedef struct s_pos
{
	float	x;
	float	y;
}	t_pos;

typedef struct s_pasring
{
	char		*mapstr;
	char		**map;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*f;
	char		*c;
	int			f_red;
	int			f_green;
	int			f_blue;
	int			c_red;
	int			c_green;
	int			c_blue;
}	t_parsing;

typedef struct s_player
{
	t_pos		pos;
	float		radius;
	int			turndirection;
	int			walkdirection;
	int			starfdirection;
	float		rotationangle;
	float		walkspeed;
	float		turnspeed;
	mlx_image_t	*player;
	mlx_image_t	*line;
}	t_player;

typedef struct s_ray
{
	float		rayangle;
	float		wallhitx;
	float		wallhity;
	float		distance;
	int			washitvertical;
	int			israyfacingup;
	int			israyfacingdown;
	int			israyfacingleft;
	int			israyfacingright;
	int			wallhitcontent;
}	t_ray;

typedef struct s_cube
{
	mlx_t		*mlx;
	mlx_image_t	*background;
	mlx_image_t	*wall;
	mlx_image_t	*floor;
	t_parsing	p;
	t_player	pl;
	t_ray		rays[NUM_RAYS];
}	t_cube;

// parsing
void		parsing(int ac, char **av, t_cube *cube);
int			check_ext(char *str, char *ext);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_strlen(char *s);
int			ft_isdigit(int c);
int			ft_atoi(const char *str);
char		*ft_substr(char *s, unsigned int start, size_t len);
char		**ft_split(char *s, char c);
void		free_matrix(char **matrice);
void		garbage(t_cube *cube);
void		get_info(t_cube *cube);
void		get_map(t_cube *cube);
void		parse_map(t_cube *cube);
void		parse_info(t_cube *cube);

// raycating
int			raycasting(t_cube *cube);
int			draw_background(t_cube *cube);
int			draw_circle(mlx_t *mlx, mlx_image_t *img, float radius, t_pos pos);
int			draw_line(mlx_t *mlx, mlx_image_t *img, t_pos pos1, t_pos pos2);
mlx_image_t	*draw_rect(mlx_t *mlx, int width, int height, int color);
int			draw_minimap(t_cube *cube);
void		initialize(t_cube *cube);
void		move_up(t_cube *cube, mlx_key_data_t keydata);
void		move_down(t_cube *cube, mlx_key_data_t keydata);
void		move_right(t_cube *cube, mlx_key_data_t keydata);
void		move_left(t_cube *cube, mlx_key_data_t keydata);
void		turn_right(t_cube *cube, mlx_key_data_t keydata);
void		turn_left(t_cube *cube, mlx_key_data_t keydata);
void		update(t_cube *cube);
void		render(t_cube *cube);

// utils
int			has_wall(t_cube *cube, float x, float y);
#endif