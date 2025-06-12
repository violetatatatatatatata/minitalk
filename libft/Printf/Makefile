# Variables
NAME        = libftprintf.a
INCLUDE     = include
SRC_DIR     = src/
CC          = cc
CFLAGS      = -Wall -Werror -Wextra
RM          = rm -rf
AR          = ar rc

# Sources
SRC_FILES   = ft_printf printnum printpoint printstring
SRC         = $(addsuffix .c, $(SRC_FILES))
OBJ         = $(SRC:.c=.o)
SRCS        = $(addprefix $(SRC_DIR), $(SRC))

# Rules
all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)
	ranlib $(NAME)

$(SRC_DIR)%.o: $(SRC_DIR)%.c Makefile ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
