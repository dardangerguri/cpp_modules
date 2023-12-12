/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:12:47 by dgerguri          #+#    #+#             */
/*   Updated: 2023/12/12 17:46:55 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include <sstream>
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
		int				checkInt(std::string str);
		void			Trimmed(std::string str);

	public:
		PhoneBook(void);
		~PhoneBook(void);

		bool	AddContact(void);
		bool	SearchContact(void);
};

# endif
