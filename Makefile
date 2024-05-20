NAME = PhoneBook
CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98
SRC = main.cpp
OBJS = $(SRC:.cpp=.o)


all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(SRC)

clean :
	rm -f $(SRC)

fclean :
	rm -f $(SRC) $(NAME)

re: fclean all