NAME            = computor
CC              = gcc
CFLAGS          = 
HEADER          = ./includes
INCLUDES        = -I$(HEADER)

SRCS            = srcs/main.c \
					srcs/debug.c \
					srcs/parsing.c \
					srcs/utils.c

OBJS_DIR        = objs
OBJS            = $(SRCS:srcs/%.c=$(OBJS_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJS_DIR)/%.o: srcs/%.c includes/computorv1.h
	@mkdir -p $(OBJS_DIR)
	@printf "Compiling $<...\n"
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re