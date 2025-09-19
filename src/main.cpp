#include <windows.h>
#include <winhttp.h>
#include <cstdio>

#pragma comment(lib, "winhttp.lib")

const char testing_ip[] = "3.167.2.92";

int main()
{
    HINTERNET h = WinHttpOpen(L"Opera/1.0", WINHTTP_ACCESS_TYPE_DEFAULT_PROXY, 0, 0, 0);
    
    if (!h) 
        return 1;

    HINTERNET c = WinHttpConnect(h, my_private_ip, 443, 0);
    HINTERNET r = WinHttpOpenRequest(c, L"GET", L"/test/test.js", 0, 0, 0, WINHTTP_FLAG_SECURE);
    
    BOOL ok = WinHttpSendRequest(r, 0, 0, 0, 0, 0, 0) && WinHttpReceiveResponse(r, 0);

    if (ok)
        std::puts("ok");

    if (r) WinHttpCloseHandle(r);
    if (c) WinHttpCloseHandle(c);
    if (h) WinHttpCloseHandle(h);
}
