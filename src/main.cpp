#include <windows.h>

int main(int nCmdShow)
{
    WNDCLASSEX windowClass = {sizeof(WNDCLASSEX)};

    windowClass.lpszClassName = "mainWindow";
    windowClass.style = CS_OWNDC;
    windowClass.hbrBackground = (HBRUSH)COLOR_WINDOW;

    RegisterClassEx(&windowClass);

    HWND windowsHandle = CreateWindowEx(
            0,
            windowClass.lpszClassName,
            "Furrany Studio",
            WS_OVERLAPPEDWINDOW,
            CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
            NULL,
            NULL,
            windowClass.hInstance,
            NULL
            );

    if(windowsHandle == NULL)
    {
        return 0;
    }

    ShowWindow(windowsHandle, nCmdShow);

}