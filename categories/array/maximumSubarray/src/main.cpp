#include <vector>
#include <iostream>

void    parseInput(std::vector<int>& nums);
int     Solution(const std::vector<int>& nums);


int main() {
    std::vector<int> nums;

    parseInput(nums);

    auto result = Solution(nums);

    std::cout << result << std::endl;

    return 0;
}