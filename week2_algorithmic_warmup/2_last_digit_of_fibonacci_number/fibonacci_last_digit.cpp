#include <iostream>

int get_fibonacci_last_digit_naive(int n)
{
    if (n <= 1)
        return n;
    int previous = 0;
    int current = 1;

    for (int i = 0; i < n - 1; ++i)
    {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}
int get_fibonacci_last_digit_fast(int n)
{
    unsigned long long fibores[n];
    for (int i = 0; i < n; i++)
    {
        fibores[i] = i;
    }
    fibores[0] = 0;
    fibores[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        fibores[i] = (fibores[i - 2] + fibores[i - 1]) % 10;
    }
    return fibores[n];
}

int main()
{
    int n;
    std::cin >> n;
    int c = get_fibonacci_last_digit_naive(n);
    std::cout << get_fibonacci_last_digit_fast(n) << '\n';
    return 0;
}
