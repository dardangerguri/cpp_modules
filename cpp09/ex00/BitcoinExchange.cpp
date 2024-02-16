/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dardangerguri <dardangerguri@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:06:49 by dgerguri          #+#    #+#             */
/*   Updated: 2024/02/16 09:42:05 by dardangergu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) {
		loadDataFromFile();
}

BitcoinExchange::~BitcoinExchange(void) {
}

time_t	BitcoinExchange::convertStringToTimeT(std::string date) {
	std::tm tm = {};
    std::istringstream ss(date);
    ss >> std::get_time(&tm, "%Y-%m-%d");
    if (ss.fail())
        return -1;
    time_t t = mktime(&tm);
	std::string const temp_date = convertTimeTToDate(t);
	if (temp_date.compare(date))
		return (-1);
	return t;
}

double BitcoinExchange::convertStringToDouble(std::string value) {
	if (value.empty() || std::count(value.begin(), value.end(), '.') > 1 ||
		std::count(value.begin(), value.end(), '-') > 1 ||
		!std::all_of(value.begin(), value.end(), [](char c) { return std::isdigit(c) || c == '.' || c == '-';}))
		return (-2);
	double result = std::stod(value);
	if (result < 0)
		return (-1);
	return (result);
}

std::string	BitcoinExchange::convertTimeTToDate(time_t date) {
	char buffer[80];
	strftime(buffer, 80, "%Y-%m-%d", localtime(&date));
	return buffer;
}

void	BitcoinExchange::displayBitcoinValue(time_t date, double value) {
		std::map<time_t, double>::iterator closestDate = exchangeRatesByDates.lower_bound(date);
			double closestValue = std::prev(closestDate)->second;
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

void	BitcoinExchange::calculateBitcoinValue(char *filename) {
		std::ifstream file(filename);
		if (!file.is_open())
			throw BitcoinExchange::InvalidFile();
		std::string line;
		std::getline(file, line);
		if (line.compare("date | value") != 0)
			std::cout << RED "Warning: the file title is not correct." RESET << std::endl;
		while (std::getline(file, line)) {
			time_t date = convertStringToTimeT(line.substr(0, line.find(" |")));
			double value = convertStringToDouble(line.substr(line.find("|") + 1));
			std::cout << GREEN << value << RESET << std::endl;
			if (date != -1 && value != -2)
				displayBitcoinValue(date, value);
			else if (date == -1)
				std::cout << RED "Error: bad input => " << line.substr(0, line.find(" |")) << RESET << std::endl;
			else
				std::cout << RED "Error: bad input => " << line.substr(line.find("|") + 1) << RESET << std::endl;
		}
		file.close();
}

void	BitcoinExchange::loadDataFromFile(void) {

	try {
		std::ifstream file("data.csv");
		if (!file.is_open())
			throw BitcoinExchange::InvalidFile();

		std::string line;
		std::getline(file, line);
		if (line.compare("date,exchange_rate") != 0)
			throw BitcoinExchange::InvalidFile();
		while (std::getline(file, line)) {
			time_t date = convertStringToTimeT(line.substr(0, line.find(",")));
			if (date == -1)
				throw BitcoinExchange::InvalidFile();
			double value = std::stod(line.substr(line.find(",") + 1));
			if (value == -1)
				throw BitcoinExchange::InvalidFile();
			exchangeRatesByDates.insert(std::pair<time_t, double>(date, value));
		}
		file.close();
	}
	catch (std::exception & e) {
		throw BitcoinExchange::InvalidFile();
	}
}

char const *BitcoinExchange::InvalidFile::what() const throw() {
	return (RED "Error: could not open file." RESET);
}
