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
		source/cleanup.c \
		source/error.c \
		source/events.c \
		source/init.c \
		source/parser.c \
		source/parser_utils.c \
		source/test.c
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
	$(MAKE) -C $(MINILIBX_PATH)

clean:
	@$(MAKE) -s -C $(LIBFT_PATH) clean
	$(MAKE) -C $(MINILIBX_PATH) clean

fclean: clean
	@$(MAKE) -s -C $(LIBFT_PATH) fclean
	rm -f $(NAME)

re: fclean all
