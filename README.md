# MSCS-632-Assignment5: Ride Sharing System in C++ and Smalltalk

## 📘 Course
**Advanced Programming Languages – MSCS 632**

## 👨‍💻 Author
Sandesh Pokharel

## 👢️ Project Structure
```
MSCS-632-Assignment5/
│
├── c++/
│   └── rideshare.cpp
│
├── smalltalk/
│   └── rideshare.st
│
└── README.md
```

## 👋 Overview
This project implements a Ride Sharing System in **both C++ and Smalltalk**, demonstrating the application of three core Object-Oriented Programming (OOP) principles:
- **Encapsulation**
- **Inheritance**
- **Polymorphism**

The goal of this assignment is to show how these principles are applied differently in statically-typed (C++) vs dynamically-typed (Smalltalk) languages, while maintaining consistent system functionality.

---

## 🚘 System Features
- Base `Ride` class with fields like rideID, pickupLocation, dropoffLocation, distance, and fare.
- Subclasses `StandardRide` and `PremiumRide`, each overriding `fare()` logic.
- `Driver` and `Rider` classes that manage ride assignments and ride history.
- Demonstrates polymorphism by using a list of mixed ride types and invoking overridden methods.

---

## 💡 Object-Oriented Concepts Demonstrated

| Principle      | C++ Implementation                    | Smalltalk Implementation              |
|----------------|----------------------------------------|----------------------------------------|
| Encapsulation  | Private members with public accessors  | Instance variables with method access  |
| Inheritance    | `StandardRide` and `PremiumRide` from `Ride` | `StandardRide` and `PremiumRide` from `Ride` |
| Polymorphism   | Virtual methods with base class pointers | Message passing via dynamic dispatch   |

---

## 📁 Folder Details

### `/c++/rideshare.cpp`
- Full C++ implementation using classes, inheritance, smart pointers, and vectors.
- Demonstrates runtime polymorphism and encapsulation.

### `/smalltalk/rideshare.st`
- Smalltalk version using dynamic message-passing and class-based structure.
- Encapsulation achieved through class methods and private instance variables.

---

## 💻 How to Run

### ✅ C++ (Tested on Ubuntu)
```bash
g++ -std=c++11 rideshare.cpp -o rideshare && ./rideshare
```

### ✅ Smalltalk (GNU Smalltalk)
```bash
gst rideshare.st
```

---

## 📸 Sample Output
Screenshots of output and code structure are provided in the report.

---

## 📄 Report
See the APA-style report (`.docx` or `.pdf`) for:
- OOP principle explanations
- Sample output
- Code structure and screenshots
- GitHub link to this repo

---

---

## 📚 References
- Sebesta, R. W. (2016). *Concepts of Programming Languages* (11th ed.). Pearson.
- Goldberg, A., & Robson, D. (1983). *Smalltalk-80: The Language and its Implementation*. Addison-Wesley.

