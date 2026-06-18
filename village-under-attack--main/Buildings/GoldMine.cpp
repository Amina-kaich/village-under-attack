#include "GoldMine.h"

GoldMine::GoldMine(Position pos)
    : ResourceGenerator(3, 3, "⛏️", 0, 100, 3, pos, 500) {} // Size 3x3, emoji ⛏, 100 elixir, max 3, 500 health
    // Note: Repr changes to 🪙 when full (handled in Board rendering)
