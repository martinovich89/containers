NAME_FT			=	ft_containers

NAME_STL		=	stl_containers

OBJS_FT_DIR		=	./ft_objs

OBJS_STL_DIR	=	./stl_objs

HEADERS			=	vector.hpp\
					vector.tpp\
					reverse_iterator.hpp\
					vector_const_iterator.hpp\
					vector_iterator.hpp\
					iterator_traits.hpp

SRCS			=	mymain.cpp

OBJS			=	$(OBJS_FT_DIR)/$(SRCS:.cpp=.o)

OBJS_STL		=	$(OBJS_STL_DIR)/$(SRCS:.cpp=.o)

CXX				=	g++


CXXFLAGS		=	-Wall -Wextra -Werror -std=c++98 #-D __STL__ #-fsanitize=address -g3

STL_FLAGS	=	-Wall -Wextra -Werror -std=c++98 -D __STL__ #-fsanitize=address -g3

all : $(NAME_FT) $(NAME_STL)

$(NAME_FT) : $(OBJS_FT_DIR) $(OBJS)
		$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME_FT)

$(NAME_STL) : $(OBJS_STL_DIR) $(OBJS_STL)
		$(CXX) $(CXXFLAGS) $(OBJS_STL) -o $(NAME_STL)


$(OBJS_FT_DIR) :
		mkdir -p $@

$(OBJS_STL_DIR) :
		mkdir -p $@

$(OBJS_FT_DIR)/%.o : %.cpp $(HEADERS) Makefile
		$(CXX) $(CXXFLAGS) -o $@ -c $<

$(OBJS_STL_DIR)/%.o : %.cpp $(HEADERS) Makefile
		$(CXX) $(CXXFLAGS) $(STL_FLAGS) -o $@ -c $<


clean :
		rm -rf $(OBJS_FT_DIR)
		rm -rf $(OBJS_STL_DIR)

fclean : clean
		rm -rf $(NAME_FT)
		rm -rf $(NAME_STL)

re : fclean all

.PHONY : all clean fclean re
