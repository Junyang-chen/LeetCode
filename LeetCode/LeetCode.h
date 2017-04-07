#pragma once
#include <string>
#include <vector>
using std::string;

class LeetCode {

public:
	LeetCode();
	// https://leetcode.com/problems/regular-expression-matching/?tab=Description
	static bool isMatch(string s, string p);
	static bool isMatch2(string s, string p);
	static bool isMatch_DP(string s, string p);
	
	// https://leetcode.com/problems/two-sum/#/description
	static std::vector<int> twoSum(const std::vector<int>& nums, int target);

	// insertion sort
	static std::vector<double> insertionSort(std::vector<double> &);
	// min sort
	static std::vector<double> minSort(std::vector<double> &);
	// merge sort
	static std::vector<double> mergeSort(std::vector<double> &);
	static void mergeSortHelper(std::vector<double> & vec, int start, int end);
	static void merge(std::vector<double> & vec, int start, int mid, int end);
};