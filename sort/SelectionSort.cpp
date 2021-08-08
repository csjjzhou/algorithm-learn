/**
 * 选择排序
 * 
 * 选择排序(Selection-sort)是一种简单直观的排序算法。
 * 它的工作原理：
 * 首先在未排序序列中找到最小（大）元素，存放到排序序列的起始位置，
 * 然后，再从剩余未排序元素中继续寻找最小（大）元素，
 * 然后放到已排序序列的末尾。以此类推，直到所有元素均排序完毕。 
 *
 * 算法描述
 * n个记录的直接选择排序可经过n-1趟直接选择排序得到有序结果。
 * 具体算法描述如下：
 * 初始状态：无序区为R[1..n]，有序区为空；
 * 第i趟排序(i=1,2,3…n-1)开始时，当前有序区和无序区分别为R[1..i-1]和R(i..n）。
 * 该趟排序从当前无序区中-选出关键字最小的记录 R[k]，
 * 它与无序区的第1个记录R交换，使R[1..i]和R[i+1..n)分别变为记录个数增加1个的新有序区和记录个数减少1个的新无序区；
 * n-1趟结束，数组有序化了。
 * */

#include <vector>
#include <iostream>

template <typename T>
void SelectionSort(std::vector<T> &data)
{
    auto size = data.size();
    if(size < 2)
        return;
    
    for(decltype(size) i = 0; i < size - 1; ++i)
    {
        //找出下标范围为[i, size - 1]的最小值
        int min_idx = i;
        for(decltype(i) j = i + 1; j < size; ++j)
        {
            if(data[j] < data[min_idx])
                min_idx = j;
        }
        //交换
        std::swap(data[i],  data[min_idx]);
    }
}

int main(int argc, char** argv)
{
    std::vector<int> tmp = {2, 4, 6, 8, 1, 3, 5, 7};
    SelectionSort<int>(tmp);
    for(auto item : tmp)
    {
        std::cout << item << " ";
    }
    std::cout << std::endl;
    return 0;
}