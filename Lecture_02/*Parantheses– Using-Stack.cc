#include<iostream>
#include<stack>
using namespace std;

#define STRING_SIZE 10

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.length(); i ++) {
            if ((s[i] == '(') || (s[i] == '[') || (s[i] == '{')) {
                st.push(s[i]); // add to the stack
            } else {
                if (st.size() == 0) return false;
                char top = st.top();
                if (s[i] == ')') {
                    if (top != '(') return false;
                } else if (s[i] == ']') {
                    if (top != '[') return false;
                } else {
                    if (top != '{') return false;
                }
                st.pop(); // remove a top element from the stack
            }
        }
        return st.size() == 0;
    }
};

int main(){
  Solution sln;
  char st[STRING_SIZE];
  cout << "Enter a string: ";
  cin >> st;
 
  cout << sln.isValid(st) << endl;
 return 0;
}
