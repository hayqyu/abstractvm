//
// Int16.hh for int16 in /home/gazzol_j/rendu/abstractvm/headers
// 
// Made by julien gazzola
// Login   <gazzol_j@epitech.net>
// 
// Started on  Tue Feb 10 11:03:34 2015 julien gazzola
// Last update Wed Feb 11 11:48:46 2015 julien gazzola
//

#ifndef INT16_HH_
# define INT16_HH_

# include <string>
# include "IOperand.hh"

class Int16 : public IOperand
{
private:
  std::string			_value;
  eOperandType 			_type;

public:
  Int16(std::string);
  Int16(Int16 const &);
  Int16	       			&operator=(Int16 const &);
  virtual      			~Int16();

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

#endif	// !INT16_HH_
