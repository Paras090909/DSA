class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>negative;
        vector<int>positive;
        vector<int>res;
        // data store 
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < 0){
                negative.push_back(nums[i]);
            }
            else{
                positive.push_back(nums[i]);
            }
        }

        // squaring
        for(int i = 0; i < positive.size(); i++){
            positive[i] *=positive[i];
        }
        for(int i = 0; i < negative.size(); i++){
            negative[i] *= negative[i];
        }

        // merging data 
        int i = 0, j = negative.size()-1;
        while(i <positive.size() && j >=0){
            if(negative[j] <= positive[i]){
                res.push_back(negative[j]);
                j--;
            }else{
                res.push_back(positive[i]);
                i++;
            }
        }

        while(i < positive.size()){
            res.push_back(positive[i]);
            i++;
        }

         while(j>=0){
            res.push_back(negative[j]);
            j--;
        }
        return res;
    }
};
