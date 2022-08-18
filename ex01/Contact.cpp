/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 14:32:58 by mmarinel          #+#    #+#             */
/*   Updated: 2022/08/18 15:12:07 by earendil         ###   ########.fr       */
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
			&& false == str_is_digit(this->phone_number.c_str()))
		{
			std::cout << std::endl
				<< "Please enter a digit string"
				<< std::endl;
			getchar();
		}
		else
			break ;

	}
	this->darkest_secret = get_cur_field("darkest secret");
	if (false == std::cin.eof())
	{
		std::cout << "<<SUCCESS>>" << std::endl;
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
		std::cout << "Enter field " << "< " << field_name << " >" << ": ";
		std::getline(std::cin, field_val, '\n');
		if (field_val.empty() && false == std::cin.eof())
		{
			std::cout << std::endl
				<< "Empty field are not allowed!"
				<< std::endl;
			getchar();
		}
	}
	return (field_val);
}
