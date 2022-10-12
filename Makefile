NAME			=	ft_containers

HEADERS			=	vector.hpp\
					vector.tpp\
					reverse_iterator.hpp\
					vector_const_iterator.hpp\
					vector_iterator.hpp\
					iterator_traits.hpp

SRCS			=	mymain.cpp\

OBJS			=	$(SRCS:.cpp=.o)

CXX				=	clang++

CXXFLAGS		=	-Wall -Wextra -Werror -std=c++98 -fsanitize=address -g3

all : $(NAME)

$(NAME) : $(OBJS)
		$(CXX) $(CXXFLAGS) $^ -o $(NAME)

%.o : %.cpp $(HEADERS) Makefile
		$(CXX) $(CXXFLAGS) -o $@ -c $<

clean :
		rm -rf $(OBJS)

fclean : clean
		rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
