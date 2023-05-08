#pragma once
#include <string>
#include "observerPattern.h"


class MsgView : public Observer{
public:
    void update(void* a, bool printSheet, bool printMenu, std::string msg);
};


class SheetView : public Observer{
private:
    double* sheetContent = nullptr;

public:
    void update(void* a, bool printSheet, bool printMenu, std::string msg);
};


class Views : public Observer{
private:
    MsgView msgView;
    SheetView sheetView;

public:
    void setModel(Subject &a);
    void update(void* a, bool printSheet, bool printMenu, std::string msg);
}; 