#include <iostream>
#include <vector>

void procurar_menor(std::vector<int> queue, int value)
{
    int menor = 100;
    for (int i = 0; i < 6; i++) {
        if (queue[ i ] < menor) {
        menor = queue[ i ];
        }
    }
    std::cout << "-----------------------" << std::endl;
    std::cout << "menor numero da fila: " << menor << std::endl;
}

void procurar_maior(std::vector<int> queue, int value)
{
    int maior = 0;
    for (int i = 0; i < 6; i++) {
        if (queue[ i ] > maior) {
        maior = queue[ i ];
        }
    }
    std::cout << "-----------------------" << std::endl;
    std::cout << "maior numero da fila: " << maior << std::endl;
}

void procurar_apos(std::vector<int> queue, int value)
{
    int init_pos = 1;
    int count = 0;
    int menor  = 99;
    for (init_pos; init_pos < 6; init_pos++) {
        if (queue[ init_pos ] < menor) {
            menor = init_pos;
            count++;
        } 
        
    } 
    std::cout << "-----------------------" << std::endl;
    std::cout << "iniciando a busca na pos 1 o numero aparece na pos " << count << " " <<std::endl;
    std::cout << "-----------------------" << std::endl;
}

void procurar_melhor_se(std::vector<int> queue, int value)
{
    int menor = 100;
    for (int i = 0; i < 6; i++) {
        if (queue[ i ] < menor && queue[ i ] > 0) {
        menor = queue[ i ];
        }
    }
    std::cout << "homem mais calmo da fila: " << menor << std::endl;
    std::cout << "-----------------------" << std::endl;
}

int main(int argc, char** argv)
{
    int value = 25;
    std::vector<int> queue = {5 ,75 , -60, -12, 24, 2};
    procurar_menor(queue,value);
    procurar_maior(queue,value);
    procurar_apos(queue,value);
    procurar_melhor_se(queue,value);
}