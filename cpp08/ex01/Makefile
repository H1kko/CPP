CXX = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98 -g

NAME = Span
HDIR = ./

SRCS = 	main.cpp \
		Span.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CFLAGS) -c $< -o $@ -I $(HDIR)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: re fclean clean all
