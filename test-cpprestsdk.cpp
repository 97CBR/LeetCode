
#include <iostream>
#ifdef _WIN32
#include <fcntl.h>
#include <io.h>
#endif
#include <cpprest/http_client.h>

using namespace utility;
using namespace web::http;
using namespace web::http::client;
using std::cerr;
using std::endl;

#ifdef _WIN32
#define tcout std::wcout
#else
#define tcout std::cout
#endif

auto get_headers(http_response resp)
{
    auto headers = resp.to_string();
    auto end =
        headers.find(U("\r\n\r\n"));
    if (end != string_t::npos)
    {
        headers.resize(end + 4);
    };
    return headers;
}

auto get_request(string_t uri)
{
    http_client client{uri};
    // �� GET ��ʽ����һ���ͻ�������
    auto request =
        client.request(methods::GET)
            .then([](http_response resp) {
                if (resp.status_code() !=
                    status_codes::OK)
                {
                    // �� OK����ʾ��ǰ��Ӧ��Ϣ
                    auto headers =
                        get_headers(resp);
                    tcout << headers;
                }
                // ��һ��ȡ��������Ӧ
                return resp
                    .extract_string();
            })
            .then([](string_t str) {
                // ������ն�
                tcout << str;
            });
    return request;
}

#ifdef _WIN32
int wmain(int argc, wchar_t *argv[])
#else
int main(int argc, char *argv[])
#endif
{
#ifdef _WIN32
    _setmode(_fileno(stdout),
             _O_WTEXT);
#endif

    if (argc != 2)
    {
        cerr << "A URL is needed\n";
        return 1;
    }

    // �ȴ��������������ȫ�����
    try
    {
        auto request =
            get_request(argv[1]);
        request.wait();
    }
    // ������������в������쳣
    catch (const std::exception &e)
    {
        cerr << "Error exception: "
             << e.what() << endl;
        return 1;
    }
}