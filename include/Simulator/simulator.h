/*
** simulator.h for LoveBrains in /home/robin_f/Programming/Git/CPP/LoveBrains
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Thu Jul 23 11:56:50 2015 Guillaume ROBIN
** Last update Thu Jul 30 19:45:42 2015 Guillaume ROBIN
*/

#ifndef SIMULATOR_H_
# define SIMULATOR_H_

# include "GANN/gann_engine.h"
# include "ANN/ann_generator.h"
# include "Graphics/environment.h"
# include "Simulator/simulator_config.h"

namespace Simulator
{
  class Simulator
  {
  public:
    Simulator(void) throw();
    ~Simulator(void) throw();

    /*
    ** Getters.
    */
    GANN::GANNEngine const&	getEngine(void) const throw();
    GANN::GANNEngine&		getEngine(void) throw();
    GANN::ANNGenerator const&	getGenerator(void) const throw();
    GA::GAConfig const&		getConfig(void) const throw();

    /*
    ** Overload.
    */
    Simulator&	operator=(Simulator const& simulator);

    /*
    ** Methods.
    */
    void	Init(SConfig const& config, const char *file);
    static void	Evaluate(std::list<GA::IDNA *>& brains);

  private:
    static Graphics::Environment	*_env;
    GANN::GANNEngine			_engine;
    GANN::ANNGenerator			_generator;
    GA::GAConfig			_config;
  };
}

#endif /* !SIMULATOR_H_ */
