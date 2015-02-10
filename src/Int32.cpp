//
// Int32.cpp for Int32 in /home/gazzol_j/rendu/abstractvm/src
// 
// Made by julien gazzola
// Login   <gazzol_j@epitech.net>
// 
// Started on  Tue Feb 10 11:22:56 2015 julien gazzola
// Last update Tue Feb 10 11:24:20 2015 julien gazzola
//

#include <sstream>
#include "Int32.hh"
#include "IOperand.hh"

Int32::Int32(std::string value):
  _value(value.at(0)), _type(IOperand::eOperandType::Int32)
{
}

Int32::Int32(Int32 const &other):
  _value(other._value), _type(other._type)
{
}

Int32			&Int8::operator=(Int32 const &other)
{
  if (this != &other)
    {
      this->_value = other._value;
      this->_type = other._type;
    }
  return (*this);
}

Int32::~Int32()
{
}

std::string const	&Int32::toString() const
{

}

int			Int32::getPrecision() const
{
  return (sizeof(this->_value));
}

IOperand::eOperandType	Int32::getType() const
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
