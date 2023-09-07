#include <iostream>

int fib(int n) {
  if(n == 1) return 1; 
  return n*fib(n-1);
}

int main() {
  std::cout << fib(5);
}