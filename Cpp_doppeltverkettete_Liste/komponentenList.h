//-------------------------------------------------------------------
// KomponentenList
// Copyright 26.04.2022
// Author: Thomas Pongratz
//-------------------------------------------------------------------
#ifndef KOMPONENTENLIST_H
#define KOMPONENTENLIST_H

#include "komponente.h"
#include "komponentenElement.h"

class KomponentenList {
public:
    KomponentenList();
    ~KomponentenList();

    int size() const { return counter; }
    Komponente const* at(int pos) const;
    int erase(int pos);
    void push_back(Komponente* k);
    KomponentenElement* end() const { return nullptr; }
    KomponentenElement* begin() const { return first; }
private:
//    static inline int counter = 0;  // c++17
//    static int counter;
    int counter;
    KomponentenElement* first;
    KomponentenElement* getElement(int pos) const;
};

#endif // KOMPONENTENLIST_H
