#include "INIReader.hpp"

#include <iostream>
#include <fstream>

using namespace std;

//Init.
INIReader::INIReader(const char* file){
    cout << "make" << endl;
    ifstream a(file);
    string b;

    map<string, // Key
    string> tm; // Value

    string currentGroup;

    if(a.is_open()){
            cout << "open" << endl;
            while( getline( a, b) ){
                 cout << b << endl;
                    if(isGroup(b)){
                            if(!currentGroup.empty()){//We've not just started
                                groups.insert(pair< string , map< string, string > >(currentGroup, tm));
                                tm.erase(tm.begin(), tm.end());
                            }
                            b = stripComments(b);
                            currentGroup = getGroup(b);
                            cout << currentGroup << endl;
                            cout << "group" << endl;
                    }else if(isKeyPair(b)){

                        b = stripComments(b);
                        string c = getKey(b);


                        string d = getValue((b));

                        tm.insert(pair< string, string >(c, d));
                        cout << c << endl;
                        cout << d << endl;
                        cout << "keypair" << endl;

                    }

            }
            //Make sure we insert the last group.
            if(!currentGroup.empty()){//We've not just started
                                groups.insert(pair< string , map< string, string > >(currentGroup, tm));
                                tm.erase(tm.begin(), tm.end());
            }

    }
}

//Returns value in key within group.
string INIReader::getValue(string group, string key){
    cout << "Looking for: " << group << endl;
    map<string, map<string, string> >::iterator g = groups.find(group);
    cout << "Looking for: " << key << endl;
    map<string, string>::iterator k = g->second.find(key);
    return k->second;

}

//Returns true if is [group], false otherwise.
bool INIReader::isGroup(string a){
    if(a.find('[') != std::string::npos || a.find(']') != std::string::npos){
        return true;
    }
    return false;
}

//Returns true if is key=value, false otherwise.
bool INIReader::isKeyPair(string a){
    if(a.find("=") != std::string::npos){
        return true;
    }
    return false;
}

//Returns group in [group].
string INIReader::getGroup(string a){
    unsigned Start = a.find("[") + 1;
    unsigned End = a.find("]") - 1;
    string b = a.substr(Start, End);
    return b;

}

//Returns key in key=value.
string INIReader::getKey(string a){
    return a.substr(0, a.find("=", 0) );
}

//Returns value in key=value.
string INIReader::getValue(string a){
    string b = a;
    b.erase(0, a.find("=", 0) + 1);
    return b;
}

//Strips Comments should they exist.
string INIReader::stripComments(string a){

    if(a.find("#") != string::npos){
        return a.substr(0, a.find("#", 0) );
    }
    return a;
}
