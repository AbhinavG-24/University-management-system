# 🎓 University Management System

A console-based University Management System implemented in **C++** that simulates real-world university operations using fundamental **Data Structures and Algorithms**.

> **Course:** Data Structures Lab (15B17CI371) — B.Tech III Semester  
> **Institution:** Jaypee Institute of Information Technology, Noida  
> **Team:** Abhinav Garg (992401030078), Samridhi (992401030076) — Batch F-11  
> **Supervisor:** Mr. Mohit Singh, Dept. of CSE

---

## 📋 Table of Contents

- [About the Project](#about-the-project)
- [Features](#features)
- [Data Structures Used](#data-structures-used)
- [Algorithms Used](#algorithms-used)
- [Project Structure](#project-structure)
- [How to Run](#how-to-run)
- [System Design](#system-design)

---

## 📖 About the Project

This project simulates a **University Management System** with two roles — **Admin** and **Student**. It demonstrates real-life applications of core data structures and algorithms in managing students, courses, enrollments, social networks, and file systems within a university.

The goal is to bridge the gap between theoretical DSA concepts and practical software design.

---

## ✨ Features

| Feature | Description |
|---|---|
| 🧑‍🎓 Student Record Management | Add, search, and view student records dynamically |
| 📚 Course Management | Add, delete, and search courses using binary search |
| 📝 Course Enrollment | Link students to courses via a multi-list structure |
| 🔗 Prerequisite Mapping | Directed graph to manage course prerequisites |
| 🤝 Social Network | Undirected graph to model student friendships |
| 📁 File System Simulation | Tree-based simulation for student assignment submissions |
| 🔍 Search & Sort | Efficient searching and sorting across records |

---

## 🧱 Data Structures Used

| Data Structure | Application |
|---|---|
| **Array & String** | Store and manage course details and student info |
| **Linked List** | Dynamic management of student records |
| **Binary Search Tree (BST)** | Fast student lookup by roll number |
| **Multi-list** | Many-to-many Student ↔ Course enrollment |
| **Graph (Undirected)** | Student friendship/social network |
| **Graph (Directed)** | Course prerequisite dependencies |
| **Tree** | File system simulation for assignments |

---

## ⚙️ Algorithms Used

- **Binary Search** — Course lookup in sorted course list
- **Inorder Traversal** — Retrieve roll numbers in sorted order from BST
- **BFS (Breadth-First Search)** — Network traversal for friendships
- **DFS (Depth-First Search)** — Prerequisite chain exploration
- **Sorting** — Organize records by roll number / name

---

## 📁 Project Structure

```
university-management-system/
├── main.cpp           # Full source code
├── README.md          # Project documentation
└── docs/
    ├── synopsis.pdf   # Project synopsis
    └── report.pdf     # Detailed project report
```

---

## 🚀 How to Run

### Prerequisites
- GCC / G++ compiler (C++11 or later)

### Compile & Run

```bash
g++ -std=c++11 -o university_management main.cpp
./university_management
```

### Menu Navigation

```
Select Role:
1. Admin
2. Student
0. Exit

Admin Options:
  1. Add Course
  2. Delete Course
  3. Add Student
  4. View All Students
  5. Enroll Student in Course
  ...

Student Options:
  1. View My Courses
  2. View Friends
  3. Search Course
  ...
```

---

## 🗺️ System Design

```
                    University Management System
                             │
              ┌──────────────┴──────────────┐
           Admin                         Student
              │                              │
   ┌──────────┼──────────┐          ┌────────┼────────┐
Courses   Students   Enrollment   MyCourses Friends  Files
(Array)  (LinkedList) (MultiList) (MultiList)(Graph) (Tree)
            │
           BST
       (roll number)
```

---

## 📄 License

This project was developed as part of academic coursework at JIIT Noida. Feel free to use it for learning purposes.
