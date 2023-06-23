#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct Student {
    string name;
    int id;
    string course;
};

struct Course {
    string name;
    string code;
};

// Function to display the menu
void display()
{
    system("cls");
    cout << "Student Identification System" << endl;
    cout << "1. Add Student" << endl;
    cout << "2. Search for Student" << endl;
    cout << "3. Delete Student" << endl;
    cout << "4. Update Student" << endl;
    cout << "5. List of Students" << endl;
    cout << "6. Add Course" << endl;
    cout << "7. Search for Course" << endl;
    cout << "8. Delete Course" << endl;
    cout << "9. Update Course" << endl;
    cout << "10. List of Courses" << endl;
    cout << "0. Exit/Save" << endl;
    cout << "Enter your choice: ";
}

// Function to add a student to the database
void add_student(vector<Student>& students)
{
    Student student;
    system("cls");
    cout << "Enter student name: ";
    getline(cin, student.name);
    cout << "Enter student ID: ";
    cin >> student.id;
    cin.ignore();
    cout << "Enter student course: ";
    getline(cin, student.course);
    students.push_back(student);
    cout << "\nStudent added successfully!" << endl;
    system("pause");
}

// Function to add a course to the database
void add_course(vector<Course>& courses)
{
    Course course;
     system("cls");
    cout << "Enter course name: ";
    getline(cin, course.name);
    cout << "Enter course code: ";
    getline(cin, course.code);
    courses.push_back(course);
    cout << "\nCourse added successfully!" << endl;
    system("pause");
}

// Function to select a student from the database
void select_student_id(const vector<Student>& students)
{
    int id;
    system("cls");
    cout << "Enter student ID: ";
    cin >> id;
    cin.ignore();
    for (const auto& student : students) {
        if (student.id == id) {
            cout << "\nStudent name: " << student.name << endl;
            cout << "Student ID: " << student.id << endl;
            cout << "Student course: " << student.course << endl<<endl;
            system("pause");
            return;
        }
    }
    system("cls");
    cout << "Student not found!" << endl;
    system("pause");
}

void select_student_name(const vector<Student>& students)
{
    string key;
    system("cls");
    cout << "Enter student Name(BE MINDFUL OF CAPITALS): ";
    cin >> key;
    cin.ignore();
    for (const auto& student : students) {
            size_t proc = student.name.find(key);
            if(proc != string::npos) {
            cout << "\nStudent name: " << student.name << endl;
            cout << "Student ID: " << student.id << endl;
            cout << "Student course: " << student.course << endl<<endl;
            system("pause");
            return;
        }
    }
    system("cls");
    cout << "Student not found!" << endl;
    system("pause");
}

void select_course(const vector<Course>& courses)
{
    string key;
    system("cls");
    cout << "Enter Course code: ";
    cin >> key;
    cin.ignore();
    for (const auto& course : courses) {
            size_t proc = course.code.find(key);
            if(proc != string::npos) {
            cout << "\nCourse name: " << course.name << endl;
            cout << "Course code: " << course.code << endl<<endl;
            system("pause");
            return;
        }
    }
    system("cls");
    cout << "Course not found!" << endl;
    system("pause");
}

// Function to list all students
void list_students(vector<Student>& students)
{
    system("cls");
    cout<<"Current students in the database: "<<endl<<endl;
    for (const auto& student : students)
        {
            cout << "Student name: " << student.name << endl;
            cout << "Student ID: " << student.id << endl;
            cout << "Student course: " << student.course << endl<<endl;
        }
    system("pause");
}

// Function to list all courses
void list_courses(vector<Course>& courses)
{
    system("cls");
    cout<<"Current courses in the database: "<<endl<<endl;
    for (const auto& course: courses)
        {
            cout << "Course name: " << course.name << endl;
            cout << "Course code: " << course.code << endl<<endl;
        }
    system("pause");
}

// Function to delete a student from the database
void delete_student(vector<Student>& students)
{
    int id;
    string ch;
    system("cls");
    cout << "Enter student ID: ";
    cin >> id;
    cout << "\nAre you sure you want to delete this course?(Y/N) ";
    cin >> ch;

    if (ch == "Y" || ch == "y") {
        for (auto it = students.begin(); it != students.end(); ++it) {
            if (it->id == id) {
                students.erase(it);
                cout << "\nStudent deleted successfully!" << endl;
                system("pause");
                return;
            }
        }
    }
    else{
        cout << "\nDeletion aborted!\n";
        system("pause");
        return;
    }
    system("cls");
    cout << "Student not found!" << endl;
    system("pause");
}

