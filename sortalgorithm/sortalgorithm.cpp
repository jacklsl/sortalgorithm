
#include"sortalgorithm.h"


namespace LSLnamespace
{
	//1. 冒泡排序(Bubble Sort)

	/**********************************************************************************************************
	冒泡排序是最简单粗暴的排序方法之一。它的原理很简单，每次从左到右两两比较，
	把大的交换到后面，每次可以确保将前M个元素的最大值移动到最右边。

	步骤:
	1从左开始比较相邻的两个元素x和y，如果 x > y 就交换两者
	2执行比较和交换，直到到达数组的最后一个元素
	3重复执行1和2，直到执行n次，也就是n个最大元素都排到了最

	复杂度分析:
	由于我们要重复执行n次冒泡，每次冒泡要执行n次比较（实际是1到n的等差数列，
	也就是(a1 + an) * n / 2），也就是 O(n^2)。 空间复杂度是O(n)。
	**********************************************************************************************************/
	void LSLnamespace::sortalgorithm::bubble_sort(std::vector<int> &nums)
	{
		for (unsigned int i = 0; i < nums.size() - 1; i++)
		{ // times
			for (unsigned int j = 0; j < nums.size() - i - 1; j++)
			{ // position
				if (nums[j] > nums[j + 1])
				{
					int temp = nums[j];
					nums[j] = nums[j + 1];
					nums[j + 1] = temp;
				}
			}
		}
	}
	//2. 插入排序（Insertion Sort）
	/**********************************************************************************************************
	插入排序的原理是从左到右，把选出的一个数和前面的数进行比较，找到最适合它的位置放入，使前面部分有序。

	步骤

	1从左开始，选出当前位置的数x，和它之前的数y比较，如果x < y则交换两者
	2对x之前的数都执行1步骤，直到前面的数字都有序
	3选择有序部分后一个数字，插入到前面有序部分，直到没有数字可选择
	复杂度分析

	因为要选择n次，而且插入时最坏要比较n次，所以时间复杂度同样是O(n^2)。空间复杂度是O(n)。

	**********************************************************************************************************/

	void LSLnamespace::sortalgorithm::insert_sort(std::vector<int> &nums)
	{
		for (unsigned int i = 1; i < nums.size(); i++) { // position
			for (int j = i; j > 0; j--) {
				if (nums[j] < nums[j - 1]) {
					int temp = nums[j];
					nums[j] = nums[j - 1];
					nums[j - 1] = temp;
				}
			}
		}
	}
	//3. 选择排序（Selection Sort）
	/**********************************************************************************************************
	选择排序的原理是，每次都从乱序数组中找到最大（最小）值，放到当前乱序数组头部，最终使数组有序。

	步骤:
	1从左开始，选择后面元素中最小值，和最左元素交换
	2从当前已交换位置往后执行，直到最后一个元素

	复杂度分析:
	每次要找一遍最小值，最坏情况下找n次，这样的过程要执行n次，所以时间复杂度还是O(n^2)。空间复杂度是O(n)。
	**********************************************************************************************************/
	void LSLnamespace::sortalgorithm::selection_sort(std::vector<int> &nums)
	{
		for (unsigned int i = 0; i < nums.size(); i++) { // position
			int min = i;
			for (unsigned int j = i + 1; j < nums.size(); j++) {
				if (nums[j] < nums[min]) {
					min = j;
				}
			}

			int temp = nums[i];
			nums[i] = nums[min];
			nums[min] = temp;
		}
	}
	//4. 希尔排序（Shell Sort）
	/**********************************************************************************************************
	希尔排序从名字上看不出来特点，因为它是以发明者命名的。它的另一个名字是“递减增量排序算法“。
	这个算法可以看作是插入排序的优化版，因为插入排序需要一位一位比较，然后放置到正确位置。
	为了提升比较的跨度，希尔排序将数组按照一定步长分成几个子数组进行排序，通过逐渐减短步长来完成最终排序。

	步骤:

	1计算当前步长，按步长划分子数组
	2子数组内插入排序
	3步长除以2后继续12两步，直到步长最后变成1

	复杂度分析:

	希尔排序的时间复杂度受步长的影响，具体分析在维基百科。

	**********************************************************************************************************/
	void LSLnamespace::sortalgorithm::shell_sort(std::vector<int> &nums)
	{
		for (int gap = nums.size() >> 1; gap > 0; gap >>= 1) { // times
			for (unsigned int i = gap; i < nums.size(); i++) { // position
				int temp = nums[i];

				int j = i - gap;
				for (; j >= 0 && nums[j] > temp; j -= gap) {
					nums[j + gap] = nums[j];
				}

				nums[j + gap] = temp;
			}
		}
	}
	//5. 归并排序（Merge Sort）
	/**********************************************************************************************************
	归并排序是采用分治法（Divide and Conquer）的一个典型例子。这个排序的特点是把一个数组打散成小数组，
	然后再把小数组拼凑再排序，直到最终数组有序。

	步骤:

	1把当前数组分化成n个单位为1的子数组，然后两两比较合并成单位为2的n/2个子数组
	2继续进行这个过程，按照2的倍数进行子数组的比较合并，直到最终数组有序

	复杂度分析:

	在merge_array过程中，实际的操作是当前两个子数组的长度，即2m。又因为打散数组是二分的，最终循环执行数是logn。
	所以这个算法最终时间复杂度是O(nlogn)，空间复杂度是O(n)。
	**********************************************************************************************************/
	void LSLnamespace::sortalgorithm::merge_array(std::vector<int> &nums, int b, int m, int e, std::vector<int> &temp)
	{
		int lb = b, rb = m, tb = b;
		while (lb != m && rb != e)
			if (nums[lb] < nums[rb])
				temp[tb++] = nums[lb++];
			else
				temp[tb++] = nums[rb++];

		while (lb < m)
			temp[tb++] = nums[lb++];

		while (rb < e)
			temp[tb++] = nums[rb++];

		for (int i = b; i < e; i++)
			nums[i] = temp[i];
	}

