# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mokutucu <mokutucu@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/24 13:51:09 by mokutucu          #+#    #+#              #
#    Updated: 2025/01/24 14:04:10 by mokutucu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Megaphone

# Directories
OBJDIR  = obj
SRC_DIR = src

# Compiler and flags
CC		= g++
CFLAGS  = -Wall -Wextra -Werror

# Cleanup
RM      = rm -rf

# Source files and objects
SRCS	= src/

OBJS	= $(patsubst $(SRC_DIR)/%.c, $(OBJDIR)/%.o, $(SRCS))

all: $(NAME)

$(NAME): $(OBJS)
    $(CC) $(CFLAGS) -o $@ $^

		$(OBJDIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJDIR)
		$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
    mkdir -p $(OBJDIR)

clean:
    $(RM) $(OBJDIR)

# Full clean, including the executable
fclean: clean
    $(RM) $(NAME)
    
# Phony targets
.PHONY: all clean fclean