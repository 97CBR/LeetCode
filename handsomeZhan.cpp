#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;
    char c = getchar();
    vector<string> HTML;     //存储模板
    map<string, string> VAR; //存储
    string str, key, value;
    string myhtml;
    for (int i = 0; i < m; i++)
    {
        getline(cin, str);
        // HTML.push_back(str);
        myhtml = myhtml + str + "\n";
    }

    for (int i = 0; i < n; i++)
    {
        cin >> key;
        getline(cin, value);



        VAR[key] = value.substr(2, value.length() - 3);
        // cout << key << endl;
    }

    string help_s = myhtml;

    while ((help_s.find_last_of("{{") != help_s.npos) && (help_s.find_last_of("}}") != help_s.npos))
    {
        int l = help_s.find_last_of("{{"); //x为变量所在位置
        int r = help_s.find_last_of("}}"); //x为变量所在位置

        string html_sub = myhtml.substr(l - 1, r - l + 2);
        // cout << "this is "
        //      << "\t"
        //      << l << "\t" << r
        //      << "\t" << html_sub << endl
        //      << endl;
        int flag = 1;
        for (map<string, string>::iterator it = VAR.begin(); it != VAR.end(); it++)
        {
            string cmp_str = "{{ " + it->first + " }}";
            if (cmp_str == html_sub)
            {
                myhtml.replace(l - 1, r - l + 2, it->second);
                help_s.replace(l - 1, r - l + 2, "just help you");
                flag = 0;
            }
        }
        if (flag)
        {
            myhtml.replace(l - 1, r - l + 2, "");
            help_s.replace(l - 1, r - l + 2, "just help you");
        }

        // break;
    }
    cout << myhtml << endl;
}

// int point_90()
// {
//     int m, n;
//     cin >> m >> n;
//     char c = getchar();
//     vector<string> HTML;     //存储模板
//     map<string, string> VAR; //存储
//     string str, key, value;
//     string myhtml;
//     for (int i = 0; i < m; i++)
//     {
//         getline(cin, str);
//         // HTML.push_back(str);
//         myhtml = myhtml + str + "\n";
//     }

//     for (int i = 0; i < n; i++)
//     {
//         cin >> key;
//         getline(cin, value);
//         VAR[key] = value.substr(2, value.length() - 3);
//         // cout << key << endl;
//     }

//     for (map<string, string>::iterator it = VAR.begin(); it != VAR.end(); it++)
//     {

//         char temp[64];
//         sprintf(temp, "{{ %s }}", it->first.data());
//         string aim_var = temp;
//         while (myhtml.find(aim_var) != myhtml.npos)
//         {
//             int x = myhtml.find(aim_var); //x为变量所在位置
//             myhtml.replace(x, aim_var.length(), it->second);
//         }

//         // for (int k = 0; k < m; k++)
//         // {
//         //     char temp[64];
//         //     sprintf(temp, "{{ %s }}", it->first.data());
//         //     string aim_var = temp;
//         //     while (HTML[k].find(aim_var) != HTML.at(k).npos)
//         //     {
//         //         int x = HTML[k].find(aim_var); //x为变量所在位置
//         //         HTML[k].replace(x, aim_var.length(), it->second);
//         //     }
//         // }
//     }

//     while ((myhtml.find("{{") != myhtml.npos) && (myhtml.find("}}") != myhtml.npos))
//     {
//         int l = myhtml.find("{{"); //x为变量所在位置
//         int r = myhtml.find("}}"); //x为变量所在位置
//         myhtml.replace(l, r - l + 2, "");
//     }
//     cout << myhtml << endl;
//     // for (int i = 0; i < m; i++)
//     // {
//     //     while ((HTML[i].find("{{") != HTML.at(i).npos) && (HTML[i].find("}}") != HTML.at(i).npos))
//     //     {
//     //         int l = HTML[i].find("{{"); //x为变量所在位置
//     //         int r = HTML[i].find("}}"); //x为变量所在位置
//     //         HTML[i].replace(l, r - l + 2, "");
//     //     }
//     //     cout << HTML[i] << endl;
//     // }

//     return 0;
// }

// 11 2
// <!DOCTYPE html>
// <html>
// <head>
// <title>User {{ name }}</title>
// </head>
// <body>
// <h1>{{ name }}</h1>
// <p>Email: <a href="mailto:{{ email }}">{{ email }}</a></p>
// <p>Address: {{ address }}</p>
// </body>
// </html>
// name "David Beckham"
// email "david@beckham.com"