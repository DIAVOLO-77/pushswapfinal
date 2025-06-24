NAME = push_swap

SRCS = main.c \
	   stack_utils.c \
	   parse_args.c \
	   parse_args_utils.c \
	   parse_args_utils2.c \
	   operations_push.c \
	   operations_swap.c \
	   operations_rotate.c \
	   operations_reverse_rotate.c \
	   indexing.c \
	   sort.c \
	   sort_small.c \
	   sort_large.c \
	   sort_large_utils.c \
	   sort_large_utils2.c \
	   sort_large_utils3.c \
	   utils.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -f

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re