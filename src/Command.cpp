//
// Command.cpp for Command in /home/gazzol_j/rendu/abstractvm/src
// 
// Made by julien gazzola
// Login   <gazzol_j@epitech.net>
// 
// Started on  Tue Feb 10 10:20:20 2015 julien gazzola
// Last update Wed Feb 11 18:14:46 2015 Cédric Voinnet
//

#include <fstream>
#include <sstream>
#include <iostream>
#include "Command.hh"

Command::Command()
{
  
}

void		Command::getInstructions()
{
  std::string	instruction;

  while (getline(std::cin, instruction) && instruction != ";;")
    {
      if (instruction != "" && instruction.at(0) != ';')
	this->_instructions.push_back(instruction);
    }
}

int		Command::getInstructions(char *filename)
{
  std::ifstream	file(filename);
  std::string	instruction;

  if (file.is_open())
    {
      while (getline(file, instruction))
	if (instruction != "" && instruction.at(0) != ';')
	  this->_instructions.push_back(instruction);
      file.close();
    } 
  else
    {
      std::cout << "Cannot open file: " << filename << std::endl;
      return (-1);
    }
  return (0);
}

int					Command::execution()
{
  std::vector<std::string>::iterator	currentInstruction = this->_instructions.begin();

  while (currentInstruction != this->_instructions.end()){
    std::cout << "Execution de: " << *currentInstruction << std::endl;
    if (parser(*currentInstruction))
      return (-1);
    ++currentInstruction;
  }
  return (0);
}

int	Command::parser(std::string line)
{
  std::stringstream			ss;

  ss << line;
  
  return (0);
}

void	Command::push()
{
  std::cout << "C'est un push" << std::endl;
}

void	Command::pop()
{
  std::cout << "C'est un pop" << std::endl;
}

void	Command::dump()
{
  std::cout << "C'est un dump" << std::endl;
}

void	Command::assert()
{
  std::cout << "C'est un assert" << std::endl;
}

void	Command::add()
{
  std::cout << "C'est un add" << std::endl;
}

void	Command::sub()
{
  std::cout << "C'est un sub" << std::endl;
}

void	Command::mul()
{
  std::cout << "C'est un mul" << std::endl;
}

void	Command::div()
{
  std::cout << "C'est un div" << std::endl;
}

void	Command::mod()
{
  std::cout << "C'est un mod" << std::endl;
}

void	Command::printf()
{
  std::cout << "C'est un printf" << std::endl;
}

void	Command::exit()
{
  std::cout << "C'est un exit" << std::endl;
}
