/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 15:52:52 by mmarinel          #+#    #+#             */
/*   Updated: 2022/08/18 12:05:28 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
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
