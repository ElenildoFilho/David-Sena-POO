#include <iostream>
#include <vector>

bool existe(std::vector<int> num, int value)
{
    
    for (int i = 0; i <= 4; i++) {
        if (num[ i ] == value) {
            return true;
        }  
    } return false;
}

void contar(std::vector<int> num, int value) 
{
    int count = 0;
    for (int i = 0; i <= 4; i++) {
        if (num[ i ] == value) {
            count++;
        } 
    } 
    std::cout << "-----------------------" << std::endl;
    std::cout << "o numero aparece " << count << " vezes na fila" <<std::endl;
    std::cout << "-----------------------" << std::endl;
}

void procurar_valor(std::vector<int> num, int value)
{
    int pos = 0;
    for (int i = 0; i <= 4; i++) {
        if (num[ i ] == value) {
            pos = i;
        } 
    } 
    std::cout << "-----------------------" << std::endl;
    std::cout << "o numero aparece na " << pos << " posicao" <<std::endl;
    std::cout << "-----------------------" << std::endl;
}

void procurar_valor_apos(std::vector<int> num, int value)
{
    int pos = 0;
    int init_pos = 1;

    for (init_pos; init_pos <= 4; init_pos++) {
        if (num[ init_pos ] == value) {
            pos = init_pos;
        } 
    } 
    std::cout << "-----------------------" << std::endl;
    std::cout << "iniciando a busca na pos 1 o numero aparece na pos " << pos << " " <<std::endl;
    std::cout << "-----------------------" << std::endl;
}

int main(int argc ,char** argv)
{
    int value = -90;
    std::vector<int> num = {5, 50, -90, 35};
    bool c = existe(num,value); 
    contar(num,value);
    procurar_valor(num,value);
    procurar_valor_apos(num,value);

        if (c == 1) {    
            std::cout << "-----------------------" << std::endl;
            std::cout << "o numero existe na fila" << std::endl; 
            std::cout << "-----------------------" << std::endl;
        } 
        if (c == 0) {
            std::cout << "-----------------------" << std::endl;
            std::cout << "o numero nao existe na fila" << std::endl; 
            std::cout << "-----------------------" << std::endl;
        }

return 0;
}