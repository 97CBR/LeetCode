#include <iostream>
#include <vector>
#include <memory>
#include <string.h>
#include <string>
#include <map>
#include <time.h>
// #include <ext/hash_map>
#include <algorithm>
#include <string>
// #include <atlconv.h>

#pragma execution_character_set("utf-8")

using namespace std;
using namespace __gnu_cxx;

class test_class
{
private:
    /* data */
public:
    test_class(/* args */);
    void gg();
    ~test_class();
};

test_class::test_class(/* args */)
{
}

void test_class::gg(/* args */)
{
}

test_class::~test_class()
{
}

std::vector<string> split(std::string &str, const std::string &delims = " ")
{
    std::vector<std::string> output;

    while (str.find_first_of(',') != str.npos)
    {
        int index = str.find_last_of(',');
        string tmp = str.substr(index + 1, str.length());
        str = str.substr(0, index);
        cout << tmp << endl;
        output.emplace_back(tmp);
    }
    cout << str << endl;
    output.emplace_back(str);
    return output;
}
// test_class *a;
// cout << sizeof(a->gg()) << endl;

void eight_find(vector<int> &tmp_all, vector<vector<int>> &points, int x, int y)
{
    for (int j = -1; j < 2; j++)
    {
        for (int k = -1; k < 2; k++)
        {
            if (j == 0 && k == 0)
            {
                continue;
            }

            vector<int> tmp;
            int tmp_x = x + j;
            int tmp_y = y + k;
            // cout << "八方向" << tmp_x << "\t" << tmp_y << endl;
            tmp.push_back(tmp_x);
            tmp.push_back(tmp_y);
            vector<vector<int>>::iterator index = find(points.begin(), points.end(), tmp);

            // vector<int>::iterator sf = find(tmp_all.begin(), tmp_all.end(), tmp);
            if (index != points.end() /* && index_2 == tmp_all.end()*/)
            {
                cout << "yes" << endl;
                tmp_all.push_back(tmp_x);
                tmp_all.push_back(tmp_y);
                eight_find(tmp_all, points, tmp_x, tmp_y);
            }
        }
    }
}

string exec(const char *cmd)
{
    FILE *pipe = popen(cmd, "r");
    if (!pipe)
        return "ERROR";
    char buffer[128];
    std::string result = "";
    while (!feof(pipe))
    {
        if (fgets(buffer, 128, pipe) != NULL)
            result += buffer;
    }
    pclose(pipe);
    return result;
}

class marx
{
public:
    marx();
    ~marx();
};
marx::marx()
{
    cout << "create" << endl;
}

marx::~marx()
{
    cout << "destory" << endl;
}

void test_class()
{
    marx cbr;
    marx *tina = new marx();
    delete tina;
}
#include <functional>

int main()
{

    int* marx;
    int *cbr;

    int gg = 9712;

    marx = &gg;

    //     string tmp = exec("echo hello my friend");
    //     cout << tmp;

    //    std::string str = "Meet the new boss...";
    //     std::hash<std::string> hash_fn;
    //     size_t str_hash = hash_fn(str);

    //     std::cout << str_hash << '\n';

    //     test_class();

    //     int counts = 3;
    //     float result = 0.0;
    //     for (int i = 1; i <= counts; i++)
    //     {
    //         result += 1.0 / i;
    //     }
    //     printf("%.2f", result);
    //     cout << result << endl;
    return 0;
}

int max_line()
{
    vector<vector<int>> points = {{1, 1},
                                  {3, 2},
                                  {5, 3},
                                  {4, 1},
                                  {2, 3},
                                  {1, 4}};
    // map<int, int> exists_points;
    // for (int i = 0; i < points.size(); i++)
    // {
    //     int x = points.at(i)[0];
    //     int y = points.at(i)[1];

    //     cout << "x-y" << x << y << endl;
    //     exists_points.insert(pair<int, int>(x, y));
    // }
    vector<vector<float>> res_all_line;
    for (int i = 0; i < points.size(); i++)
    {
        int x = points.at(i)[0];
        int y = points.at(i)[1];

        cout << "x-y"
             << "\t" << x << "\t" << y << endl;
        vector<float> tmp_all;
        // a*查找不适用，在处理不连续点时错误
        // eight_find(tmp_all, points, x, y);
        for (int j = 0; j < points.size(); j++)
        {
            if (j == i)
            {
                continue;
            }
            int sx = points.at(j)[0];
            int sy = points.at(j)[1];
            float ang = 0.0;
            if ((sx - x) != 0)
            {
                ang = (sy - y) * 1.0 / (sx - x) * 1.0;
            }
            else
            {
                ang = 0.0;
            }

            cout << "p1-p2\t" << sx << "\t" << sy << "\t" << ang << endl;
            tmp_all.push_back(ang);
        }
        sort(tmp_all.begin(), tmp_all.end());
        int repeat_num = count(tmp_all.begin(), tmp_all.end(), -1);
        res_all_line.push_back(tmp_all);
    }

    return 0;
}

