CXX = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98 -g

NAME = AMateria

HDIR = ./

SRCS = AMateria.cpp \
		main.cpp \
		Character.cpp \
		Cure.cpp \
		Ice.cpp \
		SuperIce.cpp \
		MateriaSource.cpp \

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
