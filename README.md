# 42cursus C++ Modules: A Journey into Object-Oriented Programming

Welcome to my C++ Modules repository! This project is a comprehensive series of exercises from the 42 Network's curriculum, designed to master the fundamentals of C++ and the Object-Oriented Programming (OOP) paradigm, specifically within the C++98 standard.

## 🚀 Overview

The curriculum is structured into 10 modules (00 through 09), each focusing on a specific set of concepts, progressively building in complexity. From basic syntax and memory management to advanced template metaprogramming and the Standard Template Library (STL).

### Key Technical Focus
- **Orthodox Canonical Class Form**: Ensuring classes are robust with proper constructors, destructors, and assignment operators.
- **Memory Management**: Deep diving into stack vs. heap allocation, references, and avoiding memory leaks.
- **Polymorphism**: Implementing subtype and ad-hoc polymorphism through inheritance and operator overloading.
- **Templates & STL**: Leveraging generic programming and efficient data structures.
- **Exception Handling**: Crafting resilient code with try-catch blocks and custom exceptions.

---

## 🛠️ Module Breakdown

| Module | Focus Area | Key Concepts & Exercises |
| :--- | :--- | :--- |
| **CPP 00** | **Basics & Classes** | Namespaces, classes, member functions, I/O streams. (Megaphone, PhoneBook) |
| **CPP 01** | **Memory & Pointers** | Heap allocation, references, pointers to members, file streams. (Zombie, Moar Zombies, Weapon) |
| **CPP 02** | **Operator Overloading** | Ad-hoc polymorphism, fixed-point arithmetic, Canonical Form. (Fixed) |
| **CPP 03** | **Inheritance** | Class hierarchies, shadowed members, base/derived interactions. (ClapTrap, ScavTrap, FragTrap) |
| **CPP 04** | **Subtype Polymorphism** | Abstract classes, interfaces, virtual destructors, deep vs. shallow copies. (Animal, Dog, Cat, Brain) |
| **CPP 05** | **Exceptions** | Try-catch blocks, custom exception classes, Bureaucracy simulation. (Bureaucrat, Shrubbery/Robotomy/Presidential Forms) |
| **CPP 06** | **Type Casting** | Scalar conversion, static/dynamic/reinterpret/const casts. (ScalarConverter, Serializer) |
| **CPP 07** | **Templates** | Function templates, class templates, generic programming. (whatever, iter, Array) |
| **CPP 08** | **STL Containers** | Iterators, algorithms, and containers (vector, list, stack). (easyfind, Span, MutantStack) |
| **CPP 09** | **Advanced STL** | Complex algorithm implementation, container selection (vector, deque, list). (BitcoinExchange, RPN, PmergeMe) |

---

## 🏗️ Building the Project

Each module contains multiple exercises, each with its own `Makefile`. To compile an exercise:

1. Navigate to the exercise directory:
   ```bash
   cd cpp-module-XX/exYY
   ```
2. Run `make`:
   ```bash
   make
   ```
3. Run the generated executable:
   ```bash
   ./executable_name
   ```

---

## ✨ Highlights

### Ford-Johnson Algorithm (PmergeMe)
In **Module 09**, I implemented the **Merge-Insertion Sort** (Ford-Johnson algorithm) to sort large sequences of integers. This exercise involved:
- Comparative performance analysis between different STL containers (`std::vector` and `std::deque`).
- Handling complex recursion and element pairing logic.
- Ensuring efficiency and accuracy with large datasets.

### Orthodox Canonical Class Form
Every class throughout this project follows the **Orthodox Canonical Form**, ensuring proper resource management:
```cpp
class MyClass {
    public:
        MyClass();                          // Default constructor
        MyClass(const MyClass& other);      // Copy constructor
        MyClass& operator=(const MyClass& other); // Copy assignment operator
        ~MyClass();                         // Destructor
};
```

---

## 👨‍💻 Author
**kez-zoub** (1337 Student)
- GitHub: [kez-zoub](https://github.com/kamal98ETH)

---
*Note: This repository is intended for educational purposes and as a showcase of my C++ proficiency.*
