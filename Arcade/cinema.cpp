#include <iostream>
#include <list>
#include <vector>
#include <memory>
#include <sstream>

class Client { 
public:
int id;
std::string fone;

Client(int id = 0, std::string fone = " ") :
    id{id} , fone{fone} {

    }

};


class Sala {
public:
    std::vector<std::shared_ptr<Client >> cadeira{5};

    friend std::ostream& operator<<(std::ostream& os, const Client c) {
        os << "nome: " << c.id << ", ";
        os << "fone: " << c.fone << ", ";
        return os;
    }

    Sala() {

    }

    Sala(int espacos) : cadeira(espacos, nullptr) {};

    void show() {
    for (int i = 0; i < cadeira.size(); i++) {
        if (this->cadeira[i] == nullptr){
            std::cout << "- ,";
        }   else std::cout << cadeira[i]->id << " ,";
    }

    }

    bool check(std::shared_ptr<Client> c) {
        for (int i = 0; i < cadeira.size(); i++) {
            if (c == cadeira[i]){
                return true;
            }
        }
        return false;
    }


    void reservar(std::shared_ptr<Client> c, int i) {

        if (this->cadeira[i] == nullptr) {
            if (this->check(c) == true){
                std::cout << "falha";
                return;
            }

            this->cadeira[i] = c;
            std::cout << "reserva feita" << "\n";
            
    } else std::cout << "lugar ja reservado\n";
    }

    void remover(int i) {
        
        this->cadeira[i] = nullptr;

    }

};

int main() {

Sala sala;


sala.reservar(std::make_shared<Client>(6, "888"), 2);

sala.reservar(std::make_shared<Client>(3, "888"), 2);

//sala.remover(2);

sala.show();

   
}
