/**
 * 插入排序
 * 
 * 插入排序（Insertion-Sort）的算法描述是一种简单直观的排序算法。
 * 它的工作原理是通过构建有序序列，对于未排序数据，在已排序序列中从后向前扫描，找到相应位置并插入。
 *
 * 算法描述
 * 一般来说，插入排序都采用in-place在数组上实现。
 * 具体算法描述如下：
 * 1. 从第一个元素开始，该元素可以认为已经被排序；
 * 2. 取出下一个元素，在已经排序的元素序列中从后向前扫描；
 * 3. 如果该元素（已排序）大于新元素，将该元素移到下一位置；
 * 4. 重复步骤3，直到找到已排序的元素小于或者等于新元素的位置；
 * 5. 将新元素插入到该位置后；
 * 6. 重复步骤2~5。
*/

#include <vector>
#include <iostream>

template <typename T>
void InsertionSort(std::vector<T> &data)
{
    auto size = data.size();
    if(size < 2)
        return;

    for(decltype(size) i = 0; i < size - 1; ++i)
    {
        decltype(i) idx = i;
        while(true)
        {
            if(data[idx] > data[idx + 1])
            {
                std::swap(data[idx], data[idx + 1]);
            }
            if(idx == 0)//idx类型为size_t(即unsigned int)，执行--会越界
                break;
            --idx;
        }
    }
}

int main(int argc, char** argv)
{
    std::vector<int> tmp = {2, 4, 6, 8, 1, 3, 5, 7};
    InsertionSort<int>(tmp);
    for(auto item : tmp)
    {
        std::cout << item << " ";
    }
    std::cout << std::endl;
    return 0;
}