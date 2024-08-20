#include <iostream>
#include <vector>
using namespace std;

int main() {
    std::vector<int> numbers;

    int count;
    std::cout << "How many numbers do you want to enter? ";
    std::cin >> count;

    for (int i = 0; i < count; i++) {
        int number;
        std::cout << "Enter nr[" << (i + 1) << "]: ";
        std::cin >> number;
        numbers.push_back(number);
    }

    std::cout << "You entered: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
