#include <iostream>
#include "exception.h"


Exception::Exception(std::string problem, std::string description)
{
  std::cerr <<"-- Problem: " << problem << std::endl;
  std::cerr <<"-- Description: " << description << std::endl ;
}
