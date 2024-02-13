/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:06:49 by dgerguri          #+#    #+#             */
/*   Updated: 2024/02/13 14:07:41 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# define	GREEN	"\033[0;32m"
# define	RED		"\033[0;31m"
# define	BLUE	"\033[0;34m"
# define	YELLOW	"\033[0;33m"
# define	RESET	"\033[0m"


# include <iostream>
# include <fstream>
# include <map>
# include <string>
# include <sstream>

class BitcoinExchange {

	public:

		BitcoinExchange(void);
		~BitcoinExchange(void);

		void	calculateBitcoinValue(char *filename);

		class InvalidFile : public std::exception {
			public:
				virtual const char *what() const throw();
		};

	private:

		BitcoinExchange(BitcoinExchange const & copy);
		BitcoinExchange & operator=(const BitcoinExchange & copy);

		std::map<time_t, double>exchangeRatesByDates;

		void		loadDataFromFile(void);
		time_t		convertStringToTimeT(std::string date);
		std::string	convertTimeTToDate(time_t date);
		void		displayBitcoinValue(time_t date, double value);
};

# endif
