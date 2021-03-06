/*
** ga_engine_exception.h for GAEngine in /home/robin_f/Programming/Git/CPP/GAEngine
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Tue Jul 21 14:18:49 2015 Guillaume ROBIN
** Last update Tue Jul 21 15:36:44 2015 Guillaume ROBIN
*/

#ifndef GA_ENGINE_EXCEPTION_H_
# define GA_ENGINE_EXCEPTION_H_

# include <exception>

namespace GA
{
  class GAEngineException : public std::exception
  {
  public:
    GAEngineException(const char *msg) throw();
    ~GAEngineException(void) throw();

    const char	*what(void) const throw();

  private:
    char	*_msg;
  };
}

#endif /* !GA_ENGINE_EXCEPTION_H_ */
