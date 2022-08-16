# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: earendil <earendil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/16 17:34:54 by earendil          #+#    #+#              #
#    Updated: 2022/08/16 20:09:27 by earendil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = @c++
CFLAGS = -std=c++98 -Wall -Werror -Wextra

NAME = megaphone
OBJS_DIR = bin
OBJS = $(addprefix $(OBJS_DIR)/, $(shell find . -name "*.cpp" -print | sed 's/\.cpp/\.o/g' | sed 's/\.\///'))
INCLUDES = $(shell find . -name "*.hpp" -print)

RMF = @/bin/rm -f
MAKE_REC = @make --no-print-directory

exercise: .BUILD

run: .BUILD
	@./$(NAME) "shhhhh... I think the students are asleep..."
	@./$(NAME)  Damnit " ! " "Sorry students, I thought this thing was off."
	@./$(NAME)

all:
	@$(MAKE_REC) -C ..

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@printf "\033[0;35mProject done!\n\n\033[0;37m"

$(shell echo $(OBJS_DIR))/%.o: %.cpp $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@

fclean: clean
	@printf "removing program executable $(NAME)\n\033[0;37m"
	$(RMF) -f $(NAME)
	@printf "\033[0;35mExecutable removed!\n\n\033[0;37m"

clean:
	@printf "removing Object files $(OBJS)\n\033[0;37m"
	$(RMF) $(OBJS)
	@printf "\033[0;35mObject files removed!\n\n\033[0;37m"

re: fclean all

.BUILD:
	@printf "\e[1;33mMaking exercise $(NAME) \n\033[0;37m"
	@$(MAKE_REC) $(NAME)