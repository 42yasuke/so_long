# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jralph <jralph@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/14 17:43:43 by jose              #+#    #+#              #
#    Updated: 2023/04/04 04:07:49 by jralph           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

CFLAGS_OBJ = -Wall -Wextra -Werror -c

RM = rm -f

C_FILES =	main.c \
			error.c \
			events.c \
			events_utils.c \
			events_utils2.c \
			events_utils3.c \
			utils.c \
			free.c \
			maps.c \
			maps_utils.c \
			maps_utils2.c \
			maps_utils3.c \
			image.c \
			image_utils.c \
			enemy.c \
			enemy_utils.c

C_FILES_BONUS =	main_bonus.c \
				error_bonus.c \
				events_bonus.c \
				events_utils_bonus.c \
				events_utils2_bonus.c \
				events_utils3_bonus.c \
				utils_bonus.c \
				free_bonus.c \
				maps_bonus.c \
				maps_utils_bonus.c \
				maps_utils2_bonus.c \
				maps_utils3_bonus.c \
				image_bonus.c \
				image_utils_bonus.c \
				enemy_bonus.c \
				enemy_utils_bonus.c

SRC = $(addprefix src/, $(C_FILES))

BONUS = $(addprefix bonus/, $(C_FILES_BONUS))

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(BONUS:.c=.o)

INC = -I includes/

LIB = -L. -lft

MLBX = libmlx.a -Iinclude -ldl -lglfw -pthread -lm -lmlx -lXext -lX11

NAME = so_long

SLB = so_long_bonus

all : $(NAME)

libft.a :
			make bonus -C libft
			
libmlx.a :
			make -C mlx42

%.o : %.c
			$(CC) $(CFLAGS_OBJ) $< -o $@ $(LIB) $(MLBX) $(INC)

$(NAME) : libft.a libmlx.a $(OBJ)
				$(CC) $(CFLAGS) $(OBJ) -o $@ $(LIB) $(MLBX)

bonus : $(SLB)

so_long_bonus : libft.a libmlx.a $(OBJ_BONUS)
			$(CC) $(CFLAGS) $(OBJ_BONUS) -o $@ $(LIB) $(MLBX)
clean :
		make clean -C libft
		make clean -C mlx42
		$(RM) src/*.o
		$(RM) bonus/*.o

fclean : clean
		$(RM) $(NAME) $(SLB) libft.a libmlx.a

re : fclean all

.PHONY : all fclean clean re bonus