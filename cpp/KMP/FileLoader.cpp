#include "FileLoader.h"

void FileLoader::load(char path[], char* &string, uint* length) {
    ifstream inFile;
    inFile.open(path);
    if (inFile.fail()) {
        cerr << "unable to open file " << path << endl;
        exit(1);
    }
    char ch;
    *length = 0;
    inFile.seekg(0, ios::end);
    *length = inFile.tellg();
    string = new char[*length];
    inFile.seekg(0, ios::beg);
    inFile.read(string, *length);
    inFile.close();
}
