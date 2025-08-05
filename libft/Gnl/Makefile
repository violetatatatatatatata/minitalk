NAME	= gnl.a
CC		= cc
CFLAGS	= -Wall -Werror -Wextra
DFLAGS	= -g -fsanitize=all
RM		= rm -fr
AR		= ar rc

SRC_FILES	= get_next_line get_next_line_utils
SSRC_FILES	= $(addsufix (_bonus.c, $(SRC_FILES)))
OBJ			= $(SRC_FILES:.c=.o)

all:$(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)
	ranlib $(NAME)

$(SSRC_FILES)%.o: $(SSRC_FILES)%.c Makefile get_next_line_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
