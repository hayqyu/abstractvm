//
// Double.cpp for Double in /home/gazzol_j/rendu/abstractvm/src
// 
// Made by julien gazzola
// Login   <gazzol_j@epitech.net>
// 
// Started on  Tue Feb 10 11:26:18 2015 julien gazzola
// Last update Wed Feb 11 13:05:16 2015 julien gazzola
//

#include <sstream>
#include "Double.hh"
#include "IOperand.hh"

Double::Double(std::string value) :
  _value(value), _type(DOUBLE)
{}

Double::Double(Double const &other):
  _value(other._value), _type(other._type)
{
}

Double     		&Double::operator=(Double const &other)
{
  if (this != &other)
    {
      this->_value = other._value;
      this->_type = other._type;
    }
  return (*this);
}

Double::~Double()
{}

std::string const	&Double::toString() const
{

}

int			Double::getPrecision() const
{
  return (sizeof(this->_value));
}

eOperandType		Double::getType() const
{
  return (this->_type);
}

IOperand		*Double::operator+(const IOperand::IOperand &rhs) const
{
  //return (this->_value + ?);
}

IOperand		*Double::operator-(const IOperand::IOperand &rhs) const
{
  //return (this->_value - ?);
}

IOperand		*Double::operator*(const IOperand::IOperand &rhs) const
{
  //return (this->_value * ?);
}

IOperand		*Double::operator/(const IOperand::IOperand &rhs) const
{
  //?
}

IOperand		*Double::operator%(const IOperand::IOperand &rhs) const
{
  
}

