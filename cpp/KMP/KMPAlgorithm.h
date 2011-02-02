/* 
 * File:   KMPAlgorithm.h
 * Author: Karlson
 *
 * Created on 1. Februar 2011, 10:33
 */
#include <iostream>
#include <string>
#include <list>
#include <cstdlib>
using namespace std;

struct SubString {
    int shift1;
    int shift2;
};
typedef unsigned int uint;

class KMPAlgorithm {
public:
    list<SubString> run(char* t1, char* t2);
    uint s_length, t_length;

private:
    static const bool debug = false;
    uint* prefixFunction;

    void calculatePrefixFunction(char* pattern, uint start, uint minLength);
};

