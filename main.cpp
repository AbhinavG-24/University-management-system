#include <bits/stdc++.h>
using namespace std;

int nextRoll = 1001;


struct Course {
    string id;
    string title;
    int credits;
};

vector<Course> allCourses;

void addCourse(const Course &c) {
    for (auto &course : allCourses) {
        if (course.id == c.id) {
            cout << "Error: Course ID already exists.\n";
            return;
        }
    }
    allCourses.push_back(c);
    cout << "Course added successfully.\n";
}

void deleteCourse(const string &id) {
    auto it = remove_if(allCourses.begin(), allCourses.end(),
                        [&](const Course &c) { return c.id == id; });
    if (it != allCourses.end()) {
        allCourses.erase(it, allCourses.end());
        cout << "Course deleted successfully.\n";
    } else {
        cout << "Error: Course not found.\n";
    }
}

void showCourses() {
    if (allCourses.empty()) {
        cout << "No courses available.\n";
        return;
    }
    cout << "\nAvailable Courses:\n";
    for (auto &c : allCourses)
        cout << c.id << " - " << c.title << " (" << c.credits << " credits)\n";
}


struct Student {
    int roll;
    string firstName, lastName;
    string email, batch;
    string password;
};

struct Node {
    Student *data;
    Node *next;
    Node(Student *s) : data(s), next(nullptr) {}
};

Node *studentHead = nullptr;

void addStudent(Student *s) {
    Node *newNode = new Node(s);
    newNode->next = studentHead;
    studentHead = newNode;
    cout << "Student added successfully. Roll: " << s->roll << "\n";
}

