//
// Int16.cpp for Int16 in /home/gazzol_j/rendu/abstractvm/src
// 
// Made by julien gazzola
// Login   <gazzol_j@epitech.net>
// 
// Started on  Tue Feb 10 11:19:37 2015 julien gazzola
// Last update Tue Feb 10 15:34:50 2015 julien gazzola
//

#include <sstream>
#include "Int16.hh"
#include "IOperand.hh"

Int16::Int16(std::string value):
  _value(value.at(0)), _type(int16)
{
}

Int16::Int16(Int16 const &other):
  _value(other._value), _type(other._type)
{
}

Int16     		&Int16::operator=(Int16 const &other)
{
  if (this != &other)
    {
      this->_value = other._value;
      this->_type = other._type;
    }
  return (*this);
}

Int16::~Int16()
{}

std::string const	&Int16::toString() const
{

}

int			Int16::getPrecision() const
{
  return (sizeof(this->_value));
}

char			Int16::getValue() const
{
  return (this->_value);
}

eOperandType		Int16::getType() const
{
  return (this->_type);
}

IOperand		*Int16::operator+(const IOperand::IOperand &rhs)
{
  //return (this->_value + ?);
}

IOperand		*Int16::operator-(const IOperand::IOperand &rhs)
{
  //return (this->_value - ?);
}

IOperand		*Int16::operator*(const IOperand::IOperand &rhs)
{
  //return (this->_value * ?);
}

IOperand		*Int16::operator/(const IOperand::IOperand &rhs)
{
  //?
}

IOperand	*Int16::operator%(const IOperand::IOperand &rhs)
{
  
}
