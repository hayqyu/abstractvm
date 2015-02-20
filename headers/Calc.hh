//
// Calc.hh for calc.hh in /home/gazzol_j/rendu/abstractvm/headers
// 
// Made by julien gazzola
// Login   <gazzol_j@epitech.net>
// 
// Started on  Mon Feb 16 11:53:53 2015 julien gazzola
// Last update Fri Feb 20 13:28:34 2015 julien gazzola
//

#ifndef CALC_HH_
# define CALC_HH_

# include <map>
# include "IOperand.hh"

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
  IOperand *operator+(const IOperand &rhs) const;
  IOperand *operator-(const IOperand &rhs) const;
  IOperand *operator*(const IOperand &rhs) const;
  IOperand *operator/(const IOperand &rhs) const;
  IOperand *operator%(const IOperand &rhs) const;

public:
  template <typename V, typename U>
  IOperand *my_add(const IOperand &rhs);
  template <typename V, typename U>
  IOperand *my_sub(const IOperand &rhs);
  template <typename V, typename U>
  IOperand *my_mul(const IOperand &rhs);
  template <typename V, typename U>
  IOperand *my_div(const IOperand &rhs);
  template <typename V, typename U>
  IOperand *my_mod(const IOperand &rhs);
};

#endif	// CALC_HH_
