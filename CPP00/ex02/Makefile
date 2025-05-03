CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = 	job

HDIR = Account.hpp

SRCS =	tests.cpp \
		Account.cpp

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	c++ $(CFLAGS) -o $@ $^

%.o: %.c $(HDIR)
	c++ $(CFLAGS) -c  $< -o $@ -I $(HDIR)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: re fclean clean all job
