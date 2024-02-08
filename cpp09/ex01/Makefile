# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dardangerguri <dardangerguri@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/02 16:05:53 by dgerguri          #+#    #+#              #
#    Updated: 2024/02/08 11:54:58 by dardangergu      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Output binary name
NAME	=	easy

# Name, compiler, and flags
CC 		= 	c++
CFLAGS	=	-Werror -Wextra -Wall

# Source files
SRC		=	main.cpp RPN.cpp

# Object files
OBJ_D	=	obj/
OBJ		=	$(SRC:.cpp=.o)
OBJS	=	$(addprefix $(OBJ_D), $(OBJ))

# Color codes for pretty output
GREEN	=	\033[0;32m
RED		=	\033[0;31m
BLUE	=	\033[0;34m
RESET	=	\033[0m

# Default target: build the main program
all: $(NAME)

# Compile source files to object files
$(OBJ_D)%.o: %.cpp RPN.hpp
	@mkdir -p $(OBJ_D)
	@$(CC) $(CFLAGS) -c $< -o $@

# Build the main program
$(NAME): $(OBJS)
	@echo "$(BLUE)Compiling $(NAME)$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)done$(RESET)"

# Clean the project by removing object files
clean:
	@echo "$(RED)removing object files$(RESET)"
	@/bin/rm -rf $(OBJ_D)

# Clean the project and remove executables
fclean: clean
	@echo "$(RED)cleaning all compiled stuff.. :)$(RESET)"
	@/bin/rm -rf $(NAME)
	@echo "$(RED)Done!$(RESET)"

# Clean and rebuild the project
re: fclean all

# Declare phony targets (targets that don't create files with these names)
.PHONY: all clean fclean re
