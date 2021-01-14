#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

int Func(vector<int> A, int k)
{
    map<int, int> last;

    int n = A.size();

    for (int i = 0; i < n; i++)
    {
        last[A[i]] = -1;
    }
    if (last.size() < k)
    {
        return n;
    }

    set<array<int, 2>> s;

    for (auto p : last)
    {
        s.insert({p.second, p.first});
    }

    int ans = 0;
    for (int right = 0; right < n; right++)
    {
        s.erase({last[A[right]], A[right]});
        last[A[right]] = right;
        s.insert({last[A[right]], A[right]});
        // s.begin->at(0) is minimum value of all lasts...(set is sorted as per arr[0])
        ans = max(right - s.begin()->at(0), ans);
    }
    return ans;
}

int solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (int i = 0; i < A.size(); i++)
    {
        cin >> A[i];
    }
    return Func(A, k);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cout << solve() << endl;
    }
    return 0;
}