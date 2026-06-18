#include "ElixirCollector.h"

ElixirCollector::ElixirCollector(Position pos)
    : ResourceGenerator(3, 3,"🧪", 100, 0, 3, pos, 500) {} // Size 3x3, emoji 🧪, 100 gold, max 3, 500 health
    // Note: Repr changes to 🧴 when full (handled in Board rendering)

bool ElixirCollector::collect(Resources& resources) {
    if (current > 0) {
        resources.addElixir(current);
        current = 0;
        isFull = false;
        return true;
    }
    return false;
}
