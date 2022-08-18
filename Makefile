# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/16 17:11:58 by earendil          #+#    #+#              #
#    Updated: 2022/08/17 11:25:34 by mmarinel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	@echo "Making all exercises\n"
	@for DIR in $$(find . -print | grep "Makefile" | sed 's/Makefile//g' | grep ex); do \
		make --no-print-directory -C $$DIR exercise; \
	done;
	@echo Exercises done!

run:
	@make --no-print-directory -si .RUN

fclean:
	@echo "Destroying all exercises\n"
	@for DIR in $$(find . -print | grep "Makefile" | sed 's/Makefile//g' | grep ex); do \
		make --no-print-directory -C $$DIR fclean; \
	done;
	@echo Exercises destroyed!

re: fclean all

.RUN:
	@echo "Running all exercises\n"
	@for DIR in $$(find . -print | grep "Makefile" | sed 's/Makefile//g' | grep ex); do \
		clear; \
		make --no-print-directory -C $$DIR run; \
		echo "\n"; \
		read -p "Press any key to continue"; \
	done;
	@echo "\n"
	@echo Run completed!
