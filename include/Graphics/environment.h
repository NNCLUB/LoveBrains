/*
** environment.h for LoveBrains in /home/robin_f/Programming/Git/CPP/LoveBrains
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Thu Jul 23 11:39:20 2015 Guillaume ROBIN
** Last update Fri Aug 21 14:21:17 2015 Guillaume ROBIN
*/

#ifndef ENVIRONMENT_H_
# define ENVIRONMENT_H_

# include <SFML/Graphics.hpp>

# include "Graphics/i_object.h"
# include "Graphics/i_brain.h"
# include "Graphics/physics.h"
# include "GA/a_observable.h"

/*!
 * \namespace Graphics
 * \brief Contains all the class that define the graphic environment.
 */
namespace Graphics
{
  /*!
   * \class Environment
   * \brief Define the graphic environment that will contain the objects defined by plugins.
  */
  class Environment : public GA::AObservable
  {
  public:
    /*!
     * \brief Constructor.
     */
    Environment(void);
    /*!
     * \brief Constructor.
     * \param width : window's width
     * \param height : window's height.
     */
    Environment(unsigned int width, unsigned int height);
    /*!
     * \brief Destructor.
     */
    ~Environment(void);

    /*
    ** Getters.
    */

    /*!
     * \brief Get all the objects of the environment.
     * \return std::list<IObject *> const&
     */
    std::list<IObject *> const&	getObjects(void) const;
    /*!
     * \brief Get all the objects of the environment.
     * \return std::list<IObject *> &
     */
    std::list<IObject *>&	getObjects(void);
    /*!
     * \brief Get the physics engine member.
     * \return Graphics::Physics const&
     */
    Physics const&		getPhysics(void) const;
    /*!
     * \brief Get the physics engine member.
     * \return Graphics::Physics &
     */
    Physics&			getPhysics(void);
    /*!
     * \brief Get the sf::RenderWindow member.
     * \return sf::RenderWindow &
     */
    sf::RenderWindow&		getWindow(void);

    /*
    ** Setters.
    */

    /*!
     * \brief Load the environment from the environment file given in parameters of LoveBrains.
     * \param path : contains the path of the environment file.
     */
    void	LoadFromFile(const char *path);

    /*
    ** Overload.
    */
    Environment&	operator=(Environment const& env);

    /*
    ** Methods.
    */

    /*!
     * \brief Update all the objects contains in the environment.
     * \param elapsed : Contains the elapsed time between the current update and the previous update.
     */
    void	Update(sf::Time elapsed);
    /*!
     * \brief Draw all the objects on the window.
     */
    void	Draw(void);
    /*!
     * \brief Run the simulation with the graphic environment.
     * \param brains : Contains all the neural networks used by the AI objects.
     */
    void	Run(std::list<GA::IDNA *>& brains);

  private:
    unsigned int			_num_epochs; /*!< Contains the current number of epochs */
    std::list<IObject *>		_env; /*!< Contains all the objects that inherit of Graphics::IObject */
    sf::Font				_font; /*!< Contains the font that will be used to draw the informations about the simulation. */
    sf::Text				_best_fitness; /*!< Contains the current state of the best fitness. */
    sf::Text				_avg_fitness; /*!< Contains the current state of the average fitness. */
    sf::Text				_epochs; /*!< Contains the current state of the number of epochs. */
    Physics				_physics; /*!< Contains the physics engine. */
    static sf::RenderWindow		_window; /*!< Contains the window that will be used to display the objects on the screen. */

    /*!
     * \brief Update the informations about the simulation.
     */
    void	UpdateInfos(void);
  };
}

#endif /* !ENVIRONMENT_H_ */