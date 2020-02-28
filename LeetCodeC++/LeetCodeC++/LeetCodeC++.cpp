// LeetCodeC++.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#pragma warning(disable : 4996)
using namespace std;
//
//int fun() {
//
//    union test {
//        int i;
//        char j;
//    };
//    test t;
//    t.i = 1;
//    return (t.j == 1);
//}
//
//
//void my_fork() {
//    printf("fork after...\n");
//}
//

int main() {

	char tmp[1000];
	/*scanf("%s", tmp);
	printf("%s %d", tmp, sizeof(tmp));*/
	getline(cin, tmp);
	cout << tmp;

}

//void emt() {
//    std::cout << "Hello World!\n";
//    std::cout << fun() << std::endl;
//    int a, b;
//    while (cin >> a >> b)// 注意，如果输入是多个测试用例，请通过while循环处理多个测试用例
//        cout << a + b << endl;
//
//
//    //freopen("1.in","r",stdin);
//    int n, ans = 0;
//    cin >> n;
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n; j++) {
//            int x;
//            scanf("%d", &x);
//            ans += x;
//        }
//    }
//    cout << ans << endl;
//
//
//    //vector<int> vec1;    //默认初始化，vec1为空
//    //vec1.push_back(100);            //添加元素
//    //vec1.push_back(600);            //添加元素
//    //int size = vec1.size();         //元素个数
//    //cout << vec1[0] << endl;        //取得第一个元素
//    //vector<int>::const_iterator iterator = vec1.begin();
//    //for (; iterator != vec1.end(); iterator++)
//    //    cout << *iterator;
//}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧:
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
