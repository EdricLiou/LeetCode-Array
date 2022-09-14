//Hashset

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st(nums1.begin(), nums1.end()), res;
        for (auto a : nums2) {
            if (st.count(a)) res.insert(a);
        }
        return vector<int>(res.begin(), res.end());
    }
};

//Two pointer

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        int i = 0, j = 0;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) ++i;
            else if (nums1[i] > nums2[j]) ++j;
            else {
                if (res.empty() || res.back() != nums1[i]) {
                    res.push_back(nums1[i]);
                }
                ++i; ++j;
            }
        }
        return res;
    }
};

//Binary search

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> res;
        sort(nums2.begin(), nums2.end());
        for (auto a : nums1) {
            if (binarySearch(nums2, a)) {
                res.insert(a);
            }
        }
        return vector<int>(res.begin(), res.end());
    }
    bool binarySearch(vector<int> &nums, int target) {
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return true;
            else if (nums[mid] < target) left = mid + 1;
            else right = mid;
        }
        return false;
    }
};

// https://www.cnblogs.com/grandyang/p/5507129.html
