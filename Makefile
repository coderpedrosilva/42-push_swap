CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
NAME	= push_swap

SRC_PATH = sources/
OBJ_PATH = sources/

SRC		= main.c \
		  check_args.c check_utils.c \
		  start_stack.c \
		  stack_sorted.c \
		  swap_elements.c pushes_elements.c reverse_to_bottom.c reverse_to_top.c \
		  low_sort.c high_sort.c \
		  move_stack.c cost_moves.c varied_moves.c \
		  functions_utils.c
		
SRCS	= $(addprefix $(SRC_PATH), $(SRC))
OBJ		= $(SRC:.c=.o)
OBJS	= $(addprefix $(OBJ_PATH), $(OBJ))
INCS	= -I ./includes/

all: $(OBJ_PATH) $(NAME) 

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(YELLOW)compilation ok$(DEFAULT)"

clean:
	@rm -rf $(OBJS:.c=.o)
	@echo "$(YELLOW)object files deleted$(DEFAULT)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(YELLOW)all deleted$(DEFAULT)"

re: fclean all

.PHONY: all clean fclean re 

YELLOW = \033[1;33m
DEFAULT = \033[0m