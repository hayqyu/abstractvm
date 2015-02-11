//
// Double.hh for double in /home/gazzol_j/rendu/abstractvm/headers
// 
// Made by julien gazzola
// Login   <gazzol_j@epitech.net>
// 
// Started on  Tue Feb 10 11:11:08 2015 julien gazzola
// Last update Wed Feb 11 11:48:25 2015 julien gazzola
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

public:
  Double(std::string);
  Double(Double const &);
  Double       			&operator=(Double const &);
  virtual      			~Double();

public:
  //  std::string const		&toString()const;
  int				getPrecision() const;
  eOperandType			getType() const;

  /*public:
  IOperand			*operator+(const IOperand &rhs);
  IOperand			*operator-(const IOperand &rhs);
  IOperand			*operator*(const IOperand &rhs);
  IOperand			*operator/(const IOperand &rhs);
  IOperand			*operator%(const IOperand &rhs);
  */
};

#endif  // !DOUBLE_HH_ 
