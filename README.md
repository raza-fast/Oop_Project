# Oop_Project
Project Title: Stronghold
A text-based strategy simulation game in C++ where the player manages a medieval kingdom’s population, resources, army, and finances, while responding to events like war and plague.

 Project Division
1. Header File – Stronghold.h
Defines all classes and their attributes/methods:

Person (abstract base class) with derived classes:

Peasant

Merchant

Noble

Resource – Manages food, gold, wood with production/consumption rates.

Army – Manages soldiers, morale, training, feeding, and payment.

Bank – Handles treasury, loans, and auditing.

Kingdom – Central game class integrating all above components.

2. Main File – main.cpp
Contains:

The menu system.

Input handling.

Exception classes for clean error messages.

The game loop that responds to user choices and updates the kingdom state.

3. Class Implementation Files
Person.cpp – Logic for Peasant, Merchant, and Noble behavior.

Resource.cpp + Army.cpp – Resource/Army behavior and state updates.

Bank.cpp – Bank update logic, taxation, loans, and audits.

Kingdom.cpp – Game state management: saving, loading, logging score, and responding to events.

 Technologies & Concepts Used
Object-Oriented Programming (OOP):

Inheritance (Peasant/Merchant/Noble from Person)

Polymorphism (virtual update() methods)

Encapsulation (private members with getters/setters)

Exception Handling:

Custom exceptions for input and logical errors

File Handling:

Saving/loading game state using fstream

Dynamic Memory Management:

Manual allocation/deallocation with new and delete

Structured Game Loop using menu-driven interaction

Code Modularity via separate header/source files

 What I Did in the Project:

Designed and implemented a kingdom simulation game from scratch.

Created a modular class hierarchy using inheritance and virtual methods.

Managed resources, population, and army with realistic updates and effects.

Implemented save/load functionality to persist the game state.

Handled events like war, famine, and plague to impact kingdom stability.

Used OOP principles thoroughly and correctly (abstraction, encapsulation, etc.).

Cleanly separated implementation files, especially splitting bank.cpp and kingdom.cpp
