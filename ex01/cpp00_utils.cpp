/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpp00_utils.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 12:49:57 by earendil          #+#    #+#             */
/*   Updated: 2022/08/18 15:52:03 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cpp00_utils.hpp"

bool	str_is_alpha(const char *str)
{
	size_t	i;
	
	i = 0;
	while (str[i])
	{
		if (false == std::isalpha(str[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	str_is_digit(const char *str)
{
	size_t	i;
	
	i = 0;
	while (str[i])
	{
		if (false == std::isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}
