#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
using namespace std;

void quickSort(vector<int>& nums);
void sort(vector<int>& nums, int l, int r);
int partition(vector<int>& nums, int l, int r);

int main() {
	vector<int> nums({4, 2, 1, 3, 4, 2, 9, 5, 2, 3, 4, -3, 8});
	quickSort(nums);
	for (auto& v: nums) {
		cout << v << ' ';
	}
	cout << endl;
}

void quickSort(vector<int>& nums) {
	srand(unsigned(time(NULL)));
	random_shuffle(nums.begin(), nums.end());
	sort(nums, 0, nums.size() - 1);
}

void sort(vector<int>& nums, int l, int r) {
	if (l >= r) return;
	int j = partition(nums, l, r);
	sort(nums, l, j - 1);
	sort(nums, j + 1, r);
}

int partition(vector<int>& nums, int l, int r) {
	if (r <= l) return l;
	int i = l, j = r + 1;
	int midv = nums[l];
	while (i <= j) {
		while (i <= r && nums[++i] < midv);
		while (j >= l && nums[--j] > midv);
		if (i >= j) break;
		swap(nums[i], nums[j]);
	}
	swap(nums[l], nums[j]);
	return j;
}