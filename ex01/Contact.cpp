/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 09:35:12 by qdo               #+#    #+#             */
/*   Updated: 2024/05/21 09:38:04 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string	Contact::getFirst(void) {return (firstName);}
std::string	Contact::getLast(void) {return (lastName);}
std::string	Contact::getNick(void) {return (nickName);}
std::string	Contact::getPhone(void) {return (phoneNumber);}
std::string	Contact::getSecret(void) {return (darkestSecret);}