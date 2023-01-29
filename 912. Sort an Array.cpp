class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> tmp(nums.size());
        split(nums,tmp,0,nums.size());
        return nums;
        
    }
private:
    void split(vector<int>& nums,vector<int> & tmp,int lo,int hi){
        if(hi-lo<2) return;
        int m=(lo+hi)/2;
        split(nums,tmp,lo,m),split(nums,tmp,m,hi);
        if(nums[m]>=nums[m-1]) return;

        //for merging two arrays
        int l=lo ,r=m;
        for(int i=lo;i<hi;++i){
            if((r==hi)||(l<m && nums[l]<=nums[r]))  tmp[i]=nums[l++];
            else     tmp[i]=nums[r++];
        }
        copy(begin(tmp)+lo,begin(tmp)+hi,begin(nums)+lo);
    }
};
