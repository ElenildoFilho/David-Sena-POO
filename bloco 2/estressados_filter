#include <iostream>
#include<vector>

std::vector<int> clonar(std::vector<int> queue)
{
    std::vector<int> copy = {};
    for (int i = 0; i < queue.size(); i++) {
        copy.push_back(queue[i]);
    }
    
return copy;
}

std::vector<int> retornar_homens(std::vector<int> queue)
{
    
    std::vector<int> homens(queue.size());
    for (int i = 0; i < queue.size(); i++) {
        if (queue[ i ] > 0) {
            homens[ i ] = queue [ i ];
        }
    }
    return homens;
}

std::vector<int> pegar_calmos(std::vector<int> queue)
{
    std::vector<int> calm{};
    for (int i = 0;i < queue.size(); i++) {
        if (queue [ i ] < 10 && queue[ i ]  > -10) {
            calm.push_back(queue[i]);
        }
    }
    return calm;
}

std::vector<int> pegar_mulheres_calmas(std::vector<int> queue)
{
    std::vector<int> women{};
    for (int i = 0; i < queue.size(); i++) {
        if (queue[ i ] < 0 && queue[ i ] > -10) {
            women.push_back(queue[i]); 
        }
    }
    return women;
}

int main()
{
    std::vector<int> queue = { 1 , -25, 80, -42, -9, -2};
    std::vector<int> homens(queue.size());
    std::vector<int> copy(queue.size());
    std::vector<int> most_calm(queue.size());
    std::vector<int> most_calm_women(queue.size());

    homens = retornar_homens(queue);
    std::cout << "homens da fila: ";
    for (int i=0;i<homens.size();i++) {
        if (homens[ i ] > 0) {
        std::cout << homens[i] << " ";
        }
    }
    std::cout << "\n";
    std::cout << "-----------------------" << std::endl;

    copy = clonar(queue);
    std::cout << "copia da fila: ";
    for (int i = 0; i < queue.size(); i++) {
        std::cout << copy[ i ] << " ";
    }
    std::cout << "\n";
    std::cout << "-----------------------" << std::endl;
    
    most_calm = pegar_calmos(queue);
    std::cout << "mais calmos da fila: ";
    for (int i = 0; i < most_calm.size(); i++) {
        if (most_calm[ i ] != 0) {
        std::cout << most_calm[ i ] << " ";
        }
    }
    std::cout << "\n";
    
    most_calm_women = pegar_mulheres_calmas(queue);
    std::cout << "-----------------------" << std::endl;
    std::cout << "mulheres mais calmas: ";
    for (int i = 0; i < most_calm_women.size(); i++) {
        if (most_calm_women[ i ] != 0) {
        std::cout << most_calm_women[ i ] << " ";
        }    
    }
}
