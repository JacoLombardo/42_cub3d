# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/25 13:27:38 by jalombar          #+#    #+#              #
#    Updated: 2024/09/25 13:27:38 by jalombar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLAGS = -I -g -Wall -Werror -Wextra
LIBFT_FLAGS = -L$(LIBFT_PATH) -lft -g
MINILIBX_FLAGS	= -L$(MINILIBX_PATH) -lmlx -L/usr/lib -lXext -lX11 -lm -lz
SRCS = cub3d.c \
		source/cleanup/cleanup.c \
		source/cleanup/cleanup_utils.c \
		source/libx/draw.c \
		source/libx/events.c \
		source/libx/print.c \
		source/libx/libx.c \
		source/libx/screen.c \
		source/parsing/map_check.c \
		source/parsing/parser.c \
		source/parsing/parser_utils.c \
		source/rays/intersections.c \
		source/rays/raycast.c \
		source/rays/ray_utils.c \
		source/error.c \
		source/init.c \
		source/math.c \
		source/test.c \
		source/utils.c \
		
HEADER = cub3d.h
NAME = cub3d
LIBFT_PATH = libraries/libft
LIBFT = $(LIBFT_PATH)/libft.a
MINILIBX_PATH = libraries/minilibx
MINILIBX = $(MINILIBX_PATH)/libmlx.a

all: $(NAME)

$(NAME): $(SRCS) $(LIBFT) $(MINILIBX)
	@$(CC) $(FLAGS) -o $@ $(SRCS) $(LIBFT_FLAGS) $(MINILIBX_FLAGS)

$(LIBFT):
	@$(MAKE) -s -C $(LIBFT_PATH)

$(MINILIBX):
	@$(MAKE) -C $(MINILIBX_PATH)

clean:
	@$(MAKE) -s -C $(LIBFT_PATH) clean
	@$(MAKE) -C $(MINILIBX_PATH) clean

fclean: clean
	@$(MAKE) -s -C $(LIBFT_PATH) fclean
	rm -f $(NAME)

re: fclean all
