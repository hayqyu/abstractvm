//
// Int8.hh for abstractvm in /home/voinne_c/rendu/cpp_abstractvm/headers
// 
// Made by Cédric Voinnet
// Login   <voinne_c@epitech.net>
// 
// Started on  Mon Feb  9 17:39:51 2015 Cédric Voinnet
// Last update Wed Feb 11 11:52:48 2015 julien gazzola
//

#ifndef INT8_HH_
# define INT8_HH_

# include <string>
# include "IOperand.hh"

class Int8 : public IOperand
{
private:
  std::string 	       		_value;
  eOperandType		       	_type;

public:
  Int8(std::string);
  Int8(Int8 const &);
  Int8 				&operator=(Int8 const &);
  virtual      			~Int8();

public:
  //  std::string const    		&toString()const;
  int		       		getPrecision() const;
  eOperandType		       	getType() const;

  /*public:
  IOperand			*operator+(const IOperand &rhs);
  IOperand			*operator-(const IOperand &rhs);
  IOperand			*operator*(const IOperand &rhs);
  IOperand			*operator/(const IOperand &rhs);
  IOperand			*operator%(const IOperand &rhs);
  */
};

#endif	// !INT8_HH_