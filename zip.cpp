//How to implement a1,a2,a3...an,b1,b2,b3,...bn -> a1b1a2b2...anbn
//
#include <vector>
void zip(const std::vector<T>& vec) {

  int n = vec.size()/2;
  std::vector<T> newvec(vec.size());
//without inplace:
  for (int i = 0; i < n; ++i) {
    newvec[i * 2] = vec[i]; 
  }
  for (int i = 0; i < n; ++i) {
    newvec[i * 2 + 1] = vec[i + n]; 
  }
}
