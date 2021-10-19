#include <iostream>
#include <vector>
#include <algorithm>
#include <vector>

std::vector<int> convert_negatives(std::vector<int> queue)
{
    for (int i = 0; i <queue.size(); i++) {
        if (queue[ i ] < 0) {
            queue.at(i) = queue[ i ] * -1;
        }
    }

    return queue;

}

std::vector<int> sozinhos(std::vector<int> queue) 
{
    queue = convert_negatives(queue);

    std::vector<int> alone{};
    for (auto v : queue) {
        if (std::count(begin(queue), end(queue), v) == 1)
            alone.push_back(v);
    }

    return alone;
}

int contagem_auxiliar(std::vector<int> queue, int v)
{
    int count = 0;

    queue = convert_negatives(queue);


    for (int i = 0; i < queue.size(); i++) {
        if (v == queue[ i ])
            count++;
    }

    return count;

}

void mais_ocorrencias(std::vector<int> queue) 
{
    std::vector<int> rn{};
    int menor = -1;

    for (int v : queue) {
        rn.push_back(contagem_auxiliar(queue,v));
    }

    for (int i = 0; i < rn.size(); i++) {
        if (rn[ i ] > menor) 
            menor = rn[ i ]; 

    }

    std::cout << "pessoas com o  mesmo stress :" << menor;
    std::cout << "\n";
    
    


}

void mais_recorrente(std::vector<int> queue)
{
    std::vector<int> rn{};
    int menor = -1;

    for (int i = 0; i <queue.size(); i++) {
        if (queue[ i ] < 0) {
            queue.at(i) = queue[ i ] * -1;
        }
    }

    for (int v : queue) {
      if (contagem_auxiliar(queue,v) > menor)
        menor = v;
    }   

        std::cout << "stress mais recorrente: ";
        std::cout << menor << " ";
        std::cout << "\n";
}


int main()
{
    std::vector<int> queue{2, 2, -5, -3, 3, -3};
    std::vector<int> alone{};

    alone = sozinhos(queue);
    std::cout << "stress unico na fila: ";

    for (int i : alone)
        std::cout << i << " ";

        std::cout << "\n";

    mais_ocorrencias(queue);

    mais_recorrente(queue);




}