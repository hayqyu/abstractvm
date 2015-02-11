//
// Float.hh for Float in /home/gazzol_j/rendu/abstractvm/headers
// 
// Made by julien gazzola
// Login   <gazzol_j@epitech.net>
// 
// Started on  Tue Feb 10 11:13:25 2015 julien gazzola
// Last update Wed Feb 11 13:01:37 2015 julien gazzola
//

#ifndef FLOAT_HH_
# define FLOAT_HH_

# include <string>
# include "IOperand.hh"

class Float : public IOperand
{
private:
  std::string			_value;
  eOperandType 			_type;

public:
  Float(std::string);
  Float(Float const &);
  Float	       			&operator=(Float const &);
  virtual      			~Float();

public:
  std::string const		&toString()const;
  int				getPrecision() const;
  eOperandType			getType() const;

public:
  IOperand			*operator+(const IOperand &rhs) const;
  IOperand			*operator-(const IOperand &rhs) const;
  IOperand			*operator*(const IOperand &rhs) const;
  IOperand			*operator/(const IOperand &rhs) const;
  IOperand			*operator%(const IOperand &rhs) const;
};

#endif  // !FLOAT_HH_
