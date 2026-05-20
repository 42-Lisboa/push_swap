
SRC = \
$(SRC_FOLDER)/push_swap.c

OBJS = $(SRC:.c=.o)
NAME = push_swap.a
FLAGS = -Wall -Werror -Wextra -g
HEADER = ft_printf.h
LIB_AUX = libft
SRC_FOLDER = src


all: $(NAME)

$(NAME): $(OBJS)
		make -C $(LIB_AUX)
		cp $(LIB_AUX)/libft.a $(NAME)
		ar rcs $(NAME) $(OBJS)

%.o: %.c $(HEADER)
		cc -c $(FLAGS) $< -o $@

clean:
		make clean -C $(LIB_AUX)
		rm -f $(OBJS)

fclean: clean
		make fclean -C $(LIB_AUX)
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re