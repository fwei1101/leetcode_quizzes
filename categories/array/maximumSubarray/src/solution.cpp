#include <vector>
#include <algorithm>

int Solution(const std::vector<int>& nums) {
    int pre = 0, m = nums[0];
    for (const int& n : nums) {
        pre = std::max(n, pre + n);
        m = std::max(m, pre);
    }
    return m;
}