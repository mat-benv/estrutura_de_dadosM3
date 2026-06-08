#include "sorting.hpp"
#include <iostream>

int main(){

    int n = 10;

    int vs[10]{4, 8, 1, 9, 0, 3, 7, 5, 6, 2};
    Resultados shell = shell_sort(vs, n);
    show(vs, n, shell);

    int vm[10]{4, 8, 1, 9, 0, 3, 7, 5, 6, 2};
    Resultados merge = merge_sort(vm, n);
    show(vm, n, merge);

    int vh[10]{4, 8, 1, 9, 0, 3, 7, 5, 6, 2};
    Resultados heap = heap_sort(vh, n);
    show(vh, n, heap);

    return 0;
}