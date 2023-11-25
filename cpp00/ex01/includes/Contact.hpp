/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dardangerguri <dardangerguri@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:17:35 by dgerguri          #+#    #+#             */
/*   Updated: 2023/11/24 23:24:30 by dardangergu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact {
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	secret;


	public:
		Contact(void);
		~Contact(void);

		void	SetName(std::string first_name);
		void	SetLastName(std::string last_name);
		void	SetNickname(std::string nickname);
		void	SetPhoneNumber(std::string phonenumber);
		void	SetSecret(std::string secret);
		std::string	GetFirstName(void);
		std::string	GetLastName(void);
		std::string	GetNickname(void);
		std::string	GetPhoneNumber(void);
		std::string	GetSecret(void);
};

# endif
