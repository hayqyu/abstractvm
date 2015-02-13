//
// Int32.hh for Int16 in /home/gazzol_j/rendu/abstractvm/headers
// 
// Made by julien gazzola
// Login   <gazzol_j@epitech.net>
// 
// Started on  Tue Feb 10 11:08:43 2015 julien gazzola
// Last update Fri Feb 13 16:38:43 2015 julien gazzola
//

#ifndef INT32_HH_
# define INT32_HH_

# include <string>
# include "IOperand.hh"

class Int32 : public IOperand
{
private:
  std::string			_value;
  eOperandType 			_type;
  uType				_utype;

public:
  Int32(std::string);
  Int32(Int32 const &);
  Int32				&operator=(Int32 const &);
  virtual      			~Int32();

public:
  std::string const             &toString()const;
  int                           getPrecision() const;
  eOperandType		        getType() const;

public:
  IOperand			*operator+(const IOperand &rhs) const;
  IOperand			*operator-(const IOperand &rhs) const;
  IOperand			*operator*(const IOperand &rhs) const;
  //  IOperand			*operator/(const IOperand &rhs) const;
  //  IOperand			*operator%(const IOperand &rhs) const;
};

#endif  // !INT32_HH_
