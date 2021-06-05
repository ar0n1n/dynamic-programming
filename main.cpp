#include <iostream>

#define BASE 13 
#define N 6

using namespace std;

int lookup[10][100] = {-1};

int count(int n, int sum) 
{ 
  if (n == 0) 
    return sum == 0;

  if (lookup[n][sum] != -1) 
    return lookup[n][sum];

  int ans = 0;

  for (int i = 0; i < BASE; ++i) 
    if (sum - i >= 0) 
      ans += count(n - 1, sum - i);

  return lookup[n][sum] = ans; 
}

int main(void) 
{ 
  int n = N; 
  unsigned long long int ans = 0; 
  memset(lookup, -1, sizeof lookup);

  int maxSum = N * (BASE - 1);

  for (int sum = 0; sum <= maxSum; ++sum) { 
    // Находим кол-во 6-значных чисел, сумма цифр в которых равна sum 
    unsigned long long int combs = count(n, sum);

    // Правило произведения: Если элемент а можно выбрать m способами, 
    // а элемент b (независимо от выбора элемента а) - n способами, 
    // то выбор "а и b" можно сделать m·n способами. 
    ans += (combs * combs); 
  }

  // Оставшаяся цифра (7 цифра 13-значного числа) может принимать одно из 13 значений 
  ans *= BASE; 
  cout << ans;

  return 0; 
}
