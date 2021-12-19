#ifndef PROPERTY_H
#define PROPERTY_H

#include "setup.h"
#include "entity.h"

/**
 * A property is basically the consequence of an event that executes when called.
 **/

class Property
{
public:
  Property(const char *p_label, void (*p_prop)(ENTITY), ENTITIES p_entities);
  void operator()(ENTITY entity);

  void setProperty(void (*p_prop)(ENTITY));
  ENTITIES getEntities();

private:
  void (*property)(ENTITY);
  const char *label;
  ENTITIES entities;
};

#endif // PROPERTY_H