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

////before und next zeigen immer auf das nächste element und nicht auf die next und bevors direkt!!!!!
//int KomponentenList::erase(int pos){
//    int erg = -1;
////    if (pos>=counter || pos<0){
////        //std::cerr << "Listenindex nicht vorhanden Liste endet bei: " << counter-1 << std::endl;
////        return -1;
////    }

//    //erstes Element
//    if(pos==0 && pos<counter){
//        KomponentenElement* n=getElement(pos);
//        //first neu setzten
//        first=getElement(pos+1);
//        //before auf nullptr setzen
//        if(first){
//            first->before=nullptr;
//        }
//        delete n;
//        counter--;
////        return pos;
//        erg = pos;

//    } else {


//    //alles dazwischen
//    if(pos>=1 && pos<counter-1){
//        KomponentenElement *n=getElement(pos);
//        //before und next zwischenspeichern
//        KomponentenElement *before_tmp=n->before;
//        KomponentenElement *next_tmp=n->next;

//        //before und next verbinden
////        KomponentenElement *komp_elem_before=n->before;
////        KomponentenElement *komp_elem_next=n->next;

////        komp_elem_before->next=next_tmp;
////        komp_elem_next->before=before_tmp;
//        before_tmp->next = next_tmp;
//        next_tmp->before = before_tmp;


//        counter--;
//        //löschen erst am Schluss damit Index in getElement() nicht verschoben wird!
//        delete n;

////        return pos; //Indexposition bleibt gleich weil nachfolgendes element nachrutscht?
//        erg = pos;
//    }

//    //letztes Element
//    if(pos==counter-1){
////        int erg = 0;
//        if(first){
//            KomponentenElement *n=getElement(pos);
//            //Von vorletztem Element next auf nullptr setzten
//            KomponentenElement *next_to_last=n->before;           //getElement(pos-1);
//            next_to_last->next=nullptr;

//            counter--;
//            delete n;
////            return pos;
//            erg = pos;
//        }
////        else{
////            return 0;
////        }
////        return erg;
//    }
////    return -1;
//    }
//    return erg;
//}

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




