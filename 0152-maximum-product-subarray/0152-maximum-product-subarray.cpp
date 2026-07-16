class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currentMax=nums[0];
        int currentMin=nums[0];
        int answer=nums[0];

        for(int i=1; i<nums.size(); i++){
            int prevMax=currentMax;
            int prevMin=currentMin;

            int a = nums[i];
            int b = nums[i]*prevMax;
            int c = nums[i]*prevMin;

            currentMax=max(a, max(b,c));
            currentMin=min(a,min(b,c));

            answer=max(answer, currentMax);
        }
        return answer;
    }
};