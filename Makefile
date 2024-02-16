
NAME = so_long
LIBFTDIR = ./printf/libft
CC = cc
CFLAGS = -Wall -Werror -Wextra -g3
MINILIBDIR = ./mlx_linux
PRINTFNAME = printf/libftprintf.a
PRINTFDIR = ./printf



SRCS= main.c utils.c get_next_line.c get_next_line_utils.c maap.c generate_img.c movement.c check_map.c
# Remplacez .c par .o pour obtenir les noms des fichiers objets
OBJS = $(SRCS:.c=.o)

all: $(NAME)

makelibft:
	@make -C $(PRINTFDIR)
	@cp $(PRINTFNAME) $(NAME)
	

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

# $(NAME): makelibft $(OBJS)
# 	${MAKE} -C $(MINILIBDIR)
# 	$(CC) $(OBJS) $(MINILIBDIR)/libmlx.a -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
	
$(NAME): makelibft $(OBJS)
	$(MAKE) -C $(MINILIBDIR)
	$(CC) $(OBJS) $(MINILIBDIR)/libmlx.a $(PRINTFNAME) -L$(MINILIBDIR) -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean:
	@rm -f $(OBJS)
	@cd $(MINILIBDIR) && make clean
	@cd $(PRINTFDIR) && make clean


fclean: clean
	@rm -f $(NAME) $(PRINTFNAME)
	@cd $(MINILIBDIR) && make fclean
	@cd $(PRINTFDIR) && make fclean




re: fclean all 

.PHONY: all clean fclean re 