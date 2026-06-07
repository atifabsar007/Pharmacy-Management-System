# Pharmacy Management System

## Overview

The Pharmacy Management System is a comprehensive console-based application developed in **C++** using **Object-Oriented Programming (OOP)** principles. The system is designed to automate and streamline pharmacy operations, including medicine inventory management, customer handling, sales processing, billing, and reporting.

This project demonstrates the practical implementation of advanced C++ programming concepts such as **Encapsulation, Inheritance, Abstraction, Operator Overloading, Dynamic Memory Management, STL Containers, File Handling, and Data Persistence**.

---

## Key Features

### Inventory Management

* Add new medicines
* Update medicine information
* Remove medicines from inventory
* Restock existing medicines
* Low-stock monitoring
* Expiry date tracking

### Sales & Billing

* Medicine sales processing
* Automatic invoice generation
* Sales transaction recording
* Stock validation before purchase
* Bill calculation and printing

### Customer Management

* Customer registration and tracking
* Purchase history maintenance
* Loyalty reward program
* Automated discount system

### Reporting & Analytics

* Inventory reports
* Customer loyalty ranking
* Sales records management
* Expiry and stock alerts

### User Role Management

* Administrator Access
* Pharmacist Access
* Authentication and Login System

### Data Persistence

* File-based database system
* Inventory storage
* Customer records storage
* Invoice history management

---

## Technologies Used

* C++
* Object-Oriented Programming (OOP)
* Standard Template Library (STL)
* File Handling (File I/O)
* Dynamic Memory Allocation
* Console-Based User Interface

---

## System Architecture

The project follows a modular OOP design consisting of seven major classes:

### Medicine Class

Handles medicine-related operations:

* Stock management
* Expiry checking
* Inventory display
* Operator overloading implementation

### Customer Class

Manages customer information:

* Purchase tracking
* Loyalty program
* Discount eligibility
* Customer records

### Invoice Class

Responsible for:

* Bill generation
* Transaction management
* Discount calculations
* Invoice storage

### User Class

Base class providing:

* Authentication
* Login/Logout functionality
* User information management

### Admin Class

Derived from User:

* Inventory management
* Reporting and analytics
* System administration

### Pharmacist Class

Derived from User:

* Sales processing
* Customer handling
* Medicine searching
* Invoice generation

### PharmacySystem Class

Main controller responsible for:

* System initialization
* User authentication
* Menu management
* Data loading and storage

---

## OOP Concepts Demonstrated

### Encapsulation

* Private data members
* Public getter/setter methods

### Inheritance

* User → Admin
* User → Pharmacist

### Abstraction

* Separation of responsibilities across classes

### Operator Overloading

* Arithmetic operators
* Comparison operators
* Increment operators

### Dynamic Memory Management

* Pointer-based object management

### STL Usage

* vector
* pair
* algorithms
* lambda expressions

---

## File Structure

```text
Pharmacy-Management-System/
│
├── main.cpp
├── Sample001.cpp
├── medicines.txt
├── customers.txt
├── invoices.txt
├── invoice_counter.txt
├── Pharmacy Management Project.pdf
└── README.md
```

---

## Learning Outcomes

Through this project, I gained practical experience in:

* Object-Oriented Software Design
* Inventory Management Systems
* File-Based Database Implementation
* C++ STL and Advanced Features
* Dynamic Memory Management
* Role-Based Access Control
* Real-World Business Application Development

---

## Future Improvements

* Graphical User Interface (GUI)
* Database Integration (MySQL/PostgreSQL)
* Barcode Scanner Support
* Online Prescription Management
* Multi-Branch Pharmacy Support
* Cloud-Based Data Storage
* Advanced Sales Analytics Dashboard

---

## Academic Project

This project was developed as part of the **CSE-1205: Object Oriented Programming** course at **Khulna University of Engineering & Technology (KUET)**.

---

## Author

**Md. Atif Absar**
**Krishno Mondol**
**Agomon Das Dhrubo**
**Rahanuma Rashid**
**Ritovash Chanda**
**Arnob Dam**
Department of Computer Science & Engineering
Khulna University of Engineering & Technology (KUET)

GitHub: https://github.com/atifabsar007
