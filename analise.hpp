#include <fstream>
#include <vector>
#include <random>
using namespace std;

enum {
    ASCENDING,
    DESCENDING,
    RANDOM,
};

void get_data(int list[], int n, std::string filename, int mode = ASCENDING){

    ifstream data_file(filename);
    string line;
    vector<int> data;
    if(data_file.is_open()){
        while(getline(data_file, line)){
            data.push_back(stoi(line));
        }
        data_file.close();

        switch (mode){
            case ASCENDING:
                for(int i = 0; i < n; i++){
                    list[i] = data.at(i);
                }
                break;
            
            case DESCENDING:
                for(int i = 0; i < n; i++){
                    list[i] = data.at(n-i-1);
                }
                break;
            case RANDOM:
                srand(time(NULL));
                for(int i = 0; i < n; i++){
                    int r = rand() % (10000 - i);
                    list[i] = data.at(r);
                    data.erase(data.begin() + r);
                }
                break;
        }
    } else {
        cout << "Erro ao abrir o arquivo.\n";
        exit(0);
    }
}

void copy_list(int list1[], int list2[], int n){
    for(int i = 0; i < n; i++){
        list1[i] = list2[i];
    }
}

int find_100_percent(int a, int b, int c){
    int n = a;
    if(b > n) n = b;
    if(c > n) n = c;
    return n;
}