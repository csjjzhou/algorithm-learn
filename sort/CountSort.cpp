/**
 * 计数排序
 * 
 * 计数排序不是基于比较的排序算法，其核心在于将输入的数据值转化为键存储在额外开辟的数组空间中。 
 * 作为一种线性时间复杂度的排序，计数排序要求输入的数据必须是有确定范围的整数。
 * 
 * 算法描述
 * 找出待排序的数组中最大和最小的元素；
 * 统计数组中每个值为i的元素出现的次数，存入数组C的第i项；
 * 对所有的计数累加（从C中的第一个元素开始，每一项和前一项相加）；
 * 反向填充目标数组：将每个元素i放在新数组的第C(i)项，每放一个元素就将C(i)减去1。
 * */

#include <vector>
#include <iostream>

template<typename T>
void CountSort(std::vector<T> &data)
{
    auto size = data.size();
    if(size < 2)
        return;

    //NOTE:计数排序适用于整数的排序，别的类型不太适合

    //找到最大值
    T max_value = data[0];
    for(int i = 1; i < size; ++i)
    {
        if(data[i] > max_value)
            max_value = data[i];
    }

    //开始计数
    std::vector<T> tmp(max_value + 1, 0);
    for(int i = 0; i < size; ++i)
    {
        tmp[data[i]]++;
    }

    //统计数量
    std::vector<T> res;
    res.reserve(size);
    for(int i = 0; i < tmp.size(); ++i)
    {
        if(tmp[i] > 0)
        {
            auto count = tmp[i];
            while(count--)
                res.push_back(i);
        }
    }

    //交换结果
    data.swap(res);
}

int main(int argc, char** argv)
{
    std::vector<int> tmp = {2, 4, 6, 8, 1, 3, 5, 7, 2, 4, 6, 8, 1, 3, 5, 7, 2, 4, 6, 8, 1, 3, 5, 7};
    CountSort<int>(tmp);
    for(auto item : tmp)
    {
        std::cout << item << " ";
    }
    std::cout << std::endl;
    return 0;
}