// Function to delete a student from the database
void delete_course(vector<Course>& courses, vector<Student>& students)
{
    string code, ch;
    system("cls");
    cout << "Enter Course code: ";
    cin >> code;
    cin.ignore();
    cout << "\nAre you sure you want to delete this course?(Y/N) ";
    cin >> ch;

    if(ch == "Y" || ch == "y") {
        for (auto it = courses.begin(); it != courses.end(); ++it) {
        if (it->code == code) {
            courses.erase(it);
            for (auto stu = students.begin(); stu != students.end(); ++stu) {
                if (stu->course == code){
                 stu->course = "NULL";
                }
            }
            cout << "\nCourse deleted successfully!" << endl;
            system("pause");
            return;
            }
        }
    }
    else{
        cout << "\nDeletion aborted!\n";
        system("pause");
        return;
    }
    system("cls");
    cout << "Student not found!" << endl;
    system("pause");
}

// Function to update a student's course in the database
void update_student_course(vector<Student>& students) {
    int id;
    system("cls");
    cout << "Enter student ID: ";
    cin >> id;
    cin.ignore();
    for (auto& student : students) {
        if (student.id == id) {
            cout << "Enter new course: ";
            getline(cin, student.course);
            cout << "\nCourse updated successfully!" << endl;
            system("pause");
            return;
        }
    }
    system("cls");
    cout << "Student not found!" << endl;
    system("pause");
}

// Function to update a student's course in the database
void update_student_name(vector<Student>& students) {
    int id;
    system("cls");
    cout << "Enter student ID: ";
    cin >> id;
    cin.ignore();
    for (auto& student : students) {
        if (student.id == id) {
            cout << "Enter new name: ";
            getline(cin, student.name);
            cout << "\nName updated successfully!" << endl;
            system("pause");
            return;
        }
    }
    system("cls");
    cout << "\nStudent not found!" << endl;
    system("pause");
}

// Function to update course
void update_course(vector<Course>& courses)
{
    system("cls");
    string code;
    cout << "Enter Course code: ";
    cin >> code;
    for (auto& course : courses) {
        if(course.code == code) {
            cout << "Enter new name: ";
            getline(cin, course.name);
            cout << "\nCourse updated successfully!" << endl;
            system("pause");
            return;
        }
    }
    system("cls");
    cout << "Course not found!" << endl;
    system("pause");
}

// Function to save the student database to a text file
void save_database_studs(const vector<Student>& students) {
    ofstream file("database.txt");
    for (const auto& student : students) {
        file << student.name << "," << student.id << "," << student.course << endl;
    }
    file.close();
}

// Function to save the course database to a text file
void save_database_curs(const vector<Course>& courses) {
    ofstream file("database.curs.txt");
    for (const auto& course : courses) {
        file << course.name << "," << course.code << endl;
    }
    file.close();
}

// Function to load the student database from a text file
void load_database_studs(vector<Student>& students) {
    ifstream file("database.studs.txt");
    if (file) {
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            Student student;
            getline(ss, student.name, ',');
            ss >> student.id;
            ss.ignore();
            getline(ss, student.course);
            students.push_back(student);
        }
        file.close();
    } else {
        cout << "Database file not found. Creating a new database." << endl;
    }
}

// Function to load the course database from a text file
void load_database_curs(vector<Course>& courses) {
    ifstream file("database.curs.txt");
    if (file) {
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            Course course;
            getline(ss, course.name, ',');
            getline(ss, course.code);
            courses.push_back(course);
        }
        file.close();
    } else {
        cout << "Database file not found. Creating a new database." << endl;
    }
}

int main()
 {
      vector<Student> students;
      vector<Course> courses;
      load_database_studs(students);
      load_database_curs(courses);
      int choice, ch;
      cout<<"Welcome to I(made this).Student.Identification.System"<<endl<<endl;
      system("pause");
      do {
      display();
      cin >> choice;
      cin.ignore();
      switch (choice) {
      case 1:
          add_student(students);
          break;
      case 2:
          system("cls");
          cout<<"Search by name(1) or ID(2)? ";
          cin>>ch;
          if(ch == 1){
            select_student_name(students);
          }
          else if(ch == 2){
            select_student_id(students);
          }
          else
            cout<<"\nERROR!!";
          break;
      case 3:
          delete_student(students);
          break;
      case 4:
          system("cls");
          cout << "Update Student Name(1) or Course(2)? ";
          cin >> ch;
          if (ch == 1){
            update_student_name(students);
          }
          else if (ch == 2){
            update_student_course(students);
          }
          break;
      case 5:
          list_students(students);
          break;
      case 6:
          add_course(courses);
          break;
      case 7:
          system("cls");
          select_course(courses);
          break;
      case 8:
          delete_course(courses, students);
          break;
      case 9:
          system("cls");
          update_course(courses);
          break;
      case 10:
          list_courses(courses);
          break;
      case 0:
          save_database_studs(students);
          save_database_curs(courses);
          cout << "Exiting program..." << endl;
          return 0;
          break;
      default:
          system("cls");
          cout << "Invalid choice. Please try again." << endl;
          system("pause");
          break;
          }
        } while (true);

    return 0;
}
