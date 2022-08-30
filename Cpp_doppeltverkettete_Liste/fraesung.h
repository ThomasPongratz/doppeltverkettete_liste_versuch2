//-------------------------------------------------------------------
// Fraesung
// Copyright 26.04.2022
// Author: Thomas Pongratz
//-------------------------------------------------------------------
#ifndef FRAESUNG_H
#define FRAESUNG_H

#include "bohrung.h"

class Fraesung : public Bohrung {
public:
    explicit Fraesung(double x, double y, double diam, double l, double a = 0.0);
    ~Fraesung();
    double getLength() const;
    double getAngle() const;
    double getEndX() const;
    double getEndY() const;
    void output(std::ostream& os) const;
private:
    double length;
    double angle;
};

#endif // FRAESUNG_H
