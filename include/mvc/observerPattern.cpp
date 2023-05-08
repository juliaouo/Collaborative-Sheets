#include "observerPattern.h"

// class Subject
void Subject::attach(Observer* a){
    observers.push_back(a);
}


void Subject::notify(){}