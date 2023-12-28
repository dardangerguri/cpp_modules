# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dardangerguri <dardangerguri@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/29 17:59:14 by dgerguri          #+#    #+#              #
#    Updated: 2023/12/28 11:26:20 by dardangergu      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Output binary name
NAME	=	Animal

# Name, compiler, and flags
CC 		= 	c++
CFLAGS	=	-Werror -Wextra -Wall -std=c++98

# Directories
SRC_D	=	srcs/
OBJ_D	=	obj/

# Source files
SRC		=	main.cpp Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp Brain.cpp

# Object files
OBJ		=	$(SRC:.cpp=.o)
OBJS	=	$(addprefix $(OBJ_D), $(OBJ))

# Include directories
INC_D	=	-I includes/

# Color codes for pretty output
GREEN	=	\033[0;32m
RED		=	\033[0;31m
BLUE	=	\033[0;34m
RESET	=	\033[0m

# Default target: build the main program
all: $(NAME)

# Compile source files to object files
$(OBJ_D)%.o: $(SRC_D)%.cpp ./includes/Animal.hpp ./includes/Dog.hpp ./includes/Cat.hpp \
		./includes/WrongAnimal.hpp ./includes/WrongCat.hpp ./includes/Brain.hpp
	@mkdir -p $(OBJ_D)
	@$(CC) $(CFLAGS) $(INC_D) -c $< -o $@

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
