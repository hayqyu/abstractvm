//
// Double.hh for double in /home/gazzol_j/rendu/abstractvm/headers
// 
// Made by julien gazzola
// Login   <gazzol_j@epitech.net>
// 
// Started on  Tue Feb 10 11:11:08 2015 julien gazzola
// Last update Tue Feb 10 11:13:09 2015 julien gazzola
//

#ifndef DOUBLE_HH_
# define DOUBLE_HH_

# include "IOperand.hh"

class Double : public IOperand
{
public:
  Double(std::string);
  Double(Double const &);
  Double				&operator=(Double const &);
  virtual				~Double();

public:
  virtual std::string const		&toString()const;
  virtual int				getPrecision() const;
  virtual IOperand::eOperandType	getType() const;

public:
  virtual IOperand			*operator+(const IOperand &rhs);
  virtual IOperand			*operator-(const IOperand &rhs);
  virtual IOperand			*operator*(const IOperand &rhs);
  virtual IOperand			*operator/(const IOperand &rhs);
  virtual IOperand			*operator%(const IOperand &rhs);
};

#endif  // !DOUBLE_HH_ 
