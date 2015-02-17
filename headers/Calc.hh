//
// Calc.hh for calc.hh in /home/gazzol_j/rendu/abstractvm/headers
// 
// Made by julien gazzola
// Login   <gazzol_j@epitech.net>
// 
// Started on  Mon Feb 16 11:53:53 2015 julien gazzola
// Last update Tue Feb 17 09:16:49 2015 julien gazzola
//

#ifndef CALC_HH_
# define CALC_HH_

# include "IOperand.hh"

template<typename T> class Calc;

template<typename T>
class Calc : public IOperand
{
public:
  Calc();
  ~Calc(){}

public:
  virtual std::string const     &toString() const;
  virtual int                   getPrecision() const;
  virtual eOperandType          getType() const;

public:
  IOperand *operator+(const IOperand &rhs) const;
  IOperand *operator-(const IOperand &rhs) const;
  IOperand *operator*(const IOperand &rhs) const;
  //  IOperand *operator/(const IOperand &rhs) const;                   
  //  IOperand *operator%(const IOperand &rhs) const;
};

#endif	// CALC_HH_
