//
// Int16.hh for int16 in /home/gazzol_j/rendu/abstractvm/headers
// 
// Made by julien gazzola
// Login   <gazzol_j@epitech.net>
// 
// Started on  Tue Feb 10 11:03:34 2015 julien gazzola
// Last update Tue Feb 10 11:15:51 2015 julien gazzola
//

#ifndef INT16_HH_
# define INT16_HH_

# include "IOperand.hh"

class Int16 : public IOperand
{
public:
  Int16(std::string);
  Int16(Int16 const &);
  Int16					&operator=(Int16 const &);
  virtual				~Int16();

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

#endif	// !INT16_HH_
