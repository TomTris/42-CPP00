/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 09:38:46 by qdo               #+#    #+#             */
/*   Updated: 2024/05/21 10:27:13 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	_index = 0;
	_full = 0;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "\nBye Bye" << std::endl;
}

std::string rightAlign(std::string str)
{
    std::string::iterator	iter;
    std::string				ret = "";
    int						i;

    if (str.length() > 10)
    {
        i = 9;
        iter = str.begin();
        while (--i >= 0)
        {
            ret.push_back(*iter);
            iter++;
        }
		ret.push_back('.');
        return (ret);
    }
    if (str.length() <= 10)
    {
        i = 10 - str.length();
        while (--i >= 0)
            str.insert(str.begin(), ' ');
        return str;
    }
    std::cout << "sth wrong ft_convert_string" << std::endl;
    return ("");
}

std::string getInput(std::string str)
{
	std::string	input;

	while (1)
	{
		std::cout << str << ": " << std::ends;
		if (std::getline(std::cin, input))
		{
			input = actualString(input);
			if (countWords(input) == 0)
				std::cout << "It's empty -.-" << std::endl;
			else
				return (input);
		}
		else
			break ;
		std::cout << "Please try again!" << std::endl;
	}
	return ("");
}

bool	PhoneBook::add(void)
{
	std::string first = "", last = "", nick = "", phone = "", secret = "";

	first = getInput("First Name");
	if (first == "")
		return (false);
	last = getInput("Last Name");
	if (last == "")
		return (false);
	nick = getInput("Nickname");
	if (nick == "")
		return (false);
	phone = getInput("Phone Number");
	if (phone == "")
		return (false);
	secret = getInput("Darkest Secret");
	if (secret == "")
		return (false);
	_contacts[_index] = Contact(first, last, nick, phone, secret);
	_index = (++_index) % 8;
	if (_index == 0)
		_full = 1;
	return (true);
}

void	PhoneBook::search(void)
{
	int	i;
	int	j;

	if (_index == 0 && _full == 0)
	{
		std::cout << "It's not nice to check search when you haven't added anything yet =.=" << std::endl;
		return ;
	}
	j = 8;
	if (_full == 0)
		j = _index;
	i = 0;
	while (i < j)
	{
		std::cout << rightAlign(_contacts[i].getFirst());
		std::cout << "|" << rightAlign(_contacts[i].getLast());
		std::cout << "|" << rightAlign(_contacts[i].getNick());
		std::cout << "|" << rightAlign(_contacts[i].getPhone());
		std::cout << "|" << rightAlign(_contacts[i].getSecret()) << std::endl;
		i++;
	}
	return ;
}
