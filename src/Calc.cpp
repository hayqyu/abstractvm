//
// Calc.cpp for calc in /home/gazzol_j/rendu/abstractvm/src
// 
// Made by julien gazzola
// Login   <gazzol_j@epitech.net>
// 
// Started on  Mon Feb 16 13:32:42 2015 julien gazzola
// Last update Sat Feb 21 16:22:19 2015 julien gazzola
//

#include <sstream>
#include <string>
#include "Operand.hh"
#include "Calc.hh"

Calc::Calc(std::string value):
  _value(value)
{
  _type["INT8"] = &Calc<char>::my_calc;
  _type["INT16"] = &Calc<short>::my_calc;
  _type["INT32"] = &Calc<int>::my_calc;
  _type["FLOAT"] = &Calc<float>::my_calc;
  _type["DOUBLE"] = &Calc<double>::mycalc;
}

template<typename T>
template<typename V, typename U>
IOperand		*Calc::my_add(const IOperand &rhs)
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
IOperand		*Calc::my_sub(const IOperand &rhs)
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
     nbr2 = nbr1 + nbr2;
     ss << nbr2;
     ss >> nbr2;
     return (op.createOperand(rhs.getType(), str));
   }
}

template<typename T>
template<typename V, typename U>
IOperand		*Calc::my_mul(const IOperand &rhs)
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
     nbr2 = nbr1 + nbr2;
     ss << nbr2;
     ss >> nbr2;
     return (op.createOperand(rhs.getType(), str));
   }
}

template<typename T>
template<typename V, typename U>
IOperand		*Calc::my_div(const IOperand &rhs)
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
      nbr1 = nbr1 / nbr2;
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
IOperand		*Calc::my_mod(const IOperand &rhs)
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
      nbr1 = nbr1 % nbr2;
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

IOperand			*Calc::operator+(const IOperand &rhs) const
{
  IOperand			*IO;
  eOperandType			tmp;
  eOperandType			tmp2;
  std::stringstream		ss;

  tmp = this->getType();
  tmp2 = rhs.getType();
  IO = this->my_add<, >(rhs);
  return (IO);
}

IOperand		*Calc::operator-(const IOperand &rhs) const
{
  return (this->my_sub(rhs));
}

IOperand		*Calc::operator*(const IOperand &rhs) const
{
  return (this->my_mul(rhs));
}

IOperand		*Calc::operator/(const IOperand &rhs) const
{
  return (this->my_div(rhs));
}

IOperand		*Calc::operator%(const IOperand &rhs) const
{
  return (this->my_mod(rhs));
}
