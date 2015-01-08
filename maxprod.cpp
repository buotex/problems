#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxProduct(int A[], int n) {
        vector<int> memory(n);
        int start =1;
        for (int i = 0 ; i < n; ++i){
            memory[i] = (start *= A[i]);
            if (memory[i] == 0) start = 1; 
        }
        int minabs = 1;
        int minint = 1;
        int maxint = memory[0];


        for (int i = 1; i < n; ++i){
            if (memory[i] > 0){
                maxint = std::max(memory[i] / minint, maxint);
                minint = std::min(minint, memory[i]);
            }
            else if (memory [i] < 0){
                maxint = std::max(-memory[i] / minabs, maxint);
                std::cout << minabs << " " << -memory[i] << std::endl;
                minabs = std::min(minabs, -memory[i]);
            }
        }


        return maxint;
    }
};
int main() {
  int a[3] = {-2,0,-1};
  Solution sol;
return sol.maxProduct(a, 3);

}
