// 0 ms | 14 MB
class Solution {
public:

    void sum(vector<int> &temp,vector<int> &candidates,vector<vector<int>> &ans,int start,int tar){
        if(tar<0) return;
        if(tar==0){
            ans.push_back(temp);
            return;
        }
        for(int i=start;i<candidates.size();i++){
            temp.push_back(candidates[i]);
            sum(temp,candidates,ans,i,tar-candidates[i]);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sum(temp,candidates,ans,0,target);
        return ans;
    }
};