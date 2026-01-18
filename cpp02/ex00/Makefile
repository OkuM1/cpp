# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mokutucu <mokutucu@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/03 17:39:55 by mokutucu          #+#    #+#              #
#    Updated: 2025/04/11 13:42:29 by mokutucu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fixed

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

CXX = c++

SRCS = main.cpp src/Fixed.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re