#include <iostream>

long long lcm_naive(int a, int b)
{
  for (long l = 1; l <= (long long)a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long)a * b;
}
unsigned long long gcd_fast(long a, long b)
{
  if (a % b == 0)
    return b;
  long rest;
  rest = a % b;
  return (gcd_fast(b, rest));
}

unsigned long long lcm_fast(long long a, long long b)
{
  unsigned long long test = (a * b);
  long long gcd = gcd_fast(a, b);
  return test / gcd;
}
int main()
{
  int a, b;
  std::cin >> a >> b;
  //Fast solution
  //clock_t begin2 = clock();
  std::cout
      << lcm_fast(a, b) << std::endl;
  //clock_t end2 = clock();
  //double time_spent2 = (double)(end2 - begin2) / CLOCKS_PER_SEC;
  //std::cout << "Time2:" << time_spent2 << "\n";
  //Naive
  //clock_t begin = clock();
  //std::cout << lcm_naive(a, b) << std::endl;
  //clock_t end = clock();
  //double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  //std::cout << "Time1:" << time_spent << "\n";

  return 0;
}
