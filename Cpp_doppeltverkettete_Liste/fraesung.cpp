//-------------------------------------------------------------------
// Fraesung
// Copyright 26.04.2022
// Author: Thomas Pongratz
//-------------------------------------------------------------------
#include "fraesung.h"
#include <cmath>

Fraesung::Fraesung(double x, double y, double diam, double l, double a)
    : Bohrung(x, y, diam), length{l}, angle{a} {
    l < 0 ? length = 0 : length = l;
}
Fraesung::~Fraesung() {}
double Fraesung::getLength() const { return length; }
double Fraesung::getAngle() const { return angle; }
double Fraesung::getEndX() const {
    return getX() + cos(getAngle()) * getLength();
}
double Fraesung::getEndY() const {
    return getY() + sin(getAngle()) * getLength();
}
void Fraesung::output(std::ostream& os) const {
    os << "Fraesung mit Start: ";
    Komponente::output(os);
    os << " und Endpunkt: ("
       << getEndX() << ", "
       << getEndY() << "), Durchmesser: "
       << getDiameter();
}
