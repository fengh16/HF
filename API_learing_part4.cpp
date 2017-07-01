#include<Windows.h>
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HWND hwnd;
MSG Msg;
WNDCLASS wndclass;
int nmode = 0;//����һ���������ڴ��ӳ��ģʽ��ѡ��
int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE hPrevInst,LPSTR IpszCmdLine, int nCmdShow)
{
	char IpszClassName[] = "����";
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
		SetMapMode(hdc,nmode);				//����ӳ��ģʽ
/*������������:�ú�������ָ���豸������ӳ�䷽ʽ��ӳ�䷽ʽ�����˽��߼���λת��Ϊ�豸��λ�Ķ�����λ�����������豸��X��Y��ķ���
nMapMode:ָ����ӳ���ģʽ����������������һֵ��
MM_ANISOTROPIC���߼���λת���ɾ����������������ⵥλ����SetWindowExt��SetViewportExt������ָ����λ������ͱ�����
MM_HIENGLISH��ÿ���߼���λת��Ϊ0.001Ӣ�磬X�����������ң�Y�����������ϡ�
MM_HIMETRIC��ÿ���߼���λת��Ϊ0.01���ף�X���������ң�Y�����������ϡ�
MM_ISOTROPIC���߼���λת���ɾ��о��ȱ���������ⵥλ������X���һ����λ������Y���һ����λ����SetWindowExt��SetViewportExt��������ָ������ĵ�λ�ͷ���ͼ���豸���棨GDI����Ҫ���е������Ա�֤X��Y�ĵ�λ������ͬ��С�������ô��ڷ�Χʱ���ӿڽ��������Դﵽ��λ��С��ͬ����
MM_LOENGLISH��ÿ���߼���λת��Ϊ0.01Ӣ�磬X���������ң�Y���������ϡ�
MM_LOMETRIC��ÿ���߼���λת��Ϊ0.1���ף�X���������ң�Y���������ϡ�
MM_TEXT��ÿ���߼���λת��Ϊһ��ͼ�أ�X���������ң�Y���������¡�
MM_TWIPS��ÿ���߼���λת��Ϊ��ӡ���1/20����1/1440Ӣ�磩��X���������ң�Y�������ϡ�*/
		SetWindowExtEx(hdc,150,150,NULL); 	//���ô�������
		SetViewportExtEx(hdc,150,100,NULL); //�����ӿ�����
		SetViewportOrgEx(hdc,150,60,NULL); 	//�����ӿ�ԭ��
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
//���������£���ʱˢ��
//InvalidateRect()�Ǳ�ʾĳ������Ϊ��Ч��������,�������Ч������ڵĻ�,ϵͳ��⵽�Ժ�ͻ��Ӧ�ó�����WM_PAINT��Ϣ
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
