/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 14:32:58 by mmarinel          #+#    #+#             */
/*   Updated: 2022/08/18 20:10:47 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

static std::string	get_cur_field(char const *field_name);
//* end of static declarations

Contact::Contact(void)
{
	this->name = std::string();
	this->last_name = std::string();
	this->nickname = std::string();
	this->phone_number = std::string();
	this->darkest_secret = std::string();
}

void	Contact::update_contact(void)
{
	this->name = get_cur_field("name");
	this->last_name = get_cur_field("last_name");
	this->nickname = get_cur_field("nickname");
	while (false == std::cin.eof())
	{
		this->phone_number = get_cur_field("phone_number");
		if (false == this->phone_number.empty()
			&& false == str_is_digit(this->phone_number))
		{
			std::cout << std::endl
				<< RED "Please enter a digit string" RESET
				<< std::endl;
			getchar();
		}
		else
			break ;

	}
	this->darkest_secret = get_cur_field("darkest secret");
	if (false == std::cin.eof())
	{
		std::cout << GREEN "<<SUCCESS>>" RESET << std::endl;
		std::cout << "Press any Key to continue..." << std::endl;
		getchar();
		system("clear");
	}
}

static std::string	get_cur_field(char const *field_name)
{
	std::string	field_val;

	while (field_val.empty() && false == std::cin.eof())
	{
		system("clear");
		std::cout << "Enter field " << "< " << field_name << " >" << " : ";
		std::getline(std::cin, field_val, '\n');
		if (field_val.empty() && false == std::cin.eof())
		{
			std::cout << std::endl
				<< RED "Empty fields are not allowed!" RESET
				<< std::endl;
			getchar();
		}
	}
	return (field_val);
}
