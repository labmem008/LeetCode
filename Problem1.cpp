#include <map>
using namespace std;
/**
 * LeetCode第一题
 * 给出一个vector和一个数字target
 * 要求返回这个vector里面相加等于
 * target的两个数字的indexm并存储在
 * 一个新的vector里面
 *
 * 2020年2月22日
 * 汪涵铭
 */

vector<int> twoSum(vector<int>& nums, int target)
{
	vector<int> ans;
	map<int, int> record;	// 创建一个map来存储vector里面的值和index
	int complement;		// 寻找map的key等于complement并返回其index
	int size = nums.size();
	for (int i = 0; i < size; i++)
	{
		complement = target - nums[i];	// 遍历vector并计算当前num需要的complement
		if (record.find(complement) != record.end())
		{
			ans.push_back(i);
			ans.push_back(record.find(complement) -> second);
			// record.end(), record.find(complement)都是map的iterator
			// 用箭头->来获取其member
			// first是key second是value
		}
		record.insert(make_pair(nums[i], i));	// 如果没有找到则在record里面记录i的值和i的index
	}
	return ans;
}
