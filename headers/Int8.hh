//
// Int8.hh for abstractvm in /home/voinne_c/rendu/cpp_abstractvm/headers
// 
// Made by Cédric Voinnet
// Login   <voinne_c@epitech.net>
// 
// Started on  Mon Feb  9 17:39:51 2015 Cédric Voinnet
// Last update Tue Feb 10 09:52:59 2015 Cédric Voinnet
//

#ifndef INT8_HH_
# define INT8_HH_

# include "IOperand.hh"

class Int8 : public IOperand
{
private:
  char				_value;
  IOperand::eOperandType	_type;

public:
  Int8(std::string);
  Int8(Int8 const &);
  Int8		&operator=(Int8 const &);
  virtual	~Int8();

public:
  virtual std::string const		&toString()const;
  virtual int				getPrecision() const;
  virtual IOperand::eOperandType	getType() const;

public:
  virtual IOperand	*operator+(const IOperand &rhs);
  virtual IOperand	*operator-(const IOperand &rhs);
  virtual IOperand	*operator*(const IOperand &rhs);
  virtual IOperand	*operator/(const IOperand &rhs);
  virtual IOperand	*operator%(const IOperand &rhs);
};

#endif	// !INT8_HH_
