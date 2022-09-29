#include "../include/bankSystem.h"
#include "../include/utils.h"

BankSystem::BankSystem() { m_country = utils::net::getLocalCountry(); }
