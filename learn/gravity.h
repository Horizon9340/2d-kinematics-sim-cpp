class gravity {
public:
  //gravity(); //default
  gravity(double g = 6.6743e-11); //set by user

  double computeForce(double m1, double m2, double r);
  double computeAcceleration(double m, double r);
  double getG() const;

private:
  double G;
};
