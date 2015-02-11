//
// Float.cpp for Float in /home/gazzol_j/rendu/abstractvm/src
// 
// Made by julien gazzola
// Login   <gazzol_j@epitech.net>
// 
// Started on  Tue Feb 10 11:24:32 2015 julien gazzola
// Last update Wed Feb 11 12:55:15 2015 julien gazzola
//

#include <string>
#include <sstream>
#include "Float.hh"
#include "IOperand.hh"

Float::Float(std::string value) :
  _value(value), _type(FLOAT)
{}

Float::Float(Float const &other):
  _value(other._value), _type(other._type)
{
}

Float     		&Float::operator=(Float const &other)
{
  if (this != &other)
    {
      this->_value = other._value;
      this->_type = other._type;
    }
  return (*this);
}

Float::~Float()
{}

std::string const	&Float::toString() const
{
  
}

int			Float::getPrecision() const
{
  return (sizeof(this->_value));
}

eOperandType		Float::getType() const
{
  return (this->_type);
}

IOperand		*Float::operator+(const IOperand::IOperand &rhs)
{
  //return (this->_value + ?);
}

IOperand		*Float::operator-(const IOperand::IOperand &rhs)
{
  //return (this->_value - ?);
}

IOperand		*Float::operator*(const IOperand::IOperand &rhs)
{
  //return (this->_value * ?);
}

IOperand		*Float::operator/(const IOperand::IOperand &rhs)
{
  //?
}

IOperand		*Float::operator%(const IOperand::IOperand &rhs)
{
  
}

