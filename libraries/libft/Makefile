# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/17 13:48:12 by jalombar          #+#    #+#              #
#    Updated: 2024/11/14 13:43:47 by jalombar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc   
CFLAGS = -Wall -Werror -Wextra
SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_charjoin.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strcmp.c ft_strdup.c ft_strjoin.c ft_strjoinjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strndup.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tab_sort.c ft_tolower.c ft_toupper.c ft_split.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
OBJS = $(SRCS:.c=.o)
LL_SRCS = linked_list/ft_lstnew.c linked_list/ft_lstadd_front.c linked_list/ft_lstsize.c linked_list/ft_lstlast.c linked_list/ft_lstadd_back.c linked_list/ft_lstdelone.c linked_list/ft_lstclear.c linked_list/ft_lstiter.c linked_list/ft_lstmap.c
LL_OBJS = $(LL_SRCS:.c=.o)
PRINTF_SRCS = ft_printf/ft_printf.c ft_printf/ft_print_char.c ft_printf/ft_print_ptr.c ft_printf/ft_print_nbr.c
PRINTF_OBJS = $(PRINTF_SRCS:.c=.o)
GNL_SRCS = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
GNL_OBJS = $(GNL_SRCS:.c=.o)
HEADER = libft.h
NAME = libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LL_OBJS) $(PRINTF_OBJS) $(GNL_OBJS)
	ar -rcs $(NAME) $(OBJS) $(LL_OBJS) $(PRINTF_OBJS) $(GNL_OBJS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	rm -f $(OBJS)
	rm -f $(LL_OBJS)
	rm -f $(PRINTF_OBJS)
	rm -f $(GNL_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
