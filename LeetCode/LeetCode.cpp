
#include <string>
#include <vector>
#include <unordered_map>
#include <utility>
#include "LeetCode.h"

using std::string;

LeetCode::LeetCode() {};

bool LeetCode::isMatch(string s, string p) {
	int i=0, j = 0;
	while (i<s.size() && j<p.size()) {
		if (p[j] == '.') {
			if (j + 1 < p.size() && p[j + 1] == '*') {
				// deal with cases like "ab" ".*c"
				if (j + 2 < p.size()) {
					return isMatch(s.substr(1), p);
				}
				else
					return true;
			}
			else if (j + 1 < p.size()) {
				++j;
				++i;
				continue;
			}
		}
		if (j + 1 < p.size() && p[j + 1] == '*') {
			while (i<s.size() && s[i] == p[j]) {
				++i;
			}
			j += 2;
			continue;
		}
		else {
			if (s[i] != p[j])
				return false;
			++i;
			++j;
		}
	}
	if (i < s.size())
		return false;
	else
		return true;
}

bool LeetCode::isMatch2(string s, string p) {
	if (p.empty()) return s.empty();
	if ('*' == p[1])
		return isMatch2(s, p.substr(2)) || !s.empty() && ((s[0] == p[0] || '.' == p[0]) && isMatch2(s.substr(1), p));
	else
	{
		return !s.empty() && ((s[0] == p[0] || '.' == p[0]) && isMatch2(s.substr(1), p.substr(1)));
	}
}

bool LeetCode::isMatch_DP(string s, string p) {
	std::vector<std::vector<bool>> matrix(s.size(), std::vector<bool>(p.size(), false));
	matrix[0][0] = true;
	for (int i = 0; i <= s.size(); ++i) {
		for (int j = 1; j <= p.size(); ++j) {
			if (p[j-1] != '*')
				matrix[i][j] = i>0 && matrix[i - 1][j - 1] && (s[i-1] == p[j-1] || p[j-1] == '.');
			else
			{
				matrix[i][j] = matrix[i][j - 2] || (matrix[i - 1][j] && (s[i-1] == p[j-2] || p[j-2] == '.'));
			}
		}
	}
	return matrix[s.size()][p.size()];
}

std::vector<int> LeetCode::twoSum(const std::vector<int>& nums, int target) {
	std::unordered_map<int, int>dict;
	auto result = std::vector<int>();
	for (int i = 0; i < nums.size(); ++i) {
		auto found = dict.find(target - nums[i]);
		if ( found == dict.end()) {
			dict.insert(std::make_pair(nums[i], i));
		}
		else
		{
			if (nums[i] > found->first)
				result = std::vector<int>{ found->second, i };
			else
				result = std::vector<int>{ i, found->second };
			return result;
		}
	}

}

std::vector<double> LeetCode::insertionSort(std::vector<double> &vec) {
	if (vec.size() <= 1)
		return vec;
	int j = 0;
	for (int i = 1; i < vec.size(); ++i) {
		j = i - 1;
		double key = vec[i];
		while (j >= 0 && key < vec[j]) {
			vec[j+1] = vec[j];
			--j;
		}
		vec[j+1] = key;
	}
	return vec;
}

std::vector<double> LeetCode::minSort(std::vector<double> &vec) {
	if (vec.size() <= 1)
		return vec;
	double temp;
	for (int i = 0; i < vec.size(); ++i) {
		for (int j = i + 1; j < vec.size(); ++j) {
			if (vec[i] > vec[j]) {
				temp = vec[i];
				vec[i] = vec[j];
				vec[j] = temp;
			}

		}
	}
	return vec;
}

std::vector<double> LeetCode::mergeSort(std::vector<double> & vec) {

}