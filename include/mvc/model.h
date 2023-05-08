#pragma once
#include <string>
#include <vector>
#include "datastruc/user.h"
#include "observerPattern.h"


class Model : public Subject{
private:
    std::vector<User*> userList;
    double* selectedSheet;

    User* getUserPtr(std::string userName);
    Sheet* getSheetPtr(std::string userName, std::string sheetName);
    void math(char op, std::vector<double>& numStack);
    double calVal(std::string value);
    
public:
    void notify(bool printSheet, bool printMenu, std::string msg);

    double* getSelectedSheet();
    void createUser(std::string userName);
    void createSheet(std::string userName, std::string sheetName);
    bool checkSheet(std::string userName, std::string sheetName, bool printMenu);
    void changeSheetValue(std::string userName, std::string sheetName, int m, int n, std::string value);
    void changeSheetRight(std::string userName, std::string sheetName, std::string status);
    void collaborate(std::string userName, std::string sheetName, std::string partnerName);
};