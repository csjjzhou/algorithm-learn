/**
 * 归并排序
 * 
 * 归并排序是建立在归并操作上的一种有效的排序算法。该算法是采用分治法（Divide and Conquer）的一个非常典型的应用。
 * 将已有序的子序列合并，得到完全有序的序列；即先使每个子序列有序，再使子序列段间有序。
 * 若将两个有序表合并成一个有序表，称为2-路归并。 
 * 
 * 算法描述
 * 把长度为n的输入序列分成两个长度为n/2的子序列；
 * 对这两个子序列分别采用归并排序；
 * 将两个排序好的子序列合并成一个最终的排序序列。
 * */

#include <vector>
#include <iostream>

template<typename T>
void MergeSortCore(std::vector<T> &data, std::vector<T> &tmp, int left, int right)
{
    if(left >= right)
        return;

    int mid = left + ((right - left) >> 1);
    MergeSortCore(data, tmp, left, mid);
    MergeSortCore(data, tmp, mid + 1, right);

    //合并已经排好序的两组数据
    int idx = left;
    int left_begin = left;
    int left_end = mid;
    int right_begin = mid + 1;
    int right_end = right;
    while(left_begin <= left_end && right_begin <= right_end)
        tmp[idx++] = data[left_begin] > data[right_begin] ? data[right_begin++] : data[left_begin++];
    while(left_begin <= left_end)
        tmp[idx++] = data[left_begin++];
    while(right_begin <= right_end)
        tmp[idx++] = data[right_begin++];

    //tmp此时是排好序的数组，因此需要做个交换
    tmp.swap(data);
}

template<typename T>
void MergeSort(std::vector<T> &data)
{
    auto size = data.size();
    if(size < 2)
        return;
    
    //定义辅助数组
    std::vector<T> tmp(data.begin(), data.end());

    MergeSortCore(data, tmp, 0, size - 1);
}

int main(int argc, char** argv)
{
    std::vector<int> tmp = {2, 4, 6, 8, 1, 3, 5, 7};
    MergeSort<int>(tmp);
    for(auto item : tmp)
    {
        std::cout << item << " ";
    }
    std::cout << std::endl;
    return 0;
}