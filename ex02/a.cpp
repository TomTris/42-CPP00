/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 02:18:49 by qdo               #+#    #+#             */
/*   Updated: 2024/05/26 03:15:13 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int	main(void)
{
	std::time_t	now = std::time(nullptr);
	std::tm*	localTime = std::localtime(&now);
	
	std::cout << "[" << localTime->tm_year + 1900
		<< std::setw(2) << std::setfill('0') << localTime->tm_mon
		<< std::setw(2) << std::setfill('0') << localTime->tm_mday << "_"
		<< std::setw(2) << std::setfill('0') << localTime->tm_hour
		<< std::setw(2) << std::setfill('0') << localTime->tm_min
		<< std::setw(2) << std::setfill('0') << localTime->tm_sec << "] " << std::endl;
}
