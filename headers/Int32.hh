//
// Int32.hh for Int16 in /home/gazzol_j/rendu/abstractvm/headers
// 
// Made by julien gazzola
// Login   <gazzol_j@epitech.net>
// 
// Started on  Tue Feb 10 11:08:43 2015 julien gazzola
// Last update Tue Feb 10 11:10:21 2015 julien gazzola
//

#ifndef INT32_HH_
# define INT32_HH_

# include "IOperand.hh"

class Int32 : public IOperand
{
public:
  Int32(std::string);
  Int32(Int32 const &);
  Int32					&operator=(Int32 const &);
  virtual				~Int32();

public:
  virtual std::string const             &toString()const;
  virtual int                           getPrecision() const;
  virtual IOperand::eOperandType        getType() const;

public:
  virtual IOperand			*operator+(const IOperand &rhs);
  virtual IOperand			*operator-(const IOperand &rhs);
  virtual IOperand			*operator*(const IOperand &rhs);
  virtual IOperand			*operator/(const IOperand &rhs);
  virtual IOperand			*operator%(const IOperand &rhs);
};

#endif  // !INT32_HH_
