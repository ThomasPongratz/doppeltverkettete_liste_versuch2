//-------------------------------------------------------------------
// %{Cpp:License:ClassName}
// Copyright 26.04.2022
// Author: Thomas Pongratz
//-------------------------------------------------------------------
#include <iostream>
#include <cmath>
#include "bohrung.h"
#include "fraesung.h"
#include "komponente.h"
#include "komponentenlist.h"

using std::cout;
using std::endl;

int main(){
    Bohrung b1{1, 2, 8}, b2{2, 6, 4}, b3{10, 8, 7}, b4{7, 2, 5};
    //Fraesung f1{2, 3, 5, 2.83, 45}, f2{6, 7, 6, 3, 0}, f3{17, 6, 4, 5.66, 45};
    Fraesung f1{2, 3, 5, 2*sqrt(2), 45*M_PI/180}, f2{6, 7, 6, 3, 0}, f3{17, 6, 4, 4*sqrt(2), 225*M_PI/180};

    KomponentenList list;
    list.push_back(&b1);
    list.push_back(&f1);
    list.push_back(&b3);
    list.push_back(&f2);
    list.push_back(&b4);
    list.push_back(&f3);
    list.push_back(&b2);

    cout << list.size() << endl;
    cout << "Ausgabe der Liste" << endl;
    for (int i = 0; i < list.size(); ++i) {
        list.at(i)->output(cout);
        cout << endl;
    }

/*
    b1.output(cout);
    cout << endl;
    //f1.output(cout);
    cout << f1;
    cout << endl;
    b2.output(cout);
    cout << endl;
    f2.output(cout);
    cout << endl;
    b3.output(cout);
    cout << endl;
    f3.output(cout);
    cout << endl;
    b4.output(cout);
    cout << endl;
*/

    return 0;
}
