#include<Windows.h>
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
	HWND hwnd;
	MSG Msg;
	WNDCLASS wndclass;
//�ṹWNDCLASS����һ���������ȫ����Ϣ��Ҳ��Windows�����ʹ�õĻ������ݽṹ֮һ��Ӧ�ó���ͨ������һ��������ȷ�����ڵ�����
//LRESULT��LONG RESULT��
//CALLBACK�ǻص�������
//h ��������������ʾ���(handle)�� Wnd �Ǳ���������������ʾ���ڣ�����hWnd ��ʾ���ھ��
//UINT������WINDOWS API���ж��壬����Ӧ��32λ�޷�������
//WPARAM����Ϣ��Ӧ���ƣ�wParam��lParam ��������Win16ϵͳ���������Ĳ���
//���ں���˵��
int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE hPrevInst,LPSTR IpszCmdLine, int nCmdShow)
				   //hPrevInst=hPrevInstance,instanceʵ��
{
	char IpszClassName[] = "����"; //��������
	char IpszTitle[] = "My_Windows";  //���ڱ�����
	wndclass.style = 0;  //��������
	wndclass.lpfnWndProc = WndProc;  //���崰�ڴ�����
	wndclass.cbClsExtra = 0;  //����������չ
	wndclass.hInstance = hinstance;  //��ǰʵ�����
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);  //������С��ͼ��Ϊȱʡͼ��
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW); //���ڲ��ü�ͷ���
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); //���ڱ���Ϊ��ɫ
	wndclass.lpszMenuName = NULL; //�������޲˵�
	wndclass.lpszClassName = IpszClassName;
	//�������ע��
	if(!RegisterClass(&wndclass))  //�������ע��ʧ���򷢳�����
	{
		MessageBeep(0);
		return GetLastError();
	}
	hwnd = CreateWindow(IpszClassName, IpszTitle, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hinstance, NULL);
	//��ʾ����
	ShowWindow(hwnd, nCmdShow);
	//�����û���
	UpdateWindow(hwnd);
	//��Ϣѭ��
	while(GetMessage(&Msg, NULL, 0, 0))
	{
		TranslateMessage(&Msg);
		DispatchMessage(&Msg);
	}
	return Msg.wParam; //��Ϣѭ��������������ֹʱ����Ϣ����ϵͳ
}
//���ں���
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
