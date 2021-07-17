// Include Input Output Stream
#include <iostream>
// Include the Windows header
#include <windows.h>

// Prototype of the Window Procedure function
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

// Main function
int main(int argc, char **argv)
{
    // Window class
    WNDCLASS wc = { };

    // Window Procedure Function to call
    wc.lpfnWndProc   = WindowProc;
    // Window Instance
    wc.hInstance     = GetModuleHandleA(NULL); // Get the module handle of the executable
    // Window Class Name
    wc.lpszClassName = "mainWindow";

    // Register the window class
    RegisterClassA(&wc);

    // Create the window
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

    // Check if the Window was created
    if(windowsHandle == NULL)
    {
        // Return 1 if the window was not created
        return 1;
    }
    
    // Show the window
    ShowWindow(windowsHandle, argc);
    
    // DEBUG
    //TODO: Remove this
    std::cout << "Hello, world!" << std::endl;

    // Window Message variable
    MSG messages = { };

    // Loop until the window is closed A.k.A. GameLoop
    //TODO: Make a true GameLoop
    while(GetMessageA(&messages, NULL, 0, 0))
    {
        // Translate the message
        TranslateMessage(&messages);
        // Dispatch the message
        DispatchMessageA(&messages);
    }

    // Return 0 if the window was closed
    return 0;
}

// Window Procedure function
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    // Check Window Messages
    switch(uMsg)
    {
        // Window was exited
        case WM_DESTROY:
        {
            // Destroy the window
            PostQuitMessage(0);
            break;
        }
    }

    // Return Default Window Procedure if no message was found
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}