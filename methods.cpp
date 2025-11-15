#include "methods.h"

int calculateHandValue(const std::vector<Card>& hand)
{
    int value = 0;
    int anzAss = 0;

    for (const Card &s : hand)
    {
        value += s.getValue();
        if (s.getRank() == 1)
        {
            anzAss++;
        }
    }

    while (value > 21 && anzAss > 0)
    {
        value -= 10;
        anzAss--;
    }

    return value;
}

void printCards(std::string name, const std::vector<Card>& hand)
{
    std::cout << name << ":" << std::endl;
    for (const Card &c : hand)
    {
        std::cout << c << std::endl;
    }
}