#pragma once

#include <SFML/Graphics.hpp>
#include <assert.h>
#include <ctime>

#include "Vector2.h"

using namespace my_math;

const unsigned int SCREEN_WIDTH = 800;
const unsigned int SCREEN_HEIGHT = 600;

const float DEFAULT_AREA_RADIUS = 200.;
const float DEFAULT_AREA_PCOUNT = 40.;
const float DEFAULT_AREA_CENTER_X = 0;
const float DEFAULT_AREA_CENTER_Y = 300;
const float MAX_DISTANCE_FROM_AREA_CENTER = 1000;

const float DEFAULT_FRONT_ELEMENT_RADIUS = 3.;
const float DEFAULT_FRONT_ELEMENT_PCOUNT = 40.;

const float DEFAULT_DIPOLE_DIRECTION = 180;
const float DIPOLE_SCALE_X = 0.015;
const float DIPOLE_SCALE_Y = 0.015;

const float DEFAULT_PHASE = 0;
const float DEFAULT_AMPLITUDE = 10000;
const float CYCLIC_FREQUENCY = 10;
const float LIGHT_SPEED = 10000;
const float FRONT_ELEMENT_MOVE_SPEED = 1000;
const float TIME_SCALE = 10;

/*
const float X_SCALE = 50;
const float Y_SCALE = 50;
*/

class Element {
 public:
  Element();

  explicit Element(const Vector2 & position);

  virtual bool Draw(sf::RenderWindow & window) = 0;

  virtual bool Dump() const = 0;

  Vector2 GetPosition() const;

  float GetDirection() const;

  bool SetPosition(const Vector2 & position);

  bool SetDirection(const float direction);

  virtual ~Element();

 protected:
  Vector2 position_;
  float direction_;
  sf::Sprite sprite_;
};

bool CreateTexture(const char* picture, sf::Texture & texture);
