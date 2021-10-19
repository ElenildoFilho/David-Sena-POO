#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>


std::vector<int> inverter_com_copia(std::vector<int> queue)
{
    std::vector<int> copy(queue.size());
    
    for (int i = queue.size(); i > 0; i--) {
        copy[ i ]  = queue[ i-1 ];
    }
    
return copy;
}

void revert_inplace(std::vector<int> queue)
{
    
    for (int i = queue.size(); i > -1; i--) {
        queue[ i ]  = queue[ i ];
    }
    
    std::cout << "copia da fila invertida localmente: ";
    for (int i = queue.size(); i >= 1; i--) {
    std::cout << queue[ i-1 ] << " ";
    }
    
}

int sortear(std::vector<int> queue)
{
    std::srand(std::time(0));
    int chosen = 0;

    chosen = rand() % queue.size();
    
    return chosen;
}

void embaralhar(std::vector<int> queue)
{
    for (int i = 0; i <queue.size(); i++) {
        queue[ i ] = queue [ rand() % queue.size() ];
    }
    std::cout << "\n";
    std::cout << "-----------------------" << std::endl;
    std::cout << "fila embaralhada: ";
    for (int i = 0; i <queue.size(); i++) {
    std::cout << queue[ i ] << " ";
    }
}

void ordenar(std::vector<int> queue)
{
    int B = -101;
    int L = 101;
    int count = 0;

    std::sort(queue.begin(), queue.end());

    std::cout << "\n";
    std::cout << "-----------------------" << std::endl;
    std::cout << "vetor original ordenado: ";
    for (int i = 0; i < queue.size(); i++) {

        std::cout << queue[ i ] << " ";

    }



}

int main()
{
    
    std::vector<int> queue = {20, 53, -6, 87, -52, 35, 26};
    std::vector<int> invert_copy(queue.size());
    int chosen = 0;
    

    invert_copy = inverter_com_copia(queue);
    std::cout << "copia da fila invertida: ";
    for (int i = invert_copy.size(); i > 0; i--)
    {
        std::cout << invert_copy[ i ] << " ";
    }

    std::cout << "\n";
    std::cout << "-----------------------" << std::endl;

    revert_inplace(queue);

    
    std::cout << "\n";
    std::cout << "-----------------------" << std::endl;
    std::cout << "valor sorteado: " << sortear(queue);
   
    embaralhar(queue);
    
    ordenar(queue);
}