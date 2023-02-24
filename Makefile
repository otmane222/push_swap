NAME = push_swap

NAME_BNS = checker

SRCS	= errors.c \
		free.c \
		helpful_functions.c \
		instructions.c \
		instructions1.c \
		node_utils.c \
		node_utils1.c \
		node_utils2.c \
		node_utils3.c \
		node_utils4.c \
		node_utils5.c \
		push_swap.c \

SRCS_BNS	= utils_bonus.c \
			utils1_bonus.c \
			utils2_bonus.c \
			utils3_bonus.c \
			utils4_bonus.c \
			utils5_bonus.c \
			checker_bonus.c \
			get_next_line_bonus.c \
			get_next_line_utils_bonus.c \

OBJS = $(SRCS:%.c=%.o)

OBJS_BNS = $(SRCS_BNS:%.c=%.o)

INCL = push_swap.h libft/libft.h get_next_line.h

FLAGS = -Werror -Wextra -Wall

all: $(NAME)

%.o	: %.c $(INCL)
	cc -c $(FLAGS) $<

$(NAME): $(OBJS)
	@make -C libft
	cc -o $(NAME) ${OBJS} libft/libft.a 

%_bonus.o: %_bonus.c $(INCL)
	cc -c $(FLAGS) $<


bonus: $(OBJS_BNS) $(NAME_BNS)

$(NAME_BNS): $(OBJS_BNS)
	@make -C libft
	cc -o $(NAME_BNS) ${OBJS_BNS} libft/libft.a

clean:
	@make -C libft clean
	rm -f $(OBJS) $(OBJS_BNS)

fclean: clean
	rm -f $(NAME) $(NAME_BNS) libft/libft.a

re: fclean all

.PHONY: all bonus clean fclean re