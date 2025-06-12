# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avelandr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/01 22:06:43 by avelandr          #+#    #+#              #
#    Updated: 2025/06/12 17:10:54 by avelandr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler
CC = clang

# Compiler flags for regular compilation
CFLAGS = -Wall -Werror -Wextra -MD -MP -g -fsanitize=address

# Compiler flags for Valgrind (without AddressSanitizer)
CFLAGS_VALGRIND = -Wall -Werror -Wextra -MD -MP -g

# Directories
SRC_DIR = src
OBJ_DIR = obj
LIBFT_DIR = libft
LIB_DIR = libs
INC_DIR = Includes
DEPS_DIR = deps

# Source files
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
DEP_FILES = $(SRC_FILES:$(SRC_DIR)/%.c=$(DEPS_DIR)/%.d)
CLIB = .a

# Executable name
NAME = !!!

# Rules
all: $(NAME)

$(NAME): $(OBJ_FILES) $(LIB_DIR)/$(LIBFT_DIR)$(CLIB)
	# Usa CFLAGS para la compilación final del ejecutable
	$(CC) $(CFLAGS) -o $@ $^ -L$(LIB_DIR) -I $(INC_DIR) -l:$(LIBFT_DIR)$(CLIB)

$(LIB_DIR)/$(LIBFT_DIR)$(CLIB):
	@make -C $(LIBFT_DIR) # Compile libft library
	@mkdir -p $(LIB_DIR) # Create libs directory if it doesn't exist
	@cp -a $(LIBFT_DIR)/$(LIBFT_DIR)$(CLIB) $(LIB_DIR)/ # Copy the library to libs

$(INC_DIR):
	@mkdir -p $(INC_DIR) # Create Includes directory if it doesn't exist
	@cp -a $(LIBFT_DIR)/$(INC_DIR)/*.h $(INC_DIR) # Copy the header files to Includes

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c Makefile
	@mkdir -p $(OBJ_DIR)  # Create object directory if it doesn't exist
	@mkdir -p $(DEPS_DIR)  # Create dependencies directory if it doesn't exist
	# Usa CFLAGS para compilar los archivos .c
	$(CC) $(CFLAGS) -c $< -o $@ -MD -MF $(DEPS_DIR)/$*.d -I $(INC_DIR)

# Include dependency files
-include $(DEP_FILES)

clean:
	@rm -rf $(OBJ_DIR)  # Remove object files
	@rm -rf $(LIB_DIR) # Remove libs
	@rm -rf $(DEPS_DIR) # Remove dependencies
	@make fclean -C $(LIBFT_DIR)  # Clean libft

fclean: clean
	@rm -f $(NAME)  # Remove the executable

re: fclean all  # Rebuild the project

# Nueva regla para Valgrind: recompila con CFLAGS_VALGRIND y luego ejecuta Valgrind
mem: clean_valgrind $(NAME)_valgrind
	valgrind --verbose --track-origins=yes --leak-check=full --show-leak-kinds=all ./$(NAME)_valgrind $(TESTVALUES)

# Regla para compilar el ejecutable específico para Valgrind
$(NAME)_valgrind: $(OBJ_FILES) $(LIB_DIR)/$(LIBFT_DIR)$(CLIB)
	$(CC) $(CFLAGS_VALGRIND) -o $@ $^ -L$(LIB_DIR) -I $(INC_DIR) -l:$(LIBFT_DIR)$(CLIB)

# Regla para limpiar el ejecutable de Valgrind
clean_valgrind:
	@rm -f $(NAME)_valgrind

test: $(NAME)
	./$(NAME) $(TESTVALUES)

.PHONY: all clean fclean re mem test clean_valgrind
