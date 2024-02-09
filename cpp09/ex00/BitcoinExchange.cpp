/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:06:49 by dgerguri          #+#    #+#             */
/*   Updated: 2024/02/09 16:41:38 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/************ Constructor and Destructor ************/

BitcoinExchange::BitcoinExchange(void) {
	try {
		loadDataFromFile();
		// displayData(); //delete
	}
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}
}

BitcoinExchange::~BitcoinExchange(void) {
}


time_t	BitcoinExchange::convertDateToTimeT(std::string date) {
	struct tm tm;
	strptime(date.c_str(), "%Y-%m-%d", &tm);
	time_t t = mktime(&tm);
	std::cout << t << std::endl;
	return t;
}

std::string	BitcoinExchange::convertTimeTToDate(time_t date) {
	char buffer[80];
	strftime(buffer, 80, "%Y-%m-%d", localtime(&date));
	return buffer;
}


void	BitcoinExchange::displayValue(time_t date, double value) {
		time_t closestDate = 0;
		double closestValue = 0;
		for (auto it = exchangeRatesByDates.begin(); it != exchangeRatesByDates.end(); it++) {
			if (it->first >= date) {
				if (it->first != date)
					it--;
				closestDate = it->first;
				closestValue = it->second;
				break;
			}
		}
		if (value > 0 && value < 1000) {
			std::cout << convertTimeTToDate(date) << " => " << value << " = " << closestValue * value << std::endl;
		}
		else if (value <= 0) {
			std::cerr << RED "Error: not a positive number." RESET << std::endl;
		}
		else if (value >= 1000) {
			std::cerr << RED "Error: too large a number." RESET << std::endl;
		}
}

void	BitcoinExchange::valueOfBitcoin(char *filename) {
	std::ifstream file(filename);
	if (!file.is_open())
		throw BitcoinExchange::InvalidFile();
	std::string line;
	std::getline(file, line);
	while (std::getline(file, line)) {
		time_t date = convertDateToTimeT(line.substr(0, line.find(" |")));
		double value = std::stod(line.substr(line.find("|") + 1));
		if (date != -1)
			displayValue(date, value);
		else
			std::cerr << RED "Error: invalid date." RESET << std::endl;
		}
	}



void	BitcoinExchange::loadDataFromFile(void) {

	std::ifstream file("data.csv");
	if (!file.is_open())
		throw BitcoinExchange::InvalidFile();

	std::string line;
	std::getline(file, line);
	while (std::getline(file, line)) {
		time_t date = convertDateToTimeT(line.substr(0, line.find(",")));
		if (date == -1)
			std::cerr << RED "Error: invalid date." RESET << std::endl;
		double value = std::stod(line.substr(line.find(",") + 1));
		exchangeRatesByDates.insert(std::pair<time_t, double>(date, value));
	}
	file.close();
}

/************ Exceptions ************/

char const *BitcoinExchange::InvalidFile::what() const throw() {
	return (RED "Error: could not open file." RESET);
}

/********************DELETE************************/

void	BitcoinExchange::displayData(void) {
	for (auto it = exchangeRatesByDates.begin(); it != exchangeRatesByDates.end(); it++) {
		std::cout << it->first << " : " << it->second << std::endl;
	}
}
