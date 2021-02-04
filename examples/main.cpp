#include <iostream>

#include "INIReader.hpp"
#include "INIWriter.hpp"

using namespace std;

int main()
{
    try{
        INIReader ini("characters.ini");//Load ini for reading.

        cout << "Get: " << ini.getValue("crecent", "name");// Get the value of name in group crecent.

    }catch(exception& e){//If all is good we'll never reach this.

        cout << e.what() << '\n';

    }

    try{
        INIWriter wini("cheats.ini");//Open cheats.ini for writing create if not exists.

        wini.addGroup("god");//Adds group "[god]".

        wini.addKey("god", "name", "godmode");// Adds "name" to "[god]" with value "godmode".

        wini.write();//Write to file.
    }catch(exception& e){

        cout << e.what() << '\n';

    }
    return 0;
}
