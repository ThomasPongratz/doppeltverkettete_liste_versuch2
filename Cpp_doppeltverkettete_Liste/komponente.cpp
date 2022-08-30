//-------------------------------------------------------------------
// Komponente
// Copyright 26.04.2022
// Author: Thomas Pongratz
//-------------------------------------------------------------------
#include "komponente.h"

Komponente::Komponente(double xPos, double yPos) : x{xPos}, y{yPos} {}

Komponente::~Komponente() {}

double Komponente::getX() const { return x; }

double Komponente::getY() const { return y; }

void Komponente::output(std::ostream& os) const {
    os << "(" << getX() << ", " << getY() << ")";
}
