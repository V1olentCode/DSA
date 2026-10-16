// 2 ms | 14.2 MB
class Solution {
public:
    void sum(vector<int> &temp,vector<int> &candidates,vector<vector<int>> &ans,int start,int tar){
        if(tar<0) return;
        if(tar==0){
            ans.push_back(temp);
            return;
        }
        for(int i=start;i<candidates.size();i++){
            if(i>start && candidates[i]==candidates[i-1]) continue;
            if(candidates[i]>tar) break;
            temp.push_back(candidates[i]);
            sum(temp,candidates,ans,i+1,tar-candidates[i]);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        sum(temp,candidates,ans,0,target);
        vector<vector<int>> ans2(ans.begin(),ans.end());
        return ans2;
    }
};