NAME            = computorv1
CC              = gcc
CFLAGS          = 
HEADER          = ./includes
INCLUDES        = -I$(HEADER)

SRCS            = srcs/main.c

OBJS_DIR        = objs
OBJS            = $(SRCS:srcs/%.c=$(OBJS_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJS_DIR)/%.o: srcs/%.c includes/computerv1.h
	@mkdir -p $(OBJS_DIR)
	@printf "Compiling $<...\n"
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re