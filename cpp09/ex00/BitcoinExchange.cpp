/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dardangerguri <dardangerguri@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:06:49 by dgerguri          #+#    #+#             */
/*   Updated: 2024/02/09 11:21:19 by dardangergu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/************ Constructor and Destructor ************/

BitcoinExchange::BitcoinExchange(void) {
	try {
		loadDataFromFile();
		displayData(); //delete
	}
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}
}

BitcoinExchange::~BitcoinExchange(void) {
}

/********************DELETE************************/

void	BitcoinExchange::displayData(void) {
	for (std::map<time_t, double>::iterator it = exchangeRatesByDates.begin(); it != exchangeRatesByDates.end(); it++) {
		std::cout << "Timestamp: " << it->first << " Value: " << it->second << std::endl;
	}
}

/************ Public Member functions ************/

// void	BitcoinExchange::exchange(char *filename) {
// 	std::ifstream file(filename);
// 	if (!file.is_open())
// 		throw BitcoinExchange::InvalidFile();

// }



/************ Private Member functions ************/

void	BitcoinExchange::loadDataFromFile(void) {

	std::ifstream file("data.csv");
	if (!file.is_open())
		throw BitcoinExchange::InvalidFile();

    std::string line;
	std::getline(file, line);
    while (std::getline(file, line)) {
        std::string timestampStr = line.substr(0, line.find(","));
        std::string valueStr = line.substr(line.find(",") + 1);

        char* end;
        time_t timestamp = static_cast<time_t>(std::strtod(timestampStr.c_str(), &end));
        if (end == timestampStr.c_str()) {
            throw std::invalid_argument("Invalid timestamp in data file");
        }

        double value = std::strtod(valueStr.c_str(), &end);
        if (end == valueStr.c_str()) {
            throw std::invalid_argument("Invalid value in data file");
        }

        exchangeRatesByDates.insert(std::pair<time_t, double>(timestamp, value));
    }

    file.close();
}

/************ Exceptions ************/

char const *BitcoinExchange::InvalidFile::what() const throw() {
	return (RED "Error: could not open file." RESET);
}