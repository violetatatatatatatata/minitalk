# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avelandr <avelandr@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/07 21:55:54 by avelandr          #+#    #+#              #
#    Updated: 2025/07/24 19:56:56 by avelandr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	minitalk/
#	├── client.c
#	├── server.c
#	├── utils.c
#	├── minitalk.h
#	├── Makefile
#	└── libft/
#	    ├── libft.a
#	    ├── ft_*.c
#	    └── Makefile

NAME_SERVER = server
NAME_CLIENT = client

LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

SRCS_SERVER = server.c utils.c
SRCS_CLIENT = client.c utils.c

OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -O0

all: $(LIBFT_LIB) $(NAME_SERVER) $(NAME_CLIENT)

$(LIBFT_LIB):
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME_SERVER): $(OBJS_SERVER)
	$(CC) $(CFLAGS) $(OBJS_SERVER) $(LIBFT_LIB) -o $(NAME_SERVER)

$(NAME_CLIENT): $(OBJS_CLIENT)
	$(CC) $(CFLAGS) $(OBJS_CLIENT) $(LIBFT_LIB) -o $(NAME_CLIENT)

clean:
	rm -f $(OBJS_SERVER) $(OBJS_CLIENT)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME_SERVER) $(NAME_CLIENT)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

bonus:
	@$(MAKE) BONUS=1 all

.PHONY: all clean fclean re bonus
