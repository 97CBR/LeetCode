// ��Ŀ����
// ��һ������Ϊn����������������ֶ���0��n-1�ķ�Χ�ڡ� ������ĳЩ�������ظ��ģ�����֪���м����������ظ��ġ�
// Ҳ��֪��ÿ�������ظ����Ρ����ҳ�����������һ���ظ������֡�
// ���磬������볤��Ϊ7������{2,3,1,0,2,5,3}����ô��Ӧ������ǵ�һ���ظ�������2��

// https : //www.nowcoder.com/practice/623a5ac0ea5b4e5f95552655361ae0a8?tpId=13&tqId=11203&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

// ˼·��
// ����string�����Խ��п������ף�����˫��ѭ������ O n ��ƽ�� ��Ϊ O n
// �ȱ���һ�Σ�����ԭʼ�������ַ���
// Ȼ���ٱ���һ�����֣���string Ѱ�ң� ��ԭʼ�� ������� �Լ� ���ҳ��� ��index
// ���������ͬ�� ����Ψһ����ͬ��Ψһ�����ɷ�����

#include <iostream>
#include <vector>
#include <memory>
#include <string.h>
#include <string>
#include <map>
#include <list>
#include <algorithm>

        using namespace std;

class Solution
{
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int *duplication)
    {
        string tmp = "";
        for (int i = 0; i < length; i++)
        {
            // cout << numbers[i] << endl;
            tmp += to_string(numbers[i]);
        }
        for (int i = 0; i < length; i++)
        {
            // cout << numbers[i] << endl;
            int index_l = tmp.find_first_of(to_string(numbers[i]));
            int index_r = tmp.find_last_of(to_string(numbers[i]));
            if (index_l != index_r)
            {
                *duplication = numbers[i];
                return true;
            }
        }
        return false;
    }
};

int main()
{
    cout << "Hello" << endl;

    int nums[] = {2, 3, 1, 0, 2, 5, 3};
    int target_len = 7;
    int duplication;
    // head->next = tmp_head->next;

    Solution cbr;
    cbr.duplicate(nums, target_len, &duplication);

    cout << duplication << endl;

    // cout << cbr.study(num1, num2);
    return 0;
}
