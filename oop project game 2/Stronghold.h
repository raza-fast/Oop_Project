#ifndef STRONGHOLD_H
#define STRONGHOLD_H

#include <string>

using namespace std;

class Person {
private:
    string name;
    int age;
    string socialClass;
    double wealth;
    bool isAlive;

public:
    Person(const string& n, int a, const string& sc);
    virtual ~Person() = default;
    virtual void update() = 0;
    bool getIsAlive() const;
    void setIsAlive(bool alive);
    string getSocialClass() const;
    double getWealth() const;
    void setWealth(double w);
    string getName() const;
    int getAge() const;
};

class Peasant : public Person {
private:
    double foodProduction;
    double taxRate;

public:
    Peasant(const string& n, int a);
    void update() override;
    double getFoodProduction() const;
    void setTaxRate(double rate);
};

class Merchant : public Person {
private:
    double tradeVolume;
    double inventory[10]; // Fixed size array for inventory
    string itemNames[10]; // Names corresponding to inventory items
    int itemCount;

public:
    Merchant(const string& n, int a);
    void update() override;
    void trade(const string& item, double amount);
    double getTradeVolume() const;
};

class Noble : public Person {
private:
    int influence;
    Person* subjects[20]; // Fixed size array for subjects
    int subjectCount;

public:
    Noble(const string& n, int a);
    ~Noble();
    void update() override;
    void addSubject(Person* subject);
    int getInfluence() const;
};

class Resource {
private:
    string name;
    double amount;
    double productionRate;
    double consumptionRate;

public:
    Resource(const string& n, double initial);
    void update();
    double getAmount() const;
    void setAmount(double a);
    void setProductionRate(double rate);
    void setConsumptionRate(double rate);
};

class Army {
private:
    int soldiers;
    double morale;
    double training;
    double foodConsumption;
    double payRate;

public:
    Army();
    void update();
    void train();
    void pay();
    void feed();
    int getSoldiers() const;
    double getMorale() const;
    void setMorale(double m);
};

class Bank {
private:
    double treasury;
    double loanAmounts[10]; // Fixed size array for loan amounts
    double loanInterests[10]; // Fixed size array for loan interests
    int loanCount;
    double interestRate;
    double corruptionLevel;

public:
    Bank(double initial);
    void update();
    void loan(double amount);
    void collectTaxes(double amount);
    void audit();
    double getTreasury() const;
    void setInterestRate(double rate);
};

class Kingdom {
private:
    string name;
    Person* population[100]; // Fixed size array for population
    int populationCount;
    Resource* resources[10]; // Fixed size array for resources
    int resourceCount;
    Army* army;
    Bank* bank;
    Person* ruler;
    double stability;

public:
    Kingdom(const string& n);
    ~Kingdom();
    void update();
    void handleEvent(const string& event);
    void saveGame(const string& filename);
    void loadGame(const string& filename);
    void logScore(const string& filename) const;
    double getStability() const;
    void setRuler(Person* newRuler);
    void addPerson(Person* person);
    void addResource(Resource* resource);
    Resource* getResource(const string& name);
};

#endif #pragma once
