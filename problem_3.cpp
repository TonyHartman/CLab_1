#include <iostream>
#include <chrono>
#include <limits>
#include <random>
using namespace std;
// �������� �������������� ������� ������� size, � ������� ����� ��������� �����
const int n = 1000000;
int arr[1000000];

bool binary_search(int arr[], int size, int key){
    // ����� �������
    int l = 0;
    // ������ �������
    int r = size - 1;

    while (l <= r){
        if (arr[l] + arr[r] == key){
            return true;
        }
        if (arr[l] + arr[r] < key) l++;
        else r--;
    }
    return false;
}


//���������� �������, ������ � ��� ������
void test(unsigned repeat, int arr[], int size){
    std::default_random_engine rnd(1001);
    std::uniform_int_distribution<unsigned> dstr(0, 2 * size); //���� ������ ������
    for (unsigned counter = repeat; counter != 0; --counter){
        auto key = dstr(rnd);
        auto res = binary_search(arr, size, key);
    }

}


int main(){
    for (int size = 100; size <= 1000000; size = size * 1.5)
    {
        for (unsigned i = 0; i != n; i++){arr[i] = i;}
        //������ ������� �������
        auto begin = std::chrono::steady_clock::now();
        test(10000, arr, size);
        auto end = std::chrono::steady_clock::now();
        auto time_span = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
        cout << time_span.count() << ',';
    }
    return 0;
}
