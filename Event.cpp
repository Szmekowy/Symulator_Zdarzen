#include "Event.h"
#include <iostream>

Event::Event(EventType typeof_event, double time)
    : typeof_event(typeof_event), time(time) {}

double Event:: getTime() const { return time; }

EventType Event:: getType() const { return typeof_event; }
