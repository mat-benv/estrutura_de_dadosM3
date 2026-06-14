#include "sorting.hpp"
#include "analise.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main(){

    int n = 10000;
    
    int list0[10000], list1[10000], list2[10000], list3[10000];

    string arquivo = "./dados.txt";

    int f;

    char opt;

    cout << "Digite o nome do arquivo: ";
    getline(cin, arquivo);
        
    ofstream csv("tabela.csv");
    csv << "Quantidade de dados,C(n),,,M(n),," << endl
        << ",shell sort,merge sort,heap sort,shell sort,merge sort,heap sort" << endl;
    csv.close();

    do{
        do{
            cout << "Digite o número de dados (1 a 10.000):\n";
            cin >> n;
        }while(n < 1 || n > 10000);
        do{
            cout << "1 = Crescente\n2 = Decrescente\n3 = Aleatório\n";
            cin >> f;
            f--;
        }while(f < 0 || f > 2);

        get_data(list0, n, arquivo, f);
    
        copy_list(list0, list1, n);
        Resultados shell = shell_sort(list1, n);

        copy_list(list0, list2, n);
        Resultados merge = merge_sort(list2, n);

        copy_list(list0, list3, n);
        Resultados heap = heap_sort(list3, n);

        csv.open("tabela.csv", ios::app);

        csv << n << ',';
        int c = find_100_percent(shell.comparacoes, merge.comparacoes, heap.comparacoes);
        csv << setprecision(4) << ((double) shell.comparacoes / c)*100 << ','
            << setprecision(4) << ((double) merge.comparacoes / c)*100 << ','
            << setprecision(4) << ((double) heap.comparacoes / c)*100 << ',';
        c = find_100_percent(shell.movimentacoes, merge.movimentacoes, heap.movimentacoes);
        csv << setprecision(4) << ((double) shell.movimentacoes / c)*100 << ','
            << setprecision(4) << ((double) merge.movimentacoes / c)*100 << ','
            << setprecision(4) << ((double) heap.movimentacoes / c)*100 << endl;
        csv.close();

        cin.get();

        do{
            cout << "Continuar? (S/N)";
            cin.get(opt);
        }while(opt != 'S' && opt != 'N');
    }while(opt != 'N');

    return 0;
}