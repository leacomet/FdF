# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acomet <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/03 16:30:18 by acomet            #+#    #+#              #
#    Updated: 2023/04/21 15:03:37 by acomet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fdf
NAME_BONUS	=	fdf_bonus

MLX			=	minilibx-linux/libmlx_Linux.a
LIBFT		=	libft/libft.a
PRINTFERR	=	ft_printferr/libftprintferr.a

CC			=	clang

CFLAGS		=	-Wall -Wextra -Werror -g
LDFLAGS		=	-L $(dir $(MLX)) -L $(dir $(LIBFT)) -L $(dir $(PRINTFERR))
CPPFLAGS	=	-I minilibx-linux -I libft -I . -O3 -I ft_printferr
LDLIBS		=	-l:libmlx_Linux.a -lmlx -lXext -lX11 -l:libft.a -lm -l:libftprintferr.a

SRCS		= 	fdf.c \
				gnl/get_next_line.c gnl/get_next_line_utils.c \
				axis_ordin_count.c \
				dots_str.c dots_int.c \
				libft_modified.c \
				draw_map.c \
				draw_str.c \
				fdf_pixel_put.c \
				check_imput.c \
				fill_coor.c \
				point_on_map.c \
				free.c

SRCS_BONUS	=	bonus/fdf_bns.c \
				gnl/get_next_line.c gnl/get_next_line_utils.c \
				axis_ordin_count.c \
				dots_str.c dots_int.c \
				libft_modified.c \
				bonus/draw_map_bns.c \
				draw_str.c \
				fdf_pixel_put.c \
				bonus/check_imput_bns.c \
				fill_coor.c \
				point_on_map.c \
				free.c \
				bonus/free_bns.c \
				bonus/fdf_rotations.c bonus/fill_rotations_values.c \
				bonus/translations.c \
				bonus/mirror.c

OBJS 		= 	$(SRCS:.c=.o)

OBJS_BONUS	=	$(SRCS_BONUS:.c=.o)

all: $(NAME)
.PHONY: all

.c.o:
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS) $(MLX) $(LIBFT) $(PRINTFERR)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) $(LDLIBS) -o $(NAME)

$(MLX):
	$(MAKE) -C $(dir $(MLX))

$(LIBFT):
	$(MAKE) -C $(dir $(LIBFT))

$(PRINTFERR):
	$(MAKE) -C $(dir $(PRINTFERR))

bonus: $(NAME_BONUS)
.PHONY: bonus

$(NAME_BONUS): $(OBJS_BONUS) $(MLX) $(LIBFT)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS_BONUS) $(LDLIBS) -o $(NAME_BONUS)

clean:
	rm -f $(OBJS) $(OBJS_BONUS)
	$(MAKE) -C ./ft_printferr clean
	$(MAKE) -C ./libft clean
	$(MAKE) -C ./minilibx-linux clean
.PHONY: clean

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	$(MAKE) -C ./libft fclean
	$(MAKE) -C ./ft_printferr fclean
.PHONY: fclean

run: all
	./$(NAME) 42.fdf

run2: all
	valgrind ./$(NAME) 42.fdf

re: fclean all
.PHONY: re

rebonus: fclean bonus
.PHONY: rebonus
