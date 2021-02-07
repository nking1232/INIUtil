#include "INIGroup.hpp"
#include "INIKey.hpp"

//Init.
INIGroup::INIGroup(){
    #ifdef __DEBUG__
        cout << "INIGroup::INIGroup()" << endl;
    #endif // __DEBUG__

    parent = 0;
}

//Init.
INIGroup::INIGroup(string a){
    #ifdef __DEBUG__
        cout << "INIGroup::INIGroup(string(" << a << "))" << endl;
    #endif // __DEBUG__

    group = a;
    parent = 0;
}

//Init
INIGroup::INIGroup(string a, list< INIKey* > b){
    #ifdef __DEBUG__
        cout << "INIGroup::INIGroup(string(" << a << "), list< INIKey* >())" << endl;
    #endif // __DEBUG__

    group = a;
    keys = b;
    parent = 0;
}

//Adds a child using INIGroup object.
void INIGroup::addChild(INIGroup* a){
    #ifdef __DEBUG__
        cout << "INIGroup::addChild(string(" << a << "))" << endl;
    #endif // __DEBUG__

    children.push_back(a);
}

//Adds a key using a as key and b as value.
void INIGroup::addKey(string a, string b){
    #ifdef __DEBUG__
        cout << "INIGroup::addKey(string(" << a <<"), string(" << b << "))" << endl;
    #endif // __DEBUG__

    INIKey* c =  new INIKey(a, b);
    addKey(c);
}

//Adds a key using INIKey object.
void INIGroup::addKey(INIKey* a){
    #ifdef __DEBUG__
        cout << "INIGroup::addKey(INIKey*))" << endl;
    #endif // __DEBUG__

    keys.push_front(a);
}

//Sets this groups parent.
void INIGroup::setParent(INIGroup* a){
    #ifdef __DEBUG__
        cout << "INIGroup::setParent(INIGroup*))" << endl;
    #endif // __DEBUG__

    parent = a;
}

//Gets a child from this group by name.
INIGroup* INIGroup::getChild(string a){
    #ifdef __DEBUG__
        cout << "INIGroup::getChild(string(" << a << "))" << endl;
    #endif // __DEBUG__

    list< INIGroup* >::iterator it;
    INIGroup* b = 0;
    for (it=children.begin(); it!=children.end(); ++it){
            INIGroup* c = *it;
            if(a.compare(c->getGroup()) == 0){
                b = c;
                break;
            }
            b = 0;
    }
    return b;
}

//Gets the group name.
string INIGroup::getGroup(){
    #ifdef __DEBUG__
        cout << "INIGroup::getGroup()" << endl;
    #endif // __DEBUG__

    return group;
}

//Returns a key via name.
INIKey* INIGroup::getKey(string a){
    #ifdef __DEBUG__
        cout << "INIGroup::getKey(string(" << a << "))" << endl;
    #endif // __DEBUG__

    cout << a << endl;
    list< INIKey* >::iterator it;
    INIKey* b = 0;
    for (it=keys.begin(); it!=keys.end(); ++it){
        INIKey* c = *it;
        if(a.compare(c->getKey()) == 0){
               b = c;
               break;
        }
        b = 0;
    }
    return b;
}

//Returns the vale in key via name.
string INIGroup::getValueFromKey(string a){
    #ifdef __DEBUG__
        cout << "INIGroup::getValueFromKey(string(" << a << "))" << endl;
    #endif // __DEBUG__
    INIKey* b = getKey(a);
    if(!b)
    {
        return string("NULL");
    }
    return b->getValue();
}

//Returns this groups parent.
INIGroup* INIGroup::GetParent(){
    #ifdef __DEBUG__
        cout << "INIGroup::getParent()" << endl;
    #endif // __DEBUG__

    return parent;
}

//Returns true if this group has no parent.
bool INIGroup::isRoot(){
    #ifdef __DEBUG__
        cout << "INIGroup::isRoot()" << endl;
    #endif // __DEBUG__

    if(!parent){
        return true;
    }
    return false;
}

//Writes the groups data to a string.
string INIGroup::write(){
    #ifdef __DEBUG__
        cout << "INIGroup::write()" << endl;
    #endif // __DEBUG__

    stringstream a;
    list< INIKey* >::iterator it;
    a << "[" << group << "]" << endl;
    for(it=keys.begin(); it!=keys.end(); it++){
            INIKey *key = *it;
            string k=key->getKey(), v=key->getValue();
            a << k << "=" << v << endl;
    }
    list< INIGroup* >::iterator ita;
    for(ita=children.begin(); ita!=children.end(); ita++)
    {
        INIGroup *child = *ita;
        a << child->write() << endl;
    }
    a << "[/" << group << "]" << endl;
    return a.str();
}
