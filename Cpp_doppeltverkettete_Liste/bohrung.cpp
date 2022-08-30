//-------------------------------------------------------------------
// Bohrung
// Copyright 26.04.2022
// Author: Thomas Pongratz
//-------------------------------------------------------------------
#include "bohrung.h"

Bohrung::Bohrung(double x_, double y_, double diam)
    : Komponente(x_, y_), diameter{diam} {
    diam <= 0 ? diameter = 6.0 : diameter = diam;
}
Bohrung::~Bohrung() {}
double Bohrung::getDiameter() const { return diameter; }
void Bohrung::output(std::ostream& os) const {
    os << "Bohrung: ";
    Komponente::output(os);
    os << ", Durchmesser: " << getDiameter();
}
