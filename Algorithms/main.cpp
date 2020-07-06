#include "LinkedList.h"
#include "Heap.h"
#include <functional>
#include <algorithm>
#include <numeric>
#include <regex>
#include <iostream>
#include <vector>
#include "DivideAndConquer.h"
#include <set>
#include "Sorting.h"
int maxProfit(std::vector<int>& prices) {
	const auto& valueMin = std::min_element(prices.begin(), prices.end());
	const auto& minIndex = std::distance(prices.begin(), valueMin);
	const auto& max = std::max_element(valueMin, prices.end());
	
	const auto& secMin = std::find_if(prices.begin(), valueMin, [=](const int& num) {return num != valueMin[0]; });
	const auto& secMax = std::max_element(secMin, prices.end());

	int BestValue = (max[0] - valueMin[0]) > secMax[0] - secMin[0] ? (max[0] - valueMin[0]) : secMax[0] - secMin[0];
	if (prices.empty())
		return 0;
	return BestValue;
}
// 321

int reverse(int x) {
	
	int result = 0;
	int pop = 0;
	while (x != 0)
	{
		pop = x % 10;
		if (result > (INT_MAX / 10)) 
			return 0;
		if (result < (INT_MIN / 10)) 
			return 0;
		result = result * 10 + pop;
		x = x - pop;
		x /= 10;
	}
	return result;
}
int strongPasswordChecker(std::string s) {

	int ctr = 0;
	if (s.length() < 6 || s.length() > 20)
		ctr++;
	if (!std::regex_search(s, std::regex("(?=.*[a-z])")))
		ctr++;
	if (!std::regex_search(s, std::regex("(?=.*[A-Z])")))
		ctr++;
	if (std::regex_search(s, std::regex("(?=.*\d)")))
		ctr++;


	return ctr;
}

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
	
};


ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	ListNode* finalNode = new ListNode(0);
	ListNode* finalNext = finalNode;
	ListNode* curr1 = l1;
	ListNode* curr2 = l2;

	while (curr1 != nullptr && curr2 != nullptr)
	{
		if (curr1->val <= curr2->val)
		{
			finalNext->next = curr2;
			finalNext = curr1;
		}
		else
		{
			finalNext->next = curr1;
			finalNext = curr2;
		}
		finalNext = finalNext->next;
		curr2 = curr2->next;
		curr1 = curr1->next;
	}
	if (!curr1)
	{
		finalNext->next = curr2;
	}
	else
	{
		finalNext->next = curr1;
	}
	return finalNode;

}
ListNode* deleteDuplicates(ListNode* head) {
	ListNode* current = head;

	if (current == nullptr)
	{
		return nullptr;
	}
	while (current->next != nullptr)
	{
		if (current->val == current->next->val)
		{
			current->next = current->next->next;

		}
		else
		{
			current = current->next;
		}
	}
	return head;
}
ListNode* removeElements(ListNode* head, int val) {
	ListNode* previous = head;
	ListNode* current = head;
	if (head == nullptr)
	{
		return nullptr;
	}
	while (current->next != nullptr)
	{
		if (head->val == val)
		{
			head = head->next;
			current = head;
		}
		else
		{

			if (current->next->val == val)
			{
				current->next = current->next->next;
			}
			else
			{
				current = current->next;
			}
		}
	}
	if (head->val == val)
	{
		head = head->next;
	}
	return head;
}//1-2-3-4-5->nullptr
//5-4-3-2-1->nullptr
ListNode* reverseList(ListNode* head) {
	ListNode* cur = head;
	ListNode* prev = nullptr;

	while (cur!=nullptr)
	{
		ListNode* next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	return prev;
}
//5 123 52 1 235
void InsertionSort(std::vector<int>& fckthis)
{
	for (int i = 1; i < fckthis.size(); i++)
	{
		int val = fckthis[i];

		int j = i - 1;
		
		while (j >=0 && fckthis[j] < val)
		{
			fckthis[j + 1] = fckthis[j];
			j--;
		}
		fckthis[j + 1] = val;
	}

}
void Test(int i,int j)
{
	static int framesFloor = 0;
	static int framesCeiling = 0;
	int firstHalf = 0;
	int secHalf = 3;

	if (i == 5)
		return;
	i++;
	std::cout << "Called Before Recursion " << i << " time." << std::endl;
	Test(firstHalf, j);
	std::cout << "<<<<<<<<<<<<<<SPLIT1<<<<<<<<<<<<<<<<<" << std::endl;
	Test(secHalf, j);

	std::cout << "Called After Recursion " << i << " time." << std::endl;
	
	for (int i = 0; i < 5; i++)
	{
		std::cout << "What happening ?????" << std::endl;
	}
	framesFloor++;
	std::cout << "FLOOR IS CALLED<< " << framesFloor << " <<" << std::endl;
}
std::vector<int> runningSum(std::vector<int>& nums) {

	for (int i = 1; i < nums.size(); i++)
	{
		for (int j = 0; j < i; j++)
		{
			nums[i] += nums[j];
		}
	}
	return nums;
}
std::vector<int> shuffle(std::vector<int>& nums, int n) {
	std::vector<int> shuf(nums.size());
	int ctr = 0;
	for (int i = 0; i < nums.size() && ctr < nums.size(); i++)
	{

		if (i % 2 == 0 || i == 0)
		{
			shuf[i] = nums[ctr];
			ctr++;
		}
	}
	ctr = 0;
	for (int i = 0; i < nums.size() && ctr < nums.size(); i++)

	{
		if (i % 2 != 0)
		{
			shuf[i] = nums[ctr];
		}
		ctr++;
	}
	return shuf;
}
int numJewelsInStones(std::string J, std::string S) {
	std::set<char>jewls;
	for (int i = 0; i < J.length(); i++)
	{
		jewls.insert(J[i]);
	}
	int ctr = 0;
	for (int i = 0; i < S.length(); i++)
	{
		auto const& t = jewls.find(S[i]);
		if (t != jewls.end())
		{
			ctr++;
		}
	}
	return ctr;
}
std::vector<int> smallerNumbersThanCurrent(std::vector<int>& nums) {
	std::vector<int> res(nums.size());

	for (int i = 0; i < nums.size(); i++)
	{
		int j;
		int ctr = 0;
		for (j = 0; j < nums.size(); j++)
		{
			if (nums[j] < nums[i])
			{
				ctr++;
			}
		}
		res[j] = ctr;
	}
	return res;
}

std::vector<int> decompressRLElist(std::vector<int>& nums) {
	int totalSpaceNeeded = 0;
	for (int i = 0; i < nums.size(); i += 2)
	{
		totalSpaceNeeded += nums[i];
	}
	std::vector<int> result;
	result.reserve(totalSpaceNeeded);
	int i = 0;
	int j = 1;
	int ctr = 0;
	int jumpCtr = 0;
	while (i < totalSpaceNeeded)
	{
		if (ctr < nums[jumpCtr])
		{
			result.emplace_back(nums[j]);
			ctr++;
		}
		else
		{
			i += ctr;
			j += 2;
			ctr = 0;
			jumpCtr += 2;
		}
	}
	return result;
}

int subtractProductAndSum(int n) {
	int mod = 0;
	int product = 1;
	int sum = 0;
	int result = 0;

	while (n != 0)
	{
		mod = n % 10;
		product = product * mod;
		sum = sum + mod;
		n = n - mod;
		n = n / 10;
	}
	return product - sum;
}

std::vector<int> sumZero(int n) {
	std::vector<int>nums(n);
	if (n % 2 == 0)
	{
		for (int i = 0; i < n / 2; i++)
		{
			nums[i] = -n + i;
		}
		int mid = (n / 2) + 1;
		for (int i = mid; i < n; i++)
		{
			nums[i] = i;
		}
	}
	else
	{
		int mid = (n / 2) + 1;
		for (int i = 0; i < n / 2; i++)
		{
			nums[i] = -n + i;
		}
		for (int i = mid; i < n; i++)
		{
			nums[i] = i + 1;
		}
	}

	return nums;
}
std::vector<int> createTargetArray(std::vector<int>& nums, std::vector<int>& index) {
	std::vector<int> targetArray(nums.size());

	for (int i = 0; i < targetArray.size(); i++)
	{
		int idx = index[i];
		int temp = targetArray[idx];
		targetArray[idx] = nums[i];

		for (int j = idx + 1; j < targetArray.size() - 1; j++)
		{
			int temp2 = targetArray[j];
			targetArray[j] = temp;
			temp = targetArray[j + 1];
			targetArray[j + 1] = temp2;

		}
	}
	return targetArray;
}
int main()
{
	std::vector<int>test1{ 4,16,14,10,7,9,3,2,8,1 };
	std::vector<int>test2{ 4,1,3,2,16,9,10,14,8,7 };
	//MergeSort(test1, 0, test1.size()-1);
	std::cout << std::is_heap(test2.begin(), test2.end());

	Heap heap;
	heap.HeapSortMax(test2);

	Sorting sort;
	sort.HeapSort(test1);
//	std::vector<int>vec{ 100,110,90,115,200 };
	//Results res = FindMaximumSubArray(vec, 0, vec.size() - 1);
	
	ListNode* l11 = new ListNode(1);
	ListNode* l12 = new ListNode(2);
	ListNode* l13 = new ListNode(3);
	ListNode* l14 = new ListNode(4);

	l11->next = l12;
	l12->next = l13;
	l13->next = l14;

	ListNode* head1 = l11;



	ListNode* l21 = new ListNode(1);
	ListNode* l22 = new ListNode(3);
	ListNode* l23 = new ListNode(4);
	l21->next = l22;
	l22->next = l23;

	mergeTwoLists(head1, l21);
	return 0;
}
