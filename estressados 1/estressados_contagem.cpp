#include <iostream>
#include <vector>

void calcular_stress_medio(std::vector<int> queue)
{
    float aux = 0;
    for (int i = 0; i < 6; i++) {
        aux += queue[ i ];
    }
    std::cout << "-----------------------" << std::endl;
    std::cout << "stress medio da fila: " << aux/6 << std::endl;
    std::cout << "-----------------------" << std::endl;
}

void mais_homens_ou_mulheres(std::vector<int> queue)
{
    int men = 0;
    int women = 0;

    for (int i = 0; i < 6; i++) {
        if (queue[ i ] > 0) {
            men++;
        }   else women++;
    }

    if (men > women) {
        std::cout << "existem mais homens na fila: " << men << std::endl;
        std::cout << "-----------------------" << std::endl;
    }   
        
    if (women > men){
        std::cout << "existem mais mulheres na fila: " << women << std::endl;
        std::cout << "-----------------------" << std::endl;
    } 

    if (men == women) {
        std::cout << "empate" << std::endl;
        std::cout << "-----------------------" << std::endl;
    }

}

void qual_metade_eh_mais_estressada(std::vector<int> queue)
{
    int fh = 0;
    int sh = 0;
    
    for (int i = 0; i < 6; i++) {
        if (i < 3) {
            fh += queue[ i ];
        } else sh += queue[ i ];
    }
    if (fh > sh) {
        std::cout << "a primeira metade esta mais extressada" << std::endl;
        std::cout << "-----------------------" << std::endl;
    }   else std::cout << "a segunda metade esta mais extressada" << std::endl;
            std::cout << "-----------------------" << std::endl;
}

void homens_sao_mais_estressados_que_mulheres(std::vector<int> queue)
{
   int ms = 0;
   int ws = 0;

   for (int i = 0; i < 6; i++) {
       if (queue[ i ] > 0) {
          ms += queue[ i ];
       }    else ws += queue[ i ];
    }

    if (ms > ws * -1) {
        std::cout << "homens estao mais extressados: " << std::endl;
    }   else std::cout << "mulheres estao mais extressadas: " << std::endl;
}

int main()
{
    std::vector<int> queue = {50, -25, -32, 10, 80, 5};
    calcular_stress_medio(queue);
    mais_homens_ou_mulheres(queue);
    qual_metade_eh_mais_estressada(queue);
    homens_sao_mais_estressados_que_mulheres(queue);
}