#include "Stronghold.h"

using namespace std;

Person::Person(const string& n, int a, const string& sc)
    : name(n), age(a), socialClass(sc), wealth(0.0), isAlive(true)
{
}

bool Person::getIsAlive() const
{
    return isAlive;
}

void Person::setIsAlive(bool alive)
{
    isAlive = alive;
}

string Person::getSocialClass() const
{
    return socialClass;
}

double Person::getWealth() const
{
    return wealth;
}

void Person::setWealth(double w)
{
    wealth = w;
}

string Person::getName() const { return name; }
int Person::getAge() const { return age; }



Peasant::Peasant(const string& n, int a)
    : Person(n, a, "Peasant"), foodProduction(1.0), taxRate(0.2)
{
}

void Peasant::update()
{
    if (!getIsAlive()) return;
    double production = foodProduction * (1.0 - taxRate);
    setWealth(getWealth() + production);
}

double Peasant::getFoodProduction() const
{
    return foodProduction;
}

void Peasant::setTaxRate(double rate)
{
    taxRate = rate;
}

Merchant::Merchant(const string& n, int a)
    : Person(n, a, "Merchant"), tradeVolume(0.0), itemCount(0)
{
    for (int i = 0; i < 10; i++) {
        inventory[i] = 0.0;
        itemNames[i] = "";
    }
}

void Merchant::update()
{
    if (!getIsAlive()) return;
    double profit = tradeVolume * 0.1;
    setWealth(getWealth() + profit);
}

void Merchant::trade(const string& item, double amount)
{
    tradeVolume += amount;

    // Check if item already exists in inventory
    for (int i = 0; i < itemCount; i++) {
        if (itemNames[i] == item) {
            inventory[i] += amount;
            return;
        }
    }

    // Add new item if there's space
    if (itemCount < 10) {
        itemNames[itemCount] = item;
        inventory[itemCount] = amount;
        itemCount++;
    }
}

double Merchant::getTradeVolume() const
{
    return tradeVolume;
}

Noble::Noble(const string& n, int a)
    : Person(n, a, "Noble"), influence(100), subjectCount(0)
{
    for (int i = 0; i < 20; i++) {
        subjects[i] = nullptr;
    }
}

Noble::~Noble()
{
}

void Noble::update()
{
    if (!getIsAlive()) return;
    double income = influence * 0.01;
    setWealth(getWealth() + income);
}

void Noble::addSubject(Person* subject)
{
    if (subjectCount < 20) {
        subjects[subjectCount] = subject;
        subjectCount++;
        influence += 10;
    }
}

int Noble::getInfluence() const
{
    return influence;
}