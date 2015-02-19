//
// Calc.cpp for calc in /home/gazzol_j/rendu/abstractvm/src
// 
// Made by julien gazzola
// Login   <gazzol_j@epitech.net>
// 
// Started on  Mon Feb 16 13:32:42 2015 julien gazzola
// Last update Thu Feb 19 15:16:32 2015 julien gazzola
//

#include <sstream>
#include <string>
#include "Calc.hh"

template<typename T>
Calc<T>::Calc(std::string value):
  _value(value)
{
  _operand['+'] = &Calc::operator+;
  _operand['-'] = &Calc::operator-;
  _operand['*'] = &Calc::operator*;
  _operand['/'] = &Calc::operator/;
  _operand['%'] = &Calc::operator%;
}

template<typename T>
template<typename V, U>
IOperand		*Calc<T>::operator+(const IOperand &rhs)
{
  V			nbr1;
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

template<typename T>
template<typename V, typename U>
IOperand		*Calc<T>::operator-(const IOperand &rhs)
{
  V			nbr1;
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

template<typename T>
template<typename V, typename U>
IOperand		*Calc<T>::operator*(const IOperand &rhs)
{
  V			nbr1;
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

template<typename T>
template<typename V, typename U>
IOperand		*Calc<T>::operator/(const IOperand &rhs)
{
  V			nbr1;
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

template>typename T
template<typename V, typename U>
IOperand		*Calc<T>::operator%(const IOperand &rhs)
{

}

template<>
std::string const	&Calc<>::toString() const
{

}

template<>
int			Calc<>::getPrecision() const
{

}

template<>
eOperandType		Calc<>::getType() const
{

}

template class Calc <char>;
template class Calc <short>;
template class Calc <int>;
template class Calc <float>;
template class Calc <double>;
