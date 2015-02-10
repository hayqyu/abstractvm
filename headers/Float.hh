//
// Float.hh for Float in /home/gazzol_j/rendu/abstractvm/headers
// 
// Made by julien gazzola
// Login   <gazzol_j@epitech.net>
// 
// Started on  Tue Feb 10 11:13:25 2015 julien gazzola
// Last update Tue Feb 10 11:15:01 2015 julien gazzola
//

#ifndef Float_HH_
# define Float_HH_

# include "IOperand.hh"

class Float : public IOperand
{
public:
  Float(std::string);
  Float(Float const &);
  Float					&operator=(Float const &);
  virtual				~Float();

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

#endif  // !INT8_HH_
