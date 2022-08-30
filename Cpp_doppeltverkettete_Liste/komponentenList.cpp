//-------------------------------------------------------------------
// KomponentenList
// Copyright 26.04.2022
// Author: Thomas Pongratz
//-------------------------------------------------------------------
#include "komponentenList.h"
#include <stdexcept>

//int KomponentenList::counter = 0; //static AttributInitialisierung (c++11)

KomponentenList::KomponentenList()
    : counter{0}, first{nullptr} {}

KomponentenList::~KomponentenList() {
    KomponentenElement* tmp = nullptr;
    while (first != end()) {
        tmp = first->next;
        delete first;
        first = tmp;
    }
    counter = 0;
}

KomponentenElement* KomponentenList::getElement(int pos) const {
    KomponentenElement* curr = nullptr;
    if (pos >= 0 && pos < counter) {
        curr = first;
//        while (curr != nullptr) {                         // verursacht segfault!!!
        for (int i = 0; curr != nullptr && i < pos; ++i) {
            curr = curr->next;
        }
    }
    return curr;
}

Komponente const* KomponentenList::at(int pos) const {
    KomponentenElement* curr = getElement(pos);
    return (curr != nullptr) ? curr->k : nullptr;
//    return (0 <= pos && pos < counter) ? getElement(pos)->k : nullptr;
}

int KomponentenList::erase(int pos) {
    int erg = -1;
    KomponentenElement* a = getElement(pos);
    if (a != end()) {
        erg = pos;
        KomponentenElement* n = a->next;
        KomponentenElement* b = a->before;
        if (n != end()) {
            n->before = b;
        }
        if (b != end()) {
            b->next = n;
        }
        if (a == first) {
            first = a->next;
            if (first != end()) {
                first->before = end();
            }
        }
        delete a;
        --counter;
    }
    return erg;
}

void KomponentenList::push_back(Komponente* k) {
    KomponentenElement* newElement = new KomponentenElement;
    newElement->next = nullptr;
    newElement->k = k;
    if (first == end()) {
        newElement->before = nullptr;
        newElement->next = nullptr;
        first = newElement;
    } else {
// fuer einfach verkettete Liste
//        KomponentenElement* curr = first;
//        while (curr->next != end()) {
//            curr = curr->next;
//        }
        KomponentenElement* curr = getElement(counter - 1);
        newElement->before = curr;
        curr->next = newElement;
    }
    ++counter;
}




