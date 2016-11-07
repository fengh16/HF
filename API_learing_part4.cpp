#include<Windows.h>
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HWND hwnd;
MSG Msg;
WNDCLASS wndclass;
int nmode = 0;//先找一个变量用于存放映射模式的选择
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
	HBRUSH hBrush;
	HPEN hPen;
	POINT points[6]={{100, 212},{70, 227},{70, 250},{130, 250},{130, 227},{100, 212}};
	switch(message)
	{
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		SetMapMode(hdc,nmode);				//设置映射模式
/*函数功能描述:该函数设置指定设备环境的映射方式，映射方式定义了将逻辑单位转换为设备单位的度量单位，并定义了设备的X、Y轴的方向。
nMapMode:指定新映射的模式。它可以是以下任一值：
MM_ANISOTROPIC：逻辑单位转换成具有任意比例轴的任意单位，用SetWindowExt和SetViewportExt函数可指定单位、方向和比例。
MM_HIENGLISH：每个逻辑单位转换为0.001英寸，X的正方向向右，Y的正方向向上。
MM_HIMETRIC：每个逻辑单位转换为0.01毫米，X正方向向右，Y的正方向向上。
MM_ISOTROPIC：逻辑单位转换成具有均等比例轴的任意单位，即沿X轴的一个单位等于沿Y轴的一个单位，用SetWindowExt和SetViewportExt函数可以指定该轴的单位和方向。图形设备界面（GDI）需要进行调整，以保证X和Y的单位保持相同大小（当设置窗口范围时，视口将被调整以达到单位大小相同）。
MM_LOENGLISH：每个逻辑单位转换为0.01英寸，X正方向向右，Y正方向向上。
MM_LOMETRIC：每个逻辑单位转换为0.1毫米，X正方向向右，Y正方向向上。
MM_TEXT：每个逻辑单位转换为一个图素，X正方向向右，Y正方向向下。
MM_TWIPS；每个逻辑单位转换为打印点的1/20（即1/1440英寸），X正方向向右，Y方向向上。*/
		SetWindowExtEx(hdc,150,150,NULL); 	//设置窗口区域
		SetViewportExtEx(hdc,150,100,NULL); //设置视口区域
		SetViewportOrgEx(hdc,150,60,NULL); 	//设置视口原点
		hPen = (HPEN)GetStockObject(NULL_PEN);
		SelectObject(hdc, hPen);
		hBrush = (HBRUSH)GetStockObject(BLACK_BRUSH);
		SelectObject(hdc,hBrush);
		LineTo(hdc,50,50);
		DeleteObject(hPen);
		hPen = CreatePen(PS_SOLID, 2, RGB(255,0,0));
		SelectObject(hdc, hPen);
		LineTo(hdc, 150, 50);
		LineTo(hdc, 100, 137);
		LineTo(hdc, 50, 50);
		Polyline(hdc, points, 6);
		Arc(hdc, 63, 137, 138, 212, 100, 137, 100, 137);
		Pie(hdc, 213, 137, 288, 212, 240, 137, 260, 137);
		Rectangle(hdc, 213, 212, 287, 250);
		RoundRect(hdc, 213, 100, 287, 137, 20, 20);
		DeleteObject(hPen);
		DeleteObject(hBrush);
		EndPaint(hwnd, &ps);
		break;
	case WM_LBUTTONDOWN:
		nmode = MM_ANISOTROPIC;
		InvalidateRect(hwnd, NULL, 1);
//鼠标左键按下，此时刷新
//InvalidateRect()是标示某个区域为无效矩形区域,如果该无效区域存在的话,系统检测到以后就会给应用程序发送WM_PAINT消息
		break;
	case WM_RBUTTONDOWN:
		nmode = MM_ISOTROPIC;
		InvalidateRect(hwnd, NULL, 1);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}
	return(0);
}
