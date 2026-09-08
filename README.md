# Campus-Resource-Reservation-System

# Project 1: Campus Resource Reservation System
## Project Overview

Universities manage a variety of resources every day, including study rooms, tutoring appointments, laptops, calculators, and laboratory equipment. Students frequently request access to these resources, and administrators must efficiently manage reservations, waiting lists, cancellations, and usage reports.

In this project, your team will develop a Campus Resource Reservation System that allows users to reserve campus resources, manage waiting lists, track reservation history, and generate reports.

The goal of this project is to apply object-oriented programming and fundamental data structures to solve a realistic problem.
Learning Objectives

Upon completion of this project, students will be able to:

    Design and implement a moderately sized C++ software system.
    Apply object-oriented programming principles.
    Read and write structured data files.
    Implement and use linked lists.
    Implement and use stacks.
    Implement and use queues.
    Analyze algorithm efficiency.
    Implement searching algorithms.
    Implement sorting algorithms.
    Collaborate using GitHub.
    Develop modular and maintainable code.

## Functional Requirements
# Resource Management

The system shall:

    Load resource data from input files.
    Store information about available resources.
    Display all resources.
    Search for resources.
    Sort resources according to user-selected criteria.

Resources may include:

    Study Rooms
    Laptops
    Calculators
    Lab Equipment
    Tutoring appointments

Each resource must contain:

    Resource ID
    Resource Name
    Resource Type
    Availability Status

Reservation Management

Users shall be able to:

    Create a reservation.
    Cancel a reservation.
    View current reservations.
    Search for reservations.

Each reservation must contain:

    Reservation ID
    Student ID
    Student Name
    Resource ID
    Reservation Date

## Waiting List Management

When a resource is unavailable:

    Student requests must be placed in a waiting queue.
    Requests must be processed in FIFO order.
    Available resources must automatically be assigned to the next waiting user.

## Reservation History

The system shall maintain a cancellation history.

When a reservation is cancelled:

    It is stored on a stack.
    Users may undo the most recent cancellation.

Only the most recently cancelled reservation may be restored.
## Reporting

The system shall generate reports including:

    Most frequently reserved resources
    Current availability
    Number of active reservations
    Waiting list reports

## Non-Functional Requirements
## Code Organization

    Separate implementation and header files.
    Main function must be in its own source file.
    Use meaningful file and class names.

## Documentation

    Source code must contain comments.
    README file required.
    Function-level documentation encouraged.

## User Interface

Menu-driven command-line interface.

Example:

===== Campus Resource Reservation System =====

    View Resources
    Create Reservation
    Cancel Reservation
    View Waiting Lists
    Undo Cancellation
    Search Reservations
    Sort Resources
    Generate Report
    Exit

Enter Choice:

## Required Data Structures
# Linked List

Used For:

    Active reservation storage

Why Appropriate:

    Frequent insertions and deletions
    Dynamic size

# Queue

Used For:

    Resource waiting lists

Why Appropriate:

    First Come, First Served processing

# Stack

Used For:

    Cancellation history
    Undo functionality

Why Appropriate:

    Last In, First Out behavior

# Vector

Used For:

    Resource inventory

Why Appropriate:

    Fast traversal and sorting support

## Required Algorithms
# Searching

Students must implement:

    Linear Search OR
    Binary Search

Applications:

    Finding a resource by ID
    Finding a reservation by ID
    Finding reservations associated with a specific student

# Sorting

Students must implement at least one efficient sorting algorithm:

    Merge Sort OR
    Quick Sort

Applications:

    Resource reports
    Reservation reports

## Suggested Object-Oriented Design
Classes
Resource

Stores information about campus resources.
Reservation

Stores reservation information.
Student

Stores student data.
ReservationManager

Handles reservation operations.
WaitingList

Manages queue operations.
CancellationHistory

Manages stack operations.
ReportGenerator

Creates reports and statistics.
## File Organization

Project1/

│

├── include/

│ ├── Resource.h

│ ├── Reservation.h

│ ├── ReservationManager.h

│

├── src/

│ ├── main.cpp

│ ├── Resource.cpp

│ ├── Reservation.cpp

│ └── ReservationManager.cpp

│

├── data/

│ ├── resources.txt

│ └── reservations.txt

│

├── README.txt

└── .gitignore

 
## Error Handling

The system must:

    Validate all menu selections.
    Validate file opening.
    Prevent duplicate reservation IDs.
    Prevent invalid resource IDs.
    Handle empty stacks.
    Handle empty waiting queues.

## Sample Execution
Create Reservation

Student ID: 1001

Student Name: Alice Smith

Resource ID: R205

Reservation Created Successfully.

Cancel Reservation

Reservation ID: 301

Reservation Cancelled.

Added to cancellation history.

Undo Cancellation

Reservation Restored Successfully.
