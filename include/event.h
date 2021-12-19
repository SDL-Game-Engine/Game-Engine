#ifndef EVENT_H
#define EVENT_H

#include "setup.h"
#include "property.h"

/**
 * Since gameplay is driven by events and their respective properties, each
 * event is going to house a list of properties (call-back functions) that 
 * will execute each time the event object is called.
 **/

class Event
{
public:
  Event(const char *p_label, bool (*p_event)());

  // passed during main game loop.
  bool operator() ();

  // check if an event is happening.
  bool listen();

  PROPERTY addProp(PROPERTY p_prop);

  // run all props if event requirements are met
  void runProps();
  
private:
  PROPERTIES properties;

  // Just for context purposes
  const char *label;
  bool (*event)();
};
#endif // EVENT_H