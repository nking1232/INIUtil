#ifndef INIKEY_HPP_INCLUDED
#define INIKEY_HPP_INCLUDED

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class INIKey{
public:

    INIKey(string, string);

    string getKey();

    string getValue();

    void setKey(string);

    void setValue(string);

protected:

private:

    string key;
    string value;

};

#endif // INIKEY_HPP_INCLUDED
