# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cocheong <cocheong@student.42kl.my>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/11 14:47:50 by cocheong          #+#    #+#              #
#    Updated: 2022/10/11 14:47:50 by cocheong         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

INCLUDES	= ./include

LIBFT	= Libft

LIBFT_PATH	= ./Libft

MAIN_DIR	= $(shell pwd)

CC	= gcc

CFLAGS = -Wall -Wextra -Werror -I

PATH_SRCS	= ./src/

SRCS = $(wildcard ./*.c)

OBJ	= $(SRCS:.c=.o)

AR = ar rcs

all: $(NAME)

.c.o:		
		$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $(<:.c=.o)

$(NAME): $(OBJ)
		@make -C $(LIBFT)
		@cp libft/libft.a $(MAIN_DIR)
		@mv libft.a $(NAME)
		$(AR) $(NAME) $(OBJ)

clean:
		make -C $(LIBFT_PATH) clean
		/bin/rm -rf $(OBJ)

fclean: clean
		make -C $(LIBFT_PATH) fclean
		/bin/rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
