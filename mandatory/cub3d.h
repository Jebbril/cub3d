/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 14:41:03 by orakib            #+#    #+#             */
/*   Updated: 2023/09/07 20:04:50 by orakib           ###   ########.fr       */
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
# define NUM_RAYS W_WIDTH

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
	float		x;
	float		y;
	float		radius;
	int			turndirection;
	int			walkdirection;
	float		rotationangle;
	float		walkspeed;
	float		turnspeed;
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
	mlx_image_t	*player;
	t_parsing	p;
	t_player	pl;
	t_ray		rays[NUM_RAYS];
}	t_cube;

// parsing
void	parsing(int ac, char **av, t_cube *cube);
int		check_ext(char *str, char *ext);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strlen(char *s);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	**ft_split(char *s, char c);
void	free_matrix(char **matrice);
void	garbage(t_cube *cube);
void	get_info(t_cube *cube);
void	get_map(t_cube *cube);
void	parse_map(t_cube *cube);
void	parse_info(t_cube *cube);

// raycating
int		raycasting(t_cube *cube);
int		draw_background(t_cube *cube);
int		draw_circle(t_cube *cube);

#endif