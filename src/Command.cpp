//
// Command.cpp for Command in /home/gazzol_j/rendu/abstractvm/src
// 
// Made by julien gazzola
// Login   <gazzol_j@epitech.net>
// 
// Started on  Tue Feb 10 10:20:20 2015 julien gazzola
// Last update Tue Feb 10 15:46:27 2015 Cédric Voinnet
//

#include <fstream>
#include <iostream>
#include "Command.hh"

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

void					Command::execution()
{
  std::vector<std::string>::iterator	currentInstruction = this->_instructions.begin();

  while (currentInstruction != this->_instructions.end()){
    std::cout << "Execution de: " << *currentInstruction << std::endl;
    ++currentInstruction;
  }
}

// void	Command::push()
// {

// }

// void	Command::pop()
// {

// }

// void	Command::dump()
// {

// }

// void	Command::asser()
// {

// }

// void	Command::add()
// {

// }

// void	Command::sub()
// {

// }

// void	Command::mul()
// {

// }

// void	Command::div()
// {

// }

// void	Command::mod()
// {

// }

// void	Command::printf()
// {

// }

// void	Command::exit()
// {

// }
