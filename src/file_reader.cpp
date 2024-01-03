#include "../include/file_reader.h"

#include <fstream>
#include <iostream>
#include <regex>

#define RESET         "\033[0m"
#define BRIGHT_RED    "\033[91m"
#define BRIGHT_YELLOW "\033[93m"

std::vector<std::string> getFileLines(const std::string &filePath) {
    std::ifstream file(filePath);
    std::vector<std::string> lines;
    if (!file.is_open()) {
        std::cerr << BRIGHT_RED << "Cannot find file '" << filePath << "'" << RESET << std::endl; 
        return lines;
    }
    std::string line;
    while (std::getline(file, line)) {
        lines.push_back(line);
    }
    file.close();
    if (lines.size() == 0)
        std::cerr << BRIGHT_RED << "File is empty" << RESET << std::endl;
    return lines;
}

std::vector<std::pair<std::string, std::string>> regexMatch(const std::vector<std::string> &lines, std::string regexPattern) {
    std::regex pattern(regexPattern);
    std::vector<std::pair<std::string, std::string>> matches;
    std::smatch match;
    for (const std::string &line : lines) {
        if (std::regex_search(line, match, pattern)) {
            matches.push_back(std::make_pair(match.str(), line));
        }
    }
    if (matches.size() == 0)
        std::cerr << BRIGHT_RED << "No matches" << RESET << std::endl;;
    return matches;
}