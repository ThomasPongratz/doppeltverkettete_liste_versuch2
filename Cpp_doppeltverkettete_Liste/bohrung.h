//-------------------------------------------------------------------
// Bohrung
// Copyright 26.04.2022
// Author: Thomas Pongratz
//-------------------------------------------------------------------
#ifndef BOHRUNG_H
#define BOHRUNG_H

#include "komponente.h"

class Bohrung : public Komponente {
public:
    explicit Bohrung(double x_ = 0.0, double y_ = 0.0, double diam = 6.0);
    ~Bohrung();
    double getDiameter() const;
    void output(std::ostream& os) const;
private:
    double diameter;
};

#endif // BOHRUNG_H
