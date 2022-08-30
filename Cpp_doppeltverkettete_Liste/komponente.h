//-------------------------------------------------------------------
// Komponente
// Copyright 26.04.2022
// Author: Thomas Pongratz
//-------------------------------------------------------------------
#ifndef KOMPONENTE_H
#define KOMPONENTE_H

#include <iostream>

class Komponente{
public:
    explicit Komponente(double xPos = 0.0, double yPos = 0.0);
    virtual ~Komponente();
    double getX() const;
    double getY() const;
    virtual void output(std::ostream& os) const;
private:
    double x;
    double y;
};

inline std::ostream& operator<<(std::ostream& os, const Komponente& k) {
    k.output(os);
    return os;
}

#endif // KOMPONENTE_H
