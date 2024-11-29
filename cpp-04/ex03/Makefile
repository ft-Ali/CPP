NAME        =   AbstractAnimal

CC          =   c++

FLAG        =   -std=c++98 -Wall -Wextra -Werror -pedantic -g3

C_FILES     = 	main.cpp \

OBJ_DIR     =   builds

OBJS        =   $(addprefix $(OBJ_DIR)/, $(C_FILES:.cpp=.o))

DEPS        =   $(OBJS:.o=.d)

CYAN        =   \033[36;1m
RESET       =   \033[0m

all:        $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	@printf "\r$(CYAN)Compiling $<$(RESET)"
	@$(CC) $(FLAG) -c $< -o $@ 
	@printf "\r\033[K"

$(NAME):    $(OBJS)
	@$(CC) $(OBJS) -o $(NAME) $(FLAG)
	@printf "\r$(CYAN)Done!$(RESET)\n"

clean:
	@rm -f $(OBJ_DIR)/*.o $(DEPS)
	@rm -rf $(OBJ_DIR)
	@printf "$(CYAN)Cleaned .o files and dependencies!$(RESET)\n"

fclean:    clean
	@rm -f $(NAME)
	@printf "$(CYAN)Cleaned all!$(RESET)\n"

re:	fclean all

-include $(DEPS)

.PHONY:    all clean fclean re