/**
 * 快速排序
 * 
 * 基本思想：
 * 通过一趟排序将待排记录分隔成独立的两部分，其中一部分记录的关键字均比另一部分的关键字小，
 * 则可分别对这两部分记录继续进行排序，以达到整个序列有序。
 * 
 * 算法描述:
 * 快速排序使用分治法来把一个串（list）分为两个子串（sub-lists）。具体算法描述如下：
 * 从数列中挑出一个元素，称为 “基准”（pivot）；
 * 重新排序数列，所有元素比基准值小的摆放在基准前面，所有元素比基准值大的摆在基准的后面（相同的数可以到任一边）。在这个分区退出之后
 * 该基准就处于数列的中间位置。这个称为分区（partition）操作；
 * 递归地（recursive）把小于基准值元素的子数列和大于基准值元素的子数列排序。
 * */

#include <vector>
#include <iostream>

#if 1//递归
template<typename T>
void QuickSortCore(std::vector<T>& data, int low, int high)
{
    if(low >= high)
        return;
    
    int begin = low;
    int end = high;
    T pivot = data[begin];

    while(begin < end)
    {
        //从后往前找到第一个小与基准值的元素，放到空闲位置中
        while(begin < end && data[end] >= pivot)
            --end;
        if(begin < end)
            data[begin++] = data[end];

        //从前往后找到第一个大于基准值的元素，放到空闲位置中
        while(begin < end && data[begin] <= pivot)
            ++begin;
        if(begin < end)
            data[end--] = data[begin];
    }
    //将最后一个空闲位置放上基准元素
    data[begin] = pivot;

    QuickSortCore(data, low, begin - 1);
    QuickSortCore(data, begin + 1, high);
}

template<typename T>
void QuickSort(std::vector<T> &data)
{
    if(data.size() < 2)
        return;
    
    QuickSortCore(data, 0, data.size() - 1);
}

#else //非递归

template <typename T>
void QuickSort(std::vector<T> &data)
{
    //TODO:
}

#endif

int main(int argc, char** argv)
{
    std::vector<int> tmp = {2, 4, 6, 8, 1, 3, 5, 7};
    QuickSort<int>(tmp);
    for(auto item : tmp)
    {
        std::cout << item << " ";
    }
    std::cout << std::endl;
    return 0;
}