#include "FileLoader.h"

vector<char> FileLoader::load(char path[]){
    ifstream inFile;
    inFile.open(path);
    if (inFile.fail()){
        cerr << "unable to open file " << path << endl;
        exit(1);
    }
    vector<char> result(6500);
    char ch;
    while (inFile.get(ch)) result.push_back(ch);

    return result;
}
