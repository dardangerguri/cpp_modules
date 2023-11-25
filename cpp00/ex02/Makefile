# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dardangerguri <dardangerguri@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/23 12:51:20 by dgerguri          #+#    #+#              #
#    Updated: 2023/11/25 14:48:37 by dardangergu      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Output binary name
NAME	=	testAccount

# Name, compiler, and flags
CC 		= g++
CFLAGS	=	#-Werror -Wextra -Wall -std=c++98

# Source files
SRC		=	tests.cpp Account.cpp

# Object files
OBJ		=	$(SRC:.cpp=.o)
OBJS	=	$(addprefix $(OBJ_D), $(OBJ))

# Object files directory
OBJ_D	=	obj/

# Color codes for pretty output
GREEN	=	\033[0;32m
RED		=	\033[0;31m
BLUE	=	\033[0;34m
RESET	=	\033[0m

# Default target: build the main program
all: $(NAME)

# Compile source files to object files
$(OBJ_D)%.o: %.cpp Account.hpp
	@mkdir -p $(OBJ_D)
	@$(CC) $(CFLAGS) -I Account.hpp -c $< -o $@

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
