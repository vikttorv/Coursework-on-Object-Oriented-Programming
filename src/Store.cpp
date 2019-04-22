#include "Store.h"

#include <chrono>

extern std::chrono::high_resolution_clock::time_point time_start;

Store::Store()
{

}

Store::~Store()
{

}


bool Store::Draw(sf::RenderWindow & window) {
  for (int ind = 0; ind < dipoles_.size( ); ind++) {
    dipoles_[ind].Draw(window);
  }

if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
    for (int ind = 0; ind < waves_.size( ); ind++) {
      waves_[ind].Draw(window);
    }
  }

  return true;
}

bool Store::Push(const Dipole & dipole)
{
  #ifdef STORE_DEBUG
  std::cout << "Store::Push(dipole)" << std::endl;
  #endif /* STORE_DEBUG */

  dipoles_.push_back(dipole);

  #ifdef STORE_DEBUG
  std::cout << "Store::Push(dipole) end" << std::endl;
  #endif /* STORE_DEBUG */

  std::cout << std::endl;
  return true;
}

bool Store::Push(const Wave & wave)
{
  #ifdef STORE_DEBUG
  std::cout << "Store::Push(wave)" << std::endl;
  #endif /* STORE_DEBUG */

  waves_.push_back(wave);

  #ifdef STORE_DEBUG
  std::cout << "Store::Push(wave) end" << std::endl;
  #endif /* STORE_DEBUG */

  std::cout << std::endl;
  return true;
}

bool Store::Dump() const
{
  #ifdef STORE_DEBUG
  std::cout << "Store::Dump()" << std::endl;
  #endif /* STORE_DEBUG */

  std::cout << "Print dipole_: " << dipoles_.size() << std::endl;
  for(auto& i : dipoles_)
  {
    i.Dump();
  }

  std::cout << "Print waves_: " << waves_.size() << std::endl;
  for(auto& i : waves_)
    i.Dump();

  #ifdef STORE_DEBUG
  std::cout << "Store::Dump() end" << std::endl;
  #endif /* STORE_DEBUG */

  std::cout << std::endl;
  return true;
}

Vector2 Store::GetFieldStrength(const my_math::Vector2 & position) const
{
  Vector2 result(0, 0);

  for(auto& i : dipoles_)
    result += i.GetFieldStrength(position);

  return result;
}

bool Store::MoveWaves()
{
  #ifdef STORE_DEBUG
  std::cout << "Store::MoveWaves()" << std::endl;
  #endif /* STORE_DEBUG */

  std::chrono::duration<float> diff = std::chrono::high_resolution_clock::now() - time_start;

  float t = diff.count() / TIME_SCALE;

  for (auto& i : waves_)
  {
    FrontElement & front_element = i.GetMain();
    Vector2 field_strength = GetFieldStrength(front_element.GetPosition());
    Vector2 speed_direction = field_strength.GetRotated(90);
    speed_direction.Norm();
    Vector2 position = front_element.GetPosition();
    #ifdef STORE_DEBUG
    std::cout << "\tt: " << t << std::endl;
    std::cout << "\tposition: " << position << std::endl;
    std::cout << "\tfield_strength: " << field_strength << std::endl;
    std::cout << "\tspeed_direction: " << speed_direction << std::endl;
    #endif /* STORE_DEBUG */

    position += speed_direction * LIGHT_SPEED * t;
    front_element.SetPosition(position);

    #ifdef STORE_DEBUG
    std::cout << "new position: " << position << std::endl;
    #endif /* STORE_DEBUG */
  }

  #ifdef STORE_DEBUG
  std::cout << "Store::MoveWaves() end" << std::endl;
  std::cout << std::endl;
  #endif /* STORE_DEBUG */

}
