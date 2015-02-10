//
// Float.cpp for Float in /home/gazzol_j/rendu/abstractvm/src
// 
// Made by julien gazzola
// Login   <gazzol_j@epitech.net>
// 
// Started on  Tue Feb 10 11:24:32 2015 julien gazzola
// Last update Tue Feb 10 11:26:05 2015 julien gazzola
//

#include <sstream>
#include "Float.hh"
#include "IOperand.hh"

Float::Float(std::string value):
  _value(value.at(0)), _type(IOperand::eOperandType::Float)
{
}

Float::Float(Float const &other):
  _value(other._value), _type(other._type)
{
}

Float			&Float::operator=(Float const &other)
{
  if (this != &other)
    {
      this->_value = other._value;
      this->_type = other._type;
    }
  return (*this);
}

Float::~Float()
{
}

std::string const	&Float::toString() const
{

}

int			Float::getPrecision() const
{
  return (sizeof(this->_value));
}

IOperand::eOperandType	Float::getType() const
{
  return (this->_type);
}

IOperand::IOperand	*operator+(const IOperand::IOperand &rhs)
{
  
}

IOperand::IOperand	*operator-(const IOperand::IOperand &rhs)
{
}

IOperand::IOperand	*operator*(const IOperand::IOperand &rhs)
{
}

IOperand::IOperand	*operator/(const IOperand::IOperand &rhs)
{
}

IOperand::IOperand	*operator%(const IOperand::IOperand &rhs)
{
}
