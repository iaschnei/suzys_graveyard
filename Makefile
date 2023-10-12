# ---------------------------------------------------------------------------- #

SRCS		=	main.cpp srcs/Game.cpp srcs/Player.cpp srcs/Animation.cpp      \
				srcs/vector_manipulation.cpp

# ---------------------------------------------------------------------------- #

OBJS		=	$(SRCS:.cpp=.o)

G++			=	g++

FLAGS		= 	-lsfml-graphics -lsfml-window -lsfml-system

NAME		=	suzys_graveyard

COLOR_GREEN	=	\033[1;32m
COLOR_RED	=	\033[1;31m
COLOR_BLUE	=	\033[3;36m
COLOR_PURP	=	\033[1;35m
COLOR_END	=	\033[0m

%.o: %.cpp
	@$(G++) -c $< -o $@ $(FLAGS)
	@echo "$(COLOR_BLUE) || Compiling ($<)...$(COLOR_END)"

all: $(NAME)

$(NAME): $(OBJS)
	@$(G++) $(OBJS) -o $(NAME) $(FLAGS)
	@echo "$(COLOR_GREEN) || Done !$(COLOR_END)"

clean:
	@rm -rf $(OBJS)
	@echo "$(COLOR_RED) || Cleaning files...$(COLOR_END)"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(COLOR_RED) || Cleaning library...$(COLOR_END)"

re: fclean all

.PHONY: re fclean all clean
