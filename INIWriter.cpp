#include "INIWriter.hpp"

#include "INIGroup.hpp"

//Init.
INIWriter::INIWriter(string a){
    #ifdef __DEBUG__
        cout << "INIWriter::INIWriter(string(" << a << "))" << endl;
    #endif // __DEBUG__

    file.open(a.c_str());
}


//Adds child to group a using b as the name
void INIWriter::addChildtoGroup(string a, string b){
    #ifdef __DEBUG__
        cout << "INIWriter::addKey(string(" << a << "), string(" << b << "))" << endl;
    #endif // __DEBUG__

    INIGroup *c = getGroupFromName(a);
    if(c){
        c->addChild(new INIGroup(b));
    }
}

//Adds group using a as name.
void INIWriter::addGroup(string a){
    #ifdef __DEBUG__
        cout << "INIWriter::addGroup(string(" << a << "))"<< endl;
    #endif // __DEBUG__

    INIGroup *group = new INIGroup(a);
    groups.push_back(group);
}

//Adds a keypair to the provided group
void INIWriter::addKey(string group, string key, string value){
    #ifdef __DEBUG__
        cout << "INIWriter::addKey(string(" << group << "), string(" << key << "), string(" << value << "))" << endl;
    #endif // __DEBUG__

    INIGroup* g = getGroupFromName(group);
    if(g){
        g->addKey(key, value);
    }
}

//Returns group from name.
INIGroup* INIWriter::getGroupFromName(string a){
    #ifdef __DEBUG__
        cout << "INIWriter::getGroupFromName(string(" << a << "))" << endl;
    #endif // __DEBUG__

    list< INIGroup* >::iterator it;
    INIGroup* b = 0;
    for (it=groups.begin(); it!=groups.end(); ++it){
            INIGroup* c = *it;
            if(a.compare(c->getGroup()) == 0){
                b = c;
                break;
            }
            b = 0;
    }
    return b;
}

//Writes all groups to ini file.
void INIWriter::write(){
    #ifdef __DEBUG__
        cout << "INIWriter::write()" << endl;
    #endif // __DEBUG__

    list< INIGroup* >::iterator it;
    for(it=groups.begin(); it!=groups.end(); it++){
            INIGroup *group = *it;
            if(group){
                string out = group->write();
                file << out;
            }
    }
}
