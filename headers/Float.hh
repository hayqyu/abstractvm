//
// Float.hh for Float in /home/gazzol_j/rendu/abstractvm/headers
// 
// Made by julien gazzola
// Login   <gazzol_j@epitech.net>
// 
// Started on  Tue Feb 10 11:13:25 2015 julien gazzola
// Last update Wed Feb 11 09:37:50 2015 julien gazzola
//

#ifndef Float_HH_
# define Float_HH_

# include "IOperand.hh"

class Float : public IOperand
{
private:
  float	       			_value;
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
  double       			getValue() const;

public:
  IOperand			*operator+(const IOperand &rhs);
  IOperand			*operator-(const IOperand &rhs);
  IOperand			*operator*(const IOperand &rhs);
  IOperand			*operator/(const IOperand &rhs);
  IOperand			*operator%(const IOperand &rhs);
};

#endif  // !INT8_HH_
