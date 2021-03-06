# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/02 10:00:00 by kcosta            #+#    #+#              #
#    Updated: 2017/05/15 15:12:55 by kcosta           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# =========== Colors =========== #
CLEAR			:= "\033[2K"
UP				:= "\033[A"
EOC				:= "\033[0;0m"
BLACK			:= "\033[0;30m"
RED				:= "\033[0;31m"
GREEN			:= "\033[0;32m"
YELLOW			:= "\033[0;33m"
BLUE			:= "\033[0;34m"
PURPLE			:= "\033[0;35m"
CYAN			:= "\033[0;36m"
WHITE			:= "\033[0;37m"
# ============================== #

# ========== Editable ========== #
NAME			:= fdf
# ============================== #

# ========== Standard ========== #
CC				:= gcc
FLAGS			:= -Wall -Wextra -Werror -O3#-fsanitize=address
# ============================== #

# =========== Files ============ #
SRCS_FILES		:=	ft_math.c		\
					color_0.c		\
					color_1.c		\
					vector2_0.c		\
					vector2_1.c		\
					vector2_2.c		\
					vector3_0.c		\
					vector3_1.c		\
					vector3_2.c		\
					vector3_3.c		\
					vector3_4.c		\
					matrix_0.c		\
					matrix_1.c		\
					matrix_2.c		\
					matrix_3.c		\
					matrix_4.c		\
					camera.c		\
					mesh.c			\
					render_0.c		\
					render_1.c		\
					render_2.c		\
					fdf_parser.c	\
					fdf_utils.c		\
					fdf_mesh.c		\
					fdf.c
HEADERS_FILES	:=	ft_math.h		\
					color.h			\
					vector2.h		\
					vector3.h		\
					matrix.h		\
					camera.h		\
					mesh.h			\
					render.h		\
					fdf.h
# ============================== #

# ========== Sources =========== #
SRCS_PATH		:= srcs/
SRCS			:= $(addprefix $(SRCS_PATH), $(SRCS_FILES))
# ============================== #

# ========== Objects =========== #
OBJS_PATH		:= objs/
OBJS			:= $(addprefix $(OBJS_PATH), $(SRCS_FILES:.c=.o))
# ============================== #

# ========== Includes ========== #
INCLUDES_PATH	:= includes/
INCLUDES		:= -I $(INCLUDES_PATH)
HEADERS			:= $(addprefix $(INCLUDES_PATH), $(HEADERS_FILES))
# ============================== #

# ========== Libraries ========= #
LIBFT_PATH		:= libft/
LIBFT_INCLUDES	:= -I libft/includes
LIBFT			:= -L $(LIBFT_PATH) -lft
MLX_PATH		:= minilibx/
MLX_INCLUDES	:= -I minilibx/
MLX				:= -L $(MLX_PATH) -lmlx -framework OpenGL -framework AppKit
MATH			:= -lm
# ============================== #

.PHONY: all libft mlx clean fclean re

all: libft mlx $(NAME)

mlx:
	@make -C $(MLX_PATH)

libft:
	@make -C $(LIBFT_PATH)

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c $(HEADERS) $(LIBFT_PATH)/libft.a
	@mkdir $(OBJS_PATH) 2> /dev/null || true
	$(CC) $(FLAGS) $(INCLUDES) $(LIBFT_INCLUDES) $(MLX_INCLUDES) -o $@ -c $<

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(LIBFT) $(MLX) $(MATH) $(OBJS) -o $@

clean:
	@make -C $(MLX_PATH) clean
	@make -C $(LIBFT_PATH) clean
	@rm -fv $(OBJS)
	@rmdir $(OBJS_PATH) 2> /dev/null || true

fclean: clean
	@make -C $(LIBFT_PATH) fclean
	@rm -fv $(NAME)

re: fclean all
