//
// Error.hh for abstractvm in /home/voinne_c/rendu/cpp_abstractvm
// 
// Made by Cédric Voinnet
// Login   <voinne_c@epitech.net>
// 
// Started on  Wed Feb 18 09:32:18 2015 Cédric Voinnet
// Last update Wed Feb 18 09:48:39 2015 Cédric Voinnet
//

#ifndef ERROR_HH_
# define ERROR_HH_

class Error : public std::exception
{
public:
  Error(std::string const &);
  ~Error() throw();
  virtual const char *what() const throw();
private:
  std::string	_message;
};

#endif // !ERROR_HH_
