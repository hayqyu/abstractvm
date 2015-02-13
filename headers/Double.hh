//
// Double.hh for double in /home/gazzol_j/rendu/abstractvm/headers
// 
// Made by julien gazzola
// Login   <gazzol_j@epitech.net>
// 
// Started on  Tue Feb 10 11:11:08 2015 julien gazzola
// Last update Fri Feb 13 16:38:58 2015 julien gazzola
//

#ifndef DOUBLE_HH_
# define DOUBLE_HH_

# include <string>
# include "IOperand.hh"

class Double : public IOperand
{
private:
  std::string          		_value;
  eOperandType 			_type;
  uType				_utype;

public:
  Double(std::string);
  Double(Double const &);
  Double       			&operator=(Double const &);
  virtual      			~Double();

public:
  std::string const		&toString()const;
  int				getPrecision() const;
  eOperandType			getType() const;

public:
  IOperand			*operator+(const IOperand &rhs) const;
  IOperand			*operator-(const IOperand &rhs) const;
  IOperand			*operator*(const IOperand &rhs) const;
  // IOperand			*operator/(const IOperand &rhs) const;
  // IOperand			*operator%(const IOperand &rhs) const;
  
};

#endif  // !DOUBLE_HH_ 
