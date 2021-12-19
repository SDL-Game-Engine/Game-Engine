#include "property.h"

Property::Property(const char *p_label, void (*p_prop)(ENTITY), ENTITIES p_entities)
    : label(p_label), property(p_prop), entities(p_entities) {}

void Property::operator()(ENTITY p_entity)
{
  property(p_entity);
}

void Property::setProperty(void (*p_prop)(ENTITY))
{
  property = p_prop;
}

ENTITIES Property::getEntities()
{
  return entities;
}