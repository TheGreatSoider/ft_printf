NAME	= libftprintf.a

CC	= gcc

CFLAGS = -Wall -Wextra -Werror -c

PATH_SRCS	= ./src/

SRCS = $(wildcard ./*.c)

OBJ	= $(SRCS:.c=.o)

BONUS = 

BONUS_OBJS = $(BONUS:.c=.o)

AR = ar rcs

all: $(NAME)

.c.o:		
		$(CC) $(CFLAGS) $< -o $(<:.c=.o)

$(NAME): $(OBJ)
		$(AR) $(NAME) $(OBJ)

clean:
		/bin/rm -rf $(OBJ)

fclean: clean
		/bin/rm -rf $(NAME)

re: fclean all

bonus: $(BONUS_OBJS)
		$(AR) $(NAME) $(BONUS_OBJS)

.PHONY: all clean fclean re bonus
