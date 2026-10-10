// 0 ms | 112.8 MB
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int total=0;
        int sum=0;
        int start=0;

        for(int i=0;i<n;i++) {
            int net=gas[i]-cost[i];
            total+=net;
            sum+=net;
            if(sum<0) {
                start=i+1;
                sum=0;
            }   
        }
        if(total<0) {
            return -1;
        }
        return start;
    }
};