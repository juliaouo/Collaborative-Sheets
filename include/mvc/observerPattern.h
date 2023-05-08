#pragma once
#include <string>
#include <vector>


class Observer{
public: 
    virtual void update(void* a, bool printSheet, bool printMenu, std::string msg) = 0; 
};


class Subject{ 
protected:
    std::vector<Observer*> observers;

public:
    void attach(Observer* a);
    void notify();
};
