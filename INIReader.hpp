#ifndef INIREADER_HPP_INCLUDED
#define INIREADER_HPP_INCLUDED

#include <map>
#include <string>

using namespace std;

class INIReader{
public:

    INIReader(const char*);

    string getValue(string, string);
protected:

    bool isGroup(string);

    bool isKeyPair(string);

    string getGroup(string);

    string getKey(string);

    string getValue(string);

    string stripComments(string);

private:

    map< string, map < string, string> > groups;
    std::map< string, map< string, string> >::iterator groupStart;
    std::map< string, map< string, string> >::iterator currentGroup;

    std::map<string, string>::iterator keyPairStart;
    std::map<string, string>::iterator currentKeyPair;



};

#endif // INIREADER_HPP_INCLUDED