void deleteStudent(int roll) {
    Node *curr = studentHead, *prev = nullptr;
    while (curr) {
        if (curr->data->roll == roll) {
            if (prev)
                prev->next = curr->next;
            else
                studentHead = curr->next;
            delete curr->data;
            delete curr;
            cout << "Student deleted successfully.\n";
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    cout << "Error: Student not found.\n";
}

Student* findStudent(int roll) {
    Node *curr = studentHead;
    while (curr) {
        if (curr->data->roll == roll)
            return curr->data;
        curr = curr->next;
    }
    return nullptr;
}

void showAllStudents() {
    vector<Student*> students;
    Node *curr = studentHead;

    if (!curr) {
        cout << "No student records found.\n";
        return;
    }

    while (curr) {
        students.push_back(curr->data);
        curr = curr->next;
    }

    sort(students.begin(), students.end(),
         [](Student *a, Student *b) { return a->roll < b->roll; });

    cout << "\nStudent Records (Sorted by Roll No):\n";
    for (auto s : students) {
        cout << "Roll: " << s->roll
             << ", Name: " << s->firstName << " " << s->lastName
             << ", Email: " << s->email
             << ", Batch: " << s->batch << "\n";
    }
}



unordered_map<int, set<string>> studentCourses;

void enrollDefaultCourses(int roll) {
    if (allCourses.empty()) {
        cout << "Error: No courses available to enroll.\n";
        return;
    }

    Student *s = findStudent(roll);
    if (!s) {
        cout << "Error: Invalid student roll number.\n";
        return;
    }

    for (auto &c : allCourses)
        studentCourses[roll].insert(c.id);
    cout << "Default courses enrolled for Roll: " << roll << "\n";
}

void enrollStudent(int roll, string id) {
    Student *s = findStudent(roll);
    if (!s) {
        cout << "Error: No student found with roll " << roll << ".\n";
        return;
    }

    bool courseFound = false;
    for (auto &c : allCourses) {
        if (c.id == id) {
            courseFound = true;
            break;
        }
    }

    if (!courseFound) {
        cout << "Error: Course ID " << id << " not found.\n";
        return;
    }

    if (studentCourses[roll].insert(id).second)
        cout << "Enrolled successfully in " << id << ".\n";
    else
        cout << "Student already enrolled in " << id << ".\n";
}

void deEnrollStudent(int roll, string id) {
    Student *s = findStudent(roll);
    if (!s) {
        cout << "Error: No student found with roll " << roll << ".\n";
        return;
    }

    if (studentCourses.find(roll) == studentCourses.end()) {
        cout << "Error: Student has no enrollments.\n";
        return;
    }

    if (studentCourses[roll].erase(id))
        cout << "De-enrolled from " << id << ".\n";
    else
        cout << "Error: Student not enrolled in " << id << ".\n";
}

void showStudentCourses(int roll) {
    Student *s = findStudent(roll);
    if (!s) {
        cout << "Error: No student found with roll " << roll << ".\n";
        return;
    }

    if (studentCourses[roll].empty()) {
        cout << "No courses enrolled for Roll " << roll << ".\n";
        return;
    }

    cout << "\nCourses of Roll " << roll << ":\n";
    for (auto &id : studentCourses[roll])
        cout << "- " << id << "\n";
}




unordered_map<int, set<int>> friendsMap;

void addFriendship(int r1, int r2) {
    if (r1 == r2) {
        cout << "Error: Cannot add yourself as a friend.\n";
        return;
    }

    if (!findStudent(r1) || !findStudent(r2)) {
        cout << "Error: One or both roll numbers do not exist.\n";
        return;
    }

    friendsMap[r1].insert(r2);
    friendsMap[r2].insert(r1);
    cout << "Friendship added between " << r1 << " and " << r2 << ".\n";
}

void removeFriendship(int r1, int r2) {
    if (!findStudent(r1) || !findStudent(r2)) {
        cout << "Error: One or both roll numbers do not exist.\n";
        return;
    }

    if (friendsMap[r1].erase(r2) && friendsMap[r2].erase(r1))
        cout << "Friendship removed successfully.\n";
    else
        cout << "Error: Friendship does not exist.\n";
}

void showFriends(int roll) {
    if (!findStudent(roll)) {
        cout << "Error: Student not found.\n";
        return;
    }

    cout << "Friends of Roll " << roll << ": ";
    if (friendsMap[roll].empty())
        cout << "None\n";
    else {
        for (int f : friendsMap[roll])
            cout << f << " ";
        cout << "\n";
    }
}



    struct FileNode {
    string name;
    bool isFile;
    vector<FileNode*> children;
    FileNode(string n, bool f = false) : name(n), isFile(f) {}
};

FileNode *root = new FileNode("Assignments");

FileNode* addFile(FileNode *parent, string name) {
    for (auto c : parent->children) {
        if (c->name == name && c->isFile) {
            cout << "Error: Assignment already exists.\n";
            return c;
        }
    }
    FileNode *file = new FileNode(name, true);
    parent->children.push_back(file);
    cout << "Assignment added successfully: " << name << "\n";
    return file;
}

void showFiles(FileNode *node, string indent = "") {
    cout << indent << (node->isFile ? "- " : "+ ") << node->name << "\n";
    for (auto c : node->children)
        showFiles(c, indent + "  ");
}

void removeFile(FileNode *parent, string name) {
    auto it = remove_if(parent->children.begin(), parent->children.end(),
                        [&](FileNode* f) { return f->name == name && f->isFile; });
    if (it != parent->children.end()) {
        parent->children.erase(it, parent->children.end());
        cout << "Assignment marked as completed: " << name << "\n";
    } else {
        cout << "Error: Assignment not found.\n";
    }
}


bool adminLogin() {
    string user, pass;
    cout << "\nADMIN LOGIN\nUsername: ";
    cin >> user;
    cout << "Password: ";
    cin >> pass;
    if (user == "Admin" && pass == "Admin@128") {
        cout << "Admin login successful.\n";
        return true;
    }
    cout << "Invalid credentials.\n";
    return false;
}

Student* studentLogin() {
    int roll;
    string pass;
    cout << "\nSTUDENT LOGIN\nRoll Number: ";
    cin >> roll;
    Student *s = findStudent(roll);
    if (!s) {
        cout << "Error: No student found.\n";
        return nullptr;
    }
    cout << "Password: ";
    cin >> pass;

    stringstream ss;
    ss << setw(2) << setfill('0') << (roll % 100);
    string lastTwo = ss.str();
    string correct = "Student@" + lastTwo;

    if (pass == correct) {
        cout << "Welcome " << s->firstName << ".\n";
        return s;
    } else {
        cout << "Incorrect password.\n";
        return nullptr;
    }
}



void sampleData() {
    addCourse({"CS101", "Intro to Programming", 4});
    addCourse({"CS102", "Data Structures", 4});
    addCourse({"CS103", "Algorithms", 3});

    Student *a = new Student{nextRoll++, "Abhinav", "Garg", "abhinav@jiit.ac.in", "F11"};
    a->password = "Student@01";
    Student *b = new Student{nextRoll++, "Samridhi", "Bansal", "samridhi@jiit.ac.in", "F11"};
    b->password = "Student@02";

    addStudent(a);
    addStudent(b);

    enrollDefaultCourses(a->roll);
    enrollDefaultCourses(b->roll);

    addFile(root, "Lab1.txt");
    addFile(root, "Project.docx");
}



void adminMenu() {
    while (true) {
        cout << "\nADMIN MENU\n";
        cout << "1. Add Course\n2. Delete Course\n3. Add Student\n4. Delete Student\n";
        cout << "5. Enroll Student\n6. De-enroll Student\n7. Show All Students\n8. Show All Courses\n9. Add Assignment\n0. Logout\n";
        int ch;
        cin >> ch;
        if (ch == 0) break;

        if (ch == 1) {
            Course c;
            cout << "Enter Course ID, Title, Credits:\n";
            cin >> c.id;
            cin.ignore();
            getline(cin, c.title);
            cin >> c.credits;
            addCourse(c);
        } else if (ch == 2) {
            string id;
            cout << "Enter Course ID: ";
            cin >> id;
            deleteCourse(id);
        } else if (ch == 3) {
            Student *s = new Student;
            s->roll = nextRoll++;
            cout << "Enter First Name, Last Name, Email, Batch:\n";
            cin >> s->firstName >> s->lastName >> s->email >> s->batch;
            stringstream ss;
            ss << setw(2) << setfill('0') << (s->roll % 100);
            s->password = "Student@" + ss.str();
            addStudent(s);
            enrollDefaultCourses(s->roll);
        } else if (ch == 4) {
            int roll;
            cout << "Enter Roll: ";
            cin >> roll;
            deleteStudent(roll);
        } else if (ch == 5) {
            int roll;
            string id;
            cout << "Enter Roll and Course ID: ";
            cin >> roll >> id;
            enrollStudent(roll, id);
        } else if (ch == 6) {
            int roll;
            string id;
            cout << "Enter Roll and Course ID: ";
            cin >> roll >> id;
            deEnrollStudent(roll, id);
        } else if (ch == 7) showAllStudents();
        else if (ch == 8) showCourses();
        else if (ch == 9) {
            string name;
            cout << "Enter Assignment Name: ";
            cin >> name;
            addFile(root, name);
        } else cout << "Invalid choice.\n";
    }
}

void studentMenu(Student *s) {
    while (true) {
        cout << "\nSTUDENT MENU\n";
        cout << "1. View All Courses\n2. View My Courses\n3. Add Friend\n4. Remove Friend\n5. View Friends\n6. View Assignments\n7. Mark Assignment Completed\n0. Logout\n";
        int ch;
        cin >> ch;
        if (ch == 0) break;

        if (ch == 1) showCourses();
        else if (ch == 2) showStudentCourses(s->roll);
        else if (ch == 3) {
            int f; cout << "Enter Friend Roll: "; cin >> f;
            addFriendship(s->roll, f);
        } else if (ch == 4) {
            int f; cout << "Enter Friend Roll to Remove: "; cin >> f;
            removeFriendship(s->roll, f);
        } else if (ch == 5) showFriends(s->roll);
        else if (ch == 6) showFiles(root);
        else if (ch == 7) {
            string name;
            cout << "Enter Assignment Name to Mark Completed: ";
            cin >> name;
            removeFile(root, name);
        } else cout << "Invalid choice.\n";
    }
}

int main(){
sampleData();
cout<<"UNIVERSITY MANAGEMENT SYSTEM\n";
while(true){
    cout<<"\nMain Menu:\n1.Admin Login\n2.Student Login\n0.Exit\nEnter Choice: ";
    int ch;
    cin>>ch;
    if(ch==0) break;
    else if(ch ==1 && adminLogin()) adminMenu();
    else if(ch==2){
        Student *s =studentLogin();
        if(s) studentMenu(s);
    }
}
cout<<"Thank you for using the system.\n";
return 0;
    }





