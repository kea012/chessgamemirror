#include "../header/Character.hpp"

using namespace std; 

Character::Character(CharacterType type, string characterColor) : type(type), characterColor(characterColor) {}

CharacterType Character::getType() const {
  return this->type;
}

bool Character::setAliveStatus() {
  this->alive = false;
  return this->alive;
}

bool Character::getAliveStatus() const {
  return this->alive;
}

std::string Character::getColor() const {
  return this->characterColor;
}