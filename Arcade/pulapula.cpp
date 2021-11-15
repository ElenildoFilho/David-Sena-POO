#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <memory>
#include <list>

class Crianca {
public:
std::string name;

Crianca(std::string name = " ") : 
    name{name} {

    }

};

class PulaPula{
    std::list<std::shared_ptr<Crianca>> fila;
    std::vector<std::shared_ptr<Crianca>> brinquedo;
    

public:



    PulaPula() {
    }

    //adiciona espaços vazios no brinquedo
    PulaPula(int espaços) : brinquedo(espaços, nullptr) {};

    //adiciona uma Crianca na fila
    void entrarFila(std::shared_ptr<Crianca> c) {
        this->fila.push_back(c);
    }

    void ChamarCrianca(int indice) {

        if (this->brinquedo[indice] == nullptr) {
            this->brinquedo[indice] = this->fila.front();
            this->fila.pop_front();
            std::cout << "Crianca entrou no pula pula\n";
            return;
        }

        if (this->brinquedo[indice] != nullptr) {
            std::cout << "brinquedo ocupado\n";
        }
        
    };

    void tirarCrianca(int indice) {

        if (this->brinquedo[indice] != nullptr) {
            this->fila.push_back(this->brinquedo[indice]);
            this->brinquedo[indice] = nullptr;
            std::cout << "o pula pula agora esta vazio\n";
            return;
        }

        if (this->brinquedo[indice] == nullptr) {
            std::cout << "brinquedo ja vazio\n";
        }
    }

};


int main() {

    PulaPula pula(1);

    pula.entrarFila(std::make_shared<Crianca>("tulio"));
    pula.entrarFila(std::make_shared<Crianca>("julio"));
    pula.entrarFila(std::make_shared<Crianca>("ana"));

    pula.ChamarCrianca(0);
    pula.ChamarCrianca(0);

    pula.tirarCrianca(0);

    pula.ChamarCrianca(0);
    

}
