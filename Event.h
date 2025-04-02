#ifndef EVENT_H
#define EVENT_H

#include "Event_type.h"

class Event
{
private:
    double time;
    EventType typeof_event;

public:
    Event(EventType typeof_event, double time);

    double getTime() const;

    EventType getType() const;
};

#endif