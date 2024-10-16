#include <bits/stdc++.h>
using namespace std;

vector<int> distinctDifferenceArray(vector<int> &nums)
{
    vector<int> diff;
    for (int i = 0; i < nums.size(); i++)
    {
        vector<int> pre;
        vector<int> suff;
        for (int j = 0; j <= i; j++)
        {
            pre.push_back(nums[j]);
        }
        for (int j = i + 1; j < nums.size(); j++)
        {
            suff.push_back(nums[j]);
        }
        sort(pre.begin(), pre.end());
        pre.erase(unique(pre.begin(), pre.end()), pre.end());
        for (int i = 0; i < pre.size(); i++)
        {
            cout << pre[i];
        }
        cout << endl;
        sort(suff.begin(), suff.end());
        suff.erase(unique(suff.begin(), suff.end()), suff.end());
        for (int i = 0; i < suff.size(); i++)
        {
            cout << suff[i];
        }
        cout << endl;
        diff.push_back(pre.size() - suff.size());
    }
    return diff;
}

int main()
{
    vector<int> arr;
    cout << "Enter elements : ";
    for (int i = 0; i < 5; i++)
    {
        int data;
        cin >> data;
        arr.push_back(data);
    }
    vector<int> result = distinctDifferenceArray(arr);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << "  ";
    }
    return 0;
}