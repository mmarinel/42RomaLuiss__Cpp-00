/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 11:47:56 by mmarinel          #+#    #+#             */
/*   Updated: 2022/08/18 18:03:38 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.hpp"
# include "cpp00_utils.hpp"
# include <string>
# include <cstdio>
# include <cstdlib>
# include <iostream>
# include <iomanip>


# ifndef PHONEBOOK_MAX_CONTACTS
#  define PHONEBOOK_MAX_CONTACTS 8
# endif

# ifndef PHONEBOOK_MAX_WIDTH
#  define PHONEBOOK_MAX_WIDTH 10
# endif

class PhoneBook
{
private:
	Contact			contacts[PHONEBOOK_MAX_CONTACTS];
	unsigned int	next_index;
	bool			add_contact(void);
	bool			search_contact(void);
public:
					PhoneBook(void);
	bool			interpreter(std::string command);
	Contact			get_contact(unsigned int index);
	unsigned int	get_next_index(void);
	void			set_next_index(unsigned int new_val);
};

void	display_contact(Contact contact, std::string next_index_to_display);
void	set_cout_flags(void);
void	read_input(std::string& input_ref);
void	pb_bad_input(const char *msg);

#endif