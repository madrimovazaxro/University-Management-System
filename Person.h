#pragma once
#include <iostream>
#include <string>

class Person {
protected:
    std::string name;
    int age;
    char gender;

public:
    Person(std::string n = "", int a = 0, char g = 'U') {
        setPerson(n, a, g);
    }

    virtual ~Person() {}

    void setPerson(std::string n, int a, char g) {
        name = n;

        if (a > 0) age = a;
        else {
            std::cout << "Invalid age for " << name << "! Age set to 0.\n";
            age = 0;
        }

        if (g == 'M' || g == 'F') gender = g;
        else {
            std::cout << "Invalid gender for " << name << "! Gender set to 'U'.\n";
            gender = 'U';
        }
    }

    virtual void show() const {
        std::cout << "Name   : " << name << "\n";
        std::cout << "Age    : " << age << "\n";
        std::cout << "Gender : " << gender << "\n";
    }
};

// ---------------- STUDENT ----------------
class Student : public Person {
private:
    int id;
    std::string subject;
    int grade;

public:
    Student(std::string n, int a, char g, int i, std::string sub, int gr)
        : Person(n, a, g) {
        setStudent(i, sub, gr);
    }

    void setStudent(int i, std::string sub, int gr) {
        if (i > 0) id = i;
        else {
            std::cout << "Invalid ID for " << name << "! Set to 0.\n";
            id = 0;
        }

        subject = sub;

        if (gr >= 0 && gr <= 100) grade = gr;
        else {
            std::cout << "Invalid grade for " << name << "! Set to 0.\n";
            grade = 0;
        }
    }

    void show() const override {
        std::cout << "\n--- Student ---\n";
        Person::show();
        std::cout << "ID     : " << id << "\n";
        std::cout << "Subject: " << subject << "\n";
        std::cout << "Grade  : " << grade << "\n";
    }
};

// ---------------- TEACHER ----------------
class Teacher : public Person {
private:
    std::string course;

public:
    Teacher(std::string n, int a, char g, std::string c)
        : Person(n, a, g), course(c) {}

    void show() const override {
        std::cout << "\n--- Teacher ---\n";
        Person::show();
        std::cout << "Course : " << course << "\n";
    }
};