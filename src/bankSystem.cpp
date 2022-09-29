#include "../include/bankSystem.h"

BankSystem::BankSystem() { m_country = getLocalCountry(); }

std::string_view BankSystem::getLocalCountry() { return ""; }
