#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> exclusivos(std::vector<int> queue) 
{
    std::vector<int> vip{};

    for (auto v : queue) {
        if (std::count(begin(vip), end(vip), v) == 0)
            vip.push_back(v);
    }

    return vip;
}

std::vector<int> diferentes(std::vector<int> queue) 
{
    std::vector<int> dif{};

    for (auto v : queue) {
        if (v < 0) {
            v *= -1;
        }
        //count retorna o numero de vezes que o numero aparece;
        if (std::count(begin(dif), end(dif), v) == 0)
            dif.push_back(v);

    }



    return dif;
}

std::vector<int> abandonados(std::vector<int> queue) 
{
    std::vector<int> abandoned{};

   for (auto v : queue) {
        if (std::count(begin(queue), end(queue), v) == 2)
        abandoned.push_back(v);
    }

    auto last = std::unique(abandoned.begin(),abandoned.end());

    return (std::vector<int>(abandoned.begin(),last));
    
}

int main()
{
    std::vector<int> vip{};
    std::vector<int> dif{};
    std::vector<int> abandoned{};
    std::vector<int> queue = {3 ,3 , -2, -2, 4, 4, -5};
    

    vip = exclusivos(queue);
    std::cout << "valores unicos: ";
    for (int i : vip) 
        std::cout << i << " ";
    
    std::cout << "\n";

    dif = diferentes(queue);
    std::cout << "valores diferentes: ";
    for(int i : dif)
        std::cout << i << " ";
    
    std::cout << "\n";

    abandoned = abandonados(queue);
    std::cout << "abandonados: ";
    for(int i : abandoned)
        std::cout << i << " ";
}
