#include <iostream>
#include "sheet.h"
using std::cout; 
using std::endl;
using std::string;

Sheet::Sheet(const string userName, const string sheetName, const string pms){
    this->sheetName = sheetName;
    this->permission[userName] = pms;
}


string Sheet::getSheetName(){
    return this->sheetName;
}


string Sheet::getPermission(const string userName){
    return this->permission[userName];
}


double* Sheet::getContent(){
    return this->content;
}


void Sheet::setPermission(const string userName, const string status){
    this->permission[userName] = status;
}