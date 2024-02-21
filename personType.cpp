#include "personType.h"
#include <iostream>
using std::string;

personType::personType(string first, string last) : firstName(first), lastName(last) {}


void personType::setFirstName(string first) { firstName = first; }
void personType::setLastName(string last) { lastName = last; }


void personType::print() const { std::cout << firstName << " " << lastName; }