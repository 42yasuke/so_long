# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jose <jose@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/14 17:43:43 by jose              #+#    #+#              #
#    Updated: 2023/02/14 18:50:53 by jose             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

CFLAGS_OBJ = -Wall -Wextra -Werror -c

RM = rm -f

C_FILES =	main.c

SRC = $(addprefix src/, $(C_FILES))

OBJ = $(SRC:.c=.o)

INC = -I includes/

LIB = -L. -lft

NAME = so_long

all : $(NAME)

libft.a :
			make bonus -C libft

%.o : %.c
			$(CC) $(CFLAGS_OBJ) -Imlx_linux -O3 $< -o $@ $(LIB) $(INC)

$(NAME) : libft.a $(OBJ)
			$(CC) $(CFLAGS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz $(OBJ) -o $@ $(LIB)

clean :
		make clean -C libft
		$(RM) src/*.o

fclean : clean
		$(RM) $(NAME) libft.a

re : fclean all

.PHONY : all fclean clean re bonus