//
// Int32.cpp for Int32 in /home/gazzol_j/rendu/abstractvm/src
// 
// Made by julien gazzola
// Login   <gazzol_j@epitech.net>
// 
// Started on  Tue Feb 10 11:22:56 2015 julien gazzola
// Last update Wed Feb 11 18:18:01 2015 julien gazzola
//

#include <sstream>
#include "Int32.hh"
#include "Operand.hh"
#include "IOperand.hh"

Int32::Int32(std::string value):
  _value(value), _type(INT32)
{}

Int32::Int32(Int32 const &other):
  _value(other._value), _type(other._type)
{}

Int32     		&Int32::operator=(Int32 const &other)
{
  if (this != &other)
    {
      this->_value = other._value;
      this->_type = other._type;
    }
  return (*this);
}

Int32::~Int32()
{}

std::string const	&Int32::toString() const
{
  return (this->_value);
}

int			Int32::getPrecision() const
{
  return (0);
}

eOperandType		Int32::getType() const
{
  return (this->_type);
}

IOperand		*Int32::operator+(const IOperand::IOperand &rhs) const
{
  std::stringstream    	tmp;
  std::string		stmp;
  eOperandType		enum_tmp;
  Operand		op;
  IOperand		*IO;

  enum_tmp = rhs.getType();
  if (enum_tmp < this->_type)
    enum_tmp = this->_type;
  switch (enum_tmp)
    {
     case INT8:
      char		c1;
      char		c2;

      tmp << this->_value;
      tmp >> c1;
      tmp << toString();
      tmp >> c2;
      tmp << c1 + c2;
      tmp >> stmp;
      IO = IO = op.createOperand(enum_tmp, stmp);
      break;

    case INT16:
      short		s1;
      short		s2;

      tmp << this->_value;
      tmp >> s1;
      tmp << toString();
      tmp >> s2;
      tmp << s1 + s2;
      tmp >> stmp;
      IO = op.createOperand(enum_tmp, stmp);
      break;
    case INT32:
      int		i1;
      int		i2;

      tmp << this->_value;
      tmp >> i1;
      tmp << toString();
      tmp >> i2;
      tmp << i1 + i2;
      tmp >> stmp;
      IO = op.createOperand(enum_tmp, stmp);
      break;
    case FLOAT:
      float		f1;
      float		f2;

      tmp << this->_value;
      tmp >> f1;
      tmp << toString();
      tmp >> f2;
      tmp << f1 + f2;
      tmp >> stmp;
      IO = op.createOperand(enum_tmp, stmp);
      break;
    case DOUBLE:
      double		d1;
      double		d2;

      tmp << this->_value;
      tmp >> d1;
      tmp << toString();
      tmp >> d2;
      tmp << d1 + d2;
      tmp >> stmp;
      IO = op.createOperand(enum_tmp, stmp);
      break;
    }
  return (IO);
}

IOperand		*Int32::operator-(const IOperand::IOperand &rhs) const
{
  std::stringstream    	tmp;
  std::string		stmp;
  eOperandType		enum_tmp;
  Operand		op;
  IOperand		*IO;

  enum_tmp = rhs.getType();
  if (enum_tmp < this->_type)
    enum_tmp = this->_type;
  switch (enum_tmp)
    {
     case INT8:
      char		c1;
      char		c2;

      tmp << this->_value;
      tmp >> c1;
      tmp << toString();
      tmp >> c2;
      tmp << c1 - c2;
      tmp >> stmp;
      IO = op.createOperand(enum_tmp, stmp);
      break;

    case INT16:
      short		s1;
      short		s2;

      tmp << this->_value;
      tmp >> s1;
      tmp << toString();
      tmp >> s2;
      tmp << s1 - s2;
      tmp >> stmp;
      IO = op.createOperand(enum_tmp, stmp);
      break;
    case INT32:
      int		i1;
      int		i2;

      tmp << this->_value;
      tmp >> i1;
      tmp << toString();
      tmp >> i2;
      tmp << i1 - i2;
      tmp >> stmp;
      IO = op.createOperand(enum_tmp, stmp);
      break;
    case FLOAT:
      float		f1;
      float		f2;

      tmp << this->_value;
      tmp >> f1;
      tmp << toString();
      tmp >> f2;
      tmp << f1 - f2;
      tmp >> stmp;
      IO = op.createOperand(enum_tmp, stmp);
      break;
    case DOUBLE:
      double		d1;
      double		d2;

      tmp << this->_value;
      tmp >> d1;
      tmp << toString();
      tmp >> d2;
      tmp << d1 - d2;
      tmp >> stmp;
      IO = op.createOperand(enum_tmp, stmp);
      break;
    }
  return (IO);
}

IOperand		*Int32::operator*(const IOperand::IOperand &rhs) const
{
  std::stringstream    	tmp;
  std::string		stmp;
  eOperandType		enum_tmp;
  Operand		op;
  IOperand		*IO;

  enum_tmp = rhs.getType();
  if (enum_tmp < this->_type)
    enum_tmp = this->_type;
  switch (enum_tmp)
    {
     case INT8:
      char		c1;
      char		c2;

      tmp << this->_value;
      tmp >> c1;
      tmp << toString();
      tmp >> c2;
      tmp << c1 * c2;
      tmp >> stmp;
      IO = op.createOperand(enum_tmp, stmp);
      break;

    case INT16:
      short		s1;
      short		s2;

      tmp << this->_value;
      tmp >> s1;
      tmp << toString();
      tmp >> s2;
      tmp << s1 * s2;
      tmp >> stmp;
      IO = op.createOperand(enum_tmp, stmp);
      break;
    case INT32:
      int		i1;
      int		i2;

      tmp << this->_value;
      tmp >> i1;
      tmp << toString();
      tmp >> i2;
      tmp << i1 * i2;
      tmp >> stmp;
      IO = op.createOperand(enum_tmp, stmp);
      break;
    case FLOAT:
      float		f1;
      float		f2;

      tmp << this->_value;
      tmp >> f1;
      tmp << toString();
      tmp >> f2;
      tmp << f1 * f2;
      tmp >> stmp;
      IO = op.createOperand(enum_tmp, stmp);
      break;
    case DOUBLE:
      double		d1;
      double		d2;

      tmp << this->_value;
      tmp >> d1;
      tmp << toString();
      tmp >> d2;
      tmp << d1 * d2;
      tmp >> stmp;
      IO = op.createOperand(enum_tmp, stmp);
      break;
    }
  return (IO); 
}

/*IOperand		*Int32::operator/(const IOperand::IOperand &rhs) const
{
  //?
}

IOperand		*Int32::operator%(const IOperand::IOperand &rhs) const
{
  
}
*/
