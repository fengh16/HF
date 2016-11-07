#include<Windows.h>
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
	HWND hwnd;
	MSG Msg;
	WNDCLASS wndclass;
//结构WNDCLASS包含一个窗口类的全部信息，也是Windows编程中使用的基本数据结构之一，应用程序通过定义一个窗口类确定窗口的属性
//LRESULT是LONG RESULT，
//CALLBACK是回调函数，
//h 是类型描述，表示句柄(handle)， Wnd 是变量对象描述，表示窗口，所以hWnd 表示窗口句柄
//UINT类型在WINDOWS API中有定义，它对应于32位无符号整数
//WPARAM，消息响应机制，wParam和lParam 这两个是Win16系统遗留下来的产物
//窗口函数说明
int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE hPrevInst,LPSTR IpszCmdLine, int nCmdShow)
				   //hPrevInst=hPrevInstance,instance实例
{
	char IpszClassName[] = "窗口"; //窗口类名
	char IpszTitle[] = "My_Windows";  //窗口标题名
	wndclass.style = 0;  //窗口类型
	wndclass.lpfnWndProc = WndProc;  //定义窗口处理函数
	wndclass.cbClsExtra = 0;  //窗口类无扩展
	wndclass.hInstance = hinstance;  //当前实例句柄
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);  //窗口最小化图标为缺省图标
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW); //窗口采用箭头光标
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); //窗口背景为白色
	wndclass.lpszMenuName = NULL; //窗口中无菜单
	wndclass.lpszClassName = IpszClassName;
	//窗口类的注册
	if(!RegisterClass(&wndclass))  //如果窗口注册失败则发出警告
	{
		MessageBeep(0);
		return GetLastError();
	}
	hwnd = CreateWindow(IpszClassName, IpszTitle, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hinstance, NULL);
	//显示窗口
	ShowWindow(hwnd, nCmdShow);
	//绘制用户区
	UpdateWindow(hwnd);
	//消息循环
	while(GetMessage(&Msg, NULL, 0, 0))
	{
		TranslateMessage(&Msg);
		DispatchMessage(&Msg);
	}
	return Msg.wParam; //消息循环结束即程序终止时将信息返回系统
}
//窗口函数
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch(message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}
	return(0);
}
