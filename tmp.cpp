#include <iostream>
#include <vector>
#include <memory>
#include <string.h>
#include <string>
#include <map>
#include <time.h>
#include <algorithm>

using namespace std;

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

int main()
{
    // test_class *a;
    // cout << sizeof(a->gg()) << endl;

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