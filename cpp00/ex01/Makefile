# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mokutucu <mokutucu@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/03 17:16:19 by mokutucu          #+#    #+#              #
#    Updated: 2025/03/03 17:25:56 by mokutucu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

CXX = c++

SRCS = main.cpp src/phonebook.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean:
	rm -rf $(OBJS) $(NAME)

re: fclean all

.PHONY: all clean fclean re