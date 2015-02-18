//
// Calc.cpp for calc in /home/gazzol_j/rendu/abstractvm/src
// 
// Made by julien gazzola
// Login   <gazzol_j@epitech.net>
// 
// Started on  Mon Feb 16 13:32:42 2015 julien gazzola
// Last update Wed Feb 18 16:06:15 2015 julien gazzola
//

#include <string>
#include "Calc.hh"

template<typebn T>
Calc::Calc<T>(std::string value):
  _value(value)
{
  _operand['+'] = &Calc::operator+;
  _operand['-'] = &Calc::operator-;
  _operand['*'] = &Calc::operator*;
  _operand['/'] = &Calc::operator/;
  _operand['%'] = &Calc::operator%;
}

template<typename T, typename U>
IOperand		Calc::*operator+(const IOperand &rhs) const;
{
  T			nbr1;
  U			nbr2;
  std::stringstream	ss;
  std::string		str;
  
  nbr1 = this->getValue();
  nbr2 = rhs.getValue();
   if (this->getType() > rhs.getType())
    {
      nbr1 = nbr1 + nbr2;
      ss << nbr1;
      ss >> str;
      return (createOperand(this->getType(), str));
    }
 else
   {
     nbr2 = nbr1 + nbr2;
     ss << nbr2;
     ss >> nbr2;
     return (createOperand(rhs.getType(), str));
   }
}

template<typename T, typename U>
IOperand	Calc::*operator-(const IOperand &rhs) const;
{
  T			nbr1;
  U			nbr2;
  std::stringstream	ss;
  std::string		str;
  
  nbr1 = this->getValue();
  nbr2 = rhs.getValue();
   if (this->getType() > rhs.getType())
    {
      nbr1 = nbr1 - nbr2;
      ss << nbr1;
      ss >> str;
      return (createOperand(this->getType(), str));
    }
 else
   {
     nbr2 = nbr1 - nbr2;
     ss << nbr2;
     ss >> nbr2;
     return (createOperand(rhs.getType(), str));
   }
}

template<typename T, typename U>
IOperand	Calc::*operator*(const IOperand &rhs) const;
{
  T			nbr1;
  U			nbr2;
  std::stringstream	ss;
  std::string		str;
  
  nbr1 = this->getValue();
  nbr2 = rhs.getValue();
   if (this->getType() > rhs.getType())
    {
      nbr1 = nbr1 * nbr2;
      ss << nbr1;
      ss >> str;
      return (createOperand(this->getType(), str));
    }
 else
   {
     nbr2 = nbr1 * nbr2;
     ss << nbr2;
     ss >> nbr2;
     return (createOperand(rhs.getType(), str));
   }
}

template<typename T, typename U>
IOperand	Calc::*operator/(const IOperand &rhs) const;
{
  T			nbr1;
  U			nbr2;
  std::stringstream	ss;
  std::string		str;
  
  nbr1 = this->getValue();
  nbr2 = rhs.getValue();
  if (nbr2 == 0)
    {

    }
  if (this->getType() > rhs.getType())
    {
      nbr1 = nbr1 / nbr2;
      ss << nbr1;
      ss >> str;
      return (createOperand(this->getType(), str));
    }
  else
    {
      nbr2 = nbr1 / nbr2;
      ss << nbr2;
      ss >> nbr2;
      return (createOperand(rhs.getType(), str));
    }
}

template<typename T, typename U>
IOperand	Calc::*operator%(const IOperand &rhs) const;
{

}

std::string const	&Calc::toString() const
{

}

int			Calc::getPrecision() const
{

}

eOperandType		Calc::getType() const
{

}
