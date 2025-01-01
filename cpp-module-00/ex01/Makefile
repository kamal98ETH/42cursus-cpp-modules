NAME = phonebook

COMPILER = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = awesome_phonebook.cpp PhoneBook.cpp Contact.cpp

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