# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: orakib <orakib@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/10 13:55:07 by orakib            #+#    #+#              #
#    Updated: 2023/08/11 18:39:33 by orakib           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#this line is used to compile with MLX42 library but you still need to install some stuff using brew (glfw/CMake)
#https://github.com/codam-coding-college/MLX42
#MLX/libmlx42.a -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"

NAME = cub3d

SRC = mandatory/main.c mandatory/parsing.c mandatory/parsing_utils.c gnl/get_next_line.c \
		gnl/get_next_line_utils.c mandatory/ft_split.c mandatory/garbage.c mandatory/get_info.c

BNS_SRC = 

HEADER = cub3d.h

BNS_HEADER = 

CC = cc

CFLAGS = -Wall -Werror -Wextra

OBJ = $(SRC:.c=.o)

BNS_OBJ = $(BNS_SRC:.c=.o)

all: $(NAME)

bonus: $(BONUS)

$(BONUS): $(BNS_OBJ)
	$(CC) $(CFLAGS) -o $(BONUS) $(BNS_OBJ)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

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