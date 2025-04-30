#include "Stronghold.h"
#include <iostream>
#include <string>

using namespace std;

// Custom exception classes
class KingdomException {
private:
    string message;
public:
    KingdomException(const string& msg) : message(msg) {}
    string what() const {
        return message;
    }
};

class InputException {
private:
    string message;
public:
    InputException(const string& msg) : message(msg) {}
    string what() const {
        return message;
    }
};

// Function to safely get integer input
int getIntInput() {
    int input;
    while (!(cin >> input)) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid input. Please enter a number: ";
    }
    cin.ignore(10000, '\n');
    return input;
}

// Function to safely get double input
double getDoubleInput() {
    double input;
    while (!(cin >> input)) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid input. Please enter a number: ";
    }
    cin.ignore(10000, '\n');
    return input;
}

void displayMenu() {
    cout << "\n";
    cout << "------------------------------------------------------------\n";
    cout << "                 STRONGHOLD KINGDOM MANAGEMENT              \n";
    cout << "------------------------------------------------------------\n";
    cout << "                                                            \n";
    cout << "  [1]  View Kingdom Status                                 \n";
    cout << "  [2]  Manage Population                                   \n";
    cout << "  [3]  Manage Resources                                    \n";
    cout << "  [4]  Manage Army                                         \n";
    cout << "  [5]  Manage Bank                                         \n";
    cout << "  [6]  Trigger Event                                       \n";
    cout << "  [7]  Save Game                                           \n";
    cout << "  [8]  load game                                           \n";
    cout << "  [9]  Save Score                                          \n";
    cout << "  [10] Exist                                               \n";
    cout << "------------------------------------------------------------\n";
    cout << "Enter your choice (1-8): ";
}

void displayKingdomStatus(Kingdom& kingdom) {
    cout << "\n=== Kingdom Status ===\n";
    cout << "Stability: " << kingdom.getStability() << "\n";
}

void managePopulation(Kingdom& kingdom) {
    cout << "\n=== Population Management ===\n";
    cout << "1. Add Peasant\n";
    cout << "2. Add Merchant\n";
    cout << "3. Add Noble\n";
    cout << "4. Back to Main Menu\n";
    cout << "Enter your choice (1-4): ";

    int choice = getIntInput();

    if (choice >= 1 && choice <= 3) {
        string name;
        int age;

        cout << "Enter name: ";
        getline(cin, name);

        if (name.empty()) {
            throw InputException("Name cannot be empty");
        }

        cout << "Enter age: ";
        age = getIntInput();

        if (age < 0) {
            cout << "Invalid age. Using default age of 25.\n";
            age = 25;
        }

        Person* newPerson = nullptr;

        switch (choice) {
        case 1:
            newPerson = new Peasant(name, age);
            break;
        case 2:
            newPerson = new Merchant(name, age);
            break;
        case 3:
            newPerson = new Noble(name, age);
            break;
        }

        if (newPerson) {
            kingdom.addPerson(newPerson);
            cout << "Person added successfully!\n";
        }
        else {
            throw KingdomException("Failed to create new person");
        }
    }
    else if (choice != 4) {
        cout << "Invalid choice. Returning to main menu.\n";
    }
}

void manageResources(Kingdom& kingdom) {
    cout << "\n=== Resource Management ===\n";
    cout << "1. Add Food\n";
    cout << "2. Add Gold\n";
    cout << "3. Add Wood\n";
    cout << "4. Back to Main Menu\n";
    cout << "Enter your choice (1-4): ";

    int choice = getIntInput();

    if (choice >= 1 && choice <= 3) {
        double amount;
        cout << "Enter initial amount: ";
        amount = getDoubleInput();

        if (amount < 0) {
            cout << "Invalid amount. Using default amount of 100.\n";
            amount = 100.0;
        }

        Resource* newResource = nullptr;

        switch (choice) {
        case 1:
            newResource = new Resource("food", amount);
            newResource->setProductionRate(10.0);
            newResource->setConsumptionRate(5.0);
            break;
        case 2:
            newResource = new Resource("gold", amount);
            newResource->setProductionRate(5.0);
            newResource->setConsumptionRate(2.0);
            break;
        case 3:
            newResource = new Resource("wood", amount);
            newResource->setProductionRate(8.0);
            newResource->setConsumptionRate(3.0);
            break;
        }

        if (newResource) {
            kingdom.addResource(newResource);
            cout << "Resource added successfully!\n";
        }
        else {
            throw KingdomException("Failed to create new resource");
        }
    }
    else if (choice != 4) {
        cout << "Invalid choice. Returning to main menu.\n";
    }
}

void manageArmy(Kingdom& kingdom) {
    cout << "\n=== Army Management ===\n";
    cout << "1. Train Army\n";
    cout << "2. Pay Army\n";
    cout << "3. Feed Army\n";
    cout << "4. Back to Main Menu\n";
    cout << "Enter your choice (1-4): ";

    int choice = getIntInput();

    switch (choice) {
    case 1:
        cout << "Army trained!\n";
        break;
    case 2:
        cout << "Army paid!\n";
        break;
    case 3:
        cout << "Army fed!\n";
        break;
    case 4:
        
        break;
    default:
        cout << "Invalid choice. Returning to main menu.\n";
    }
}

