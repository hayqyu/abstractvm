//
// Int8.cpp for abstractvm in /home/voinne_c/rendu/cpp_abstractvm/src
// 
// Made by Cédric Voinnet
// Login   <voinne_c@epitech.net>
// 
// Started on  Mon Feb  9 16:57:11 2015 Cédric Voinnet
// Last update Thu Feb 12 09:33:50 2015 julien gazzola
//

#include <sstream>
#include "Int8.hh"
#include "Operand.hh"
#include "IOperand.hh"

Int8::Int8(std::string value):
  _value(value), _type(INT8)
{}

Int8::Int8(Int8 const &other):
  _value(other._value), _type(other._type)
{}

Int8     		&Int8::operator=(Int8 const &other)
{
  if (this != &other)
    {
      this->_value = other._value;
      this->_type = other._type;
    }
  return (*this);
}

Int8::~Int8()
{}

std::string const	&Int8::toString() const
{
  return (this->_value);
}

int			Int8::getPrecision() const
{
  return (0);
}

eOperandType		Int8::getType() const
{
  return (this->_type);
}

IOperand		*Int8::operator+(const IOperand::IOperand &rhs) const
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

IOperand		*Int8::operator-(const IOperand::IOperand &rhs) const
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

IOperand		*Int8::operator*(const IOperand::IOperand &rhs) const
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

  /*IOperand		*Int8::operator/(const IOperand::IOperand &rhs) const
{
  Operand		tmp;
  eOperandType		enum_tmp;

  enum_tmp = rhs.getType();
  if (enum_tmp < this->_type)
    enum_tmp = this->_type;
}

IOperand		*Int8::operator%(const IOperand::IOperand &rhs) const
{
  Operand		tmp;
  eOperandType		enum_tmp;

  enum_tmp = rhs.getType();
  if (enum_tmp < this->_type)
    enum_tmp = this->_type;
}
  */
