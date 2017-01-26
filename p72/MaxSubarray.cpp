#include "./MaxSubarray.h"
#include <iostream>
// Provides floor, ceil, etc.
#include <cmath>
#include <climits>
using namespace std;

//Kalen Williams
//27 January 2017

Result findMaxCrossingSubarray(int* array, int low, int mid, int high){
    int leftSum = INT_MIN;
    int sum = 0;
    int maxLeftIndex;

    for(int i = mid; i <= low; i--){
        sum = sum + array[i];

        if(sum > leftSum){
            leftSum = sum;
            maxLeftIndex = i;
        }
    }

    int rightSum = INT_MAX;
    sum = 0;
    int maxRightIndex;

    for(int j = mid + 1; j < high; j++){
        sum = sum + array[j];

        if(sum > rightSum){
            rightSum = sum;
            maxRightIndex = j;
        }
    }

    int totalSum = leftSum + rightSum;
    return Result(maxLeftIndex, maxRightIndex, totalSum);
    
}

Result findMaxSubarray(int* array, int low, int high){

}
