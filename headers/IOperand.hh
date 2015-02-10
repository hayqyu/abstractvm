//
// IOperand.hh for abstractvm in /home/voinne_c/rendu/cpp_abstractvm/src
// 
// Made by Cédric Voinnet
// Login   <voinne_c@epitech.net>
// 
// Started on  Mon Feb  9 15:34:29 2015 Cédric Voinnet
// Last update Tue Feb 10 15:27:47 2015 julien gazzola
//

#ifndef IOPERAND_HH_
# define IOPERAND_HH_

# include <string>

typedef enum eOperandType{
  int8,
  Int16,
  Int32,
  Float,
  Double
}eOperandType;

class IOperand
{
public:
  virtual std::string const	&toString() const = 0;
  virtual int			getPrecision() const = 0;
  virtual eOperandType		getType() const = 0;
  virtual void			getValue() const = 0;

public:
  virtual IOperand *operator+(const IOperand &rhs) const = 0;
  virtual IOperand *operator-(const IOperand &rhs) const = 0;
  virtual IOperand *operator*(const IOperand &rhs) const = 0;
  virtual IOperand *operator/(const IOperand &rhs) const = 0;
  virtual IOperand *operator%(const IOperand &rhs) const = 0;

public:
  virtual ~IOperand() {}
};

#endif	// !IOPERAND_HH_
