//Naafiul Hossain
//SBU ID: 115107623

#include <iostream>
#include <string>
using namespace std;

class CEAS {
public:
    virtual void displayInfo();
    virtual void requirements();
    virtual void PrintCores();
};

class ECE : public CEAS {
public:
    void displayInfo() override;
    void PrintCores() override;
};

class ESE : public CEAS {
public:
    void displayInfo() override;
    void requirements() override;
    void PrintCores() override;
};

void CEAS::displayInfo() {
    cout << "CEAS students need..." << endl;
}

void CEAS::requirements() {
    cout << "Req1: Completion of at least 120 credit hours of passing work" << endl;
    cout << "Req2: A minimum cumulative grade point average of 2.00" << endl;
}

void CEAS::PrintCores() {}

void ECE::displayInfo() {
    cout << "ECE students need..." << endl;
}

void ECE::PrintCores() {
    cout << "ECE core1: Computer Arch" << endl;
    cout << "ECE core2: RealTimeOS" << endl;
    cout << "ECE core3: VHDL" << endl;
}

void ESE::displayInfo() {
    cout << "ESE students need..." << endl;
}



void ESE::requirements() {
    CEAS::requirements();  // Call the base class requirements
    cout << "ESE-specific requirement..." << endl;
}




void ESE::PrintCores() {
    cout << "ESE core1: Electromagnetic and Transmission Line Theroy" << endl;
    cout << "ESE core2:  Control Theroy" << endl;
}

void displayInfo(CEAS* p) {
    p->displayInfo();
}

void printRequirements(CEAS* p) {
    p->requirements();
}

void printCores(CEAS* p) {
    p->PrintCores();
}

int main() {
    CEAS* ceasStudent = new CEAS;
    displayInfo(ceasStudent);
    printRequirements(ceasStudent);
    printCores(ceasStudent);
    cout << "................" << endl;

    CEAS* eseStudent = new ESE;
    displayInfo(eseStudent);
    printRequirements(eseStudent);
    printCores(eseStudent);
    cout << "................." << endl;

    CEAS* eceStudent = new ECE;
    displayInfo(eceStudent);
    printRequirements(eceStudent);
    printCores(eceStudent);

    // Don't forget to delete the allocated memory
    delete ceasStudent;
    delete eseStudent;
    delete eceStudent;

    return 0;
}



