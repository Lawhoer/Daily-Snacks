#include <iostream>
#include <vector>

using namespace std;

int maxNonAdjacentSum(const vector<int>& nums) {
    if (nums.empty()) {
        return 0;
    }

    int inclusive = nums[0];
    int exclusive = 0;

    for (size_t i = 1; i < nums.size(); ++i) {
        int temp = max(inclusive, exclusive);

        inclusive = exclusive + nums[i];
        exclusive = temp;
    }

    return max(inclusive, exclusive);
}

int main() {
    // Test için örnek girdiler
    vector<int> nums1 = { 2, 4, 6, 2, 5 };
    vector<int> nums2 = { 5, 1, 1, 5 };
    vector<int> nums3 = { 20, 1, 5, 2, 1, 20 };

    // Sonuçlarý ekrana yazdýrma
    cout << "Result 1: " << maxNonAdjacentSum(nums1) << endl; // Beklenen çýktý: 13
    cout << "Result 2: " << maxNonAdjacentSum(nums2) << endl; // Beklenen çýktý: 10
    cout << "Result 3: " << maxNonAdjacentSum(nums3) << endl; // Beklenen çýktý: 45

    return 0;
}
