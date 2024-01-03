#include "../include/argument_handler.h"

#include "../include/file_reader.h"
#include <iostream>

#define RESET         "\033[0m"
#define BRIGHT_RED    "\033[91m"
#define BRIGHT_YELLOW "\033[93m"

int handleArguments(int argc, char* argv[]) {
    if (argc == 4 && (std::string(argv[3]) == "words" || std::string(argv[3]) == "lines")) {
        std::vector<std::string> lines = getFileLines(argv[1]);
        if (lines.size() == 0)
            return 1;
        std::vector<std::pair<std::string, std::string>> matches = regexMatch(lines, argv[2]);
        if (matches.size() == 0)
            return 1;
        std::cout << BRIGHT_YELLOW << "\nMatches: " << RESET << std::endl;
        for (const std::pair<std::string, std::string> &match : matches)
            if (std::string(argv[3]) == "words")
                std::cout << match.first << std::endl;
            else
                std::cout << match.second << std::endl;
        return 0;
    } else {
        std::cerr << BRIGHT_RED << "Usage: <file path> <regex pattern> <words|lines>" << RESET << std::endl;
        return 1;
    }
}

