#include "decorator.h"

Decorator::Decorator(Minion *target): target{target} {}

Decorator::~Decorator() {
    delete target;
    delete enchantment;
}
