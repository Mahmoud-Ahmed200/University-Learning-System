# University Learning System

## Overview
The **University Learning System** is a C++ console-based application designed to demonstrate structured programming concepts in building a university management system. The project's primary purpose is to show how basic programming constructs—such as functions, structs, loops, conditionals, and simple vectors—can be combined to create a functional application without relying on object-oriented programming (OOP) principles (e.g., inheritance, polymorphism) or advanced data structures (e.g., trees, graphs). It manages courses, students, instructors, and grades, providing a practical example of structured programming for beginners using modular design and persistent file storage.

## Features
### Admin Features
- **Add/Remove Courses**: Create or delete courses with details like ID, title, instructor, schedule, and maximum student capacity.
- **Add/Remove Students**: Register or remove students with personal details.
- **Grade Management**: Assign grades to students for specific courses.
- **Data Persistence**: Save all data (courses, students, instructors, grades) to text files.

### Student Features
- **View Courses**: Browse available courses with details like schedule and instructor.
- **Enroll in Courses**: Enroll in up to six courses, with validation to prevent over-enrollment.
- **View Enrolled Courses**: Check enrolled courses.
- **View Grades**: Display grades for each course along with an overall grade average.

## Solid Programming Concepts
The project adheres to solid programming principles:
- **Modularity**: Functions are organized into logical groups (e.g., menus, login, validity checks, file operations), enhancing code readability and maintainability.
- **Encapsulation**: Data structures (`Course`, `Student`, `Instructor`, `Grade`) encapsulate related attributes, promoting data integrity.
- **Separation of Concerns**: Distinct modules handle user interaction, data validation, and file operations.
- **Reusability**: Generic functions like `getID`, `getdetails`, and `isValidinteger` are reused across different contexts.

## Input Validation
Robust input validation ensures system reliability:
- **Integer Validation**: Checks for positive integers (e.g., IDs, student numbers) using `isValidinteger`.
- **String Validation**: Ensures non-empty strings for names, titles, etc., via `isValidstring`.
- **Time Validation**: Validates time formats (e.g., "13:50") and ensures end times follow start times with `isValidtime` and `isValidendTime`.
- **Age and Score Validation**: Restricts age (16–100) and scores (0–100) to valid ranges.
- **Choice Validation**: Ensures user inputs for confirmations (y/n) are valid using `isValidchoice`.

## File Handling
The system uses text files for persistent storage:
- **Courses**: Stored in `courses.txt` with fields like ID, title, and schedule.
- **Students**: Saved in `students.txt` with ID, name, age, major, and credentials.
- **Instructors**: Recorded in `instructors.txt` with ID, name, age, department, and credentials.
- **Grades**: Stored in `grades.txt` with grade ID, student ID, course ID, and score.
- **Enrolled Courses**: Saved in `enrolledCourses.txt` linking students to courses.
- **Save/Load Functions**: Data is loaded at startup and saved on exit, ensuring no data loss.

## Installation
1. **Prerequisites**:
   - A C++ compiler (e.g., g++, MinGW, or Visual Studio).
   - Standard C++ libraries (included in the code: `<iostream>`, `<vector>`, `<string>`, `<fstream>`, etc.).
2. **Steps**:
   - Clone or download the project repository.
   - Compile the source code using a C++ compiler:
     ```bash
     g++ main.cpp -o university_system
     ```
   - Run the executable:
     ```bash
     ./university_system
     ```

## Usage
1. **Launch the Program**: Run the compiled executable.
2. **Main Menu**:
   - Choose to log in as an **Admin**, **Student**, or **Exit**.
3. **Admin Login**:
   - Use credentials stored in `instructors.txt` (e.g., username and password).
   - Access options to manage courses, students, and grades.
4. **Student Login**:
   - Use credentials stored in `students.txt`.
   - View courses, enroll, or check grades.
5. **Exit**: Saves all data to files and terminates the program.

## Project Structure
```
university_learning_system/
├── main.cpp              # Source code
├── courses.txt           # Stores course data
├── students.txt          # Stores student data
├── instructors.txt       # Stores instructor data
├── grades.txt            # Stores grade data
├── enrolledCourses.txt   # Stores enrollment data
└── README.md             # Project documentation
```

## Technologies Used
- **Language**: C++ (Standard Library)
- **Libraries**:
  - `<iostream>`: Console input/output.
  - `<vector>`: Dynamic arrays for storing data.
  - `<string>`: String manipulation.
  - `<fstream>`: File input/output.
  - `<iomanip>`: Formatted output.
  - `<conio.h>`: Console input handling (e.g., `_getch()`).
- **File Storage**: Plain text files for data persistence.
