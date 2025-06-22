
## What Is Object-Oriented Design (OOD)?

**OOD** is a method of designing software by defining data structures (objects) and the operations (methods) that can be performed on them. It emphasizes **modularity**, **encapsulation**, **inheritance**, and **polymorphism**.

---

## Core OOD Principles (SOLID)

- **S** - Single Responsibility Principle
- **O** - Open/Closed Principle
- **L** - Liskov Substitution Principle
- **I** - Interface Segregation Principle
- **D** - Dependency Inversion Principle

---

## Key Concepts

### Encapsulation
Hide internal state; expose only necessary operations.

### Inheritance
Subclassing to reuse code and structure.

### Polymorphism
Interchangeable use of objects with shared interface.

### Composition over Inheritance
Prefer using objects inside other objects (composition) rather than subclassing for flexibility.

---

## Common OOD Interview Topics

### 1. **Design a Parking Lot**

**Classes**: ParkingLot, Level, ParkingSpot, Vehicle, Car, Bus, Motorcycle  
**Key Concepts**: Class hierarchy, Spot allocation, Size constraints

### 2. **Design a File System**

**Classes**: FileSystem, Directory, File  
**Key Concepts**: Tree structure, Path traversal, Encapsulation

### 3. **Design a Chat App (Slack/Discord)**

**Classes**: User, Message, Channel, Server  
**Key Concepts**: Real-time data, Messaging history, Observer pattern

### 4. **Design a Rate Limiter**

**Concepts**: Token Bucket, Sliding Window Log  
**Key Ideas**: Data structure usage, time window control, user throttling

---

## Tips for OOD Interviews

* Clarify requirements and assumptions before jumping into code
* Start with class responsibilities and relationships (UML-style thinking)
* Identify nouns (classes) and verbs (methods)
* Choose composition when behaviors vary
* Think about scalability, concurrency, and edge cases

---

## Example: Design a Library System

**Entities**:
- Book, Author, User, Loan, Catalog

**Operations**:
- Search books, borrow/return, reserve, fine

**Features**:
- Book availability, due date tracking, search indexing

---

## OOD Summary

OOD is about thinking in **objects and responsibilities**, not just code. Use real-world modeling, follow design principles, and demonstrate your understanding of maintainability and extensibility.
