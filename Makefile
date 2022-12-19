# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: steh <steh@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/31 12:49:52 by steh              #+#    #+#              #
#    Updated: 2022/12/19 17:04:05 by steh             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

_RESET		= \033[0m
_BOLD		= \033[1m
_RED		= \033[0;31m
_GREEN		= \033[0;32m
_YEL		= \033[0;33m
_CYN		= \033[0;36m

CC				:= gcc
CFLAGS			:= -Wall -Werror -Wextra -g -fsanitize=address
SRC_DIR			:= src
OBJ_DIR			:= obj
HEAD_DIR		:= -Iinc
DEPENDS 		:= $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.d, $(SRC))
SRC				:= $(wildcard $(SRC_DIR)/*.c)
OBJ				:= $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))


# MLX				= -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

MLX				:= -lmlx -framework OpenGL -framework Appkit -lz
LIBMLX 			= libmlx.dylib
# LIBMLX			= libmlx.a
LIB				:= -L./libft -I./libft -lft
# LIBFT			:= libft.a
NAME			= cub3D
all				: $(NAME)
				 ./$(NAME) ./maps/minimalistic.cub
				@#  ./$(NAME) a.cuba

$(NAME)			: $(OBJ) #$(LIBFT)
					@make -s -C libft
					@$(CC) $(CFLAGS) $(LIB) $(LIBMLX) $^ -o $@
					# @$(CC) $(CFLAGS) $(LIB) $(MLX) $^ -o $@
					@echo "$(_GREEN) Project Compiled $(_RESET)"

-include $(DEPENDS)

$(OBJ_DIR)/%.o	: $(SRC_DIR)/%.c Makefile
					@mkdir -p $(dir $@)
					@$(CC) $(CFLAGS) $(HEAD_DIR) -Imlx -MMD -MP -c $< -o $@
					@echo "$(_GREEN) Compiling $(_YEL) $< $(_RESET)"

$(LIBFT)		:
					@make -s -C libft

norm			:
					@echo "$(_YEL) norminatte start $(_RESET)"
					norminette $(SRC_DIR)/*.c

clean			:
					@$(RM) $(OBJS)
					@$(RM) -r $(OBJ_DIR)
					@make -C minilibx clean
					@make -C libft clean
					@echo "$(_RED) removed obj files and obj directory $(_RESET)"

fclean			: clean
					@$(RM) $(NAME)
					@make fclean -C libft
					@echo "$(_RED) removed $(NAME) $(_RESET)"

re				: fclean all

.PHONY			: all clean fclean re
