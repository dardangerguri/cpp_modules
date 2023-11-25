/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dardangerguri <dardangerguri@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:12:47 by dgerguri          #+#    #+#             */
/*   Updated: 2023/11/26 00:15:57 by dardangergu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include "Contact.hpp"

# define	GREEN	"\033[0;32m"
# define	RED		"\033[0;31m"
# define	BLUE	"\033[0;34m"
# define	YELLOW	"\033[0;33m"
# define	RESET	"\033[0m"

class PhoneBook {
	private:
		Contact	contacts[8];
		int		index;
		bool	flag;

		std::string		GetInput(std::string prompt, int type);
		bool			ValidateInformation(std::string input, int type);
		void			DisplayContacts(void);
		bool			DisplayContactIndex(void);
		int				ft_atoi(std::string str);
		void			Trimmed(std::string str);

	public:
		PhoneBook(void);
		~PhoneBook(void);

		bool	AddContact(void);
		bool	SearchContact(void);
};

# endif
