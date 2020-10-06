NAME = a.out

SRCS = main.cpp

OBJS = $(SRCS:.cpp=.o)

CLANG = clang++

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SRCS)
	$(CLANG) $(FLAGS) $(SRCS) -c
	$(CLANG) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) a.out

re: fclean all

test:	$(NAME)
	./$(NAME)
	rm -f $(NAME) a.out

.PHONY: all clean fclean re test
