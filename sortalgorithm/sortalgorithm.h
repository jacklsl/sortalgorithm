#ifdef SORTALGORITHM_EXPORTS  
#define SORTALGORITHM_API __declspec(dllexport)   
#else  
#define SORTALGORITHM_API __declspec(dllimport)   
#endif  


#include<vector>

namespace LSLnamespace
{
	class sortalgorithm
	{
	public:
		//1. ð������(Bubble Sort)
		__declspec(dllexport) void bubble_sort(std::vector<int> &nums);
		//2. ��������Insertion Sort��
		__declspec(dllexport) void insert_sort(std::vector<int> &nums);
		//3. ѡ������Selection Sort��
		__declspec(dllexport) void selection_sort(std::vector<int> &nums);
		//4. ϣ������Shell Sort��
		__declspec(dllexport) void shell_sort(std::vector<int> &nums);
		//5. �鲢����Merge Sort��
		__declspec(dllexport) void merge_sort(std::vector<int> &nums, int b, int e, std::vector<int> &temp);
		//6. ��������Quick Sort��
		__declspec(dllexport) void quick_sort(std::vector<int> &nums, int b, int e, std::vector<int> &temp);
		__declspec(dllexport) void quick_sort(std::vector<int> &nums, int b, int e);
		//7. ������Heap Sort��
		__declspec(dllexport) void heap_sort(std::vector<int> &nums);

	private:
		void max_heapify(std::vector<int> &nums, int beg, int end);
		void merge_array(std::vector<int> &nums, int b, int m, int e, std::vector<int> &temp);
	};
}