#include <iostream>
#include <windows.h>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int main(int argc, char **argv)
{
    WNDCLASS wc = { };

    wc.lpfnWndProc   = WindowProc;
    wc.hInstance     = GetModuleHandleA(NULL);
    wc.lpszClassName = "mainWindow";

    RegisterClassA(&wc);

    HWND windowsHandle = CreateWindowExA(
            CS_OWNDC,
            wc.lpszClassName,
            "Furrany Studio",
            WS_OVERLAPPEDWINDOW,
            CW_USEDEFAULT, CW_USEDEFAULT, 500, 500,
            NULL,
            NULL,
            GetModuleHandleA(NULL),
            NULL
            );

    if(windowsHandle == NULL)
    {
        return 1;
    }
    
    ShowWindow(windowsHandle, argc);
    
    std::cout << "Hello, world!" << std::endl;

    MSG messages = { };
    while(GetMessageA(&messages, NULL, 0, 0))
    {
        TranslateMessage(&messages);
        DispatchMessageA(&messages);
    }

    return 0;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch(uMsg)
    {
        case WM_DESTROY:
        {
            PostQuitMessage(0);
            break;
        }
    }

    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}