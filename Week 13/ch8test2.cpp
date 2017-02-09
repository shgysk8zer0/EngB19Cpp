#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int i;
    vector <int> nums;
    nums.insert(nums.begin(),-999);
    nums.insert(nums.begin(),14);
    nums.insert(nums.end(),10);
    
    for(i=0;i<nums.size();i++)
       cout << nums[i] << endl;
    cout << endl;
    
    sort(nums.begin(),nums.end());
    
    for(i=0;i<nums.size();i++)
       cout << nums[i] << endl;
    cout << endl;
    
    nums.erase(nums.begin());
    nums.erase(nums.begin());
    
    for(i=0;i<nums.size();i++)
       cout << nums[i] << endl;     
    
    system("pause");
    return 0;
}
    
