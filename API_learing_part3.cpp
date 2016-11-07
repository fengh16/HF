#include<Windows.h>
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
	HWND hwnd;
	MSG Msg;
	WNDCLASS wndclass;
int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE hPrevInst,LPSTR IpszCmdLine, int nCmdShow)
{
	char IpszClassName[] = "窗口";
	char IpszTitle[] = "My_Windows";
	wndclass.style = 0;
	wndclass.lpfnWndProc = WndProc;
	wndclass.cbClsExtra = 0;
	wndclass.hInstance = hinstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclass.lpszMenuName = NULL;
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
	//HDC （MFC中的设备上下文句柄）HDC设备上下文是一种包含有关某个设备（如显示器或打印机）的绘制属性信息的 Windows 数据结构。所有绘制调用都通过设备上下文对象进行，这些对象封装了用于绘制线条、形状和文本的 Windows API。
	HBRUSH hBrush;
	HPEN hPen;
	POINT points[6]={{100, 212},{70, 227},{70, 250},{130, 250},{130, 227},{100, 212}};
	switch(message)
	{
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		hPen = (HPEN)GetStockObject(NULL_PEN);//用空笔
		SelectObject(hdc, hPen);//选用这根笔
		hBrush = (HBRUSH)GetStockObject(BLACK_BRUSH);
		SelectObject(hdc,hBrush);
		LineTo(hdc,50,50);//使用lineto函数画线，首先要移动到起始位置，这里是用一根空笔
		DeleteObject(hPen);
		hPen = CreatePen(PS_SOLID, 2, RGB(255,0,0));//创建一根新笔
		SelectObject(hdc, hPen);
		LineTo(hdc, 150, 50);
		LineTo(hdc, 100, 137);
		LineTo(hdc, 50, 50);
		Polyline(hdc, points, 6);
		Arc(hdc, 63, 137, 138, 212, 100, 137, 100, 137); //椭圆
		Pie(hdc, 213, 137, 288, 212, 240, 137, 260, 137);//饼形
		Rectangle(hdc, 213, 212, 287, 250);
		RoundRect(hdc, 213, 100, 287, 137, 20, 20);//圆角矩形
		DeleteObject(hPen);//用完删除
		DeleteObject(hBrush);
		EndPaint(hwnd, &ps);//记得endpaint
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}
	return(0);
}
