NAME := libft.a 
CC 	   := gcc
CFLAGS := -Wall -Werror -Wextra #-fsanitize=address
LIB_FILES = ft_isalpha.c\
				ft_isdigit.c\
				ft_isalnum.c\
				ft_isascii.c\
				ft_isprint.c\
				ft_strlen.c\
				ft_memset.c\
				ft_bzero.c\
				ft_memcpy.c\
				ft_memmove.c\
				ft_strlcpy.c\
				ft_strlcat.c\
				ft_toupper.c\
				ft_tolower.c\
				ft_strchr.c\
				ft_strrchr.c\
				ft_strncmp.c\
				ft_memchr.c\
				ft_memcmp.c\
				ft_strnstr.c\
				ft_atoi.c\
				ft_putchar.c\
				ft_calloc.c\
				ft_strdup.c\
				ft_substr.c\
				ft_strjoin.c\
				ft_strtrim.c\
				ft_split.c\
				ft_itoa.c\
				ft_strmapi.c\
				ft_striteri.c\
				ft_putchar_fd.c\
				ft_putstr_fd.c\
				ft_putendl_fd.c\
				ft_putnbr_fd.c\
				ft_lstnew.c\
				ft_lstadd_front.c\
				ft_lstsize.c\
				ft_lstlast.c\
				ft_lstadd_back.c\
				ft_lstdelone.c\
				ft_lstclear.c\
				ft_lstiter.c\
				ft_lstmap.c\
				ft_strcmp.c\
				ft_strstr.c\
				ft_strtok.c\
				get_next_line.c\
				get_next_line_utils.c\
				ft_strlen_cube3d.c\
				ft_realloc.c

OBJ_FILES	=	$(LIB_FILES:%.c=%.o)

all:  $(NAME)

$(NAME): $(OBJ_FILES)
	@ar rcs $(NAME) $(OBJ_FILES)
	@echo "$(_GREEN) $(NAME) created $(_RESET)"

clean:
	@echo "Cleaning..."
	@rm -rf $(OBJ_FILES)

fclean:
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re

# colors
_RESET		= \033[0m
_BOLD		= \033[1m
_RED		= \033[0;31m
_GREEN		= \033[0;32m
_YEL		= \033[0;33m
_CYN		= \033[0;36m
