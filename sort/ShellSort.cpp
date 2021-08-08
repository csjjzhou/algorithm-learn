/**
 * 希尔排序
 * 
 * 1959年Shell发明，第一个突破O(n2)的排序算法，是简单插入排序的改进版。
 * 它与插入排序的不同之处在于，它会优先比较距离较远的元素。
 * 希尔排序又叫缩小增量排序。
 *
 * 算法描述
 * 先将整个待排序的记录序列分割成为若干子序列分别进行直接插入排序
 * 具体算法描述：
 * 选择一个增量序列t1，t2，…，tk，其中ti>tj，tk=1；
 * 按增量序列个数k，对序列进行k 趟排序；
 * 每趟排序，根据对应的增量ti，将待排序列分割成若干长度为m 的子序列，分别对各子表进行直接插入排序。
 * 仅增量因子为1 时，整个序列作为一个表来处理，表长度即为整个序列的长度。
 * */

#include <vector>
#include <iostream>

template <typename T>
void ShellSort(std::vector<T> &data)
{
    auto size = data.size();

    for(decltype(size) gap = size / 2; gap > 0; gap /= 2)
    {
        //NOTE:与前面注释中提到的步骤有所不同
        for(decltype(gap) i = gap; i < size; ++i)
        {
            decltype(i) pre_idx = i - gap;
            while(pre_idx >= 0 && data[pre_idx] > data[pre_idx + gap])
            {
                std::swap(data[pre_idx], data[pre_idx + gap]);
                if(pre_idx >= gap)//因为这里数据的类型为size_t
                    pre_idx -= gap;
                else
                    break;
            }
        }
    }
}

int main(int argc, char** argv)
{
    std::vector<int> tmp = {2, 4, 6, 8, 1, 3, 5, 7};
    ShellSort<int>(tmp);
    for(auto item : tmp)
    {
        std::cout << item << " ";
    }
    std::cout << std::endl;
    return 0;
}