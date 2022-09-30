NAME		=	ft_containers

CC			=	c++

FLAGS		=	-Wall -Wextra -Werror -std=c++98

HEADER		= 	iterator_traits.hpp vector_iterator.hpp reverse_iterator.hpp utility.hpp vector.hpp node.hpp tree.hpp map_iterator.hpp map.hpp stack.hpp tests.hpp

SRCS		=	my_main.cpp map_test.cpp vector_test.cpp stack_test.cpp

OBJS		=	$(SRCS:.cpp=.o)

RM			=	rm -f

.PHONY:		all clean fclean re

all:		$(NAME)

$(NAME):	$(OBJS) $(HEADER)
			$(CC) $(FLAGS) -o $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean $(NAME)