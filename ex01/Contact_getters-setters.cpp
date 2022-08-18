/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact_getters-setters.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 14:53:10 by earendil          #+#    #+#             */
/*   Updated: 2022/08/18 14:53:36 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string	Contact::get_name(void)
{
	return (std::string(this->name));
}

std::string	Contact::get_last_name(void)
{
	return (std::string(this->last_name));
}

std::string	Contact::get_nickname(void)
{
	return (std::string(this->nickname));
}

std::string	Contact::get_phone_number(void)
{
	return (std::string(this->phone_number));
}

std::string	Contact::get_darkest_secret(void)
{
	return (std::string(this->darkest_secret));
}
