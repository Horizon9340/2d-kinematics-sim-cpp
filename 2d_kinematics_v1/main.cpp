#include <iostream>
#include <string>
#include <cmath>

double const gravity = 9.81;
double dt = 0.01;

double x = 0;
double y = 0;
double t = 0;

double v = 10;
double theta = 30;

double vx = v * cos(theta * 3.14159265358979323846 / 180);
double vy = v * sin(theta * 3.14159265358979323846 / 180);

double updateX(double x, double velocityX) {
  x += velocityX * dt;
  vx = velocityX;
  return x;
}

double updateY(double y, double velocityY) {
  velocityY -= gravity * dt;
  vy = velocityY;
  y += velocityY * dt;
  return y;
}

int main () {
  while (y >= 0) {
    t += dt;
    x = updateX(x, vx);
    y = updateY(y, vy);
    std::cout << "X: " << x << "\nY: " << y << "\n";
  }
  std::cout << "Total time: " << t << " seconds.\n";
  return 0;
}
