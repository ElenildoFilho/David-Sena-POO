#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <memory>
#include <list>

class Grafite 
{
public:
    float calibre;
    std::string dureza;
    int tamanho;

    Grafite(float calibre = 0, std::string dureza = " ", int tamanho = 0) :
        calibre{calibre} , dureza{dureza} , tamanho{tamanho} {}

};

class lapiseira 
{
public:
    Grafite bico;
    float calibre;
    std::list<Grafite> tambor;

    lapiseira(float calibre = 0) :
    calibre{calibre}    {}

    friend std::ostream& operator<<(std::ostream& os, const lapiseira lap) {
        os << "nome: " << lap.bico.calibre << ", ";
        os << "nome: " << lap.bico.dureza << ", ";
        os << "nome: " << lap.bico.tamanho << ", ";
        return os;
    }
    

    void inserir(Grafite graf) {
        if (graf.calibre == this->calibre) {
            tambor.push_back(graf);
            std::cout << "grafite inserido no tambor\n";
        } else std::cout <<  "calibre incompativel\n";
    }

    void mostrar() {
        std::cout << "calibre:" << this->bico.calibre << "  ";
        std::cout << "dureza:" << this->bico.dureza << "  ";
        std::cout << "tamanho:" << this->bico.tamanho << "  \n";
    }

    void puxar() {
        if (this->bico.calibre == 0 ) {
            this->bico = this->tambor.front();
            this->tambor.pop_front();
            std::cout << "grafite puxado\n";
        } else std::cout << "bico ja possui um grafite\n";
        
    }

    void retirar() {
        if (this->bico.calibre != 0) {
            this->bico.calibre = 0;
            this->bico.dureza = " ";
            this->bico.tamanho = 0;
            std::cout << "o grafite foi retirado\n";
        }

    }

    void escrever() {

        if (this->bico.calibre == 0) {
            std::cout << "bico esta vazio\n";
            return;
        }

        if (this->bico.tamanho <= 10) {
            std::cout << "nao ha grafite para utilizar\n";
            return;
        }

        if (this->bico.dureza == "HB") {
            if (this->bico.tamanho - 1 >= 10) {
            this->bico.tamanho -= 1;
            std::cout << "folha escrita\n";
            return;
            } else std::cout << "acabou o grafite, folha incompleta\n";
        }

        if (this->bico.dureza == "2B") {
            if (this->bico.tamanho - 2 >= 10) {
            this->bico.tamanho -= 2;
            std::cout << "folha escrita\n";
            return;
            } else std::cout << "acabou o grafite, folha incompleta\n";
        }

        if (this->bico.dureza == "4B") {
            if (this->bico.tamanho - 4 >= 10) {
            this->bico.tamanho -= 4;
            std::cout << "folha escrita\n";
            return;
            } else std::cout << "acabou o grafite, folha incompleta\n";
        }

        if (this->bico.dureza == "6B") {
            if (this->bico.tamanho - 6 >= 10) {
            this->bico.tamanho -= 6;
            std::cout << "folha escrita\n";
            return;
            } else std::cout << "acabou o grafite, folha incompleta\n";

        }
    
    }


};


int main() 
{
    lapiseira l{3};

    Grafite ZB (3,"6B",16);
    Grafite HB (3,"HB",20);

    l.escrever();
    l.inserir(ZB);
    l.mostrar();
    l.inserir(HB);
    l.puxar();
    l.mostrar();
    l.retirar();
    l.puxar();
    l.mostrar();
    l.escrever();
    



}
