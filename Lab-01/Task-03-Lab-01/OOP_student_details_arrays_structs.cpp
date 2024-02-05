#include <iostream>
#include <vector>
using namespace std;

class Course{
public:
    std::string course_code;
    std::string course_name;

};

class Grade{
public:
    int mark;
    char the_grade;

    //calculating grade based on mark  using constructor
    explicit Grade(int mark){
        this->mark = mark;
        if(mark > 69)
            the_grade = 'A';
        else if (mark < 70 && mark > 59)
            the_grade = 'B';
        else if (mark < 60 && mark > 49)
            the_grade = 'C';
        else if (mark < 50 && mark > 39)
            the_grade = 'D';
        else
            the_grade = 'E';
    }
};

class Student{
public:
    std::string reg_number;
    std::string name;
    int age;
    Course course;
    Grade grades;

    //a constructor for initializing student details
    Student(std::string reg_number, std::string name, int age, Course course):reg_number(reg_number),name(name),age(age),course(course),grades(0){}

    // function for edit student details
    void editDetails(std::string new_name, int new_age){
        name = new_name;
        age = new_age;
    }

    //function to add marks and calculate grades
    void addMarks(int mark){
        //ensures that marks can only be calculated once
        if(grades.mark == 0){
            grades = Grade(mark);
        }
        else{
            std::cout<<"Error! The grades have already been calculated and cannot be altered"<< std::endl;

        }
    }
};

class StudentData{
public:
    std::vector<Student>students;
    //function that adds at most 40 students

    void addStudent(Student student){
        if(students.size() < 40){
            students.push_back(student);
        }else{
            std::cout<<"maximum number of students has been reached"<<std::endl;
        }
    }
};

int main(){
    //example usage
   Course course1{"SCT211","Computer Science"};
    StudentData database;

    Student student1("SCT211-0201","John Doe", 20, course1);
    database.addStudent(student1);

    //editing student details
    student1.editDetails("Joe stewart", 21);

    //adding marks and calculating grades
    student1.addMarks(75);
    return 0;
}