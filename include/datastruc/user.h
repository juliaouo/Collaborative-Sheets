#pragma once
#include <string>
#include <vector>
#include "sheet.h"


class User{
public:
    User(const std::string userName);
    std::string getUserName();
    std::vector<Sheet*>* getSheetList();
    void addSheet(Sheet* sheet);

private:
    std::string userName;
    std::vector<Sheet*> sheetList;
};