void manageBank(Kingdom& kingdom) {
    cout << "\n=== Bank Management ===\n";
    cout << "1. Take Loan\n";
    cout << "2. Collect Taxes\n";
    cout << "3. Audit Bank\n";
    cout << "4. Back to Main Menu\n";
    cout << "Enter your choice (1-4): ";

    int choice = getIntInput();

    if (choice >= 1 && choice <= 3) {
        double amount = 0.0;

        switch (choice) {
        case 1:
            cout << "Enter loan amount: ";
            amount = getDoubleInput();
            if (amount < 0) {
                cout << "Invalid amount. Using default amount of 1000.\n";
                amount = 1000.0;
            }
            cout << "Loan taken successfully!\n";
            break;
        case 2:
            cout << "Enter tax amount: ";
            amount = getDoubleInput();
            if (amount < 0) {
                cout << "Invalid amount. Using default amount of 500.\n";
                amount = 500.0;
            }
            cout << "Taxes collected successfully!\n";
            break;
        case 3:
            cout << "Bank audit completed!\n";
            break;
        }
    }
    else if (choice != 4) {
        cout << "Invalid choice. Returning to main menu.\n";
    }
}

void triggerEvent(Kingdom& kingdom) {
    cout << "\n=== Event Trigger ===\n";
    cout << "1. Famine\n";
    cout << "2. War\n";
    cout << "3. Plague\n";
    cout << "4. Back to Main Menu\n";
    cout << "Enter your choice (1-4): ";

    int choice = getIntInput();

    switch (choice) {
    case 1:
        kingdom.handleEvent("famine");
        cout << "Famine has struck the kingdom!\n";
        break;
    case 2:
        kingdom.handleEvent("war");
        cout << "War has broken out!\n";
        break;
    case 3:
        kingdom.handleEvent("plague");
        cout << "Plague has spread through the kingdom!\n";
        break;
    case 4:
        // Do nothing, just return to main menu
        break;
    default:
        cout << "Invalid choice. Returning to main menu.\n";
    }
}

void saveGame(Kingdom& kingdom) {
    cout << "\n=== Save Game ===\n";
    cout << "Saving game to 'game_save.txt'...\n";
    kingdom.saveGame("game_save.txt");
    cout << "Game saved successfully!\n";
}

int main()
{
    try {
        Kingdom kingdom("Medieval Kingdom");

        // Initialize with some basic population and resources
        Peasant* peasant1 = new Peasant("Ali", 25);
        Peasant* peasant2 = new Peasant("Saad", 30);
        Merchant* merchant = new Merchant("Fazi", 40);
        Noble* noble = new Noble("Mani", 45);

        kingdom.addPerson(peasant1);
        kingdom.addPerson(peasant2);
        kingdom.addPerson(merchant);
        kingdom.addPerson(noble);

        kingdom.setRuler(noble);

        Resource* food = new Resource("food", 100.0);
        Resource* gold = new Resource("gold", 500.0);
        Resource* wood = new Resource("wood", 800.0);

        kingdom.addResource(food);
        kingdom.addResource(gold);
        kingdom.addResource(wood);

        food->setProductionRate(10.0);
        food->setConsumptionRate(5.0);

        gold->setProductionRate(5.0);
        gold->setConsumptionRate(2.0);

        wood->setProductionRate(8.0);
        wood->setConsumptionRate(3.0);

        cout << "Welcome to Stronghold Kingdom Management\n";

        bool running = true;
        while (running) {
            try {
                displayMenu();

                int choice = getIntInput();

                switch (choice) {
                case 1:
                    displayKingdomStatus(kingdom);
                    break;
                case 2:
                    managePopulation(kingdom);
                    break;
                case 3:
                    manageResources(kingdom);
                    break;
                case 4:
                    manageArmy(kingdom);
                    break;
                case 5:
                    manageBank(kingdom);
                    break;
                case 6:
                    triggerEvent(kingdom);
                    break;
                case 7:
                    saveGame(kingdom);
                    break;
                case 8:
                    kingdom.loadGame("game_save.txt");
                    break;
                case 9:
                    kingdom.logScore("score.txt");
                    break;
                case 10:
                    running = false;
                    cout << "Thank you for playing Stronghold Kingdom Management!\n";
                    break;
                default:
                    cout << "Invalid choice. Please try again.\n";
                }

                // Update kingdom state after each action
                kingdom.update();
            }
            catch (const KingdomException& e) {
                cout << "Kingdom error: " << e.what() << "\n";
                cout << "Continuing with the game...\n";
            }
            catch (const InputException& e) {
                cout << "Input error: " << e.what() << "\n";
                cout << "Continuing with the game...\n";
            }
            catch (...) {
                cout << "An unknown error occurred.\n";
                cout << "Continuing with the game...\n";
            }
        }

        // Clean up resources
        delete peasant1;
        delete peasant2;
        delete merchant;
        delete noble;
        delete food;
        delete gold;
        delete wood;

        return 0;
    }
    catch (const KingdomException& e) {
        cerr << "Fatal kingdom error: " << e.what() << "\n";
        return 1;
    }
    catch (const InputException& e) {
        cerr << "Fatal input error: " << e.what() << "\n";
        return 1;
    }
    catch (...) {
        cerr << "Unknown fatal error occurred.\n";
        return 1;
    }
}
