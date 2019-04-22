#pragma once

#include <SFML/Graphics.hpp>

#include "Vector2.h"
#include "Element.h"

#define FRONT_ELEMENT_DEBUG 1

#define FRONT_ELEMENT_DEBUG 1

using namespace my_math;

class FrontElement : public Element {
 public:
  FrontElement();

  explicit FrontElement(const Vector2 & position);

  bool Draw(sf::RenderWindow & window) const override;

  bool Dump() const override;

  float GetAmplitude() const;

  bool SetAmplitude(const float amplitude);

  virtual ~FrontElement();

 private:
  float amplitude_;
};