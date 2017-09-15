/*
The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.
*/
//use sstringstream function to do int -> string convert
class Solution {
public:
	string getPermutation(int n, int k) {
		string result;
		vector<int> v;
        stringstream s;
		if (n == 1) {
			return "1";
		}
		for (int i = 0; i<n; ++i) {
			v.push_back(i+1);
		}
		int* arr_fac = cal_fac(n);//caculate the total factory array 
		int div;
		int rem;
		for (int i = 0; i < n; ++i) {
			div = (k - 1) / (*(arr_fac + n - 1 - i));
			rem = (k - 1) % (*(arr_fac + n - 1 - i)) + 1;
            s << v[div];
			result += s.str();
            s.str("");
			v.erase(v.begin() + div);
			k = rem;
		}
		
		return result;

	}
	int *cal_fac(int n) {
		int *tmp_fac = new int[n];
		tmp_fac[0] = 1;
		for (int i = 1; i<n; ++i) {
			tmp_fac[i] = i*tmp_fac[i - 1];
		}
		return tmp_fac;
	}
};