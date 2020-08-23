#include <iostream>

using namespace std;

long long rowSumOddNumbers(unsigned n){
  int result = 0;
  int start = 1;
  for(size_t i = 0; i < n; i++) {
    int rowSum = 0;
    for (size_t j = 0; j <= i; j++){
      rowSum = rowSum + start;
      start += 2;
    }
    result = rowSum;
  }
  return result;
}

int main(){
  int result = rowSumOddNumbers(2);
  cout << result << endl;
  return 0;
}