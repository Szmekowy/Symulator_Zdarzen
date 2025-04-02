#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "Event.h"
#include <iostream>
#include <queue>
#include <random>
using namespace std;

struct CompareEvent {
    bool operator()(const Event &e1, const Event &e2) {
        return e1.getTime() > e2.getTime(); 
    }
};

class Simulator
{
private:
    priority_queue<Event, vector<Event>, CompareEvent> queue;
    double currentTime;
    double totalTime;
    int customer;

    void Generator();
    void First_S();
    void Second_S();
    void Finish();
public:
    Simulator();
    double run();
};




#endif