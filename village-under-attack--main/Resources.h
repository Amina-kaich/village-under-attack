#ifndef RESOURCES_H
#define RESOURCES_H

class Resources {
public:
    int gold;
    int elixir;

    Resources(int gold = 400, int elixir = 400); // Initial values from spec (page 11)
    void addGold(int amount);
    void addElixir(int amount);
    bool consumeGold(int amount);
    bool consumeElixir(int amount);
};

#endif
