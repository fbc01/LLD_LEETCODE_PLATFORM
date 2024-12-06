#include <iostream>
#include "Sorting.h"
#include "SortingUsingAttempts.h"
#include "SortingUsingLikes.h"
using namespace std;

class SortingFactory {
public:
    Sorting* getSortingObject(string sortingType) {
        if (sortingType == "LIKES") {
            return new SortingUsingLikes();
        }
        else if (sortingType == "ATTEMPTS") {
            return new SortingUsingAttempts();
        }
        else return NULL;
    }
};