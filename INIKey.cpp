#include "INIKey.hpp"

//Init
INIKey::INIKey(string a, string b){
    #ifdef __DEBUG__
        cout << "INIKey::INIKey(string(" << a << "), string(" << b << "))" << endl;
    #endif // __DEBUG__

    key = a;
    value = b;
}

//Returns key.
string INIKey::getKey(){
    #ifdef __DEBUG__
        cout << "INIKey::getKey()" << endl;
    #endif // __DEBUG__

    return key;
}

//Returns value.
string INIKey::getValue(){
    #ifdef __DEBUG__
        cout << "INIKey::getValue()" << endl;
    #endif // __DEBUG__

    return value;
}

//Sets key.
void INIKey::setKey(string a){
    #ifdef __DEBUG__
        cout << "INIKey::setKey(string(" << a << "))" << endl;
    #endif // __DEBUG__

    key = a;
}

//Sets value.
void INIKey::setValue(string a){
    #ifdef __DEBUG__
        cout << "INIKey::setKey(string(" << a << "))" << endl;
    #endif // __DEBUG__

    value = a;
}

