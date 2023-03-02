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
            for (int j = 0; j < size; j++){
                if (arr[i] + arr[j] == key){return true; break;}
            }
        }
    return false;
}


//Количество поисков, массив и его размер
void test(unsigned repeat, int arr[], int size){
    std::default_random_engine rnd(1001);
    std::uniform_int_distribution<unsigned> dstr(0, 4 * size); //учтён худший случай
    for (unsigned counter = repeat; counter != 0; --counter){
        auto key = dstr(rnd);
        auto res = full_search(arr, size, key);
    }

}


int main(){
    for (int size = 100; size <= 1000000; size = size * 1.5)
    {
        std::default_random_engine rnd(1000);
        std::uniform_int_distribution<unsigned> dstr(0, size); // случайное заполнение массива
        for (unsigned i = 0; i != n; i++){arr[i] = dstr(rnd);}
        //Начало отсчёта времени
        auto begin = std::chrono::steady_clock::now();
        test(1000, arr, size);
        auto end = std::chrono::steady_clock::now();
        auto time_span = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
        cout << time_span.count() << ',';
    }
    return 0;
}
