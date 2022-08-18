/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook_getters-setters.cpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 14:33:29 by earendil          #+#    #+#             */
/*   Updated: 2022/08/18 15:13:41 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

/**
 * @brief this function returns the contact at index [index]
 * inside the PhoneBook object's contact array
 * or an empty Contact object if [index] is out of bound.
 * 
 * @param index 
 * @return Contact 
 */
Contact			PhoneBook::get_contact(unsigned int index)
{
	if (index <= PHONEBOOK_MAX_CONTACTS)
	{
		return (this->contacts[index]);
	}
	else
		return Contact();
}

unsigned int	PhoneBook::get_next_index(void)
{
	return (this->next_index);
}

void			PhoneBook::set_next_index(unsigned int new_val)
{
	if (new_val <= PHONEBOOK_MAX_CONTACTS)
		this->next_index = new_val;
}