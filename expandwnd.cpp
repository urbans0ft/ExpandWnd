#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <iostream>
#include <string>

#define MAX_TITLE_LEN 255

using namespace std;

HWND wnd = NULL;

BOOL CALLBACK EnumerateWindows(HWND hwnd, LPARAM lParam);

int main(int argc, char* argv[])
{
  if (argc != 2)
  {
    cout << "Usage: expandwnd \"<window name>\"" << endl;
    return 0;
  }
  cout << "Searching: \"" << argv[1] << "\"" << endl;
  EnumWindows(EnumerateWindows, (LPARAM)argv[1]);
  if (wnd)
  {
    cout << "Repositioning window." << endl;
    HMONITOR monitor = MonitorFromWindow(wnd, MONITOR_DEFAULTTONEAREST);
    MONITORINFO info{0};
    info.cbSize = sizeof(MONITORINFO);
    GetMonitorInfo(monitor, &info);
    RECT rect = info.rcWork;
    cout << "x:      " << rect.left << endl;
    cout << "width:  " << rect.right - rect.left << endl;
    cout << "y:      " << rect.top << endl;
    cout << "height: " << rect.bottom << endl;
    if (!SetWindowPos(wnd, HWND_TOP, rect.left, rect.top, rect.right - rect.left, rect.bottom, SWP_ASYNCWINDOWPOS))
    {
      cout << "SetWindowPos failed." << endl;
    }
  }
  else
  {
    cout << "Could not find: \"" << argv[1] << "\"" << endl;
  }
  return 0;
}

BOOL CALLBACK EnumerateWindows(HWND hwnd, LPARAM lParam)
{
  char* searchTitle = (char*)lParam;
  char title[MAX_TITLE_LEN] = {0};
  GetWindowTextA(hwnd, title, MAX_TITLE_LEN);
  if (strstr(title, searchTitle))
  {
    cout << "Found: \"" << title << "\"" << endl;
    wnd = hwnd;
    return FALSE;
  }
  return TRUE;
}
