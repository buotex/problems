#include <vector>
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        std::vector<int> stack;
        int newval;
        for (const auto &entry : tokens) {
            
                switch(entry.c_str()[0]){
                    case '+':
                    newval = stack[stack.size() - 2] + stack[stack.size() -1 ];
                    break;
                    case '-':
                    if (entry.size() >1 ) goto LINEDEFAULT;
                    newval = stack[stack.size() - 2] - stack[stack.size() -1 ];
                    break;
                    case '/':
                    newval = stack[stack.size() - 2] / stack[stack.size() -1 ];
                    break;
                    case '*':
                    newval = stack[stack.size() - 2] * stack[stack.size() -1 ];
                    break;
LINEDEFAULT:
                    default:
                    stack.push_back(atol(entry.c_str()));
                    std::cout << stack.back() << std::endl;
                    continue;
                }
                stack.pop_back();
                stack.back() = newval;
            }
        return stack[0];
    }
};


int main() {
  Solution sol;
  std::vector<string> testVec{"3", "-4", "+"};
  return sol.evalRPN(testVec);
}
