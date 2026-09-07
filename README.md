# **C++ Ability System**

A modular gameplay ability system implemented in C++ to demonstrate core gameplay programming concepts such as state management, cooldown logic, and clean class architecture. The system is designed to be lightweight, readable, and easily extendable for more complex mechanics.

---

## **Overview**

This project implements a simple ability framework using C++ classes.  
The system supports:

- Ability activation  
- Cooldown enforcement  
- State tracking  
- Modular class design  
- Clear separation of interface (`.h`) and implementation (`.cpp`)

The goal is to show how gameplay abilities can be structured cleanly and predictably in C++ without engine dependencies.

---

## **Project Structure**

```
/AbilitySystem
│
├── Ability.h
├── Ability.cpp
│
├── DashAbility.h
├── DashAbility.cpp
│
├── AbilityManager.h
├── AbilityManager.cpp
│
└── main.cpp
```

### **Ability**
Base class defining the interface for all abilities:
- `Activate()`
- `CanActivate()`
- Cooldown handling
- Internal state flags

### **DashAbility**
Derived class implementing a forward‑dash mechanic:
- Overrides activation logic
- Uses cooldown inherited from `Ability`
- Demonstrates polymorphism and specialization

### **AbilityManager**
Handles:
- Storing abilities  
- Triggering activation  
- Checking cooldowns  
- Managing ability lifecycle

### **main.cpp**
Simple test harness that:
- Creates abilities  
- Activates them  
- Prints state changes  
- Demonstrates cooldown behavior

---

## **How It Works**

1. The `Ability` base class defines the core behavior and cooldown logic.  
2. `DashAbility` extends the base class and implements its own activation behavior.  
3. `AbilityManager` stores and triggers abilities.  
4. `main.cpp` simulates ability usage and prints output to verify functionality.

This structure mirrors how gameplay abilities are commonly implemented in engines like Unreal or Unity, but in a clean standalone C++ environment.

---

## **Key Concepts Demonstrated**

- Object‑oriented design  
- Inheritance and polymorphism  
- Cooldown timers  
- State management  
- Modular architecture  
- Clean separation of interface and implementation  

---

## **Future Extensions**

- Add more ability types (e.g., jump, sprint, attack)  
- Add resource costs (stamina, mana)  
- Add ability queues or priority systems  
- Convert to Unreal Engine C++ for engine‑integrated abilities  
- Add unit tests for cooldown and activation logic  

---
