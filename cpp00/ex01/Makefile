CXX = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = phonebook

HDIR = ./

SRCS = PhoneBook.cpp \
       main.cpp \
       Contact.cpp

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
