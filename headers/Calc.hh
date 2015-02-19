//
// Calc.hh for calc.hh in /home/gazzol_j/rendu/abstractvm/headers
// 
// Made by julien gazzola
// Login   <gazzol_j@epitech.net>
// 
// Started on  Mon Feb 16 11:53:53 2015 julien gazzola
// Last update Thu Feb 19 15:06:05 2015 julien gazzola
//

#ifndef CALC_HH_
# define CALC_HH_

# include <map>
# include "IOperand.hh"

template<typename T>
class Calc : public IOperand
{
private:
  std::string			_value;
  typedef IOperand *(Calc::*funcptr)(const IOperand &);
  std::map<char, funcptr>	_operand;

public:
  Calc(std::string);
  ~Calc(){}

public:
  std::string const     &toString() const;
  int                   getPrecision() const;
  eOperandType          getType() const;
  T			getValue() const;			

public:
  IOperand *operator+(const IOperand &rhs);
  IOperand *operator-(const IOperand &rhs);
  IOperand *operator*(const IOperand &rhs);
  IOperand *operator/(const IOperand &rhs);                   
  IOperand *operator%(const IOperand &rhs);
};

#endif	// CALC_HH_
