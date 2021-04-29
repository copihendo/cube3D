NAME = cub3D
CC = gcc
INCLUDES =  -I ./includes/ -I ./libft/ -I ./mlx/
LIBS_ADD =  -L ./mlx/ -L ./libft/ -lft -lmlx -framework OpenGL -framework AppKit
CFLAGS = -Wall -Wextra -Werror -O3 ${INCLUDES}
SRCS =  $(addprefix ./src/,\
                main.c lstadd_back_content.c mlx_init.c exit.c \
1_parse.c 2_read_file.c check_config.c 3_handle_line.c read_config.c read_map.c\
        )
OBJS = $(SRCS:.c=.o)
all: ${NAME}
debug:      CFLAGS  += -fsanitize=address -g
debug:      all
$(NAME) :${OBJS} | tools
		${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBS_ADD}
tools:
	make bonus -C ./libft/
	make -C ./mlx/
clean:
		rm -f ${OBJS}
fclean: clean
		rm -f ${NAME}
re: fclean all


# NAME = cub3D
# SRCDIR = ./src/
# # SRCDIR_B = ./src_bonus/
# MLXDIR = ./mlx/
# LIBFTDIR = ./tools/libft/
# INCLD_MLX = -I $(MLXDIR)
# INCLD_LIBFT = -I ./tools/libft/
# HEADER = ./includes/cube.h
# INCLD = -I ./includes

# CC = gcc
# CFLAGS = -Wall -Wextra -Werror $(INCLD) $(INCLD_LIBFT) $(INCLD_MLX) -O3 -MD

# FILES_CUB3D = main.c lstadd_back_content.c mlx_init.c exit.c \
# 1_parse.c 2_read_file.c check_config.c handle_line.c read_config.c read_map.c 

# # FILES_CUB3D = ft_cub_utils.c main.c ft_map_create.c ft_param_parser.c \
# # 			ft_parser_utils.c ft_drawing.c ft_drawing_utils.c ft_mlx.c		\
# # 			ft_control_plr.c ft_raycasting.c ft_sprites.c ft_screenshot.c
# # FILES_CUB3D_B = ft_cub_utils_bonus.c main_bonus.c ft_map_create_bonus.c \
# # 			ft_param_parser_bonus.c ft_parser_utils_bonus.c \
# # 			ft_drawing_bonus.c ft_drawing_utils_bonus.c ft_mlx_bonus.c		\
# # 			ft_control_plr_bonus.c ft_raycasting_bonus.c ft_sprites_bonus.c \
# # 			ft_screenshot_bonus.c

# SRC_CUB3D = $(addprefix $(SRCDIR), $(FILES_CUB3D))
# SRC_LIBFT = $(addprefix $(LIBFTDIR), )
# # SRC_CUB3D_B = $(addprefix $(SRCDIR_B), $(FILES_CUB3D_B))
# OBJS = $(SRC_CUB3D:.c=.o)
# # OBJS_B = $(SRC_CUB3D_B:.c=.o)
# D_FILES = $(SRC_CUB3D:.c=.d)
# # D_FILES_B = $(SRC_CUB3D_B:.c=.d)

# all: $(NAME)

# $(NAME): $(OBJS) | tools
# 		$(CC) $(CFLAGS) $(OBJS) -L$(LIBFTDIR) -L$(MLXDIR) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
# include $(wildcard $(D_FILES))

# # $(NAME): $(OBJS) | tools
# # 		$(CC) $(CFLAGS) -L$(LIBFTDIR) -lft $(OBJS) -L$(MLXDIR) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
# # include $(wildcard $(D_FILES))

# # bonus: fclean $(OBJS_B) | tools
# # 		$(CC) $(CFLAGS) -L$(LIBFTDIR) -lft $(OBJS_B) -L$(MLXDIR) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
# # include $(wildcard $(D_FILES_B))

# tools:
# 		make -C $(MLXDIR)
# 		make -C $(LIBFTDIR)
# clean:
# 		rm -f $(OBJS) $(D_FILES) ./Screenshot.bmp
# 		make -C $(MLXDIR) clean
# fclean: clean
# 		rm -f ${NAME}

# re: fclean all
