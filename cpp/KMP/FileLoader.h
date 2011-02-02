/* 
 * File:   FileLoader.h
 * Author: Karlson
 *
 * Created on 1. Februar 2011, 21:28
 */

#ifndef FILELOADER_H
#define	FILELOADER_H

#include <vector>
#include <fstream>
#include <iostream>
#include <cstdlib>
using namespace std;
typedef unsigned int uint;

class FileLoader {
public:
    void load(char path[],char* &string, uint* length);
};

#endif	/* FILELOADER_H */

