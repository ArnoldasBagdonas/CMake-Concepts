#pragma once

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "CoinFlipper/Rnd.hpp"

class MockRng : public Rng {
  public:
    MOCK_METHOD2(generate, double(double, double));
};
