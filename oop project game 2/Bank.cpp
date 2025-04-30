#include "Stronghold.h"
#include <fstream>
#include <iostream>

using namespace std;

// Simple absolute value function
double myAbs(double x) {
    return (x < 0) ? -x : x;
}

Bank::Bank(double initial)
    : treasury(initial), interestRate(0.05), corruptionLevel(0.0), loanCount(0)
{
    for (int i = 0; i < 10; i++) {
        loanAmounts[i] = 0.0;
        loanInterests[i] = 0.0;
    }
}

void Bank::update()
{
    for (int i = 0; i < loanCount; i++)
    {
        double interest = loanAmounts[i] * interestRate;
        loanInterests[i] += interest;
        treasury += interest;
    }
    corruptionLevel = min(100.0, corruptionLevel + 0.1);
}

void Bank::loan(double amount)
{
    if (amount <= 0 || loanCount >= 10) return;
    loanAmounts[loanCount] = amount;
    loanInterests[loanCount] = 0.0;
    loanCount++;
    treasury += amount;
}

void Bank::collectTaxes(double amount)
{
    if (amount <= 0) return;
    treasury += amount;
}

void Bank::audit()
{
    double expectedTreasury = 0.0;
    for (int i = 0; i < loanCount; i++)
    {
        expectedTreasury += loanAmounts[i] + loanInterests[i];
    }
    if (myAbs(treasury - expectedTreasury) > 1000.0)
    {
        corruptionLevel += 10.0;
    }
}

double Bank::getTreasury() const
{
    return treasury;
}

void Bank::setInterestRate(double rate)
{
    interestRate = rate;
}

