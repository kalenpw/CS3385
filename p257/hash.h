#pragma once

#include <math.h>

// The division method of hashing. See section 11.3.1 of the textbook.
// m is the size of the table
class DivHash {
    public:
        int operator()(int key, int m) {
            return key % m;
        }
};

// TODO: implement class MultHash, similar to DivHash.
// The multiplcation method of hashing. See section 11.3.2 of the textbook.
// Use the A value suggested in equation 11.2.
// m is the size of the table
//
// Muliplication hashing
// m is the size of the table
class MultHash{
    public:
        int operator()(int key,int m){
            double A = .6180339887;
            double kTimesA = key * A;
            double kAModOne = kTimesA - floor(kTimesA);
            return m * kAModOne;
        }
};
