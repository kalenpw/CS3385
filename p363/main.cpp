//------------------------------------------------------------
//
// CS 3385
// Project p363
//
// In this project you will implement dynamic programming
// solutions to the cut rod and fibonacci problems using
// memoization.
//
// We won't call a memoized function with anything greater
// than n=100.
//
// File to submit:
//   * dynamic.h
// 
//------------------------------------------------------------

#include <iostream>
#include <sstream>

#include "./util.h"
#include "./dynamic.h"

using namespace std;

//------------------------------------------------------------
// Tests
//------------------------------------------------------------
int runTests() {

  int numFails = 0;
  int testNum = 0;

   {
     int callcount = 0;
     int p[] = { 0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30 };
     TEST(cutRodNaive(p, 1, callcount) == 1);//1
     TEST(cutRodNaive(p, 2, callcount) == 5);//2
     TEST(cutRodNaive(p, 3, callcount) == 8);//3
     TEST(cutRodNaive(p, 4, callcount) == 10);//4
     TEST(cutRodNaive(p, 5, callcount) == 13);//5
     TEST(cutRodNaive(p, 6, callcount) == 17);//6
     TEST(cutRodNaive(p, 7, callcount) == 18);//7
     TEST(cutRodNaive(p, 8, callcount) == 22);//8
     TEST(cutRodNaive(p, 9, callcount) == 25);//9
     TEST(cutRodNaive(p, 10, callcount) == 30);//10
  
     callcount = 0;
     cutRodNaive(p, 1, callcount);
     TEST(callcount == 2);//11

     callcount = 0;
     cutRodNaive(p, 4, callcount);
     TEST(callcount == 16);//12

     callcount = 0;
     cutRodNaive(p, 24, callcount);
     TEST(callcount == 16777216);//13
   }

   {
     int callcount = 0;
     int p[] = { 0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30 };
     TEST(cutRodMemo(p, 1, callcount) == 1);//14
     TEST(cutRodMemo(p, 5, callcount) == 13);//15
     TEST(cutRodMemo(p, 10, callcount) == 30);//16
  
     callcount = 0;
     cutRodMemo(p, 1, callcount);//17
     TEST(callcount == 2);

     callcount = 0;
     cutRodMemo(p, 4, callcount);//18
     TEST(callcount == 11);

     callcount = 0;
     cutRodMemo(p, 24, callcount);
     TEST(callcount == 301);//19
   }

   {
     // The fibonacci sequence is
     //  index: 0  1  2  3  4  5  6  7
     //  value: 1  1  2  3  5  8 13 21
     int callcount = 0;
     TEST(fibNaive(0, callcount) == 1);//20
     TEST(fibNaive(1, callcount) == 1);
     TEST(fibNaive(2, callcount) == 2);
     TEST(fibNaive(3, callcount) == 3);
     TEST(fibNaive(4, callcount) == 5);
     TEST(fibNaive(5, callcount) == 8);//25
  
     callcount = 0;
     fibNaive(0, callcount);
     TEST(callcount == 1);//26

     callcount = 0;
     fibNaive(4, callcount);
     TEST(callcount == 9);//27

     callcount = 0;
     fibNaive(34, callcount);
     TEST(callcount == 18454929);//28
   }

   {
     // The fibonacci sequence is
     //  index: 0  1  2  3  4  5  6  7
     //  value: 1  1  2  3  5  8 13 21
     int callcount = 0;
     TEST(fibMemo(0, callcount) == 1);//29
     TEST(fibMemo(1, callcount) == 1);//30
     TEST(fibMemo(2, callcount) == 2);//31
     TEST(fibMemo(3, callcount) == 3);//32
     TEST(fibMemo(4, callcount) == 5);//33
     TEST(fibMemo(5, callcount) == 8);//34
  
     callcount = 0;
     fibMemo(0, callcount);
     TEST(callcount == 1);//35
  
     callcount = 0;
     fibMemo(4, callcount);
     TEST(callcount > 1 && callcount < 10);//36

     callcount = 0;
     fibMemo(34, callcount);
     TEST(callcount > 30 && callcount < 70); //37

     callcount = 0;
     fibMemo(4, callcount);
     TEST(callcount == 7);//38

     callcount = 0;
     fibMemo(34, callcount);
     TEST(callcount == 67);//39
   }

  const int numSuccesses = testNum - numFails;
  cout << numSuccesses << "/" << testNum << " tests succeeded" << endl;

  return numFails;
}

int main() {
  return runTests();
}

