#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
//clock_t begin = clock();

long long MaxPairwiseProduct(const std::vector<long long> &numbers)
{
    long long max_product = 0;
    long long max1 = numbers[0];
    long long max2 = numbers[0];
    int n = numbers.size();
    int positionmax1 = 0;

    for (int first = 0; first < n; ++first)
    {
        if (numbers[first] > max1)
        {
            max1 = numbers[first];
            positionmax1 = first;
        }
    }
    for (int second = 0; second < n; ++second)
    {
        if (positionmax1 != second && ((max2 == numbers[0]) || (numbers[second] > max2)))
        {
            max2 = numbers[second];
        }
    }

    max_product = max1 * max2;
    return max_product;
}

/* for brute testing int Maxless(const std::vector<long long> &numbers)
{
    long long max_product = 0;
    int n = numbers.size();

    for (int first = 0; first < n; ++first)
    {
        for (int second = first + 1; second < n; ++second)
        {
            max_product = std::max(max_product, numbers[first] * numbers[second]);
        }
    }

    return max_product;
} */

int main()
{
    /*
    while (true)
    {
        int n = rand() % 4 + 2;
        std::cout << n << std::endl;
        std::vector<long long> a;
        for (int i = 0; i < n; i++)
        {
            a.push_back(rand() % 10);
        }
        for (int i = 0; i < n; i++)
        {
            std::cout << a[i] << ' ';
        }
        std::cout << std::endl;
        long long res1 = MaxPairwiseProduct(a);
        long long res2 = Maxless(a);
        if (res1 != res2)
        {
            std::cout << "Wrong res1=" << res1 << " Res2=" << res2;
        }
        else
        {
            std::cout << "OK" << std::endl;
        }
    }*/
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