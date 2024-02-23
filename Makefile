NAME = so_long
NAME_BONUS = so_long_bonus

SRCS_FILE = main.c utils.c get_next_line.c get_next_line_utils.c maap.c generate_img.c movement.c check_map.c end_game.c key.c
SRCS_FILE_BONUS= main_bonus.c utils_bonus.c ../src/get_next_line.c ../src/get_next_line_utils.c map_bonus.c generate_img_bonus.c movement_bonus.c check_map_bonus.c end_game_bonus.c key_bonus.c check_utils_bonus.c utils_movement_bonus.c

MINILIBDIR = ./mlx_linux
CC = cc
MD = mkdir -p
CFLAGS = -Wall -Wextra -Werror -g
MLX_FLAGS = -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

DIR_SRC = src/
DIR_OBJ = .object/
DIR_OBJ_BONUS = .object_BONUS/
DIR_BONUS = bonus/
FT_PRINTF = ./lib/printf/libftprintf.a

OBJS = $(patsubst %.c, ${DIR_OBJ}%.o, ${SRCS})
SRCS = $(addprefix ${DIR_SRC},${SRCS_FILE})
OBJS_BONUS = $(patsubst %.c, ${DIR_OBJ_BONUS}%.o, ${SRCS_BONUS})
SRCS_BONUS = $(addprefix ${DIR_BONUS},${SRCS_FILE_BONUS})

RM = rm -Rf

all: ft_printf ${NAME}

bonus: ft_printf ${NAME_BONUS}

${NAME}: ${OBJS} ${FT_PRINTF}
	$(MAKE) -C $(MINILIBDIR)
	$(CC) $(OBJS) -L$(MINILIBDIR) ${MLX_FLAGS} $(MINILIBDIR)/libmlx.a $(FT_PRINTF) -o $(NAME)

$(NAME_BONUS): $(OBJS_BONUS) ${FT_PRINTF}
	$(MAKE) -C $(MINILIBDIR)
	$(CC) $(OBJS_BONUS) -L$(MINILIBDIR) ${MLX_FLAGS} $(MINILIBDIR)/libmlx.a $(FT_PRINTF) -o $(NAME_BONUS)

${DIR_OBJ}%.o: %.c ${DIR_SRC}/so_long.h ${DIR_SRC}/get_next_line.h Makefile
	mkdir -p $(shell dirname $@)
	$(CC) ${CFLAGS} -c $< -o $@

${DIR_OBJ_BONUS}%.o: %.c ${DIR_BONUS}/so_long_bonus.h ${DIR_SRC}/get_next_line.h Makefile
	mkdir -p $(shell dirname $@)
	$(CC) ${CFLAGS} -c $< -o $@

ft_printf: ${FT_PRINTF_DIR}
	${MAKE} -C ./lib/printf all

clean:
	${MAKE} -C ./lib/printf clean
	${RM} ${DIR_OBJ}

fclean: clean
	${MAKE} -C ./lib/printf fclean
	${RM} ${NAME}

re: fclean all

clean_bonus:
	rm -Rf $(DIR_OBJ_BONUS)
	${MAKE} -C ./lib/printf fclean

fclean_bonus: clean_bonus
	@rm -f $(NAME_BONUS) $(PRINTFNAME)
	${MAKE} -C ./lib/printf fclean

re_bonus : fclean_bonus bonus

.PHONY: all clean fclean re clean_bonus fclean_bonus re_bonus
