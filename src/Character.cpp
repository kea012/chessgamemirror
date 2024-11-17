#include "../header/Character.hpp"

using namespace std; 

Character::Character(CharacterType type, string characterColor) : type(type), characterColor(characterColor) {}

CharacterType Character::getType() const {
  return type;
}

bool Character::setAliveStatus() {
  alive = false;
  return alive;
}

bool Character::getAliveStatus() const {
  return alive;
}

std::string Character::getColor() const {
  return characterColor;
}