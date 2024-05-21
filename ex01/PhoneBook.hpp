/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 07:50:18 by qdo               #+#    #+#             */
/*   Updated: 2024/05/21 09:42:29 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <sstream>
# include <iostream>

class PhoneBook
{
private:
		Contact		_contacts[8];
		int			_index;
		int			_full;
	
public:
		PhoneBook(void);
		~PhoneBook(void);
		bool	add(void);
		void	search(void);
};

int			countWords(const std::string str);
std::string actualString(std::string str);

#endif