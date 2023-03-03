#include <iostream>
#include <chrono>
#include <limits>
#include <random>
using namespace std;
// Создание упорядоченного массива размера size, в котором будет проходить поиск
const int n = 1000000;
int arr[1000000];



bool full_search(int arr[], int size, int key){
    for (int i = 0; i < size; i++){
        if (arr[i] == key){
            return true;
            break;
        }
    }
    return false;
}


bool binary_search(int arr[], int size, int key){
    // Левая граница
    int l = 0;
    // Правая граница
    int r = size - 1;
    int mid;

    while (l <= r){
        mid = (r + l)/2;
        if (arr[mid] == key){
            return true;
        }
        if (arr[mid] < key) l = mid + 1;
        else r = mid - 1;
    }
    return false;
}


//Количество поисков, массив и его размер
void test(unsigned repeat, int arr[], int size){
    int time = 0;
    std::default_random_engine rnd(1000);
    std::uniform_int_distribution<unsigned> dstr(0, 1.2*size);
    int keys [400001];
    for (int i = 1; i <= repeat; i++){keys[i] = dstr(rnd);}
    auto begin = std::chrono::steady_clock::now();
    for (unsigned counter = repeat; counter != 0; --counter){
        //auto key = keys[counter];
        auto key = size + 1; //худший случай
        //auto res = full_search(arr, size, key);
        auto res = binary_search(arr, size, key);
    }
    auto end = std::chrono::steady_clock::now();
    auto time_span = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    time += time_span.count();
    cout << time << ", ";
}


int main(){
    for (unsigned i = 0; i != n; i++){arr[i] = i;}
    for (int size = 100; size <= 1000000; size = size * 1.1)
    {
        test(400000, arr, size);
    }
    return 0;
}
