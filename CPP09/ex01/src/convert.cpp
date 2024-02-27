#include "../inc/main.hpp"

int convert (std::string str)
{
    std::stringstream ss;
    int out = 0;
    if (str.find_first_not_of("0123456789") != std::string::npos)
        throw std::runtime_error ("Incorrect syntaxis.");
    ss << str;
    ss >> out;
    return out;
}