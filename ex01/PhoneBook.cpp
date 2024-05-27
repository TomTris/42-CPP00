/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 09:38:46 by qdo               #+#    #+#             */
/*   Updated: 2024/05/27 03:09:33 by qdo              ###   ########.fr       */
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

void	PhoneBook::printIndex(int i)
{
	std::cout <<rightAlign(std::to_string(i + 1));
	std::cout << "|" << rightAlign(_contacts[i].getFirst());
	std::cout << "|" << rightAlign(_contacts[i].getLast());
	std::cout << "|" << rightAlign(_contacts[i].getNick()) << std::endl;
}

int	PhoneBook::searchIndex(void)
{
	std::string				input = "";
	std::string::iterator	ite;
	int						i;

	std::cout << "Which contact index you wanna check? Or type 'STOP' to get out" << std::endl;
	while (1)
	{
		if (std::getline(std::cin, input))
		{
			input = actualString(input);
			ite = input.begin();
			if ((input.length() != 1 && input.length() != 4) || *ite < '0'  || *ite >= '8')
			{
				if (input.length() == 4 && input == "STOP")
					return (1);
				std::cout << "Not valid, try again" << std::endl;
				std::cout << "Which contact index you wanna check? Or type 'STOP' to get out" << std::endl;
			}
			else
			{
				if ((_full == 1 && *ite >= '0' && *ite <= '7')
					|| (_full == 0 && *ite >= '0' && *ite - '0' <= _index - 1))
				{
					i = *ite - '0';
					std::cout <<rightAlign(std::to_string(i + 1));
					std::cout << "|" << rightAlign(_contacts[i].getFirst());
					std::cout << "|" << rightAlign(_contacts[i].getLast());
					std::cout << "|" << rightAlign(_contacts[i].getNick());
					std::cout << "|" << rightAlign(_contacts[i].getPhone());
					std::cout << "|" << rightAlign(_contacts[i].getSecret()) << std::endl;
				}
				else
				{
					std::cout << "Not valid, try again" << std::endl;
					std::cout << "Which contact index you wanna check? Or type 'STOP' to get out" << std::endl;
				}
			}
		}
		else
			return (0);
	}
	std::cout << "Sth wrong with searchIndex" << std::endl;
	return (0);
}

int	PhoneBook::search(void)
{
	int	i;
	int	j;

	if (_index == 0 && _full == 0)
	{
		std::cout << "It's not nice to check search when you haven't added anything yet =.=" << std::endl;
		return (1);
	}
	j = 8;
	if (_full == 0)
		j = _index;
	i = 0;

	std::cout << "-------------------------------------------" << std::endl;
	std::cout << rightAlign("  Index   ");
	std::cout << "|" << rightAlign(" FirstName");
	std::cout << "|" << rightAlign(" LastName ");
	std::cout << "|" << rightAlign(" NickName ") << std::endl;
	std::cout << rightAlign("----------");
	std::cout << "|" << rightAlign("----------");
	std::cout << "|" << rightAlign("----------");
	std::cout << "|" << rightAlign("----------") << std::endl;
	while (i < j)
	{
		std::cout <<rightAlign(std::to_string(i));
		std::cout << "|" << rightAlign(_contacts[i].getFirst());
		std::cout << "|" << rightAlign(_contacts[i].getLast());
		std::cout << "|" << rightAlign(_contacts[i].getNick()) << std::endl;
		i++;
	}
	std::cout << "-------------------------------------------" << std::endl;
	return	(this->searchIndex());
}
