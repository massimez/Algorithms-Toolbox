#include <iostream>
#include <vector>
#include <algorithm>
//clock_t begin = clock();

long long MaxPairwiseProduct(const std::vector<long long> &numbers)
{
    long long max_product = 0;
    long long max1 =numbers[0];
    long long max2 =numbers[0];
    int n = numbers.size();
    int positionmax1 = 0; 
    
    for (int first = 0; first < n; ++first)
    {
        if (numbers[first]>max1) {
          max1 = numbers[first];
          positionmax1 = first;
        }
    }
    for (int second = 0; second < n; ++second)
        {
            if (numbers[second]>max2 && positionmax1 != second){
              max2=numbers[second+1];
            }
        }
    std::cout<<"MAx1:"<<max1<<"max2:"<<max2<<std::endl;    
    max_product = max1*max2;
    return max_product;
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<long long> numbers(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProduct(numbers) << std::endl;

//clock_t end = clock();
//double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//std::cout<<"Time:"<<time_spent;

    return 0;
}