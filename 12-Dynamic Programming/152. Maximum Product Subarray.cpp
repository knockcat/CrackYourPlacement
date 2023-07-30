// Time Complexity -> O(n)
// Space Complexity -> O(1)

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int n = nums.size();
        
        int overall_max = INT_MIN;
        
        int pref = 1, suff = 1;
        
        for(int i = 0; i < n; ++i)
        {
            if(pref == 0)
                pref = 1;
            if(suff == 0)
                suff = 1;
            
            pref *= nums[i];
            suff *= nums[n-i-1];
            
            overall_max = max({overall_max, pref, suff});
        }
        
        return overall_max;
    }
};

// Time Complexity -> O(n)
// Space Complexity -> O(1)

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int n = nums.size();
        
        int max_end = nums[0];
        int min_end = nums[0];
        int overall_max = nums[0];
        
        for(int i = 1; i < n; ++i)
        {
            int temp = max_end;
            
            max_end = max({nums[i], max_end * nums[i], min_end * nums[i]});
            min_end = min({nums[i], temp * nums[i], min_end * nums[i]});
            
            overall_max = max({overall_max, max_end, min_end});
        }
        
        return overall_max;
        
    }
};
