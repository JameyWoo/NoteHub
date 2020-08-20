#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void mergeSort(vector<int>& nums);
void merge(vector<int>& nums, int l, int r);

int main() {
	vector<int> nums({4, 2, 1, 3, 4, 2, 9, 5, 2, 3, 4, -3, 8});
	mergeSort(nums);
	for (auto& v: nums) {
		cout << v << ' ';
	}
	cout << endl;
}

void mergeSort(vector<int>& nums) {
	merge(nums, 0, nums.size() - 1);
}

void merge(vector<int>& nums, int l, int r) {
	if (l >= r - 1) return;
	int mid = (l + r) >> 1;
	merge(nums, l, mid);
	merge(nums, mid, r);

	vector<int> num2;
	int p1 = l, p2 = mid;
	while (p1 < mid && p2 < r) {
		if (nums[p1] <= nums[p2]) {
			num2.push_back(nums[p1++]);
		} else if (nums[p1] > nums[p2]) {
			num2.push_back(nums[p2++]);
		}
	}
	while (p1 < mid) {
		num2.push_back(nums[p1++]);
	}
	while (p2 < r) {
		num2.push_back(nums[p2++]);
	}
	for (int i = 0; i < r - l; i++) {
		nums[i + l] = num2[i];
	}
}