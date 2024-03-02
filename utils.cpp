//File is used for improving the functionality of other classes

#include "utils.h"
#include <algorithm>
#include <cctype> 

std::string toLowerCase(const std::string& str) {
    std::string lowerCaseStr = str;
    std::transform(lowerCaseStr.begin(), lowerCaseStr.end(), lowerCaseStr.begin(),
        [](unsigned char c) { return std::tolower(c); });
    return lowerCaseStr;
}

std::string trim(const std::string& str) {

    // Remove leading whitespace
    size_t start = str.find_first_not_of(" \t\n\r");
    if (start == std::string::npos) {
        std::string result = "";
        return result;
    }

    std::string result = str.substr(start);

    // Remove trailing whitespace
    size_t end = result.find_last_not_of(" \t\n\r");
    if (end == std::string::npos) {
        result = "";
        return result;
    }
    result = result.substr(0, end + 1);
    return result;
}