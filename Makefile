# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcarrasq <hcarrasq@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/10 11:43:27 by hcarrasq          #+#    #+#              #
#    Updated: 2025/05/06 17:26:26 by hcarrasq         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS_FILES = so_long.c parsing.c flood_fill.c utils.c initialize_structs.c \
more_utils.c draw.c handle.c free3000.c initialize_structs2.c

SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_FILES))

SRCS_DIR = srcs

OBJS	= $(SRCS:.c=.o)

MLX = $(MLX_DIR)/libmlx.a
MLX_DIR = ./minilibx-linux

CFLAGS = -g -Wall -Wextra -Werror
MLX_FLAGS = -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz 
CC = @cc

all:	$(NAME)

$(NAME): $(OBJS) $(MLX)
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) $(OBJS) $(MLX) $(MLX_FLAGS) libft/libft.a -Llibft -lft -o $(NAME)

$(MLX):
	make -C $(MLX_DIR)

clean:
		@cd libft && make clean
		@rm -rf $(OBJS)

fclean:		clean
		@cd libft && make fclean
		@rm -rf $(NAME)

re:		fclean 	all

.PHONY : all clean fclean re