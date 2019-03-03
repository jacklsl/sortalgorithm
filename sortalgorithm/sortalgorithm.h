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
		//1. √∞≈›≈≈–Ú(Bubble Sort)
		__declspec(dllexport) void bubble_sort(std::vector<int> &nums);
		//2. ≤Â»Î≈≈–Ú£®Insertion Sort£©
		__declspec(dllexport) void insert_sort(std::vector<int> &nums);
		//3. —°‘Ò≈≈–Ú£®Selection Sort£©
		__declspec(dllexport) void selection_sort(std::vector<int> &nums);
		//4. œ£∂˚≈≈–Ú£®Shell Sort£©
		__declspec(dllexport) void shell_sort(std::vector<int> &nums);
		//5. πÈ≤¢≈≈–Ú£®Merge Sort£©
		__declspec(dllexport) void merge_sort(std::vector<int> &nums, int b, int e, std::vector<int> &temp);
		//6. øÏÀŸ≈≈–Ú£®Quick Sort£©
		__declspec(dllexport) void quick_sort(std::vector<int> &nums, int b, int e, std::vector<int> &temp);
		__declspec(dllexport) void quick_sort(std::vector<int> &nums, int b, int e);
		//7. ∂—≈≈–Ú£®Heap Sort£©
		__declspec(dllexport) void heap_sort(std::vector<int> &nums);

	private:
		void max_heapify(std::vector<int> &nums, int beg, int end);
		void merge_array(std::vector<int> &nums, int b, int m, int e, std::vector<int> &temp);
	};
}