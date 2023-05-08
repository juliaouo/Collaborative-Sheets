#include <iostream>
#include "user.h"
using std::cout; 
using std::endl;
using std::string;
using std::vector;

User::User(const string userName){
    this->userName = userName;
}


string User::getUserName(){
    return this->userName;
}


vector<Sheet*>* User::getSheetList(){
    return &(this->sheetList);
}


void User::addSheet(Sheet* sheet){
    this->sheetList.push_back(sheet);
}
