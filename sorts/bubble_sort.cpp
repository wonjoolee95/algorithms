#include <iostream>
#include <vector>
#include <random>
#include <unordered_set>


void bubble_sort(std::vector<int> &array) 
{
    for (int i=0; i<array.size()-1; i++) 
    {
        for (int j=0; j<array.size()-1; j++)
            if (array[j] > array[j+1])
            {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
    }
}

std::vector<int> create_random_array()
{
    std::unordered_set<int> repeated;
    std::vector<int> random_array;
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(1, 100);
    int random_number;
    while (repeated.size() <= 99)
    {
        random_number = distribution(generator);
        if (repeated.find(random_number) == repeated.end())
        {
            random_array.push_back(random_number);
            repeated.insert(random_number);
        }
    }
    return random_array;
}

void printArray(std::vector<int> &array) 
{    
    for (int i=0; i < array.size(); ++i)
    {
        std::cout << array[i] << ' ';
    }
    std::cout << std::endl;
}

int main(int argc, const char * argv[]) 
{    
    std::vector<int> array = create_random_array();
    std::cout << "  Before sorting: " << std::endl;
    printArray(array);
    bubble_sort(array);
    std::cout << "  After sorting: " << std::endl;
    printArray(array);
    return 0;
}
