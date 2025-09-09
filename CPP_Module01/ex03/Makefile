# ==== Variables ====
NAME        := ./unnecessary_violence
CXX         := g++
CXXFLAGS    := -Wall -Wextra -Werror -std=c++98 -g

SRCS        := main.cpp HumanA.cpp HumanB.cpp Weapon.cpp
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