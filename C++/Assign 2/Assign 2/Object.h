#pragma once
#include <iostream>
#include "List.h"
#include "NVPair.h"

#define DATA_MEMBERS_PER_OBJECT 5
#define VALUE_DELIMITER ','
#define OBJECTS_PER_JSON_FILE 5

class Object { //Abstract class
  public:
    // set assigns values to the data members of the derived Object
    virtual void set(List<NVPair<std::string, std::string>, DATA_MEMBERS_PER_OBJECT>) = 0;

    // getDSV returns the values of the data members delimied by VALUE_DELIMITER 
    virtual const std::string getDSV(char c = VALUE_DELIMITER) const = 0;

    // derived objects may contain pointers: virtual destructors are necessary
    virtual ~Object() {}
};