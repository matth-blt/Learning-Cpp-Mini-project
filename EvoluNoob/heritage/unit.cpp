#include "unit.hpp"

Unit::Unit(int id, const std::string& name) noexcept : _id(id), _name(name) {}
int Unit::getId() const noexcept { return _id; }
std::string Unit::getName() const noexcept { return _name; }