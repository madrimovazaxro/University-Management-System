#include <iostream>
#include <vector>
#include <memory>
#include "Person.h"

void showAll(const std::vector<std::unique_ptr<Person>>& people) {
    if (people.empty()) {
        std::cout << "No records available.\n";
        return;
    }

    for (const auto& p : people) {
        p->show();
        std::cout << "----------------------\n";
    }
}

int main() {
    std::vector<std::unique_ptr<Person>> people;

    int choice;

    do {
        std::cout << "\n===== MENU =====\n";
        std::cout << "1. Add Student\n";
        std::cout << "2. Add Teacher\n";
        std::cout << "3. Show All\n";
        std::cout << "0. Exit\n";
        std::cout << "Choice: ";
        std::cin >> choice;

        if (choice == 1) {
            std::string name, subject;
            int age, id, grade;
            char gender;

            std::cout << "Name: ";
            std::cin >> name;
            std::cout << "Age: ";
            std::cin >> age;
            std::cout << "Gender (M/F): ";
            std::cin >> gender;
            std::cout << "ID: ";
            std::cin >> id;
            std::cout << "Subject: ";
            std::cin >> subject;
            std::cout << "Grade: ";
            std::cin >> grade;

            people.push_back(std::make_unique<Student>(name, age, gender, id, subject, grade));
        }

        else if (choice == 2) {
            std::string name, course;
            int age;
            char gender;

            std::cout << "Name: ";
            std::cin >> name;
            std::cout << "Age: ";
            std::cin >> age;
            std::cout << "Gender (M/F): ";
            std::cin >> gender;
            std::cout << "Course: ";
            std::cin >> course;

            people.push_back(std::make_unique<Teacher>(name, age, gender, course));
        }

        else if (choice == 3) {
            showAll(people);
        }

    } while (choice != 0);

    return 0;
}