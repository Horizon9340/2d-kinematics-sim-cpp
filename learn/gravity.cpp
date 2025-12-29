#include "gravity.h"

gravity::gravity(double g){
  G = g;
};

double gravity::computeForce(double m1, double m2, double r){
  return G * m1 * m2 / (r * r);
};

double gravity::computeAcceleration(double m, double r) {
  return G * m / (r * r);
};

double gravity::getG() const {
  return G;
};
