# Makefile for libft

# Compiler
CC = cc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror

# Source files
SRCS = \
    Convs/ft_atoi.c \
    Mem/ft_bzero.c \
    Mem/ft_calloc.c \
    Comps/ft_isalnum.c \
    Comps/ft_isalpha.c \
    Comps/ft_isascii.c \
    Comps/ft_isdigit.c \
    Comps/ft_isprint.c \
	Comps/ft_is_negative.c \
    Mem/ft_memchr.c \
    Mem/ft_memcmp.c \
    Mem/ft_memcpy.c \
    Mem/ft_memmove.c \
    Mem/ft_memset.c \
	Mem/ft_swap.c \
    Fd/ft_putchar_fd.c \
    Fd/ft_putendl_fd.c \
    Fd/ft_putnbr_fd.c \
    Fd/ft_putstr_fd.c \
    Strings/ft_strdup.c \
    Strings/ft_strchr.c \
    Strings/ft_strlcat.c \
    Strings/ft_strlcpy.c \
    Strings/ft_strlen.c \
    Strings/ft_strncmp.c \
    Strings/ft_strnstr.c \
    Strings/ft_tolower.c \
    Strings/ft_toupper.c \
    Strings/ft_substr.c \
    Strings/ft_strjoin.c \
    Strings/ft_strtrim.c \
    Strings/ft_strmapi.c \
	Strings/ft_strcmp.c \
    Convs/ft_itoa.c \
    Strings/ft_split.c \
    List/ft_lstnew_bonus.c \
    List/ft_lstadd_front_bonus.c \
    List/ft_lstadd_back_bonus.c \
    List/ft_lstclear_bonus.c \
    List/ft_lstdelone_bonus.c \
    List/ft_lstiter_bonus.c \
    List/ft_lstlast_bonus.c \
    List/ft_lstmap_bonus.c \
    List/ft_lstsize_bonus.c \
    List/ft_lstalast_bonus.c \
	Arrays/ft_count_if.c \
	Arrays/ft_foreach.c \
	Arrays/ft_range.c \
    Gnl/get_next_line.c \
    Gnl/get_next_line_bonus.c \
    Printf/ft_printf.c \
    Printf/printnum.c \
    Printf/printstring.c \
    Printf/printpoint.c \
    Printfd/ft_printfd.c \
    Printfd/printnumfd.c \
    Printfd/printstringfd.c \
    Printfd/printpointfd.c \

# Object files
OBJS = $(SRCS:.c=.o)

# Library name
LIBRARY = libft.a

# Default target
all: $(LIBRARY)

# Rule to create the library
$(LIBRARY): $(OBJS)
	@ar rcs $@ $^

# Rule to compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files and the library
clean:
	rm -f $(OBJS)

# Clean up the library
fclean: clean
	rm -f $(LIBRARY)

# Rebuild the library
re: fclean all

.PHONY: all clean fclean re
