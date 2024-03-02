//utils.h
#pragma once 
#include <string> 

/*
  Helper function to convert string to lowercase

  Precondition: A valid string must be passed as a parameter

  Postcondition: The string is converted to lowercase
*/
std::string toLowerCase(const std::string& str);


/*
  Trims the leading and trailing whitespaces from a string

  Precondition: A valid string must be passed as a parameter

  Postcondition: The leading and trailing whitespaces are trimmed from the string
*/
std::string trim(const std::string& str);