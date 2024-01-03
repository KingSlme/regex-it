#pragma once

#include <vector>
#include <utility>
#include <string>

std::vector<std::string> getFileLines(const std::string &filePath);

std::vector<std::pair<std::string, std::string>> regexMatch(const std::vector<std::string> &lines, std::string regexPattern);