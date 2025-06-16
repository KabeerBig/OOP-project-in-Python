#include <iostream>
using namespace std;

// ----------------- Animal Base Class ---------------------
// Abstraction
class Animal {
public: 
    string name;
    int age;
    string species;

    static int totalAnimals; // Static member

    // Constructor 
    Animal(string n, int a, string s){
        name = n;
        age = a;
        species = s;
        totalAnimals++;
    }

    // Polymorphism (pure virtual functions)
    virtual void makeSound()=0;

    virtual void getDiet()=0;

    // Make destructor virtual to allow proper deletion of derived classes
    virtual ~Animal(){}  
};

int Animal::totalAnimals = 0; // Define static member

// ------------------ Derived Animal Classes ---------------------
// Polymorphism  
class Lion : public Animal { // Inheritance
public:
    Lion(string n,int a):Animal(n,a,"Lion") {}

    void makeSound()override{
        cout<<name<<" says: Roar!"<<endl;
    }

    void getDiet()override{
        cout<<name<<" is a Carnivore." <<endl;
    }
};

class Elephant:public Animal {
public:
    Elephant(string n,int a):Animal(n,a,"Elephant"){}

    void makeSound()override{
        cout<<name<<" says: Trumpet!"<<endl;
    }

    void getDiet()override{
        cout<<name<<" is a Herbivore."<< endl;
    }
};

class Parrot : public Animal{
public:
    Parrot(string n, int a):Animal(n,a,"Parrot"){}

    void makeSound()override {
        cout<<name<<" says: Squawk!"<<endl;
    }

    void getDiet()override {
        cout<<name<<" is an Omnivore."<<endl;
    }
};

// ------------------- Enclosure Class ---------------------
class Enclosure {
public: 
    int enclosureID;
    string type;
    Animal* animals[10];
    int animalCount;
    static int totalEnclosures;

    Enclosure(){
        enclosureID=1234;
        type="mammal";
        animalCount = 0;
        totalEnclosures++;
    }

    Enclosure(int id, string t) {
        enclosureID = id;
        type = t;
        animalCount = 0;
        totalEnclosures++;
    }

    void addAnimal(Animal *a) {
        if (animalCount<10){
            animals[animalCount++]=a;
        }
    }

    void listAnimals() {
        cout<<"Enclosure "<<enclosureID<<" (" << type << ") has:"<<endl;
        for (int i=0; i<animalCount; i++){
            cout<<" - "<<animals[i]->name<<endl;
        }
    }
};

int Enclosure::totalEnclosures=0;

// ------------------ Staff Base Class ---------------------
class Staff{
public: 
    string name;
    int staffID;

    Staff(string n,int id){
        name = n;
        staffID = id;
    }

    // Polymorphism and Abstraction 
    virtual void performDuty(){  
        cout << name << " is doing general duty." << endl;
    }

    // Make destructor virtual to allow proper deletion of derived classes
    virtual ~Staff(){}
};

// ------------------- Derived Staff Roles ---------------------
class Zookeeper:public Staff{
public:
    Zookeeper(string n,int id):Staff(n, id){}

    void performDuty()override {
        cout<<name <<" (Zookeeper) is feeding the animals."<<endl;
    }
};

class Veterinarian:public Staff{
public:
    Veterinarian(string n, int id):Staff(n, id){}

    void performDuty() override{
        cout<<name<<" (Veterinarian) is checking the health of the animals."<<endl;
    }
};

// --------------------- Zoo Class ---------------------
class Zoo{
public:
    Animal* animals[20];
    int animalCount;

    Enclosure enclosures[10];
    int enclosureCount;

    Staff* staff[10];
    int staffCount;

    Zoo(){
        animalCount = 0;
        enclosureCount = 0;
        staffCount = 0;
    }

    void addAnimal(Animal* a){
        if (animalCount < 20){
            animals[animalCount++] = a;
        }
    }

    void addEnclosure(const Enclosure& e){
        if (enclosureCount < 10){
            enclosures[enclosureCount++]=e;
        }
    }

    void addStaff(Staff* s){
        if (staffCount < 10){
            staff[staffCount++]=s;
        }
    }

    void showAllAnimals(){
        for (int i = 0; i < animalCount; i++){
            animals[i]->makeSound(); // Polymorphism
            animals[i]->getDiet();   // Polymorphism
        }
    }

    void showStaffDuties(){
        for (int i = 0; i < staffCount; i++){
            staff[i]->performDuty(); // Polymorphism
        }
    }

    void showSummary(){
        cout<<"\nTotal Animals: "<< Animal::totalAnimals<<endl;
        cout<<"Total Enclosures: "<< Enclosure::totalEnclosures<<endl;
    }

    ~Zoo() {
        for (int i = 0; i < animalCount; i++){
            delete animals[i];
        }
        for (int i = 0; i < staffCount; i++){
            delete staff[i];
        }
    }
};

// -------------Main Function -----------------
int main() {
    Zoo myZoo;

    // Creating animals
    Animal* a1 = new Lion("Abdullah", 5);
    Animal* a2 = new Elephant("Askari", 10);
    Animal* a3 = new Parrot("Kabeer", 2);

    myZoo.addAnimal(a1);
    myZoo.addAnimal(a2);
    myZoo.addAnimal(a3);

    // Creating enclosures
    Enclosure e1(1, "Amazon");
    e1.addAnimal(a1);

    Enclosure e2(2, "Rainforest");
    e2.addAnimal(a2);
    e2.addAnimal(a3);

    myZoo.addEnclosure(e1);
    myZoo.addEnclosure(e2);

    // Creating staff
    Staff* s1 = new Zookeeper("Zain", 100);
    Staff* s2 = new Veterinarian("Musadiq", 200);

    myZoo.addStaff(s1);
    myZoo.addStaff(s2);

    // polymorphism
    cout << "\n--- Staff Duties ---" << endl;
    myZoo.showStaffDuties();

    cout << "\n--- Animal Sounds and Diets ---" << endl;
    myZoo.showAllAnimals();

    cout << "\n--- Zoo Summary ---" << endl;
    myZoo.showSummary();

    return 0;
}