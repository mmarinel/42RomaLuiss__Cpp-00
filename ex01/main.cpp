/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 15:52:52 by mmarinel          #+#    #+#             */
/*   Updated: 2022/08/18 20:05:43 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
# include "../colors.hpp"
#include <cstdlib>
#include <string>
#include <iostream>

int main(void)
{
	PhoneBook		phonebook;
	std::string		command;

	do
	{
		command.erase(0);
		while (command.empty() && false == std::cin.eof())
		{
			system("clear");
			std::cout << "Enter command: ";
			std::getline(std::cin, command, '\n');
		}
	} while (phonebook.interpreter(command));
	return (0);
}
