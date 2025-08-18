NAME		:= ./Fixed
CXX			:= g++
CXXFLAGS	:= -Wall -Wextra -Werror -std=c++98

SRCS		:= main.cpp Fixed.cpp
OBJS		:= $(SRCS:.cpp=.o)

# ==== Rules ====

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all