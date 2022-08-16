# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: earendil <earendil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/16 17:11:58 by earendil          #+#    #+#              #
#    Updated: 2022/08/16 20:10:30 by earendil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	@echo "Making all exercises\n"
	@for DIR in $$(find . -print | grep "Makefile" | sed 's/Makefile//g' | grep ex); do \
		make --no-print-directory -C $$DIR exercise; \
	done;
	@echo Exercises done!

run:
	@echo "Running all exercises\n"
	@for DIR in $$(find . -print | grep "Makefile" | sed 's/Makefile//g' | grep ex); do \
		make --no-print-directory -C $$DIR run; \
	done;
	@echo "\n"
	@echo Run completed!

fclean:
	@echo "Destroying all exercises\n"
	@for DIR in $$(find . -print | grep "Makefile" | sed 's/Makefile//g' | grep ex); do \
		make --no-print-directory -C $$DIR fclean; \
	done;
	@echo Exercises destroyed!

re: fclean all