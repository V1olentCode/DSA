// 0 ms | 21.7 MB
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int st = 0,end = nums.size()-1,mid;
        if(end!=nums[end]){
            while(st<=end){
                mid = st + (end-st)/2;
                if(mid!=nums[mid]){
                    end = mid-1;
                }
                else{
                    st = mid+1;
                }
            }
            return st;
        }
        else{
            return nums.size();
        }
    }
};

// 1 2 4 5 6 7 8 
// s     e     