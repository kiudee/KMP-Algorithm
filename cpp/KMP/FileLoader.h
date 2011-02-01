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

class FileLoader {
public:
    vector<char> load(char path[]);
};

#endif	/* FILELOADER_H */

