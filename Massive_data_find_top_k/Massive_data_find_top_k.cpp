#include <iostream>
#include <vector>
#include <queue>
#include <functional>

/*
海量数据求top k的问题
1.求最大的/最小的前K个元素
2.求最大的/最小的第K个元素

10000个整数，找值前10大的元素
先用前10个整数创建一个小根堆(最小值就在堆顶)，然后遍历剩下的整数，如果整数比堆顶元素大，那么删除堆顶元素(出堆)，然后再把整数入堆，遍历完所有整数，小根堆里面放的就是值最大的前10个元素了;如果找的是第k小(大根堆堆顶)或者第k大(小根堆堆顶)，只需要访问堆顶一个元

大根堆 =》 找top K小的
小根堆 =》找top K大的

解法1：大根堆和小根堆 prior_queue
解法2：快排分割函数
经过快排分割函数，能够在o(log2n)时间内，把小于基准数的整数调整到左边，把大于基准数的整数调整到右边，基准数（index）就可以认为是第（index+1）小的整数[0, (index)]就是前index+1小的整数
*/

int partition(std::vector<int>& arr, int i, int j)
{
	int k = arr[i];
	while (i < j)
	{
		while (i < j && arr[j] > k)
			j--;
		if (i < j)
			arr[i++] = arr[j];

		while (i < j && arr[i] < k)
			i++;
		if (i < j)
			arr[j--] = arr[i];
	}
	arr[i] = k;
	return i;
}

int main()
{	
#if 0
	std::vector<int> vec;
	for (int i = 0; i < 10000; ++i)
	{
		vec.push_back(rand() + i);
	}

	// 定义小根堆
	std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
	int k = 0;
	for (; k < 10; ++k)
	{
		minHeap.push(vec[k]);
	}
	
	for (; k < vec.size(); ++k)
	{
		if (vec[k] > minHeap.top())
		{
			minHeap.pop();
			minHeap.push(vec[k]);
		}
	}

	while (!minHeap.empty())
	{
		std::cout << minHeap.top() << " ";
		minHeap.pop();
	}
	std::cout << std::endl;

	return 0;
#endif // 0

}