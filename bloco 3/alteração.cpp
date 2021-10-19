#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> convert_negatives(std::vector<int> queue)
{
    for (int i = 0; i <queue.size(); i++) {
        if (queue[ i ] < 0) {
            queue[i] = queue[ i ] * -1;
        }
    }

    return queue;

}

std::vector<int> remove(std::vector<int> queue) 
{
    int x {};

    std::cout << "digite quem deve sair da fila: ";
    std::cin >> x;

    while (x > queue.size()) {
        std::cout << "numero invalido" << "\n ";
        std::cout << "digite quem deve sair da fila: ";
        std::cin >> x;
    }   

    for (int i = 0; i < queue.size(); i++) {
        if (x == i) {
            queue.erase(queue.begin()+x);
        }
    }

    for (int i : queue) 
        std::cout << i << " ";
    
    std::cout << "\n";

    return queue;
}

std::vector<int> insert(std::vector<int> queue)
{
    int x{};
    int y{};

    std::cout << "\n";
    std::cout << "digite o numero que deseja adicionar a fila: ";
    std::cin >> x;

    std::cout << "digite a posicao que deseja inserir esse numero: ";
    std::cin >> y;

    while (x > 100 || x < -100) {
        std::cout << "digite um valor valido para x." << std::endl;
        std::cout << "digite o numero que deseja adicionar a fila: ";
        std::cin >> x;
        std::cout << "\n";
    }

    while (y > queue.size()) {
        std::cout << "\n";
        std::cout << "posicao invalida" << std::endl;
        std::cout << "digite uma posicao valida para y: ";
        std::cin >> y;
        
    }

    queue.insert(queue.begin()+y,x);

    for (int v : queue) {
        std::cout << v << " ";
    }

    return queue;
}

void dance(std::vector<int> queue)
{

    queue = convert_negatives(queue);
    int j = 0;
    int cont = 0;

    while(cont < 6) {
        for (int i = 0; i < queue.size(); i++) {
            for (j = 0; j < i; j++) {
                if (queue[i] == queue[j]) {
                    queue.erase(queue.begin()+i);
                    queue[j] = 0;
                    //queue.erase();
                }
            }         
        }
        cont++;
    }

    std::cout << "\n";
    std::cout << "pessoas sozinhas: " << queue.size();
    for (int v : queue) 
        if (v > 0)
        std::cout << "nivel de stress: " << v << " ";
}

int main() 
{
    std::vector<int>queue{10 ,-65 ,-65, 10 ,21, -21,2};

    queue = remove(queue);

    queue = insert(queue);

    dance(queue);
    
}

