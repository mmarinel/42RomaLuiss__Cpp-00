/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 10:09:48 by mmarinel          #+#    #+#             */
/*   Updated: 2022/08/18 11:23:27 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

static void	megaphone(const char *sentence);
//* end of static declaration

int main(int argc, char const *argv[])
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (1);
	}
	else
	{
		for (int i = 1; i < argc; i++)
			megaphone(argv[i]);
		std::cout << std::endl;
		return (0);
	}
}

static void	megaphone(const char *sentence)
{
	int	i;

	i = 0;
	while (sentence[i])
	{
		std::cout << (char) ::toupper(sentence[i]);
		i++;
	}
}
