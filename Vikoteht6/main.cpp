#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

#include "student.h"


using namespace std;

int main ()
{
    int selection =0;
    vector<Student>studentList;

    do
    {
        cout<<"Select"<<endl;
        cout<<"Add students = 0"<<endl;
        cout<<"Print all students = 1"<<endl;
        cout<<"Sort and print students according to Name = 2"<<endl;
        cout<<"Sort and print students according to Age = 3"<<endl;
        cout<<"Find and print student = 4"<<endl;
        cin>>selection;

        switch(selection)
        {
        case 0: {

            // Kysy käyttäjältä uuden opiskelijan nimi ja ikä
            // Lisää uusi student StudentList vektoriin.
            string name;
            int age;
            cout << "Anna oppilan nimi: " << endl;
            cin.ignore();  // Handle leftover newline
            getline(cin, name);
            cout << ("Anna opiskelijan ika: ") << endl;
            cin >> age;

            studentList.emplace_back(name, age);
            cout << "Oppilas lisatty!" << endl;

            break; }


        case 1:
            // Tulosta StudentList vektorin kaikkien opiskelijoiden
            // nimet.
            if (studentList.empty()) {
                cout << "Listassa ei ole opiskelijoita." << endl;
                break;
            } else {
                for (const auto& student : studentList) {
                    student.printStudentInfo();
                }
            }
            break;

        case 2:
            // Järjestä StudentList vektorin Student oliot nimen mukaan
            // algoritmikirjaston sort funktion avulla
            // ja tulosta printStudentInfo() funktion avulla järjestetyt
            // opiskelijat
            if (studentList.empty()) {
                cout << "Listassa ei ole opiskelijoita." << endl;
                break;
            } else {
                sort(studentList.begin(), studentList.end(), [](Student &a, Student &b) {
                    return a.getName() < b.getName();
                });

                for (const auto& student : studentList) {
                    student.printStudentInfo();
                }
            }
            break;

        case 3:
            // Järjestä StudentList vektorin Student oliot iän mukaan
            // algoritmikirjaston sort funktion avulla
            // ja tulosta printStudentInfo() funktion avulla järjestetyt
            // opiskelijat
            if (studentList.empty()) {
                cout << "Listassa ei ole opiskelijoita." << endl;
                break;
            } else {
                sort(studentList.begin(), studentList.end(), [](Student &a, Student &b) {
                    return a.getAge() < b.getAge();
                });

                for (const auto& student : studentList) {
                    student.printStudentInfo();
                }
            }
            break;
        case 4:
            // Kysy käyttäjältä opiskelijan nimi
            // Etsi studentListan opiskelijoista algoritmikirjaston
            // find_if funktion avulla löytyykö käyttäjän antamaa nimeä
            // listalta. Jos löytyy, niin tulosta opiskelijan tiedot.
            if (studentList.empty()) {
                cout << "Listassa ei ole opiskelijoita." << endl;
            } else {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                string targetName;
                cout << "Anna opiskelijan nimi: ";
                getline(cin, targetName);

                auto it = find_if(studentList.begin(), studentList.end(), [&targetName](Student& student) {
                    return student.getName() == targetName;
                });

                if (it != studentList.end()) {
                    cout << "Loytyi nimi: " << endl;
                    cout << endl;
                    it->printStudentInfo();
                } else {
                    cout << "Oppilasta ei loytynyt." << endl;
                }
            }

            break;

    default:
        cout<< "Wrong selection, stopping..."<<endl;
        break; }
    }
    while(selection < 5);

return 0;
}
