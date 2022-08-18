/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook_utils.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 14:33:15 by earendil          #+#    #+#             */
/*   Updated: 2022/08/18 15:55:13 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

static void	display_contact_entry(std::string entry, bool last);
//* end of static declarations

void	set_cout_flags(void)
{
	std::cout << std::setw(PHONEBOOK_MAX_WIDTH)
		<< std::resetiosflags(std::ios::adjustfield)
		<< std::setiosflags(std::ios::right);
}

void	read_input(std::string& input_ref)
{
	system("clear");
	std::cout << "Waiting for index: ";
	getline(std::cin, input_ref, '\n');
}

void	pb_bad_input(const char *msg)
{
	std::cout << msg << std::endl;
	getchar();
}

void	display_contact(Contact contact, std::string next_index_to_display)
{
	display_contact_entry(next_index_to_display, false);
	display_contact_entry(contact.get_name(), false);
	display_contact_entry(contact.get_last_name(), false);
	display_contact_entry(contact.get_nickname(), true);
	getchar();
}

static void	display_contact_entry(std::string entry, bool last)
{
	std::cout << std::setw(PHONEBOOK_MAX_WIDTH)
		<< std::resetiosflags(std::ios::adjustfield)
		<< std::setiosflags(std::ios::right);
	if (entry.length() > 10)
			std::cout << entry.erase(9) << ".";
	else
		std::cout << entry;
	{
		if (last)
			std::cout << std::endl;
		else
			std::cout << "|";
	}
}