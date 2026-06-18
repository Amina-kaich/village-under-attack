#ifndef ELIXIRCOLLECTOR_H
#define ELIXIRCOLLECTOR_H
#include "ResourceGenerator.h"

class ElixirCollector : public ResourceGenerator {
public:
    ElixirCollector(Position pos);
     bool collect(Resources& resources) override;
};

#endif
