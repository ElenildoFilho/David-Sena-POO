#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> convert_negatives(std::vector<int> queue)
{
    for (int i = 0; i <queue.size(); i++) {
        if (queue[ i ] < 0) {
            queue.at(i) = queue[ i ] * -1;
        }
    }

    return queue;

}

int acalmado(std::vector<int> queue, int pos) 
{
    for (int i = 0; i < queue.size(); i++) {
        if (queue[ pos-1] <= 10 || queue[ pos+1 ] <= 10) {
            return pos;
        }
    }
        return 0;
    


}

int detectar_briga(std::vector<int> queue, int pos) 
{
    int size = queue.size() + 1;

    queue.resize(size);

    for (int i = 1; i < queue.size()  ; i++) {
        if (queue.at(pos-1) >= 30 && queue.at(pos+1) >= 30) {
            return 1;
        }    
    }
    
    return 500;

}

int briga(std::vector<int> queue)
{
    queue = convert_negatives(queue);

    int riot = 0;

    for(int i = 1; i < queue.size() - 1; i++) {
        if (queue[ i ] >= 50) 
            if (detectar_briga(queue,i) == 1)
                riot++;
    }

    return riot;
}

std::vector<int> apaziguado(std::vector<int> queue)
{
    std::vector<int> calmed_down{};

    for (int i = 0; i < queue.size(); i++) {
        if (queue[ i ] >= 80)
            calmed_down.push_back(acalmado(queue,i));
    }

    return calmed_down;

}

int main() 
{
    int figth = 0;
    std::vector<int> queue{40 , 10, 80, 80, 10};
    std::vector<int> calmed_down{};

    figth = briga(queue);
    std::cout << "numero de brigas na fila: " << figth;

    std::cout << "\n";
    
    calmed_down = apaziguado(queue);
    std::cout << "posicao dos acalmados: ";
    for (int v : calmed_down)
        std::cout << v << " ";
}