//Kingdom::Kingdom(const string& n)
//    : name(n),stability(100.0), populationCount(0), resourceCount(0)
//{
//    army = new Army();
//    bank = new Bank(100.0);
//    ruler = nullptr;
//
//    for (int i = 0; i < 100; i++) {
//        population[i] = nullptr;
//    }
//
//    for (int i = 0; i < 10; i++) {
//        resources[i] = nullptr;
//    }
//}
//
//Kingdom::~Kingdom()
//{
//    delete army;
//    delete bank;
//
//    for (int i = 0; i < populationCount; i++) {
//        delete population[i];
//    }
//
//    for (int i = 0; i < resourceCount; i++) {
//        delete resources[i];
//    }
//}
//
//void Kingdom::update()
//{
//    for (int i = 0; i < populationCount; i++)
//    {
//        if (population[i]) {
//            population[i]->update();
//        }
//    }
//
//    for (int i = 0; i < resourceCount; i++)
//    {
//        if (resources[i]) {
//            resources[i]->update();
//        }
//    }
//
//    army->update();
//    bank->update();
//
//    stability = max(0.0, stability - 0.1);
//}
//
//void Kingdom::handleEvent(const string& event)
//{
//    if (event == "famine")
//    {
//        Resource* food = getResource("food");
//        if (food) {
//            food->setAmount(food->getAmount() * 0.5);
//        }
//        stability -= 20.0;
//    }
//    else if (event == "war")
//    {
//        army->setMorale(army->getMorale() - 20.0);
//        stability -= 30.0;
//    }
//    else if (event == "plague")
//    {
//        for (int i = 0; i < populationCount; i++)
//        {
//            if (population[i] && rand() % 100 < 20)
//            {
//                population[i]->setIsAlive(false);
//            }
//        }
//        stability -= 40.0;
//    }
//}
//
//void Kingdom::saveGame(const string& filename)
//{
//    ofstream file(filename);
//    if (!file.is_open()) {
//        cout << "Error: Could not open file for saving: " << filename << endl;
//        return;
//    }
//
//    // --- Kingdom info ---
//    file << name << "\n";
//    file << stability << "\n";
//
//    // --- Ruler info ---
//    if (ruler) {
//        file << "RULER\n";
//        file << ruler->getSocialClass() << "\n";
//        file << ruler->getName()<<"\n";
//        file << ruler->getAge() << "\n";
//        file << ruler->getWealth() << "\n";
//    }
//    else {
//        file << "NORULER\n";
//    }
//
//    // --- Bank info ---
//    file << bank->getTreasury() << "\n";
//
//    // --- Army info ---
//    file << army->getSoldiers() << "\n";
//    file << army->getMorale() << "\n";
//    // Add more like training level if needed
//
//    // --- Population info ---
//    file << populationCount << "\n";
//    for (int i = 0; i < populationCount; i++) {
//        if (population[i]) {
//            file << population[i]->getSocialClass() << "\n";
//            file << population[i]->getWealth() << "\n";
//            file << population[i]->getName() << "\n";
//            file << population[i]->getAge() << "\n";// Optional: Add name and age if you implement getName() and getAge()
//        }
//    }
//
//    // --- Resource info ---
//    file << resourceCount << "\n";
//    for (int i = 0; i < resourceCount; i++) {
//        if (resources[i]) {
//            file << resources[i]->getAmount() << "\n";
//
//        }
//    }
//
//    file.close();
//    cout << "Game saved successfully to '" << filename << "'\n";
//}
//
//
//void Kingdom::loadGame(const string& filename)
//{
//    ifstream file(filename);
//    if (!file.is_open()) {
//        cout << "Error: Could not open file for loading: " << filename << endl;
//        return;
//    }
//
//    // Clean existing data
//    for (int i = 0; i < populationCount; i++) delete population[i];
//    for (int i = 0; i < resourceCount; i++) delete resources[i];
//    populationCount = 0;
//    resourceCount = 0;
//
//    // Load kingdom name and stability
//    getline(file, name);
//    file >> stability;
//
//    // Load bank treasury
//    double treasury;
//    file >> treasury;
//    bank->collectTaxes(treasury - bank->getTreasury());
//
//    // Load army morale
//    double morale;
//    file >> morale;
//    army->setMorale(morale);
//
//    // Load population
//    file >> populationCount;
//    for (int i = 0; i < populationCount; i++)
//    {
//        string socialClass;
//        double wealth;
//        file >> socialClass >> wealth;
//
//        Person* person = nullptr;
//        if (socialClass == "Peasant") person = new Peasant("LoadedPeasant", 30);
//        else if (socialClass == "Merchant") person = new Merchant("LoadedMerchant", 40);
//        else if (socialClass == "Noble") person = new Noble("LoadedNoble", 50);
//
//        if (person) {
//            person->setWealth(wealth);
//            population[i] = person;
//        }
//    }
//
//    // Load resources
//    file >> resourceCount;
//    for (int i = 0; i < resourceCount; i++)
//    {
//        double amount;
//        file >> amount;
//
//        // Default names in same order as added (food, gold, wood)
//        string resName;
//        if (i == 0) resName = "food";
//        else if (i == 1) resName = "gold";
//        else if (i == 2) resName = "wood";
//
//        Resource* res = new Resource(resName, amount);
//        resources[i] = res;
//    }
//
//    file.close();
//    cout << "Game loaded successfully from '" << filename<<"'\n";
//}
//void Kingdom::logScore(const string& filename) const
//{
//    ofstream file(filename);
//    if (!file.is_open()) {
//        cout << "Error: Could not open score file: " << filename << endl;
//        return;
//    }
//
//    file << "===== STRONGHOLD KINGDOM SCORE REPORT =====\n\n";
//    file << "Kingdom Name: " << name << "\n";
//    file << "Stability: " << stability << "\n";
//    file << "Treasury: " << bank->getTreasury() << "\n";
//    file << "Army Morale: " << army->getMorale() << "\n";
//    file << "Army Size: " << army->getSoldiers() << "\n";
//    file << "Population Count: " << populationCount << "\n\n";
//
//    file << "\nThank you for playing Stronghold!\n";
//
//    file.close();
//    cout << "Score logged successfully to '" << filename << "'\n";
//}
//
//
//double Kingdom::getStability() const
//{
//    return stability;
//}
//
//void Kingdom::setRuler(Person* newRuler)
//{
//    ruler = newRuler;
//    stability += 10.0;
//}
//
//
//void Kingdom::addPerson(Person* person)
//{
//    if (populationCount < 100) {
//        population[populationCount] = person;
//        populationCount++;
//    }
//}
//
//void Kingdom::addResource(Resource* resource)
//{
//    if (resourceCount < 10) {
//        resources[resourceCount] = resource;
//        resourceCount++;
//    }
//}
//
//Resource* Kingdom::getResource(const string& name)
//{
//    for (int i = 0; i < resourceCount; i++) {
//        if (resources[i] && resources[i]->getAmount() > 0) {
//            return resources[i];
//        }
//    }
//    return nullptr;
//}