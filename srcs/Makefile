NAME=cub3D.a

CFLAGS=-Wall -Wextra -Werror -I.

OBJ_PATH = ./srcs/

CC = gcc

SRC_NAME=	$(addprefix srcs/,\
				$(addprefix parsing/,)
					check_config.c \
					handle_line.c \
					parse.c \
					read_config.c \
					read_file.c \
					screen_size.c \
				)\
				exit.c \
				main.c \
			)
OBJ_NAME = $(SRC_NAME:.c=.o)
#OBJ_BONUS = $(BONUS_NAME:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_NAME)
	@$(MAKE) all -C ./libft
	@$(MAKE) bonus -C ./libft
	@cp ./libft/libft.a $(NAME)
	ar rc ${NAME} ${OBJ_NAME}
	ranlib ${NAME}

# bonus: all $(OBJ_BONUS)
# 	ar rc ${NAME} ${OBJ_BONUS}
# 	ranlib ${NAME}


clean:
	rm -f $(OBJ_NAME)
	# rm -f $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all