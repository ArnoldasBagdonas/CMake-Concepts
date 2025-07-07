#include <cassert> 
#include "CoinFlipper/CoinFlipper.hpp"

CoinFlipper::CoinFlipper(Rng* rng) : _rng(rng)
{
    assert(_rng);
}

CoinFlipper::Result CoinFlipper::flipCoin() const
{
    const double val = _rng->generate(0.0, 1.0);
    assert((0.0 <= val) && (val <= 1.0));
    return (val < 0.5) ? HEADS : TAILS;
}