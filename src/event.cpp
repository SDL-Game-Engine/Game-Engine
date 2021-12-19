#include "event.h"

Event::Event(const char *p_label, bool (*p_event)())
  : label(p_label), event(p_event)
{}

bool Event::operator() ()
{
  return listen();
}

bool Event::listen() { return event(); }

PROPERTY Event::addProp(PROPERTY p_prop)
{
  properties.push_back(p_prop);

  return p_prop;
}

void Event::runProps()
{
  if (listen())
    for (PROPERTY p : properties)
      for (ENTITY e : p->getEntities())
        (*p)(e);
}
