/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 09:41:59 by qdo               #+#    #+#             */
/*   Updated: 2024/05/21 10:23:07 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

std::string actualString(std::string str)
{
    std::string::iterator   iter;
    std::string             ret = "";
    bool                    pre_white_space = false;

    iter = str.begin();
    while (iter != str.end() && (*iter == ' ' || *iter == '\n'
        || *iter == '\t' || *iter == '\r' || *iter == '\v' || *iter == '\f'))
        iter++;
    while (iter != str.end())
    {
        if (*iter == ' ' || *iter == '\n' || *iter == '\t'
            || *iter == '\r' || *iter == '\v' || *iter == '\f')
            pre_white_space = true;
        else
        {
            if (pre_white_space == true)
            {
                pre_white_space = false;
                ret.push_back(' ');
            }
            ret.push_back(*iter);
        }
        iter += 1;
    }
    return ret;
}

int countWords(const std::string str)
{
    int                 cnt = 0;
    std::istringstream  iss(str);
    std::string         temp;

    while (iss >> temp)
        cnt++;
    return cnt;
}

int main(void)
{
    std::string input;
    PhoneBook   book;

    while (1)
    {
        std::cout << "You want ADD/SEARCH/EXIT? " << std::ends;
        if (!std::getline(std::cin, input))
            break ;
        else if (countWords(input) == 0)
            std::cout << "It's nothing -.-" << std::endl;
        else if (countWords(input) > 1)
            std::cout << "It's too many arguments!" << std::endl;
        else
        {
            input = actualString(input);
            if (input == "ADD")
            {
                if (book.add() == false)
                    return (0);
                std::cout << "Adding new contact successful!" << std::endl;
            }
            else if (input == "SEARCH")
                book.search();
            else if (input == "EXIT")
                return 0;
            else
                std::cout << "Please try again." << std::endl;
        }
    }
    return 1;
}

