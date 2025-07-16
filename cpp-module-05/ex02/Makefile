NAME = form

COMPILER = c++

FLAGS = -g3 -std=c++98

SRCS = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp

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