NAME            = computor
CC              = gcc
CFLAGS          = -Wall -Werror -Wextra
HEADER          = ./includes
INCLUDES        = -I$(HEADER)

CRL             = -L/usr/local/opt/readline/lib \
                  -I/usr/local/opt/readline/include

SRCS            = srcs/main.c \
                  srcs/debug.c \
                  srcs/parsing.c \
                  srcs/utils.c \
				  srcs/calculator.c

OBJS_DIR        = objs
OBJS            = $(SRCS:srcs/%.c=$(OBJS_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(CRL) -o $(NAME) -lreadline

$(OBJS_DIR)/%.o: srcs/%.c includes/computorv1.h
	@mkdir -p $(OBJS_DIR)
	@printf "Compiling $<...\n"
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re