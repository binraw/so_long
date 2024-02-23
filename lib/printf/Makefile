
NAME = libftprintf.a
LIBFTNAME = libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra 
LIBFTDIR = ../libft

SRCS =  ft_printf.c \
                ft_printf_hexa.c \
                ft_printf_num.c \
                ft_printf_str.c \
				ft_printf_char.c \
				ft_printf_putmem.c 

OBJS = $(SRCS:.c=.o)

all: $(NAME)

makelibft:
	@make -C $(LIBFTDIR)
	@cp $(LIBFTDIR)/$(LIBFTNAME) .
	@mv $(LIBFTNAME) $(NAME)

$(NAME): makelibft  $(OBJS)
	@ar -r $(NAME) $(OBJS)

clean:
	@rm -f $(OBJS)
	@cd $(LIBFTDIR) && make clean

fclean: clean
	@rm -f $(NAME)
	@cd $(LIBFTDIR) && make fclean



re: fclean all 

.PHONY:                         all bonus clean fclean re 
