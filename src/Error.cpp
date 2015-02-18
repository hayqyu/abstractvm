//
// Error.cpp for abstractvm in /home/voinne_c/rendu/cpp_abstractvm
// 
// Made by Cédric Voinnet
// Login   <voinne_c@epitech.net>
// 
// Started on  Wed Feb 18 09:32:25 2015 Cédric Voinnet
// Last update Wed Feb 18 09:54:35 2015 Cédric Voinnet
//

#include <string>
#include "Error.hh"

Error::Error(std::string const &message):
  _message(message)
{
}

Error::~Error() throw()
{
}

const char *Error::what() const throw()
{
  return (this->_message.c_str());
}
