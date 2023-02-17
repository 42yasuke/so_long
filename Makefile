# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jralph <jralph@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/14 17:43:43 by jose              #+#    #+#              #
#    Updated: 2023/02/17 14:55:48 by jralph           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

CFLAGS_OBJ = -Wall -Wextra -Werror -c

RM = rm -f

C_FILES =	main.c \
			error.c

SRC = $(addprefix src/, $(C_FILES))

OBJ = $(SRC:.c=.o)

INC = -I includes/

LIB = -L. -lft

MLBX = libmlx.a -Iinclude -ldl -lglfw -pthread -lm -lmlx -lXext -lX11

NAME = so_long

all : $(NAME)

libft.a :
			make bonus -C libft
			
libmlx.a :
			make -C mlx42

%.o : %.c
			$(CC) $(CFLAGS_OBJ) $< -o $@ $(LIB) $(MLBX) $(INC)

$(NAME) : libft.a libmlx.a $(OBJ)
			$(CC) $(CFLAGS) $(OBJ) -o $@ $(LIB) $(MLBX)

clean :
		make clean -C libft
		make clean -C mlx42
		$(RM) src/*.o

fclean : clean
		$(RM) $(NAME) libft.a libmlx.a

re : fclean all

.PHONY : all fclean clean re bonus