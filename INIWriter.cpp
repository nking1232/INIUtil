#include "INIWriter.hpp"


INIWriter::INIWriter(string a){
    file.open(a.c_str());
}

void INIWriter::addGroup(string a){
    map< string, string > tm;
    groups.insert(pair< string, map< string, string > >(a, tm));
}

//Adds a keypair to the provided group
void INIWriter::addKey(string group, string key, string value){
    map<string, map<string, string> >::iterator g = groups.find(group);
    g->second.insert(pair< string, string>(key, value));
}

//Writes all groups to ini file.
void INIWriter::write(){

    for (map< string, map< string, string > >::iterator it=groups.begin(); it!=groups.end(); ++it){
            file << "[" << it->first << "]" << endl;
            for(map< string, string >::iterator iit=it->second.begin(); iit!=it->second.end(); iit++){
                file << iit->first << "=" << iit->second << endl;
            }
    }
}
