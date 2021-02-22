
#include "App.h"

WCHAR szTitle[100] = TEXT("portfolio");
WCHAR szWindowClass[100] = TEXT("portfolio");
HINSTANCE hInst;    // 핸들인스턴스 - 프로그램
HWND hWnd;      // Window ID 식별을 위한 핸들러
HDC hDC;    // 핸들 디바이스 컨텍스트 - 윈도우 화면 출력 도구 손잡이

bool runWnd;

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,                                     // 내 프로그램
    _In_opt_ HINSTANCE hPrevInstance,                                               // 스팀 런처
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    WNDCLASSEXW wcex;                                                               // 구조체 생성
    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_HREDRAW | CS_VREDRAW;                                           // 스크롤 될때마다 ReDraw
    wcex.lpfnWndProc = WndProc;                                                     // long point function
    wcex.cbClsExtra = 0;                                                            // memset
    wcex.cbWndExtra = 0;                                                            // memset
    wcex.hInstance = hInstance;                                                     // launcher에서 호출되었음
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_PORTFOLIOGDIPLUS));        // 아이콘
    wcex.hCursor = LoadCursor(NULL, IDC_ARROW);                                     // 마우스 커서
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);                                // handler -> 1 thread
    wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_PORTFOLIOGDIPLUS);
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));
    RegisterClassExW(&wcex);                                                        // 구조체 등록

    hInst = hInstance;
    hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);
    if (hWnd == NULL)
        return FALSE;
    hDC = GetDC(hWnd);

    ULONG_PTR token = startApp(hDC);   // GDI start

    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    MSG msg;
    for (runWnd = true; runWnd; )
    {
        // GetMessage -> 메세지가 들어올때까지 기다림
        // PeekMessage -> 메세지가 들어왔는지만 체크
        if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        else
        {
            drawApp();
        }
    }

    endApp(token);  // gdi end
    return (int)msg.wParam;
}

int keys = 0;
void checkKey()
{
    printf("[");
    if (keys & keysA)
    {
        printf("A");
    }
    if (keys & keysD)
    {
        printf("D");
    }
    if (keys & keysW)
    {
        printf("W");
    }
    if (keys & keysS)
    {
        printf("S");
    }
    if (keys & keysSpace)
    {
        printf(" ");
    }
    printf("]");
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) // WndProc 프로그램 반응 처리 함수
{
    switch (message)
    {
        case WM_CREATE:         // WM - Window Message
        {
            xprintf("wm_create\n");
            int a = 0;
            int b;

            b = a;
            return 0; //break;
        }

        case WM_SIZE:
        {
            struct iPoint
            {
                float x, y;
            };

            struct iSize
            {
                float width, height;
            };

            struct iRect
            {
                iPoint origin;
                iSize size;
            };

            iSize devSize = { 640, 480 };   // 개발자 사이즈

            //int width = LOWORD(lParam);
            //int height = HIWORD(lParam);
            RECT rt;
            GetClientRect(hWnd, &rt);
            int width = rt.right - rt.left;
            int height = rt.bottom - rt.top;

            iRect viewport;
            float rx = width / devSize.width;
            float ry = height / devSize.height;

            if (rx < ry)
            {
                viewport.origin.x = 0;
                viewport.size.width = width;

                viewport.size.height = devSize.height * rx;
                viewport.origin.y = (height - viewport.size.height) / 2;
            }
            else
            {
                viewport.origin.y = 0;
                viewport.size.height = height;

                viewport.size.width = devSize.width * ry;
                viewport.origin.x = (width - viewport.size.width) / 2;
            }

            xprintf("한글devSize(%.f, %.f), real(%d, %d), rx = %f, ry = %f , viewport(%.f, %.f, %.f, %.f)\n",
                devSize.width, devSize.height,
                width, height,
                rx, ry,
                viewport.origin.x, viewport.origin.y, viewport.size.width, viewport.size.height);

            return 0; //break;
        }

        // 게임에 적절하지 않음
        //case WM_PAINT:

        case WM_KEYDOWN:
        {
            int c = wParam;
            if (c == 'a' || c == 'A')
                keys |= keysA;
            else if (c == 'd' || c == 'D')
                keys |= keysD;
            else if (c == 'w' || c == 'W')
                keys |= keysW;
            else if (c == 's' || c == 'S')
                keys |= keysS;
            else if (c == ' ')
                keys |= keysSpace;
            return 0; //break;
        }

        case WM_KEYUP:
        {
            checkKey();
            int c = wParam;
            if (c == 'a' || c == 'A')
                keys &= ~keysA;
            else if (c == 'd' || c == 'D')
                keys &= ~keysD;
            else if (c == 'w' || c == 'W')
                keys &= ~keysW;
            else if (c == 's' || c == 'S')
                keys &= ~keysS;
            else if (c == ' ')
                keys &= ~keysSpace;
            return 0; //break;
        }

        case WM_CLOSE:
        {
            const char* s0[3] = {
                "Crazy?",
                "너 못생겼어?",
                "あなた醜い?"
            };

            const char* s1[3] = {
                "Really?",
                "진짜?",
                "本物?"
            };

            int language = 2; // en:0, kr:1, jp:2

            wchar_t* ws0 = utf8_to_utf16(s0[language]);
            wchar_t* ws1 = utf8_to_utf16(s1[language]);

            //const char* s0 = "너 못생겼어?"; // utf-8 3+1+3+3+3+1
            //const char* s1 = "진짜?";
            ////MessageBox(NULL, TEXT(s0), TEXT(s1), MB_YESNO);
            //wchar_t ws0[128]; // s0 UNICODE, _UNICODE multibyte 2+2+2+2+2+2         wchar_t - unsigned short
            //wchar_t ws1[128]; //s1
            //wsprintf(ws0, TEXT("%s"), s0);

            if (MessageBox(NULL, ws1, ws0, MB_YESNO) == IDYES)
            {
                runWnd = false;
            }

            delete ws0;
            delete ws1;
            return 0; // break;
        }

        case WM_DESTROY:
        {
            PostQuitMessage(0);
            return 0; //break;
        }

    }
    return DefWindowProc(hWnd, message, wParam, lParam);
}



