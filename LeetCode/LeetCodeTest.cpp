#define BOOST_TEST_MODULE MyTest
#include <iostream>
#include <boost/test/unit_test.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include "LeetCode.h"
using namespace std;

BOOST_AUTO_TEST_SUITE(LeetCodeTest)

BOOST_AUTO_TEST_CASE(regularstringmatching)
{
	std::vector<boost::shared_ptr<bool(*)(string, string)>> vectorfunctions;
	//vectorfunctions.push_back(boost::make_shared<bool(*)(string, string)>(&LeetCode::isMatch));
	vectorfunctions.push_back(boost::make_shared<bool(*)(string, string)>(&LeetCode::isMatch2));
	//vectorfunctions.push_back(boost::make_shared<bool(*)(string, string)>(&LeetCode::isMatch_DP));

	for (auto itr = vectorfunctions.begin(); itr != vectorfunctions.end(); ++itr) {
		//bool test = (**itr)("aa", "aa");
		BOOST_CHECK_EQUAL((**itr)("aa", "aa"), true);
		BOOST_CHECK_EQUAL((**itr)("aa", "a"), false);
		BOOST_CHECK_EQUAL((**itr)("aaa", "aa"), false);
		BOOST_CHECK_EQUAL((**itr)("aa", "a*"), true);
		BOOST_CHECK_EQUAL((**itr)("aa", ".*"), true);
		BOOST_CHECK_EQUAL((**itr)("ab", ".*"), true);
		BOOST_CHECK_EQUAL((**itr)("aab", "c*a*b"), true);
		// this bug need to be added
		BOOST_CHECK_EQUAL((**itr)("ab", ".*c"), false);
	}


	
	//BOOST_CHECK_EQUAL(add(2, 2), 4);	  // #7 continues on error
	system("pause");
}

BOOST_AUTO_TEST_CASE(twoSum)
{
	vector<boost::shared_ptr<vector<int>(*)(const vector<int>&, int)>> funcvector;
	funcvector.push_back(boost::make_shared<vector<int>(*)(const vector<int>&, int)>(&LeetCode::twoSum));

	for (auto itr = funcvector.begin(); itr != funcvector.end(); ++itr) {
		auto vec = vector<int>{ 2, 7, 11, 15 };
		auto expect_result = vector<int>{ 0, 1};
		auto result = (**itr)(vec, 9);
		BOOST_CHECK_EQUAL_COLLECTIONS(result.begin(), result.end(), expect_result.begin(), expect_result.end());

		vec = vector<int>{ 3, 2, 4 };
		expect_result = vector<int>{ 1, 2 };
		result = (**itr)(vec, 6);
		BOOST_CHECK_EQUAL_COLLECTIONS(result.begin(), result.end(), expect_result.begin(), expect_result.end());
	}
}

BOOST_AUTO_TEST_CASE(sort)
{
	vector<boost::shared_ptr<vector<double>(*)(vector<double> &)>> funcvec{ boost::make_shared<vector<double>(*)(vector<double> &)>(LeetCode::minSort),
		boost::make_shared<vector<double>(*)(vector<double> &)>(LeetCode::insertionSort)};
	//funcvec.push_back(boost::make_shared<vector<double>(*)(vector<double> &)>(LeetCode::insertionSort));

	for (auto itr = funcvec.begin(); itr != funcvec.end(); ++itr) {
		auto vec = vector<double>{ 0 };
		auto expectResult = vector<double>(vec);
		auto result = (**itr)(vec);
		BOOST_CHECK_EQUAL_COLLECTIONS(result.begin(), result.end(), expectResult.begin(), expectResult.end());

		vec = vector<double>{ 0,0,0,0,0,0};
		expectResult = vector<double>(vec);
		result = (**itr)(vec);
		BOOST_CHECK_EQUAL_COLLECTIONS(result.begin(), result.end(), expectResult.begin(), expectResult.end());

		vec = vector<double>{ 5, 3, 1, 2, 7, 8, 10, 9};
		expectResult = vector<double>{ 1,2,3,5,7,8,9,10 };
		result = (**itr)(vec);
		BOOST_CHECK_EQUAL_COLLECTIONS(result.begin(), result.end(), expectResult.begin(), expectResult.end());

		vec = vector<double>{ 5, 3, 1, 2 };
		expectResult = vector<double>{ 1,2,3,5 };
		result = (**itr)(vec);
		BOOST_CHECK_EQUAL_COLLECTIONS(result.begin(), result.end(), expectResult.begin(), expectResult.end());

	}
	int temp;
	std::cin >> temp;
}
BOOST_AUTO_TEST_SUITE_END()