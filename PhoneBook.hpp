/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 07:50:18 by qdo               #+#    #+#             */
/*   Updated: 2024/05/20 08:20:24 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>

class Contact
{
private:
	std::string	firstName;
	std::string	lastName;
	std::string	nickName;
	std::string	phoneNumber;
	std::string	darkestSecret;

public:
	Contact(std::string first, std::string last, std::string nick, std::string phone, std::string secret):
		firstName(first), lastName(last), nickName(nick), phoneNumber(phone), darkestSecret(secret) {}
	
	std::string	getFrist() 	{return (firstName);}
	std::string getLast() {return (lastName);}
	std::string getNick() {return (nickName);}
	std::string getPhone() {return (phoneNumber);}
	std::string getSecret() {return (darkestSecret);}
}

#endif