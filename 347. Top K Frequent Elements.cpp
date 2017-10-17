/*
https://leetcode.com/problems/top-k-frequent-elements/description/
Given a non-empty array of integers, return the k most frequent elements.

For example,
Given [1,1,1,2,2,3] and k = 2, return [1,2].

Note: 
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
*/
//Solution 1
class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		min_heap.resize(k);
		for (auto num : nums) {
			++mp[num];
		}
		auto it = mp.begin();
		int i = 0;
		while (i < k) {
			min_heap[i] = it->first;
			++it;
			++i;
		}
		for (int i = (k - 2) / 2; i >= 0; --i) {
			_adjustdown(min_heap, i);
		}
		while (it != mp.end()) {
			if (it->second > mp[min_heap[0]]) {
				min_heap[0] = it->first;
				_adjustdown(min_heap, 0);
			}
			++it;
		}
		vector<int> vec(k);
		while (k >= 1) {
			vec[k-1] = min_heap[0];
			swap(min_heap[0], min_heap[min_heap.size() - 1]);
			min_heap.pop_back();
			_adjustdown(min_heap, 0);
			--k;
		}
		return vec;
	}
	void _adjustdown(vector<int>& min_heap, int i) {
		int child = 2 * i + 1;
		while (child < min_heap.size()) {
			if (child + 1 < min_heap.size() && mp[min_heap[child + 1]] < mp[min_heap[child]]) child++;
			if (mp[min_heap[child]] < mp[min_heap[i]]) {
				swap(min_heap[i], min_heap[child]);
				i = child;
				child = 2 * i + 1;
			}
			else break;
		}
	}

private:
	vector<int> min_heap;
	unordered_map<int, int> mp;
};
//SOlution2:
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        unordered_map<int, int> cnt;
        for (auto num : nums) cnt[num]++;
        for (auto kv : cnt) {
            pq.push({kv.second, kv.first});
            while (pq.size() > k) pq.pop();
        }
        vector<int> res;
        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
//Solution3: Bucket sort
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        if (!nums.size()) return res;
        unordered_map<int, int> cnt;
        for (auto num : nums) cnt[num]++;
        vector<vector<int>> bucket(nums.size() + 1);
        for (auto kv : cnt) {
            bucket[kv.second].push_back(kv.first);
        }

        for (int i = bucket.size() - 1; i >= 0; --i) {
            for (int j = 0; j < bucket[i].size(); ++j){
                res.push_back(bucket[i][j]);
                if (res.size() == k) return res;
            }
        }

        return res;
    }
};