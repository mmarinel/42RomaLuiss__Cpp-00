/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 14:46:10 by mmarinel          #+#    #+#             */
/*   Updated: 2022/08/18 13:30:49 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "../cpp00_utils.hpp"
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>

static void	display_contact(Contact contact);
static void	set_cout_flags(void);
static void	read_input(std::string& input_ref);
static void	pb_bad_input(const char *msg);
//* end of static declarations

PhoneBook::PhoneBook(void)
{
	this->next_index = 0;
}

bool PhoneBook::add_contact(void)
{
	this->contacts[this->next_index].update_contact();
	this->next_index = (this->next_index + 1) % PHONEBOOK_MAX_CONTACTS;
	return (true);
}

bool PhoneBook::search_contact(void)
{
	std::string		input;
	unsigned int	next_index_to_display;

	set_cout_flags();
	while (false == std::cin.eof())
	{
		read_input(input);
		if (input.empty())
			break ;
		else if (false == str_is_digit(input.c_str()))
			pb_bad_input("Please insert a number");
		else
		{
			sscanf(input.c_str(), "%u", &next_index_to_display);
			if (next_index_to_display < 0 || next_index_to_display > PHONEBOOK_MAX_CONTACTS
				|| this->contacts[next_index_to_display].get_name().empty())
				pb_bad_input("Input out of range");
			else
				display_contact(this->get_contact(next_index_to_display));
		}
	}
}
	
static void	read_input(std::string& input_ref)
{
	system("clear");
	std::cout << "Waiting for index: ";
	getline(std::cin, input_ref, '\n');
}

static void	set_cout_flags(void)
{
	std::cout << std::setw(PHONEBOOK_MAX_WIDTH)
		<< std::resetiosflags(std::ios::adjustfield)
		<< std::setiosflags(std::ios::right);
}

static void	pb_bad_input(const char *msg)
{
	std::cout << msg << std::endl;
	getchar();
}

/**
 * @brief returns true iff the PhoneBook Objects
 * is available to interpret
 * other commands after the one given as argument.
 * 
 * @param command 
 * @return true 
 * @return false 
 */
bool	PhoneBook::interpreter(std::string command)
{
	if (0 == command.compare("EXIT"))
		return (false);
	if (0 == command.compare("ADD"))
		this->add_contact();
	if (0 == command.compare("SEARCH"))
		this->search_contact();
	{
		if (std::cin.eof())
			return (false);
		return (true);
	}
}