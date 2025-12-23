# Train Booking System (C++, OOPS)

## Problem Statement
In real-world railway reservation systems, managing train details, handling ticket bookings, cancellations, and tracking seat availability efficiently is crucial. Manual systems or poorly designed software solutions can lead to errors, delays, and inaccurate seat management. For students learning C++, it is important to understand how such real-life problems can be modeled using Object-Oriented Programming (OOPS) concepts. The challenge is to design a simple, organized, and reliable train booking system that demonstrates these concepts clearly without unnecessary complexity.

## Project Description
This project is a console-based Train Booking System developed using C++. It simulates the basic workflow of a railway reservation system, allowing users to view available trains, book tickets, cancel bookings, and monitor seat availability in real time. The primary focus of the project is on clean class design, logical flow, and effective use of OOPS principles rather than advanced features such as databases or graphical interfaces.

The system follows a menu-driven approach, making it easy for users to interact with the application. Each major responsibility of the system is handled by a separate class, ensuring better readability, maintainability, and ease of explanation during academic evaluations or interviews.

## Solution Approach
The solution is implemented using core C++ and follows Object-Oriented Programming principles to achieve modular and structured design. The system is divided into multiple classes, each responsible for a specific part of the booking process:
- The **Person** class acts as a base class containing common attributes such as name and age.
- The **Passenger** class inherits from the Person class and represents passengers booking tickets.
- The **Train** class stores train-related information and manages seat availability.
- The **Ticket** class represents individual bookings and maintains the relationship between passengers and trains.
- The **TrainBookingSystem** class controls the overall flow of the application, including displaying trains, booking tickets, and handling cancellations.

This approach ensures proper encapsulation, inheritance, and abstraction, resulting in a clean and maintainable codebase. The program runs entirely in the console and demonstrates the complete process from selecting a train to booking and cancelling tickets.

## Technologies Used
- **C++**
- **Object-Oriented Programming (OOPS)**
  - Classes and Objects  
  - Encapsulation  
  - Inheritance  
  - Abstraction  
  - Composition  
- **Git & GitHub** for version control

---

Author: **Pragnya Yelisetti**  
GitHub: https://github.com/Pragnyayelisetti
