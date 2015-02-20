//
// Calc.cpp for calc in /home/gazzol_j/rendu/abstractvm/src
// 
// Made by julien gazzola
// Login   <gazzol_j@epitech.net>
// 
// Started on  Mon Feb 16 13:32:42 2015 julien gazzola
// Last update Fri Feb 20 10:58:15 2015 julien gazzola
//

#include <sstream>
#include <string>
#include "Operand.hh"
#include "Calc.hh"

template<typename T>
Calc<T>::Calc(std::string value):
  _value(value)
{}

template<typename T>
template<typename V, typename U>
IOperand		*Calc<T>::operator+(const IOperand &rhs) const
{
  V			nbr1;
  U			nbr2;
  std::stringstream	ss;
  std::string		str;
  Operand      		op;
  
  ss << this->toString();
  ss >> nbr1;
  ss << rhs.toString();
  ss >> nbr2;
   if (this->getType() > rhs.getType())
    {
      nbr1 = nbr1 + nbr2;
      ss << nbr1;
      ss >> str;
      return (op.createOperand(this->getType(), str));
    }
   else
   {
     nbr2 = nbr1 + nbr2;
     ss << nbr2;
     ss >> nbr2;
     return (op.createOperand(rhs.getType(), str));
   }
}

template<typename T>
template<typename V, typename U>
IOperand		*Calc<T>::operator-(const IOperand &rhs) const
{
  V			nbr1;
  U			nbr2;
  std::stringstream	ss;
  std::string		str;
  Operand      		op;
  
  ss << this->toString();
  ss >> nbr1;
  ss << rhs.toString();
  ss >> nbr2;
   if (this->getType() > rhs.getType())
    {
      nbr1 = nbr1 - nbr2;
      ss << nbr1;
      ss >> str;
      return (op.createOperand(this->getType(), str));
    }
 else
   {
     nbr2 = nbr1 - nbr2;
     ss << nbr2;
     ss >> nbr2;
     return (op.createOperand(rhs.getType(), str));
   }
}

template<typename T>
template<typename V, typename U>
IOperand		*Calc<T>::operator*(const IOperand &rhs) const
{
  V			nbr1;
  U			nbr2;
  std::stringstream	ss;
  std::string		str;
  Operand      		op;
  
  ss << this->toString();
  ss >> nbr1;
  ss << rhs.toString();
  ss >> nbr2;
  if (this->getType() > rhs.getType())
    {
      nbr1 = nbr1 * nbr2;
      ss << nbr1;
      ss >> str;
      return (op.createOperand(this->getType(), str));
    }
 else
   {
     nbr2 = nbr1 * nbr2;
     ss << nbr2;
     ss >> nbr2;
     return (op.createOperand(rhs.getType(), str));
   }
}

template<typename T>
template<typename V, typename U>
IOperand		*Calc<T>::operator/(const IOperand &rhs) const
{
  V			nbr1;
  U			nbr2;
  std::stringstream	ss;
  std::string		str;
  Operand      		op;
  
  ss << this->toString();
  ss >> nbr1;
  ss << rhs.toString();
  ss >> nbr2;
  if (nbr2 == 0)
    {

    }
  if (this->getType() > rhs.getType())
    {
      nbr1 = nbr1 / nbr2;
      ss << nbr1;
      ss >> str;
      return (op.createOperand(this->getType(), str));
    }
  else
    {
      nbr2 = nbr1 / nbr2;
      ss << nbr2;
      ss >> nbr2;
      return (op.createOperand(rhs.getType(), str));
    }
}

template<typename T>
template<typename V, typename U>
IOperand		*Calc<T>::operator%(const IOperand &rhs) const
{

}

template class Calc <char>;
template class Calc <short>;
template class Calc <int>;
template class Calc <float>;
template class Calc <double>;
