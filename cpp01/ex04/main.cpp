/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:01:22 by dgerguri          #+#    #+#             */
/*   Updated: 2023/11/29 17:53:11 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <iostream>
// #include <fstream>
// #include <sstream>
// #include <string.h>
// #include <errno.h>

// bool	openFiles(std::ifstream *in_file, std::ofstream *out_file,
// 		std::string infile, std::string outfile, std::string *file)
// {
// 	std::stringstream 	buffer;
// 	in_file->open( infile.c_str(), std::ifstream::in);
// 	if ( !in_file->good() )
// 	{
// 		std::cerr << "Error: " << strerror(errno) << std::endl;
// 		return (false);
// 	}
// 	out_file->open( outfile.c_str(), std::ofstream::out | std::ofstream::trunc);
// 	if ( !out_file->good() )
// 	{
// 		in_file->close();
// 		std::cerr << "Error: " << strerror(errno) << std::endl;
// 		return (false);
// 	}
// 	buffer << in_file->rdbuf();
// 	*file = buffer.str();
// 	return (true);
// }

// bool	writeReplaceContent(std::string *file, std::ofstream *out_file,
// 	std::string findWord, std::string replaceWithWord)
// {
// 	std::string	modified;
// 	size_t		found = 0;
// 	size_t		end = 0;

// 	while (file->find(findWord, found) != file->npos) {
// 		modified = modified + file->substr(end, found - end);
// 		modified = modified + replaceWithWord;
// 		end = found + findWord.length();
// 	}
// 	modified = modified + file->substr(end);
// 	 out_file.write(file[end], file.length() - end);
// 	return (true);
// }

// int	main(int argc, char **argv) {
// 	std::ifstream	in_file;
// 	std::ofstream	out_file;
// 	std::string		file;
// 	std::string		outfile = argv[1];
// 	outfile.append(".replace");

// 	if (argc == 4) {
// 		if (!openFiles(&in_file, &out_file, argv[1], outfile, &file))
// 			return (1);
// 		if (!writeReplaceContent(&file, &out_file, argv[2], argv[3])) {
// 			in_file.close();
// 			out_file.close();
// 			return (1);
// 		}
// 		in_file.close();
// 		out_file.close();
// 		return (0);
// 	}
// 	std::cerr	<< "Usage: " << argv[0] << " <filename> <str_to_replace>"
// 				<< " <replacement_str>" << std::endl;
// 	return (1);
// }


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

bool openFiles(std::ifstream* in_file, std::ofstream* out_file,
               const std::string& infile, const std::string& outfile, std::string* file) {
    std::ifstream& in = *in_file;
    std::ofstream& out = *out_file;

    in.open(infile.c_str());
    if (!in.is_open()) {
        std::cerr << "Error opening input file: " << infile << std::endl;
        return (false);
    }

    out.open(outfile.c_str());
    if (!out.is_open()) {
        in.close();
        std::cerr << "Error opening output file: " << outfile << std::endl;
        return (false);
    }

    std::stringstream buffer;
    buffer << in.rdbuf();
    *file = buffer.str();

    return (true);
}

bool writeReplaceContent(std::string* file, std::ofstream& out_file,
                         const std::string& findWord, const std::string& replaceWithWord) {
    size_t found = 0;
    size_t end = 0;
    std::string& content = *file;

    while (content.find(findWord, found) != std::string::npos) {
        found = content.find(findWord, found);
        out_file.write(&content[end], found - end);
        out_file << replaceWithWord;
        found += findWord.length();
        end = found;
    }

    out_file.write(&content[end], content.length() - end);

    return (true);
}

int main(int argc, char** argv) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <filename> <str_to_replace> <replacement_str>" << std::endl;
        return (1);
    }

    std::ifstream in_file;
    std::ofstream out_file;

    std::string file;
    std::string outfile = argv[1];
    outfile.append(".replace");

    if (!openFiles(&in_file, &out_file, argv[1], outfile, &file))
        return (1);

    if (!writeReplaceContent(&file, out_file, argv[2], argv[3])) {
        in_file.close();
        out_file.close();
        return (1);
    }

    in_file.close();
    out_file.close();
    return (0);
}

