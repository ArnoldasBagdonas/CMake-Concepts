#pragma once

class Rng {
  public:
    virtual ~Rng() {};
    virtual double generate(double min, double max) = 0;
};
