//
// IOperand.hh for abstractvm in /home/voinne_c/rendu/cpp_abstractvm/src
// 
// Made by Cédric Voinnet
// Login   <voinne_c@epitech.net>
// 
// Started on  Mon Feb  9 15:34:29 2015 Cédric Voinnet
// Last update Mon Feb  9 15:52:20 2015 Cédric Voinnet
//

#ifndef IOPERAND_HH_
# define IOPERAND_HH_

class IOperand
{
public:
  virtual std::string const	&toString() const = 0;
  virtual int			getPrecision() const = 0;
  virtual eOperandType		getType() const = 0;

public:
  virtual IOperand *operator+(const IOperand &rhs) const = 0; //Somme
  virtual IOperand *operator-(const IOperand &rhs) const = 0; //Difference
  virtual IOperand *operator*(const IOperand &rhs) const = 0; //Produit
  virtual IOperand *operator/(const IOperand &rhs) const = 0; //Quotient
  virtual IOperand *operator%(const IOperand &rhs) const = 0; //Modulo

public:
  virtual ~IOperand() {}
};

#endif	// !IOPERAND_HH_
