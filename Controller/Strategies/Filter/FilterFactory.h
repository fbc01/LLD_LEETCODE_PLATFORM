#include <iostream>
#include "Filter.h"
#include "DifficultyLevelFilter.h"
#include "TagFilter.h"

using namespace std;

class FilterFactory {
public:
    FilterInterface* getFilter(string filterType) {
        
        if (filterType == "TAG") { // "TAG" == filtertype ()
            return new TagFilter();
        }
        else if (filterType == "DIFFICULTY") {
            return new DifficultyLevelFilter();
        }
        else return NULL;
    }
};