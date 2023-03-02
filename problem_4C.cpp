#include <iostream>
#include <chrono>
#include <limits>
#include <random>
using namespace std;
// �������� �������������� ������� ������� size, � ������� ����� ��������� �����
const int n = 1000000;
int arr[1000000];
int arr_prob[1000000]{0};

bool search(int arr[], int size, int key){
    for (int i = 0; i < size; i++){
        if (arr[i] == key){
            return true;
            arr_prob[i] += 1;
            if (i != 0 && arr_prob[i-1] < arr_prob[i])
                {
                    int tmp1 = arr[i-1];
                    arr[i-1] == arr[i]; arr[i] = tmp1;
                    int tmp2 = arr[i-1];
                    arr_prob[i-1] == arr_prob[i]; arr_prob[i] = tmp2;
                }
            break;
        }
    }
    return false;
}



//���������� �������, ������ � ��� ������
void test(unsigned repeat, int arr[], int size){
    std::default_random_engine rnd(1001);
    //std::uniform_int_distribution<unsigned> dstr(0, 2 * size); //���� ������ ������
    std::binomial_distribution<unsigned> dstr2(2 * size, 0.75); //���� ������ ������
    for (unsigned counter = repeat; counter != 0; --counter){
        auto key = dstr2(rnd);
        //auto key = dstr(rnd);
        auto res = search(arr, size, key);
    }

}


int main(){
    for (int size = 100; size <= 1000000; size = size * 1.5)
    {
        std::default_random_engine rnd(1000);
        std::uniform_int_distribution<unsigned> dstr(0, size); // ��������� ���������� �������
        for (unsigned i = 0; i != n; i++){arr[i] = dstr(rnd);}
        //������ ������� �������
        auto begin = std::chrono::steady_clock::now();
        test(10000, arr, size);
        auto end = std::chrono::steady_clock::now();
        auto time_span = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
        cout << time_span.count() << ',';
    }
    return 0;
}
