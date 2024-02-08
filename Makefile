NAME = so_long
LIBFTDIR = ./libft
CC = cc
CFLAGS = -Wall -Werror -Wextra -g3
MINILIBDIR = ./mlx_linux
LIBFTNAME = libft.a



SRCS= main.c utils.c get_next_line.c get_next_line_utils.c
# Remplacez .c par .o pour obtenir les noms des fichiers objets
OBJS = $(SRCS:.c=.o)

all: $(NAME)

makelibft:
	@make -C $(LIBFTDIR)
	@cp $(LIBFTDIR)/$(LIBFTNAME) .
	@mv $(LIBFTNAME) $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): makelibft $(OBJS)
	${MAKE} -C $(MINILIBDIR)
	$(CC) $(OBJS) $(MINILIBDIR)/libmlx.a -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean:
	@rm -f $(OBJS)
	@cd $(MINILIBDIR) && make clean
	@cd $(LIBFTDIR) && make clean


fclean: clean
	@rm -f $(NAME)
	@cd $(MINILIBDIR) && make fclean
	@cd $(LIBFTDIR) && make fclean


# compil: 
# 	$(CC) $(CFLAGS) -o pushswap_test $(SRCS) $(PRINTFDIR)/*.c $(LIBFTDIR)/*.c -I$(LIBFTDIR) -I$(PRINTFDIR)

re: fclean all compil

.PHONY: all clean fclean re compil