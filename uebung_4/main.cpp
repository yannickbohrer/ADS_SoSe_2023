#include <iostream>
#include <vector>
#include <limits>
#include <cmath>
using namespace std;

int INT_MAX = std::numeric_limits<int>::max();

std::vector<int> nums = { 19, 85, 27, 22, 83, 95, 73, 28, 53, 20 };

void print(std::vector<int> vec) {
    std::cout << "{ ";
    for (const int item : vec)
        std::cout << item << (item != vec.back() ? ", " : " }");
    std::cout << std::endl;
}

std::vector<int> selection_sort(std::vector<int> vec) {
    for (int selection = 0; selection < (int)vec.size(); selection++) {
        int index_minimum = selection;
        int minimum = vec[selection];
        for (int comparison = selection + 1; comparison < (int)vec.size(); comparison++) {
            if (vec[comparison] < minimum) {
                index_minimum = comparison;
                minimum = vec[comparison];
            }
        }
        std::swap(vec[index_minimum], vec[selection]);
        print(vec);
    }
    return vec;
}

std::vector<int> insertion_sort(std::vector<int> vec) {
    for (int value = 1; value < (int)vec.size(); value++) {
        int iterator = value;
        while(iterator != 0) {
            if (vec[iterator] < vec[iterator - 1])
                std::swap(vec[iterator], vec[iterator - 1]);
            else if (vec[iterator] >= vec[iterator - 1])
                break;
            iterator--;
        }
        print(vec);
    }
    return vec;
}

std::vector<int> bubble_sort(std::vector<int> vec) {
    for (int iteration = 1; iteration < (int)vec.size(); iteration++) {
        for (int index = 0; index < (int)vec.size() - 1; index++) {
            if (vec[index] > vec[index + 1])
                std::swap(vec[index], vec[index + 1]);
        }
        print(vec);
    }

    return vec;
}

//Aufgabe 2

std::vector<int> nums_shell = { 16, 45, 33, 98, 14, 19, 8, 11, 49, 97 };

std::vector<int> shell_sort(std::vector<int> vec) {
    int N = (int)vec.size();

    for(int gap = N/2; gap > 0; (int)((gap /= 2) - 1)){
        for(int index = gap; index < N; index++){
            int val = vec[index];
            int index_val = index;
            for(; index_val >= gap && val < vec[index_val - gap]; index_val -= gap){
                vec[index_val] = vec[index_val - gap];
            }
            vec[index_val] = val;
        }
        print(vec);
    }
    return vec;
}

//Aufgabe 3

std::vector<int> nums_adv = { 50, 45, 30, 42, 20, 98, 11, 22, 33, 60 };

int partition(std::vector<int>& vec, int p, int r) {
    int x = vec[r];
    int i = p - 1;
    for (int index = p; index < r; index++) {
        if (vec[index] <= x) {
            i++;
            std::swap(vec[index], vec[i]);
        }
    }
    std::swap(vec[i + 1], vec[r]);
    return i + 1;
}

void quick_sort(std::vector<int>& vec, int p, int r) {
    print(vec);
    if (p < r) {
        int q = partition(vec, p, r);
        quick_sort(vec, p, q - 1);
        quick_sort(vec, q + 1, r);
    }
}

std::vector<int> quick_sort(std::vector<int> vec) {
    quick_sort(vec, 0, (int)vec.size() - 1);
    return vec;
}

//Merge Sort
void merge(std::vector<int>& vec, int left, int middle, int right) {
    int index_1, index_2, index_3;
    const int n1 = middle - left + 1;
    const int n2 = right - middle;

    std::vector<int> L(n1);
    std::vector<int> R(n2);
    for (index_1 = 0; index_1 < n1; index_1++) {
        L[index_1] = vec[left + index_1];
    }
    for (index_2 = 0; index_2 < n2; index_2++) {
        R[index_2] = vec[middle + 1 + index_2];
    }
    index_1 = 0;
    index_2 = 0;
    index_3 = left;
    while (index_1 < n1 && index_2 < n2) {
        if (L[index_1] <= R[index_2]) {
            vec[index_3] = L[index_1];
            index_1++;
        }
        else {
            vec[index_3] = R[index_2];
            index_2++;
        }
        index_3++;
    }
    while (index_1 < n1) {
        vec[index_3] = L[index_1];
        index_1++;
        index_3++;
    }
    while (index_2 < n2) {
        vec[index_3] = R[index_2];
        index_2++;
        index_3++;
    }
    print(L);
    print(R);
}

void merge_sort(std::vector<int>& vec, int left, int right) {
    if (left < right) {
        int middle = std::floor((left + right) / 2);
        merge_sort(vec, left, middle);
        merge_sort(vec, middle + 1, right);
        merge(vec, left, middle, right);
        print(vec);
    }
}

std::vector<int> merge_sort(std::vector<int>& vec) {
    merge_sort(vec, 0, (int)vec.size() - 1);
    return vec;
}

//HeapSort
inline int left_child_idx(int idx) { return 2 * idx + 1; }

void perc_down(std::vector<int>& vec, int i, int N) {
    int child;
    int tmp;
    for (tmp = vec[i]; left_child_idx(i) < N; i = child) {
        child = left_child_idx(i);
        if (child != N - 1 && vec[child] < vec[child + 1]) {
            child++;
        }
        if (tmp < vec[child]) {
            vec[i] = vec[child];
        }
        else {
            break;
        }
    }
    vec[i] = tmp;
}

std::vector<int> heap_sort(std::vector<int> vec) {
    for (int index = (int)vec.size() / 2; index >= 0; index--) {
        perc_down(vec, index, vec.size());
    }
    for (int index = (int)vec.size() - 1; index > 0; index--) {
        std::swap(vec[0], vec[index]);
        perc_down(vec, 0, index);
    }

    return vec;
}

int main() {

    // Selection Sort
    /*std::vector<int> res_selection = selection_sort(nums);
    std::cout << "Result: ";
    print(res_selection);*/

    // Insertion Sort
    /*std::vector<int> res_insertion = insertion_sort(nums);
    std::cout << "Result: ";
    print(res_insertion);*/


    // Bubble Sort
    /*std::vector<int> res_bubble = bubble_sort(nums);
    std::cout << "Result: ";
    print(res_bubble);*/

    // Aufgabe 2

    // Shell Sort
    /*std::vector<int> res_shell = shell_sort(nums_shell);
    std::cout << "Result: ";
    print(res_shell);*/

    //Aufgabe 3

    // Quick Sort
    /*std::vector<int> res_quick = quick_sort(nums_adv);
    std::cout << "Result: ";
    print(res_quick);*/

    // Merge Sort
    /*std::vector<int> res_merge = merge_sort(nums_adv);
    std::cout << "result: ";
    print(res_merge);*/

    // Heap Sort
    std::vector<int> res_heap = heap_sort(nums_adv);
    std::cout << "Result: ";
    print(res_heap);

    return 0;
}


