//
// Int8.cpp for abstractvm in /home/voinne_c/rendu/cpp_abstractvm/src
// 
// Made by Cédric Voinnet
// Login   <voinne_c@epitech.net>
// 
// Started on  Mon Feb  9 16:57:11 2015 Cédric Voinnet
// Last update Wed Feb 11 09:17:20 2015 julien gazzola
//

#include <sstream>
#include "Int8.hh"
#include "IOperand.hh"

Int8::Int8(std::string value):
  _value(value.at(0)), _type(INT8)
{
}

Int8::Int8(Int8 const &other):
  _value(other._value), _type(other._type)
{
}

Int8     		&Int8::operator=(Int8 const &other)
{
  if (this != &other)
    {
      this->_value = other._value;
      this->_type = other._type;
    }
  return (*this);
}

Int8::~Int8()
{}

std::string const	&Int8::toString() const
{

}

int			Int8::getPrecision() const
{
  return (sizeof(this->_value));
}

double			Int8::getValue() const
{
  return (this->_value);
}

eOperandType		Int8::getType() const
{
  return (this->_type);
}

IOperand		*Int8::operator+(const IOperand::IOperand &rhs)
{
  //return (this->_value + ?);
}

IOperand		*Int8::operator-(const IOperand::IOperand &rhs)
{
  //return (this->_value - ?);
}

IOperand		*Int8::operator*(const IOperand::IOperand &rhs)
{
  //return (this->_value * ?);
}

IOperand		*Int8::operator/(const IOperand::IOperand &rhs)
{
  //?
}

IOperand		*Int8::operator%(const IOperand::IOperand &rhs)
{
  
}
