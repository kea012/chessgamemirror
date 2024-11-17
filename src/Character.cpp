#include "../header/Character.hpp"

CHARACTER_TYPE Character::getType() const {
  return this->Character_Type;
}

bool Character::setAliveStatus() {
  this->Character_AliveStatus = false;
  return this->Character_AliveStatus;
}

bool Character::getAliveStatus() const {
  return this->Character_AliveStatus;
}

std::string Character::getColor() const {
  return this->Character_Color;
}