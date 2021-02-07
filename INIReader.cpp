#include "INIReader.hpp"

#include <iostream>
#include <fstream>

#include "INIGroup.hpp"

using namespace std;

//Init.
INIReader::INIReader(const char* file){
    #ifdef __DEBUG__
        cout << "INIReader::INIReader(const char*(" << file << "))" << endl;
    #endif // __DEBUG__

    ifstream a(file);
    string b;

    map<string, // Key
    string> tm; // Value

    INIGroup* currentGroup = 0;

    if(a.is_open()){
            while( getline( a, b) ){
                    b = stripComments(b);
                    b = removeWhitespaces(b);
                    if(isGroup(b)){

                        INIGroup* g = new INIGroup(getGroup(b));
                        if(currentGroup){
                            g->setParent(currentGroup);
                            currentGroup->addChild(g);
                            currentGroup = g;
                        }else{
                            currentGroup = g;
                            groups.push_back(g);
                        }
                    }
                    if(currentGroup !=0){
                        if(isGroupEnd(b, currentGroup->getGroup())){
                            currentGroup = currentGroup->GetParent();


                        }
                    }
                    if(isKeyPair(b)){
                        currentGroup->addKey(getKey(b), getValue(b));

                    }

            }
    }
    a.close();
}

//Returns value in key within group.
string INIReader::getValue(string group, string key){
    #ifdef __DEBUG__
        cout << "INIReader::getValue(string(" << group << "), string(" << key << "))" << endl;
    #endif // __DEBUG__

    INIGroup* a = getGroupFromName(group);
    if(!a){
        return string("NULL");
    }
    return a->getValueFromKey(key);

}

//Returns true if is [group], false otherwise.
bool INIReader::isGroup(string a){
    #ifdef __DEBUG__
        cout << "INIReader::isGroup(string(" << a << "))" << endl;
    #endif // __DEBUG__

    if(a.find('[') != string::npos || a.find(']') != string::npos){
        if(a.find("/") != string::npos){
            return false;
        }
        return true;
    }
    return false;
}

//Is group end tag [/end].
bool INIReader::isGroupEnd(string a, string b){
    #ifdef __DEBUG__
        cout << "INIReader::isGroupEnd(string(" << a << "), string(" << b << "))" << endl;
    #endif // __DEBUG__

    string c = "[/";
    c += b;
    c += "]";
    if(a.find(c) != string::npos){
            return true;
    }
    return false;
}

//Returns true if is key=value, false otherwise.
bool INIReader::isKeyPair(string a){
    #ifdef __DEBUG__
        cout << "INIReader::isKeyPair(string(" << a << "))" << endl;
    #endif // __DEBUG__
    if(a.find("=") != string::npos){
        return true;
    }
    return false;
}

//Returns a group via name.
INIGroup* INIReader::getGroupFromName(string a){
    #ifdef __DEBUG__
        cout << "INIReader::getGroupFromName(string(" << a << "))" << endl;
    #endif // __DEBUG__
    cout << a << endl;
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

//Returns group in [group].
string INIReader::getGroup(string a){
    #ifdef __DEBUG__
        cout << "INIReader::getGroup(string(" << a << "))" << endl;
    #endif // __DEBUG__
    unsigned Start = a.find("[") + 1;
    unsigned End = a.find("]") - 1;
    string b = a.substr(Start, End);
    return b;

}

//Returns key in key=value.
string INIReader::getKey(string a){
    #ifdef __DEBUG__
        cout << "INIReader::getKey(string(" << a << "))" << endl;
    #endif // __DEBUG__
    return a.substr(0, a.find("=", 0) );
}

//Returns value in key=value.
string INIReader::getValue(string a){
    #ifdef __DEBUG__
        cout << "INIReader::getValue(string(" << a << "))" << endl;
    #endif // __DEBUG__
    string b = a;
    b.erase(0, a.find("=", 0) + 1);
    return b;
}

//Strips Comments should they exist.
string INIReader::stripComments(string a){
    #ifdef __DEBUG__
        cout << "INIReader::stripComments(string(" << a << "))" << endl;
    #endif // __DEBUG__

    if(a.find("#") != string::npos){
        return a.substr(0, a.find("#", 0) );
    }
    return a;
}

//Removes whitespaces should they exist.
string INIReader::removeWhitespaces(string a){
    #ifdef __DEBUG__
        cout << "INIReader::removeWhitespaces(string(" << a << "))" << endl;
    #endif // __DEBUG__

    int length = a.length();
    for(int i = 0; i < length; i++){
        if(isspace(a[i])){
            a.erase(i, 1);
            length--;
            i--;
        }
    }
    return a;
}
