#ifndef INIWRITER_HPP_INCLUDED
#define INIWRITER_HPP_INCLUDED

#include <string>
#include <map>
#include <iostream>
#include <fstream>


using namespace std;


class INIWriter{

public:

    INIWriter(string);

    void addGroup(string);

    void addKey(string, string, string);

    void write();

protected:



private:

    ofstream file;

    map< string, map< string, string > > groups;

};

#endif // INIWRITER_HPP_INCLUDED
