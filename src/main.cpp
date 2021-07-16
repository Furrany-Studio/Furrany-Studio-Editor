#include <windows.h>

int main(int nCmdShow)
{
    WNDCLASSEX windowClass;

    windowClass.lpszClassName = "mainWindow";
    windowClass.lpszMenuName = "Furrany Studio";
    windowClass.style = NULL;
    windowClass.hbrBackground = (HBRUSH)COLOR_WINDOW;
    windowClass.cbSize = sizeof(WNDCLASSEX);
    windowClass.cbClsExtra = NULL;
    windowClass.cbWndExtra = NULL;
    windowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
    windowClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    windowClass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
    windowClass.hInstance = NULL;

    RegisterClassEx(&windowClass);

    HWND windowsHandle =::CreateWindowEx(
            WS_EX_OVERLAPPEDWINDOW,
            "mainWindow",
            "Furrany Studio",
            WS_OVERLAPPEDWINDOW,
            CW_USEDEFAULT, CW_USEDEFAULT, 500, 500,
            NULL,
            NULL,
            NULL,
            NULL
            );

    if(windowsHandle == NULL)
    {
        return 0;
    }

    ShowWindow(windowsHandle, nCmdShow);

}