bool reachingPoints()
{
    int sx, sy, tx, ty = 0;
    sx = 1;
    sy = 2;
    tx = 3;
    ty = 5;
    if (tx == ty && sx == tx && ty == sy)
    {
        cout << "start is target" << endl;
        return 1;
    }
    if (tx != ty)
    {
        int ax = 1;
        int ay = 2;
        do
        {
            int tmp_p = sx + sy;
            int rex = abs(tx - ty);
            ax = tx > ty ? rex : tx;
            ay = tx > ty ? ty : rex;
            cout << "pre sept" << ax << "\t" << ay << endl;
            tx = ax;
            ty = ay;
            if (ax == sx && ay == sy)
            {
                cout << "you can do it" << endl;
                break;
            }
        } while (ax != ay);
    }
    cout << "you can't do it" << endl;
    return 0;
}
int lengthOfLIS()
{
    vector<int> ftv = {10, 9, 2, 5, 3, 7, 101, 18};
    if (ftv.size() < 1)
    {
        return 0;
    }
    if (ftv.size() == 1)
    {
        return 1;
    }
    int x, y = 0;
    vector<vector<int>> res;
    for (int i = 0; i < ftv.size(); i++)
    {
        x = ftv.at(i);
        vector<int> tmp_res;
        tmp_res.push_back(x);
        for (int j = i + 1; j < ftv.size(); j++)
        {
            y = ftv.at(j);
            if (x < y)
            {
                x = y;
                tmp_res.push_back(x);
            }
        }

        res.push_back(tmp_res);
        // break;
        // }
    }
    sort(res.begin(), res.end(), [](const vector<int> &a1, const vector<int> &a2) {
        return a1.size() > a2.size();
    });
    return 0;
}

void tmp_1()
{
    for (float i = 0.0000; i != 1.0000; i += 0.1)
    {
        cout << i << endl;
    }

    string ft = ".docx,.pptx,.pdf,.png";
    std::vector<std::string> ftv;
    ftv = split(ft, "");
    cout << ftv.size() << endl;
    vector<vector<int>> tst;
    vector<int> t;
    t.push_back(1);
    t.push_back(2);
    tst.push_back(t);

    t.push_back(3);
    tst.push_back(t);
    t.push_back(4);
    tst.push_back(t);
    cout << tst.at(1).at(2) << endl;

    vector<pair<int, char *>> mas;
    mas.push_back(make_pair<int, char *>(1, (char *)"sfa"));
    mas.push_back(make_pair<int, char *>(2, (char *)"asdg"));
    mas.push_back(make_pair<int, char *>(3, (char *)"asdgbhsdfh"));
    mas.push_back(make_pair<int, char *>(4, (char *)"hsdfh"));

    for (int i = 0; i < mas.size(); i++)
    {
        cout << mas[i].first << mas[i].second << endl;
    }

    string tes = "curl.exe -X POST https://content.dropboxapi.com/2/files/upload /willbereplace_1 good string --data - binary @willbereplace_2";
    string name = "2s3523zxcvxczvzxc5.exe";
    string mypath = "E:/www.dropbox.com/developers/documentation.EXE";
    tes = tes.replace(tes.find("willbereplace_1"), 15, name);
    tes = tes.replace(tes.find("willbereplace_2"), 15, mypath);
    cout << tes << endl;

    time_t myt = time(NULL);

    char time_string[16];
    sprintf(time_string, "%d_", myt);
    string file_name = "asfasgd.zip";
    file_name = time_string + file_name;
    cout << file_name << endl;

    string res_command = "curl.exe -X POST https://content.dropboxapi.com/2/files/upload "
                         "--header \"Authorization: Bearer wO-OKXR2pZAAAAAAAAAAEO5hiDcFqdWDVCGX1R7jJBKR-Gj3koTd3Xob2jkq55dV\""
                         " --header \\\"Dropbox - API - Arg : {\\\"path\": \\\"/1583389335_test_add_file.zip\\\",\\\"mode\\\": \\\"add\\\",\\\"autorename\\\": true,"
                         "\\\"mute\\\": false,\\\"strict_conflict\\\": false}\" --header \"Content-Type: application/octet-stream\" --data - binary @W:\\test_add_file.zip";

    cout << res_command << endl;
}

// void reversal_list(mylist *a_list)
// {
//     mylist *forward_node = nullptr;
//     mylist *cur_node = a_list->next;
//     mylist *next_node = cur_node->next;
//     if (cur_node == nullptr)
//     {
//         return;
//     }
//     while (1)
//     {
//         cur_node->next = forward_node;
//         forward_node = cur_node;
//         cur_node = next_node;
//         if (cur_node == nullptr)
//         {
//             break;
//         }
//         next_node = cur_node->next;
//     }
//     a_list->next = forward_node;
// }

// #include <stdio.h>
// #include <curl/curl.h>

// int main (int argc, char *argv[])
// {
//       CURL *curl;
//       CURLcode res;

//       /* In windows, this will init the winsock stuff */
//       curl_global_init(CURL_GLOBAL_ALL);

//       /* get a curl handle */
//       curl = curl_easy_init();
//       if(curl) {

//             printf ("Running curl test.\n");

//             struct curl_slist *headers=NULL; /* init to NULL is important */
//             headers = curl_slist_append(headers, "Authorization: Bearer <ACCESS_TOKEN>");
//             headers = curl_slist_append(headers, "Content-Type: application/octet-stream");
//             headers = curl_slist_append(headers, "Dropbox-API-Arg: {\"path\":\"/test_c++_upload_test.txt\"}");
//             curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

//             curl_easy_setopt(curl, CURLOPT_URL, "https://content.dropboxapi.com/2/files/upload");
//             curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "test data for upload");

//             /* Perform the request, res will get the return code */
//             res = curl_easy_perform(curl);
//             /* Check for errors */
//             if(res != CURLE_OK)
//                   fprintf(stderr, "curl_easy_perform() failed: %s\n",
//                     curl_easy_strerror(res));

//             /* always cleanup */
//               curl_easy_cleanup(curl);

//               printf ("\nFinished curl test.\n");

//       }
//       curl_global_cleanup();

//       printf ("Done!\n");
//       return 0;

// }