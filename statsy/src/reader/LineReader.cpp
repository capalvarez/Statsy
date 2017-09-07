#include <statsy/reader/LineReader.h>

std::string LineReader::trim(std::string &s) {
    std::string trim_chars = "\t";
    std::string::size_type pos = s.find_last_not_of(trim_chars);

    if (pos != std::string::npos) {
        s.erase(pos + 1);
        pos = s.find_first_not_of(trim_chars);

        if(pos != std::string::npos){
            s.erase(0, pos);
        }
    } else{
        s.erase(s.begin(), s.end());
    }
}

std::vector<std::string> LineReader::split(std::string s, const std::regex regex) {
    std::vector<std::string> result;

    std::sregex_token_iterator it(s.begin(), s.end(), regex, -1 );
    std::sregex_token_iterator reg_end;

    for ( ; it != reg_end; ++it ) {
        if (!it->str().empty())
            result.emplace_back( it->str());
    }

    return result;
}

std::vector<std::string> LineReader::splitBySpaces(std::string s) {
    return split(s, std::regex("\\s+"));
}

std::vector<std::string> LineReader::getSplittedLine(std::string s) {
    return splitBySpaces(trim(s));
}
