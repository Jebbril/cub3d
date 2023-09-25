/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 14:41:03 by orakib            #+#    #+#             */
/*   Updated: 2023/09/25 20:56:54 by orakib           ###   ########.fr       */
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
# include <limits.h>
# include <stdlib.h>
# include "../gnl/get_next_line.h"
# include "../MLX42/include/MLX42/MLX42.h"

# define TRUE 1
# define FALSE 0
# define W_WIDTH 1920
# define W_HEIGHT 1080
# define TILE_SIZE 16
# define FOV 60
# define RADIUS 3
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

typedef struct s_cast
{
	float	xintercept;
	float	yintercept;
	float	xstep;
	float	ystep;
	int		foundhwallhit;
	float	hwallhitx;
	float	hwallhity;
	float	nexthtouchx;
	float	nexthtouchy;
	float	foundvwallhit;
	float	vwallhitx;
	float	vwallhity;
	float	nextvtouchx;
	float	nextvtouchy;
	float	hhitdist;
	float	vhitdist;
}	t_cast;

typedef struct s_walls
{
	float	correct_dist;
	float	dist_projplane;
	float	projwall_height;
	int		wallstrip_height;
	int		walltop_pixel;
	int		wallbottom_pixel;
	int		top_diff;
	int		bot_diff;
	int		y;
	int		i;
}	t_walls;

typedef struct s_mini
{
	int	i;
	int	j;
	int	izero;
	int	jzero;
}	t_mini;

typedef struct s_cube
{
	mlx_t			*mlx;
	mlx_image_t		*background;
	mlx_image_t		*img;
	t_parsing		p;
	t_player		pl;
	t_ray			rays[NUM_RAYS];
	float			fov;
	int				rows;
	int				*cols;
	int				max_cols;
	mlx_texture_t	*no;
	mlx_texture_t	*so;
	mlx_texture_t	*ea;
	mlx_texture_t	*we;
	int				**no_tab;
	int				**so_tab;
	int				**we_tab;
	int				**ea_tab;
	mouse_mode_t	state;
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
void		free_matrix2(int **matrice);
void		garbage(t_cube *cube);
void		get_info(t_cube *cube);
void		get_map(t_cube *cube);
void		parse_map(t_cube *cube);
void		parse_info(t_cube *cube);

// raycating
int			raycasting(t_cube *cube);
int			draw_background(t_cube *cube);
void		draw_disc(t_cube *cube, int color, float radius);
void		draw_line(t_cube *cube, int color, t_pos p0, t_pos p1);
void		draw_minirect(t_cube *cube, float x, float y, int color);
void		draw_minimap(t_cube *cube);
void		cast_rays(t_cube *cube);
void		initialize(t_cube *cube);
void		move_up(t_cube *cube, mlx_key_data_t keydata);
void		move_down(t_cube *cube, mlx_key_data_t keydata);
void		move_right(t_cube *cube, mlx_key_data_t keydata);
void		move_left(t_cube *cube, mlx_key_data_t keydata);
void		turn_right(t_cube *cube, mlx_key_data_t keydata);
void		turn_left(t_cube *cube, mlx_key_data_t keydata);
void		update(t_cube *cube);
void		render(t_cube *cube);
void		init_ray(t_cube *cube, int i, float rayangle);
void		choose_dist(t_cube *cube, t_cast *v, int i);
void		render_rays(t_cube *cube);
void		render_walls(t_cube *cube);

// textures
int			load_pngs(t_cube *cube);
uint32_t	get_textpixel(t_cube *cube, t_walls *v, int side);
uint32_t	get_textpixel_no(t_cube *cube, t_walls *v);
uint32_t	get_textpixel_so(t_cube *cube, t_walls *v);
uint32_t	get_textpixel_ea(t_cube *cube, t_walls *v);
uint32_t	get_textpixel_we(t_cube *cube, t_walls *v);

// mouse
void		mouse_func(double xpos, double ypos, void *param);
void		mouse_enable(t_cube *cube, mlx_key_data_t keydata);
void		mouse_disable(t_cube *cube, mlx_key_data_t keydata);

// utils
int			has_wall(t_cube *cube, float x, float y);
int			has_wall2(t_cube *cube, float x, float y, t_pos p);
float		normalize_angle(float angle);
float		distancexy(float x1, float y1, float x2, float y2);
void		my_put_pixel(t_cube *cube, float x, float y, uint32_t color);
#endif