	void LSLnamespace::sortalgorithm::merge_sort(std::vector<int> &nums, int b, int e, std::vector<int> &temp)
	{
		int m = (b + e) / 2;
		if (m != b) {
			merge_sort(nums, b, m, temp);
			merge_sort(nums, m, e, temp);
			merge_array(nums, b, m, e, temp);
		}
	}
	//6. 快速排序（Quick Sort）
	/**********************************************************************************************************
	快速排序也是利用分治法实现的一个排序算法。快速排序和归并排序不同，它不是一半一半的分子数组，
	而是选择一个基准数，把比这个数小的挪到左边，把比这个数大的移到右边。然后不断对左右两部分也执行相同步骤，
	直到整个数组有序。

	步骤:

	1用一个基准数将数组分成两个子数组
	2将大于基准数的移到右边，小于的移到左边
	3递归的对子数组重复执行1，2，直到整个数组有序

	复杂度分析:

	快速排序也是一个不稳定排序，时间复杂度看维基百科。空间复杂度是O(n)。

	**********************************************************************************************************/
	void LSLnamespace::sortalgorithm::quick_sort(std::vector<int> &nums, int b, int e, std::vector<int> &temp)
	{
		int m = (b + e) / 2;
		if (m != b) {
			int lb = b, rb = e - 1;

			for (int i = b; i < e; i++) {
				if (i == m)
					continue;
				if (nums[i] < nums[m])
					temp[lb++] = nums[i];
				else
					temp[rb--] = nums[i];
			}
			temp[lb] = nums[m];

			for (int i = b; i < e; i++)
				nums[i] = temp[i];

			quick_sort(nums, b, lb, temp);
			quick_sort(nums, lb + 1, e, temp);
		}
	}
	void LSLnamespace::sortalgorithm::quick_sort(std::vector<int> &nums, int b, int e)
	{
		if (b < e - 1) {
			int lb = b, rb = e - 1;
			while (lb < rb) {
				while (nums[rb] >= nums[b] && lb < rb)
					rb--;
				while (nums[lb] <= nums[b] && lb < rb)
					lb++;
				std::swap(nums[lb], nums[rb]);
			}
			std::swap(nums[b], nums[lb]);
			quick_sort(nums, b, lb);
			quick_sort(nums, lb + 1, e);
		}
	}
	//7. 堆排序（Heap Sort）
	/**********************************************************************************************************
	堆排序经常用于求一个数组中最大k个元素时。因为堆实际上是一个完全二叉树，所以用它可以用一维数组来表示。
	因为最大堆的第一位总为当前堆中最大值，所以每次将最大值移除后，调整堆即可获得下一个最大值，
	通过一遍一遍执行这个过程就可以得到前k大元素，或者使堆有序。

	在了解算法之前，首先了解在一维数组中节点的下标：

	i节点的父节点 parent(i) = floor((i-1)/2)
	i节点的左子节点 left(i) = 2i + 1
	i节点的右子节点 right(i) = 2i + 2

	步骤:

	1.构造最大堆（Build Max Heap）：首先将当前元素放入最大堆下一个位置，然后将此元素依次和它的父节点比较，
	如果大于父节点就和父节点交换，直到比较到根节点。重复执行到最后一个元素。

	2.最大堆调整（Max Heapify）：调整最大堆即将根节点移除后重新整理堆。整理方法为将根节点和最后一个节点交换，
	然后把堆看做n-1长度，将当前根节点逐步移动到其应该在的位置。

	3.堆排序（HeapSort）：重复执行2，直到所有根节点都已移除。


	复杂度分析:

	堆执行一次调整需要O(logn)的时间，在排序过程中需要遍历所有元素执行堆调整，所以最终时间复杂度是O(nlogn)。空间复杂度是O(n)。
	**********************************************************************************************************/
	void LSLnamespace::sortalgorithm::max_heapify(std::vector<int> &nums, int beg, int end)
	{
		int curr = beg;
		int child = curr * 2 + 1;
		while (child < end) {
			if (child + 1 < end && nums[child] < nums[child + 1]) {
				child++;
			}
			if (nums[curr] < nums[child]) {
				int temp = nums[curr];
				nums[curr] = nums[child];
				nums[child] = temp;
				curr = child;
				child = 2 * curr + 1;
			}
			else {
				break;
			}
		}
	}

	void LSLnamespace::sortalgorithm::heap_sort(std::vector<int> &nums)
	{
		int n = nums.size();
		for (int i = n / 2 - 1; i >= 0; i--) { // build max heap
			max_heapify(nums, i, nums.size() - 1);
		}

		for (int i = n - 1; i > 0; i--) { // heap sort
			int temp = nums[i];
			nums[i] = nums[0];
			nums[0] = temp;
			max_heapify(nums, 0, i);
		}
	}
}