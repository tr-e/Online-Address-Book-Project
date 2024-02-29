//File is used for improving the functionality of other classes

#include "utils.h"
#include <algorithm>
#include <cctype> 


/*
  Helper function to convert string to lowercase

  Precondition: A valid string must be passed as a parameter

  Postcondition: The string is converted to lowercase
*/
std::string toLowerCase(const std::string& str) {
    std::string lowerCaseStr = str;
    std::transform(lowerCaseStr.begin(), lowerCaseStr.end(), lowerCaseStr.begin(),
        [](unsigned char c) { return std::tolower(c); });
    return lowerCaseStr;
}

/*
  Trims the leading and trailing whitespaces from a string

  Precondition: A valid string must be passed as a parameter

  Postcondition: The leading and trailing whitespaces are trimmed from the string
*/
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