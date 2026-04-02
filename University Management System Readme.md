# 🎓 University Management & Social System

> **A console-based University Management System built in C++ that simulates real-world university operations using core Data Structures and Algorithms — including Linked Lists, BST, Graphs, Maps, and Trees.**

---

## 📋 Table of Contents

1. [Project Overview](#project-overview)
2. [Key Features](#key-features)
3. [System Requirements](#system-requirements)
4. [Data Structures Used](#data-structures-used)
5. [Algorithms & Complexities](#algorithms--complexities)
6. [System Design](#system-design)
7. [Project Structure](#project-structure)
8. [How to Run](#how-to-run)
9. [Login Credentials](#login-credentials)
10. [Admin Menu](#admin-menu)
11. [Student Menu](#student-menu)
12. [Sample Data (Preloaded)](#sample-data-preloaded)
13. [Future Roadmap](#future-roadmap)
14. [References](#references)

---

## 🏛️ Project Overview

The **University Management & Social System** is a C++ console application that simulates the digital operations of a university environment. It supports two types of users — **Admin** and **Student** — who can perform operations like course management, student record management, enrollment, friendship networking, and assignment tracking.

The project bridges the gap between theoretical DSA concepts and practical software design by integrating multiple data structures into one cohesive system — all without a database or GUI framework.

> **Course:** Data Structures Lab (15B17CI371) — B.Tech III Semester  
> **Institution:** Jaypee Institute of Information Technology, Noida    
> **Supervisor:** Mr. Mohit Singh, Dept. of CSE, JIIT

---

## ✨ Key Features

| Feature | Description |
|---|---|
| 🔐 Dual Login System | Separate Admin and Student login with credential validation |
| 🧑‍🎓 Student Management | Add, delete, search, and display student records dynamically |
| 📚 Course Management | Add, delete, and view courses with ID, title, and credits |
| 📝 Enrollment System | Enroll or de-enroll students from courses via Map + Set |
| 🤝 Friendship Network | Add/remove/view student friendships using an undirected Graph |
| 📁 Assignment Tracker | Tree-based file system simulation for assignment submissions |
| 🔍 Search & Sort | Linear search on Linked List; sort students by roll number |
| 🔑 Auto Password Generation | Student passwords auto-generated as `Student@XX` from roll number |
| 📦 Sample Data | Preloaded sample students, courses, and assignments on startup |

---

## 🖥️ System Requirements

### Software Requirements

| Component | Requirement |
|---|---|
| **Language** | C++ (C++11 or later) |
| **Compiler** | GCC / g++ |
| **IDE** | Code::Blocks, Visual Studio Code, or any terminal |
| **OS** | Windows / Linux / macOS |

### Functional Requirements

- Admin Login with fixed credentials (`Admin / Admin@128`)
- Student login with auto-generated password (`Student@XX` based on roll number)
- Course CRUD operations (Create, Read, Delete)
- Student CRUD operations with dynamic Linked List
- Many-to-many enrollment via `unordered_map<int, set<string>>`
- Friendship graph stored as `unordered_map<int, set<int>>`
- Tree-based file nodes for assignment tracking

---

## 🧱 Data Structures Used

| Data Structure | Implementation | Purpose |
|---|---|---|
| **Vector** | `vector<Course>` | Store all available courses |
| **Linked List** | Custom `Node*` chain | Dynamic student record management |
| **Map + Set** | `unordered_map<int, set<string>>` | Student ↔ Course enrollment (multi-list) |
| **Graph (Adjacency List)** | `unordered_map<int, set<int>>` | Student friendship network (undirected) |
| **Tree** | Custom `FileNode*` with children vector | Assignment file system simulation |

---

## ⚙️ Algorithms & Complexities

| Operation | Algorithm | Complexity |
|---|---|---|
| Student Search | Linear traversal of Linked List | O(n) |
| Course Search | Linear traversal of Vector | O(n) |
| Sort Students (display) | `std::sort` — Introsort internally | O(n log n) |
| Enrollment (insert) | `unordered_map` + `set` insertion | O(log n) |
| Friendship Add/Remove | `set` insert/erase in adjacency map | O(log n) |
| Assignment Add/Delete | Vector traversal on `FileNode` children | O(n) |

---

## 🗺️ System Design

```
                    UNIVERSITY MANAGEMENT SYSTEM
                               │
                 ┌─────────────┴─────────────┐
              Admin                        Student
                 │                              │
    ┌────────────┼────────────┐      ┌──────────┼──────────┐
  Courses    Students    Enrollment  MyCourses Friends  Assignments
 (Vector)  (LinkedList)  (Map+Set)  (Map+Set) (Graph)    (Tree)
```

### Structure / Class Overview

| Structure | Purpose |
|---|---|
| `Course` | Stores course `id`, `title`, and `credits` |
| `Student` | Stores student `roll`, `firstName`, `lastName`, `email`, `batch`, `password` |
| `Node` | Linked List node wrapping a `Student*` pointer |
| `FileNode` | Tree node representing an assignment file or directory |

---

## 📁 Project Structure

```
university-management-system/
├── main.cpp          # Complete C++ source code
├── README.md         # Project documentation
└── docs/
    ├── synopsis.pdf  # Project synopsis submitted to JIIT
    └── report.pdf    # Detailed project report
```

---

## 🚀 How to Run

### Prerequisites
- GCC / G++ compiler with C++11 support

### Compile

```bash
g++ -std=c++11 -o university_management main.cpp
```

### Run

```bash
./university_management        # Linux / macOS
university_management.exe      # Windows
```

On launch, sample data is automatically preloaded (2 students, 3 courses, 2 assignments).

---

## 🔑 Login Credentials

### Admin Login
```
Username : Admin
Password : Admin@128
```

### Student Login
```
Roll Number : 1001  (Abhinav Garg)
Password    : Student@01

Roll Number : 1002  (Samridhi Bansal)
Password    : Student@02
```

> 💡 Student passwords are auto-generated as `Student@` + last two digits of roll number.

---

## 🧑‍💼 Admin Menu

```
ADMIN MENU
1. Add Course
2. Delete Course
3. Add Student
4. Delete Student
5. Enroll Student in Course
6. De-enroll Student from Course
7. Show All Students
8. Show All Courses
9. Add Assignment
0. Logout
```

| Option | Action |
|---|---|
| Add Course | Enter Course ID, Title, Credits — adds to `allCourses` vector |
| Delete Course | Removes course by ID using `remove_if` |
| Add Student | Auto-assigns roll number, generates password, enrolls in all default courses |
| Delete Student | Removes student node from Linked List |
| Enroll / De-enroll | Updates `studentCourses` map for the given roll + course ID |
| Show All Students | Displays all students sorted by roll number |
| Add Assignment | Adds a `FileNode` to the assignment tree root |

---

## 🧑‍🎓 Student Menu

```
STUDENT MENU
1. View All Courses
2. View My Courses
3. Add Friend
4. Remove Friend
5. View Friends
6. View Assignments
7. Mark Assignment Completed
0. Logout
```

| Option | Action |
|---|---|
| View All Courses | Lists all courses from `allCourses` vector |
| View My Courses | Shows course IDs enrolled for the logged-in student |
| Add / Remove Friend | Inserts or removes from `friendsMap` (both directions — undirected) |
| View Friends | Prints all roll numbers connected to the student in the graph |
| View Assignments | Traverses and prints the assignment `FileNode` tree |
| Mark Completed | Removes a `FileNode` by name from the assignment tree |

---

## 📦 Sample Data (Preloaded)

On startup, `sampleData()` loads the following automatically:

**Courses:**
| ID | Title | Credits |
|---|---|---|
| CS101 | Intro to Programming | 4 |
| CS102 | Data Structures | 4 |
| CS103 | Algorithms | 3 |

**Students:**
| Roll | Name | Email | Batch |
|---|---|---|---|
| 1001 | Abhinav Garg | abhinav@jiit.ac.in | F-11 |
| 1002 | Samridhi Bansal | samridhi@jiit.ac.in | F-11 |

Both students are auto-enrolled in all 3 courses.

**Assignments:**
- `Lab1.txt`
- `Project.docx`

---

## 🔭 Future Roadmap

- [ ] **GUI Interface** — Build a graphical interface using Qt or Java Swing
- [ ] **Database Integration** — Connect to MySQL/SQLite for persistent storage
- [ ] **File I/O** — Save and load student/course records from `.txt` or `.csv` files
- [ ] **BST for Student Search** — Replace linear Linked List search with a BST for O(log n) lookup
- [ ] **BFS/DFS Traversal** — Implement friend-of-friend discovery using graph traversal
- [ ] **Role-based Access** — Add more roles (Faculty, HOD) with different permissions
- [ ] **Analytics** — Course popularity, friend network size, enrollment statistics

---

## 📚 References

1. Project Synopsis: *University Management & Social System*, JIIT Noida (2025)
2. GeeksforGeeks — *Data Structures and Algorithms Concepts*
3. CPPReference — *Standard Template Library (STL)* documentation
4. TutorialsPoint — *C++ File Handling and OOP Concepts*
5. JIIT DSA Lab Manual (15B17CI371)

---
