#pragma once
#include <string>
#include <iostream>

class Card
{
private:
    std::string m_suit;
    int m_rank;

public:
    Card(const std::string &suit, int rank);
    // void toString();
    int getValue() const;
    int getRank() const;

    friend std::ostream &operator<<(std::ostream &os, const Card &card);
};