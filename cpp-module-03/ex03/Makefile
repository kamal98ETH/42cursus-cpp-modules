NAME = diamondtrap

COMPILER = c++

FLAGS = -Wall -Wextra -Werror -std=c++98 -Wshadow

SRCS = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp

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