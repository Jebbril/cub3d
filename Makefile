# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: orakib <orakib@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/10 13:55:07 by orakib            #+#    #+#              #
#    Updated: 2023/09/28 16:27:50 by orakib           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#this line is used to compile with MLX42 library but you still need to install some stuff using brew (glfw/CMake)
#https://github.com/codam-coding-college/MLX42
#MLX/libmlx42.a -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"

NAME = cub3d

BONUS = cub3d_bonus

SRC = mandatory/main.c mandatory/parsing/parsing.c mandatory/parsing/parsing_utils.c gnl/get_next_line.c \
		gnl/get_next_line_utils.c mandatory/parsing/ft_split.c mandatory/garbage.c mandatory/parsing/get_info.c \
		mandatory/parsing/get_map.c mandatory/parsing/parse_map.c mandatory/parsing/parse_info.c \
		mandatory/parsing/ft_atoi.c mandatory/parsing/ft_isdigit.c \
		mandatory/raycasting/raycasting.c mandatory/raycasting/background.c mandatory/raycasting/drawing.c \
		mandatory/raycasting/minimap.c mandatory/raycasting/initialize.c mandatory/raycasting/utils.c \
		mandatory/raycasting/moves.c mandatory/raycasting/update.c mandatory/raycasting/moves2.c \
		mandatory/raycasting/cast_rays.c mandatory/raycasting/cast_rays2.c mandatory/raycasting/render_walls.c \
		mandatory/textures/textures.c mandatory/textures/textures2.c mandatory/parsing/parse_map2.c


BNS_SRC = bonus/main.c bonus/parsing/parsing.c bonus/parsing/parsing_utils.c gnl/get_next_line.c \
		gnl/get_next_line_utils.c bonus/parsing/ft_split.c bonus/garbage.c bonus/parsing/get_info.c \
		bonus/parsing/get_map.c bonus/parsing/parse_map.c bonus/parsing/parse_info.c \
		bonus/parsing/ft_atoi.c bonus/parsing/ft_isdigit.c \
		bonus/raycasting/raycasting.c bonus/raycasting/background.c bonus/raycasting/drawing.c \
		bonus/raycasting/minimap.c bonus/raycasting/initialize.c bonus/raycasting/utils.c \
		bonus/raycasting/moves.c bonus/raycasting/update.c bonus/raycasting/moves2.c \
		bonus/raycasting/cast_rays.c bonus/raycasting/cast_rays2.c bonus/raycasting/render_walls.c \
		bonus/textures/textures.c bonus/mouse/mouse.c bonus/textures/textures2.c bonus/parsing/parse_map2.c

HEADER = mandatory/cub3d.h

BNS_HEADER = bonus/cub3d.h

CC = cc

CFLAGS = -Wall -Werror -Wextra -Ofast #-g -fsanitize=address

OBJ = $(SRC:.c=.o)

BNS_OBJ = $(BNS_SRC:.c=.o)

all: $(NAME)

bonus: $(BONUS)

$(BONUS): $(BNS_OBJ)
	$(CC) $(CFLAGS) -o $(BONUS) $(BNS_OBJ) MLX42/build/libmlx42.a -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) MLX42/build/libmlx42.a -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"

mandatory/%.o: mandatory/%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

bonus/%.o: bonus/%.c $(BNS_HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ) $(BNS_OBJ)

fclean: clean
	rm -rf $(NAME) $(BONUS)

re: fclean all

.PHONY: all clean fclean re bonus