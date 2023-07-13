#pragma once

#include "CoinFlipper/Rnd.hpp"

class CoinFlipper {
  private:
    Rng* _rng; // held, not owned

  public:
    enum Result {
        HEADS = 0,
        TAILS = 1
    };

    explicit CoinFlipper(Rng* rng);
    Result flipCoin() const;
};