#include <iostream>
#include <vector>
#include <memory>
#include <string.h>
#include <string>
#include <map>
#include <time.h>

using namespace std;

int main()
{
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
    tes = tes.replace(tes.find("willbereplace_1"), 15 ,name);
    tes = tes.replace(tes.find("willbereplace_2"), 15 ,mypath);
    cout << tes <<endl;

    time_t myt = time(NULL);

    char time_string[16];
    sprintf(time_string, "%d_", myt);
    string file_name = "asfasgd.zip";
    file_name = time_string + file_name;
    cout << file_name<<endl;

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