#include<Windows.h>
#include<math.h>
#define Pi 3.1415927
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HWND hwnd;
MSG Msg;
WNDCLASS wndclass;
int i, R_of_Circle;
POINT SinPoint[101];
int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE hPrevInst,LPSTR IpszCmdLine, int nCmdShow)
{
	for(i = 0; i <= 100; i++)
	{
		SinPoint[i].x = i * 8;
		SinPoint[i].y = sin(Pi * i / 50) * 100;
	}
	char IpszClassName[] = "窗口";
	char IpszTitle[] = "My_Windows";
	wndclass.lpfnWndProc = WndProc;
	wndclass.hInstance = hinstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclass.lpszClassName = IpszClassName;
	if(!RegisterClass(&wndclass))
	{
		MessageBeep(0);
		return GetLastError();
	}
	hwnd = CreateWindow(IpszClassName, IpszTitle, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hinstance, NULL);
	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);
	while(GetMessage(&Msg, NULL, 0, 0))
	{
		TranslateMessage(&Msg);
		DispatchMessage(&Msg);
	}
	return Msg.wParam;
}
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;
	HBRUSH hBrush;
	HPEN hPen;
	switch(message)
	{
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		SetWindowOrgEx(hdc, -150, -250, NULL); //设置原点坐标
		hPen = CreatePen(PS_DASH, 1, RGB(255, 0, 0));
		SelectObject(hdc, hPen);
		Polyline(hdc, SinPoint, 101);
		if(i > 100)
			i %= 100;
		if(i <= 25)
		{
			hPen = CreatePen(PS_DASH, 1, RGB(255, 0, 0));
			hBrush = CreateHatchBrush(HS_BDIAGONAL, RGB(255, 0, 0));
		}
		else if(i <= 50)
		{
			hPen = CreatePen(PS_DASH, 1, RGB(0, 255, 0));
			hBrush = CreateHatchBrush(HS_BDIAGONAL, RGB(0, 255, 0));
		}
		else if(i <= 75)
		{
			hPen = CreatePen(PS_DASH, 1, RGB(0, 0, 255));
			hBrush = CreateHatchBrush(HS_BDIAGONAL, RGB(0, 0, 255));
		}
		else
		{
			hPen = CreatePen(PS_DASH, 1, RGB(255, 0, 255));
			hBrush = CreateHatchBrush(HS_BDIAGONAL, RGB(255, 0, 255));
		}
		SelectObject(hdc, hPen);
		SelectObject(hdc, hBrush);
		R_of_Circle = (i - 1) % 25 * 2 + 3;
		Ellipse(hdc, SinPoint[i].x - R_of_Circle, SinPoint[i].y + R_of_Circle, SinPoint[i].x + R_of_Circle, SinPoint[i].y - R_of_Circle);
		DeleteObject(hPen);
		DeleteObject(hBrush);
		i++;
		Sleep(100);
		EndPaint(hwnd, &ps);
		InvalidateRect(hwnd, NULL, 1);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}
	return(0);
}
