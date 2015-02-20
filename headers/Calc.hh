//
// Calc.hh for calc.hh in /home/gazzol_j/rendu/abstractvm/headers
// 
// Made by julien gazzola
// Login   <gazzol_j@epitech.net>
// 
// Started on  Mon Feb 16 11:53:53 2015 julien gazzola
// Last update Fri Feb 20 11:08:21 2015 Cédric Voinnet
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
  typedef IOperand *(Calc::*funcptr)(const IOperand &) const;

public:
  Calc(std::string);
  ~Calc(){}

public:
  std::string const     &toString() const;
  int                   getPrecision() const;
  eOperandType          getType() const;

public:
  template<typename V, typename U>
  IOperand *operator+(const IOperand &rhs) const;
  template<typename V, typename U>
  IOperand *operator-(const IOperand &rhs) const;
  template<typename V, typename U>
  IOperand *operator*(const IOperand &rhs) const;
  template<typename V, typename U>
  IOperand *operator/(const IOperand &rhs) const;
  template<typename V, typename U>
  IOperand *operator%(const IOperand &rhs) const;
};

#endif	// CALC_HH_
