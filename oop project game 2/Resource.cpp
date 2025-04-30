#include "Stronghold.h"

using namespace std;

Resource::Resource(const string& n, double initial)
    : name(n), amount(initial), productionRate(0.0), consumptionRate(0.0)
{
}

void Resource::update()
{
    amount += productionRate - consumptionRate;
    if (amount < 0) amount = 0;
}

double Resource::getAmount() const
{
    return amount;
}

void Resource::setAmount(double a)
{
    amount = a;
}

void Resource::setProductionRate(double rate)
{
    productionRate = rate;
}

void Resource::setConsumptionRate(double rate)
{
    consumptionRate = rate;
}

Army::Army()
    : soldiers(0), morale(100.0), training(0.0), foodConsumption(1.0), payRate(1.0)
{
}

void Army::update()
{
    if (soldiers <= 0) return;
    morale = max(0.0, morale - 0.1);
    training = min(100.0, training + 0.1);
}

void Army::train()
{
    if (soldiers <= 0) return;
    training = min(100.0, training + 1.0);
    morale = max(0.0, morale - 0.5);
}

void Army::pay()
{
    if (soldiers <= 0) return;
    morale = min(100.0, morale + 5.0);
}

void Army::feed()
{
    if (soldiers <= 0) return;
    morale = min(100.0, morale + 2.0);
}

int Army::getSoldiers() const
{
    return soldiers;
}

double Army::getMorale() const
{
    return morale;
}

void Army::setMorale(double m)
{
    morale = max(0.0, min(10.0, m));
}