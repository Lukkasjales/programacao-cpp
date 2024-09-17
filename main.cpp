#include <fstream>
#include <iomanip>
#include <ios>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct Student {
    string name;
    string registration;
    string classgroup;
};

struct Discipline {
    string name;
    string id;
};

vector<vector<float>> grades; 
vector<Student> students_list;
vector<Discipline> disciplines;

void load_students() {
    ifstream file("students.txt");
    if (!file.is_open()) {
        cout << "Erro ao abrir arquivo" << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        istringstream iss(line); //input operations on strings
        string name, registration, classgroup;
        if (getline(iss, name, ',') && getline(iss, registration, ',') && getline(iss, classgroup)) {
            students_list.push_back({name, registration, classgroup});
        }
    }
    file.close();
}

void load_disciplines() {
    ifstream file("disciplines.txt");
    if (!file.is_open()) {
        cout << "Erro ao abrir arquivo" << endl;
        return;
    }
    
    string line;
    while(getline(file, line)) {
        istringstream iss(line);
        string name, id;
        if (getline(iss, name, ',') && getline(iss, id)) {
            students_list.push_back({name, id});
        }
    }
    file.close();
}

void reload_grades() {
    grades.clear();
    grades.resize(students_list.size(), vector<float>(disciplines.size(), 0.0f)); // initializes the grades at 0
}

void load_grades() {
    ifstream file("grades.txt");
    if (!file.is_open()) {
        cout << "Erro ao abrir arquivo \"grades.txt\"";
        reload_grades();
        return;
    }
    
    string line;
    grades.clear();
    while (getline(file, line)) {
        istringstream iss(line);
        string value;
        vector<float> student_grades;
        while (getline(iss, value, ',')) {
            student_grades.push_back(stof(value));
        }
        grades.push_back(student_grades);
    }
    file.close();

    if (grades.size() != students_list.size() || 
    (grades.size() > 0 && grades[0].size() != disciplines.size())) {
        cout << "Erro nas listas de notas e disciplinas, refazendo a lista" << endl;
        reload_grades();       
    }
}

int main() {
    setlocale(LC_ALL, "pt_br.UTF-8");
    //init_system();

    int option;
    do {
        cout << "\nMenu Principal:" << endl;
        cout << "1 - Cadastrar Aluno" << endl;
        cout << "2 - Cadastrar Disciplina" << endl;
        cout << "3 - Lançar Notas" << endl;
        cout << "4 - Calcular Médias" << endl;
        cout << "5 - Consultar Notas de Aluno" << endl;
        cout << "6 - Consultar Notas de Disciplina" << endl;
        cout << "7 - Gerar Relatório" << endl;
        cout << "0 - Sair" << endl;
        cout << "Escolha uma opção: ";
    
        while(!(cin >> option)) { //when 'cin >> option' fails (isn't a int value) it is false, then the '!' operator turns it true
            cout << "Digite um número" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    
    } while {

    }

    
}
