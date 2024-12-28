NAME = account

COMPILER = c++

FLAGS = -Wall -Wextra -Werror

SRCS = tests.cpp Account.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
		$(COMPILER) $(FLAGS) $(OBJS) -o $(NAME)

.cpp.o:
	$(COMPILER) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all