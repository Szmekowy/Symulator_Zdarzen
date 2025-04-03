#include <iostream>
#include "Simulator.h"
#include <random>
#include <queue>
#include "Event.h"

Simulator::Simulator()
    : currentTime(0.0), totalTime(0.0), customer(0) {}
double Simulator::run()
{
    queue.push(Event(EventType::GENERATOR, 0.0)); // dodanie do kolejki pierwszego generatora
    while (!queue.empty())
    {
        Event top_event = queue.top();
        queue.pop();
        currentTime = top_event.getTime();
        switch (top_event.getType())
        {
        case EventType::GENERATOR:
            Generator();
            break;
        case EventType::FIRST_SERVICE:
            First_S();
            break;
        case EventType::SECOND_SERVICE:
            Second_S();
            break;
        case EventType::FINISH:
            Finish();
            break;
        }
    }
    if (customer != 0)
        return (totalTime / customer);
    return 0;
}
void Simulator::Generator()
{
    if (currentTime < 10.0) // generowanie dopoki czas nie przekroczy 10 jednostek czasu
    {
        double nextArrival = currentTime + (-log((double)rand() / RAND_MAX)); // zmienna losowa o rozkladzie wykladniczym
        queue.push(Event(EventType::GENERATOR, nextArrival));
    }
    queue.push(Event(EventType::FIRST_SERVICE, currentTime));
}
void Simulator::First_S()
{
    double time = 2.0 + ((double)rand() / RAND_MAX) * (3.0 - 2.0); // zmienna o rozkladzie rownomiernym (3.0 -2.0) szerokość przedzialu = 1.0
    queue.push(Event(EventType::SECOND_SERVICE, currentTime + time));
}
void Simulator::Second_S()
{
    double time = 3.0 + ((double)rand() / RAND_MAX) * (4.0 - 3.0); // zmienna o rozkladzie rownomiernym (4.0 -3.0) szerokość przedzialu = 1.0
    queue.push(Event(EventType::FINISH, currentTime + time));
}
void Simulator::Finish() // zakonczenie zdarzenia aktualizacja czasu i uzytkownikow
{
    customer++;
    totalTime += currentTime;
}
