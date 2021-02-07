#ifndef INIREADER_HPP_INCLUDED
#define INIREADER_HPP_INCLUDED

#include <map>
#include <string>
#include <list>



using namespace std;

class INIGroup;

class INIReader{
public:

    INIReader(const char*);

    string getValue(string, string);
protected:

    bool isGroup(string);

    bool isGroupEnd(string, string);

    bool isKeyPair(string);

    INIGroup* getGroupFromName(string);

    string getGroup(string);

    string getKey(string);

    string getValue(string);

    string stripComments(string);

    string removeWhitespaces(string a);

private:

    list<INIGroup*> groups;

};

#endif // INIREADER_HPP_INCLUDED
