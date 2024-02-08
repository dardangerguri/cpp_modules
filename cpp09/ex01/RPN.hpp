/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:06:49 by dgerguri          #+#    #+#             */
/*   Updated: 2024/02/08 17:50:37 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# define	GREEN	"\033[0;32m"
# define	RED		"\033[0;31m"
# define	BLUE	"\033[0;34m"
# define	YELLOW	"\033[0;33m"
# define	RESET	"\033[0m"


# include <iostream>
# include <list>
# include <cctype>

class RPN {

	public:

		RPN(std::string input);
		~RPN(void);

	private:

		RPN(void);
		RPN(RPN const &copy);
		RPN &operator=(RPN const &src);

		void	validateInputandFillContainer(std::string &input);
		void	insertSpace(std::string &input);
		void	fillContainer(std::string &value);

		std::list<int> arguments;

};

# endif
