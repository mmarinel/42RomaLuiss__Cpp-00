/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 14:46:10 by mmarinel          #+#    #+#             */
/*   Updated: 2022/08/18 11:11:33 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
# include <iomanip>
#include <iostream>
#include <string>

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
	return (false);
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