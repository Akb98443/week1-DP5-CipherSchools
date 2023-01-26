#include <bits/stdc++.h>
using namespace std;

vector<int> searchRange(vector<int> &nums, int target)
{
    int n = nums.size() - 1;

    int st = 0, end = n;
    vector<int> ans{-1, -1};
    // finding the first occurance
    while (st <= end)
    {
        int mid = st + (end - st) / 2;
        if (nums[mid] == target)
        {
            ans[0] = mid;
            end = mid - 1;
        }
        else if (nums[mid] > target)
        {
            end = mid - 1;
        }
        else
            st = mid + 1;
    }
    // renew the value of st and end
    // for second occurance
    st = 0, end = n;
    while (st <= end)
    {
        int mid = st + (end - st) / 2;
        if (nums[mid] == target)
        {
            ans[1] = mid;
            st = mid + 1;
        }
        else if (nums[mid] > target)
        {
            end = mid - 1;
        }
        else
            st = mid + 1;
    }
    return ans;
}

int main(){
    vector<int> nums = {1,3,4,5,5,5,5,5,5,5,5,5,5,5,5,5,5,6, 9 ,12};
    vector<int> ans = searchRange(nums, 5);

    return 0;
}