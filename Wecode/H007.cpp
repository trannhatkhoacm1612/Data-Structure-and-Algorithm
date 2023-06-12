#include <iostream>
#include <stack>
using namespace std;
stack<int>st;
int main()
{
    long long a;
    int x;
    cin >> a >> x;
    if (a == 0)
    {
        cout << "0";
        return 0;
    }

    while (a != 0)
    {
        st.push(a % x);
        a /= x;
    }

    while (!st.empty())
    {
        cout << st.top();
        st.pop();
    }
    return 0;
}