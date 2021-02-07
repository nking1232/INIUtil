#ifndef INIWRITER_HPP_INCLUDED
#define INIWRITER_HPP_INCLUDED

#include <string>
#include <list>
#include <iostream>
#include <fstream>

using namespace std;

class INIGroup;


class INIWriter{

public:

    INIWriter(string);

    void addChildtoGroup(string, string);

    void addGroup(string);

    void addKey(string, string, string);

    INIGroup* getGroupFromName(string a);

    void write();

    ofstream file;

protected:



private:

    list< INIGroup* > groups;

};

#endif // INIWRITER_HPP_INCLUDED
