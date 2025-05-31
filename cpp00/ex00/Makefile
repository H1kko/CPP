CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = 	megaphone

SRCS =	megaphone.cpp

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	c++ $(CFLAGS) -o $@ $^

%.o: %.c
	c++ $(CFLAGS) -c  $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: re fclean clean all megaphone
