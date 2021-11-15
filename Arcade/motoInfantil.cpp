#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

struct Person {
    std::string name;
    int age;

    Person (int age = 0,std::string name = " ") :
        age{age},name{name} { 
    }

};

struct motoca {
    int power;
    int time;
    Person* person;  

    motoca (int power = 1 ,int time = 0 , Person* person = nullptr) :
        power{power}, time{time}, person{person} {

    }

    friend std::ostream& operator<<(std::ostream& os, const motoca& moto) {
        os << "power: " << moto.power << ", ";
        os << "time: " << moto.time << ", ";
        os << "age: " << moto.person->age << ", ";
        os << "name: " << moto.person->name << " ";
        return os;
    }

    void subir_pessoa(Person p) {
        if (this->person == nullptr) {
        
        this->person = &p;
        return;
        }else std::cout << "moto ocupada ";
    }

    void potencia() {
        if (this->person != nullptr) {

        std::cout << "escolha a potencia da motoca\n";
        std::cin >> this->power;
        std::cout << "potencia escolhida\n";
        }
    }

    void buyTime() {

        int tempo;

        if (this->person != nullptr) {
        std::cout << "quanto tempo quer?\n";
        std::cin >> tempo;
        std::cout << "tempo comprado\n";
        }
        this->time = tempo;
    }

    void drive (int passeio) {

        if (this->person->age > 10) {
            std::cout << "nao pode dirigir\n ";
            return;
        }   

        if (this->time - passeio < 0) {
            std::cout << "voce dirigiu por: " << this->time << " minutos e seu tempo acabou\n";
        }   else std::cout << "voce dirigiu por " << passeio << " minutos\n";

        if (this->time > passeio) {
        std::cout << "voce dirigiu " << passeio << " minutos, e agora tem " << this->time - passeio << " minutos sobrando\n";
        this->time -= passeio;
        return;
        } 
        
        if (this->time == 0) {
            std::cout << "voce nao tem tempo\n";
            return;
        }

    }

    void honk(int &power) {

        if (this->person == nullptr) {
            std::cout << "ninguem para buzinar\n";
            return;
        }

        std::cout << "P";
        for (int i = 0;i < power; i++) {
            std::cout << "e";
        }
        std::cout << "m\n";
        
    
    }

    void get_out() {
        if (this->person != nullptr) {
            this->person = nullptr;
            std::cout << "descendo da moto...\n";
        }   else std::cout << "motoca ja vazia\n";
    }
};



int main() {
    motoca moto;
    
    Person p{20, "ana"};
    Person p2{6, "tulio"};
    
    moto.subir_pessoa(p2);
    moto.potencia();
    moto.honk(moto.power);
    moto.buyTime();
    moto.drive(10);
    moto.get_out();

    moto.subir_pessoa(p);
    moto.potencia();
    moto.honk(moto.power);
    moto.buyTime();
    moto.drive(5);
    moto.get_out();

    
    
}
