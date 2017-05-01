#include <string>
#include <sstream>
#include <iostream>
#include "include/helpers.hpp"

std::string numToString (long l) {
	std::stringstream ss;
    ss << l;
    std::string newString = ss.str();
	return newString;
}