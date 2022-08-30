//-------------------------------------------------------------------
// %{Cpp:License:ClassName}
// Copyright 26.04.2022
// Author: Thomas Pongratz
//-------------------------------------------------------------------
#ifndef KOMPONENTENELEMENT_H
#define KOMPONENTENELEMENT_H

#include "komponente.h"

struct KomponentenElement {
    Komponente* k;
    KomponentenElement* before;
    KomponentenElement* next;
};

#endif // KOMPONENTENELEMENT_H
