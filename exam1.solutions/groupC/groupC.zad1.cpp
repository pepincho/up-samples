// solve.my.exam.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

typedef unsigned int uint;

uint gets( uint n ) {
    int res = 0;

    do {
        res += n % 10;
        n /= 10;
    } while ( n );
    return res;
};

// find first n numbers such that the product of their digits
// can be divided by k

int main()  {
    uint n = 4;
    uint k = 12;
    uint cnum = 1;
    do {
        if (gets(cnum) == k) {
                printf("%d ", cnum);
                n--;
        }
        cnum++;
    } while(n>0);
}

