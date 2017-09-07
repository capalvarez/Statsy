#ifndef STATSY_LINEREADER_H
#define STATSY_LINEREADER_H

#include <string>
#include <vector>
#include <regex>

class LineReader {
public:
    static std::string trim(std::string& s);
    static std::vector<std::string> split(std::string s, const std::regex regex);
    static std::vector<std::string> splitBySpaces(std::string s);
    static std::vector<std::string> getSplittedLine(std::string s);
};

#endif