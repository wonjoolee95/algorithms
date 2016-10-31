#include <iostream>
#include <vector>
#include <random>
#include <unordered_set>


void selection_sort(std::vector<int> &array) 
{
    for (int i = 0; i < array.size(); i++) 
    {
        int min_index = i;
        for (int j = i+1; j < array.size(); j++) 
        {
            if (array[j] < array[min_index]) 
            {
                local_min_index = j;
            }
        }
        int temp = array[min_index];
        array[i] = array[min_index];
        array[min_index] = temp;
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
    selection_sort(array);
    std::cout << "  After sorting: " << std::endl;
    printArray(array);
    return 0;
}
