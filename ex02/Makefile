NAME = Bankdata
CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98
SRC = Account.cpp tests.cpp
OBJS = $(SRC:.cpp=.o)


all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(SRC)

clean :
	rm -f $(OBJS)

fclean :
	rm -f $(OBJS) $(NAME)

re: fclean all