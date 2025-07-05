# ==== Variables ====
NAME        := phonebook
CXX         := g++
CXXFLAGS    := -Wall -Wextra -Werror -std=c++98

SRCS        := main.cpp add.cpp Phonebook.cpp search.cpp
OBJS        := $(SRCS:.cpp=.o)

# ==== Règles ====

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
