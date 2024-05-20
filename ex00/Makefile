NAME = megaphone
CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98
OBJS = megaphone.cpp
SRC = megaphone.o


all: $(NAME)

$(NAME): megaphone.o
	$(CXX) $(CXXFLAGS) -o $(NAME) $(SRC)

clean :
	rm -f $(SRC)

fclean :
	rm -f $(SRC) $(NAME)

re: fclean all