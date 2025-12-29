#include <iostream>
#include <string>
#include "gravity.h" //includes file defining gravity class

void doesSomethingIGuess() { //void means the function cannot have a return value
  std::cout << "You're lame man\n";
}
//note that functions must be declared before int main() if it will be used there

int main(){

  //understanding variable types
  //const double gravity = 9.81;
  double velocity, velocityX, velocityY, theta; //double means double precision floating point number (64 bits)

  //creating a string and printing it
  std::string hello = "hello";
  std::cout << &hello << "\n";

  //understanding character output
  std::cout << "I am " << 17 << " years old.\n";
  std::cout << "Hello world!\n";

  //for loop syntax, basically JS
  for (int i = 0; i <= 10; i++) {
    if (i == 4) {
      continue;
    }
    std::cout << i;
  }
  std::cout << "\n";

  doesSomethingIGuess();

  gravity normGravity; //declares an object for gravity class, uses default constructor so the normal gravitational constant
  std::cout << normGravity.getG() << "\n";
  std::cout << normGravity.computeForce(3,4,5) << "\n";
  std::cout << normGravity.computeAcceleration(5.972e24, 6.371e6) << " m/s^2 is the acceleration due to gravity on the surface of the Earth.\n";

  return 0; //gives an int return value to function so code doesn't break
}
