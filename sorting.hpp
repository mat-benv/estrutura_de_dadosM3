#include <iostream>

enum SortingAlg{
    SHELL,
    MERGE,
    HEAP
};

struct Resultados{
    SortingAlg sa;
    int comparacoes;
    int movimentacoes;
};

template <typename T>
Resultados shell_sort(T v[], int n){
    Resultados shell{SHELL, 0, 0};

    T aux;
    int j;

    for (int gap = n / 2; gap > 0; gap /= 2) {

        for (int i = gap; i < n; i++) {
            
            aux = v[i];
            shell.movimentacoes++;
            j = i;

            while(true){
                if(j >= gap){
                    shell.comparacoes++;
                } else {
                    break;
                }
                if(v[j-gap] > aux){
                    v[j] = v[j - gap];
                    shell.movimentacoes++;
                    j -= gap;
                } else {
                    break;
                }
            }

            v[j] = aux;
            shell.movimentacoes++;
        }
    }

    return shell;
}

template <typename T>
void merging(T v[], int ini, int meio, int fim, T vAux[], Resultados &merge){
    bool mantem;
    int esq = ini;
    int dir = meio;
    for(int i = ini; i < fim; i++){
        mantem = false;
        if(esq < meio){
            if(dir >= fim){
                mantem = true;
            }
            else{ 
                merge.comparacoes++; // contando explicitamente comparações entre chaves
                if(v[esq] < v[dir]){ //tentando o minimo de comparações entre chaves
                    mantem = true;
                }
            }
        }
        if(mantem){
            vAux[i] = v[esq];
            esq++;
            merge.movimentacoes++;
        } else {
            vAux[i] = v[dir];
            dir++;
            merge.movimentacoes++;
        }
    }
    for(int i = ini; i < fim; i++){
        v[i] = vAux[i];
        merge.movimentacoes++;
    }
}

template <typename T>
void merge_sort(T v[], int ini, int fim, T vAux[], Resultados &merge){
    if((fim - ini) < 2) return;

    int meio = ((ini + fim)/2);
    merge_sort(v, ini, meio, vAux, merge);
    merge_sort(v, meio, fim, vAux, merge);
    merging(v, ini, meio, fim, vAux, merge);
}

template <typename T>
Resultados merge_sort(T v[], int n){
    Resultados merge{MERGE, 0, 0};
    T vAux[n];

    merge_sort(v, 0, n, vAux, merge);

    return merge;
}



template <typename T>
Resultados heap_sort(T v[], int n){
    Resultados heap{HEAP, 0, 0};

    int i = n/2;
    int pai, filho, aux;

    while(true){
        if(i > 0){
            i--;
            aux = v[i];
            heap.movimentacoes++;
        } else {
            n--;
            if(n <= 0) return heap;
            aux = v[n];
            heap.movimentacoes++;
            v[n] = v[0];
            heap.movimentacoes++;
        }
        pai = i;
        filho = i*2 + 1;
        while(filho < n){
            if( (filho+1) < n ){
                heap.comparacoes++;
                if(v[filho+1] > v[filho]){
                    filho++;                    
                }
            }
            heap.comparacoes++;
            if(v[filho] > aux){
                v[pai] = v[filho];
                pai = filho;
                filho = pai*2 +1;
                heap.movimentacoes++;
            } else {
                break;
            }
        }
        v[pai] = aux;
        heap.movimentacoes++;
    }

    return heap;
}

template <typename T>
void show(T v[], int n, Resultados r){
    for(int i = 0; i < n; i++){
        std::cout << v[i] << " ";
    }
    std::cout << std::endl << "Comparações: " << r.comparacoes << "\nMovimentações: " << r.movimentacoes << std::endl; 
}