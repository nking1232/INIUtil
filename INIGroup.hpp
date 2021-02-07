#ifndef INIGROUP_HPP_INCLUDED
#define INIGROUP_HPP_INCLUDED

#include <list>
#include <string>
#include <iostream>
#include <sstream>



class INIKey;

using namespace std;

class INIGroup{
public:
    INIGroup();

    INIGroup(string);

    INIGroup(string, list< INIKey* >);

    void addChild(INIGroup*);

    void addKey(string, string);

    void addKey(INIKey*);

    void setParent(INIGroup*);

    INIGroup* getChild(string);

    string getGroup();

    INIKey* getKey(string);

    string getValueFromKey(string);

    INIGroup* GetParent();

    bool isRoot();

    string write();

protected:

private:

    string group;
    INIGroup *parent;
    list< INIGroup* > children;
    list< INIKey* > keys;
};

#endif // INIGROUP_HPP_INCLUDED
