
NAME = so_long
LIBFTDIR = ./../printf/libft
CC = cc
CFLAGS = -Wall -Werror -Wextra -g3
MINILIBDIR = ./../mlx_linux
PRINTFNAME = ../lib/printf/libftprintf.a
PRINTFDIR = ./../lib/printf



SRCS= main_bonus.c utils_bonus.c ../lib/get_next_line.c ../lib/get_next_line_utils.c map_bonus.c generate_img_bonus.c movement_bonus.c check_map_bonus.c end_game_bonus.c key_bonus.c check_utils_bonus.c utils_movement_bonus.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

makelibft:
	@make -C $(PRINTFDIR)
	@cp $(PRINTFNAME) $(NAME)
	

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@


	
$(NAME): makelibft $(OBJS)
	$(MAKE) -C $(MINILIBDIR)
	$(CC) $(OBJS) $(MINILIBDIR)/libmlx.a $(PRINTFNAME) -L$(MINILIBDIR) -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME) -pthread

clean:
	@rm -f $(OBJS)
	# @cd $(MINILIBDIR) && make clean
	@cd $(PRINTFDIR) && make clean


fclean: clean
	@rm -f $(NAME) $(PRINTFNAME)
	# @cd $(MINILIBDIR) && make fclean
	@cd $(PRINTFDIR) && make fclean


re: fclean all 

.PHONY: all clean fclean re 
