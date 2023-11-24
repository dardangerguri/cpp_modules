/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:17:35 by dgerguri          #+#    #+#             */
/*   Updated: 2023/11/24 17:58:35 by dgerguri         ###   ########.fr       */
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

};

# endif
