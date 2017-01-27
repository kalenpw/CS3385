#include "./MaxSubarray.h"
#include <iostream>
// Provides floor, ceil, etc.
#include <cmath>
#include <climits>
using namespace std;

//Kalen Williams
//27 January 2017
//returns a Result containing the lowest index, highest index, and sum of the max sub array
Result findMaxCrossingSubarray(int* array, int low, int mid, int high){
    int leftSum = INT_MIN;
    int sum = 0;
    int maxLeftIndex;

    for(int i = mid; i >= low; i--){
        sum = sum + array[i];

        if(sum > leftSum){
            leftSum = sum;
            maxLeftIndex = i;
        }
    }

    int rightSum = INT_MIN;
    sum = 0;
    int maxRightIndex;

    for(int j = mid + 1; j <= high; j++){
        sum = sum + array[j];

        if(sum > rightSum){
            rightSum = sum;
            maxRightIndex = j;
        }
    }

    int totalSum = leftSum + rightSum;
    return Result(maxLeftIndex, maxRightIndex, totalSum);
    
}

//returns a Result containing the loweset index, highest index, and max sub array total
Result findMaxSubarray(int* array, int low, int high){
    if(high == low){
        return Result(low, high, array[low]);
    }
    else{
        int mid = (low + high) / 2;
        Result leftArray = findMaxSubarray(array, low, mid);
        Result rightArray = findMaxSubarray(array, mid + 1, high);
        Result crossArray = findMaxCrossingSubarray(array, low, mid, high);

        if(leftArray.sum >= rightArray.sum && leftArray.sum >= crossArray.sum){
            return leftArray;
        }
        else if(rightArray.sum >= leftArray.sum && rightArray.sum >= crossArray.sum){
            return rightArray;
        }
        else{
            return crossArray;
        }
    }
}
