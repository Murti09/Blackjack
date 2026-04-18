#pragma once
#include "card.h"
#include <vector>

int calculateHandValue(const std::vector<Card>& hand);
void printCards(std::string name, const std::vector<Card>& hand);