#include <vector>
#include <thread>
#include <mutex>
#include <iostream>

class MergeSort {
public:
    void Merge(std::vector<int>& arr, int low, int mid, int high) {
        int left_part = mid - low + 1;
        int right_part = high - mid;

        std::vector<int> left_arr(left_part), right_arr(right_part);

        for (int i = 0; i < left_part; ++i)
            left_arr[i] = arr[low + i];
        for (int j = 0; j < right_part; ++j)
            right_arr[j] = arr[mid + 1 + j];

        int i = 0, j = 0, k = low;

        while (i < left_part && j < right_part) {
            if (left_arr[i] <= right_arr[j]) {
                arr[k] = left_arr[i];
                i++;
            }
            else {
                arr[k] = right_arr[j];
                j++;
            }
            k++;
        }

        while (i < left_part) {
            arr[k] = left_arr[i];
            i++;
            k++;
        }

        while (j < right_part) {
            arr[k] = right_arr[j];
            j++;
            k++;
        }
    }

    void Sort(std::vector<int>& arr, int low, int high) {
        if (low < high) {
            int mid = low + (high - low) / 2;
            Sort(arr, low, mid);
            Sort(arr, mid + 1, high);
            Merge(arr, low, mid, high);
        }
    }
};

int main() {

    setlocale(LC_ALL, "RU");
    std::vector<int> arr(10);

    std::vector<int> input_arr(10);

    std::cout << "Введите 10 числел:\n";
    for (int i = 0; i < 10; i++) {
        std::cin >> input_arr[i];
    }

    MergeSort merge_sort_instance;
    merge_sort_instance.Sort(input_arr, 0, input_arr.size() - 1);

    std::cout << "Отсортированный массив:\n";
    for (int num : input_arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
