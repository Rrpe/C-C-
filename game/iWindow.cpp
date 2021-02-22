#include "iWindow.h"
#include "iStd.h"

//Graphics graphics(hdc); // 정적할당
Graphics* graphics;     // 동적할당
//iFPS* fps;
ULONG_PTR startApp(HDC hdc)    // GDI Start
{
    GdiplusStartupInput gdiplusStartupInput;
    ULONG_PTR gdiplusToken;
    GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

    graphics = new Graphics(hdc);
    graphics->SetPageUnit(UnitPixel);
    //graphics->SetPageScale(1.0f);
    graphics->SetPixelOffsetMode(PixelOffsetModeHalf);
    graphics->SetTextRenderingHint(TextRenderingHintClearTypeGridFit);
    graphics->SetTextContrast(0xffffffff);
    graphics->SetCompositingMode(CompositingModeSourceOver);
    graphics->SetCompositingQuality(CompositingQualityAssumeLinear);
    graphics->SetSmoothingMode(SmoothingModeAntiAlias8x8);
    graphics->SetInterpolationMode(InterpolationModeHighQualityBicubic);
    //fps = new iFPS();

    struct AAA
    {
        const char* name;
        int score;
    };
    AAA aaa[5] = {
        {"ko", 100},
        {"en", 50},
        {"jp", 80},
        {"aa", 70},
        {"bb", 90}
    };

    struct BBB
    {
        int score;
    };
    BBB bbb[100];
    for (int i = 0; i < 100; i++)
    {
        bbb[i] = { random() % 100 };
        xprintf("%d\n", bbb[i]);
    }

    iSort s, ss, sss;
    s.init();
    ss.init();
    for (int i = 0; i < 5; i++)
    {
        s.add(aaa[i].score);
        ss.add(aaa[i].score);
    }
    


    s.update();
    ss.update2();
    for (int i = 0; i < 5; i++)
    {
        AAA* a = &aaa[s.get(i)];
        AAA* aa = &aaa[ss.get(i)];
        printf("a.name[%s] a.score[%d] aa.name[%s] aa.score[%d]\n", a->name, a->score, aa->name, aa->score);    
    }

    return gdiplusToken;
}

void endApp(ULONG_PTR token)    // GDI End
{
    delete graphics;
    //delete fps;
    GdiplusShutdown(token);
}

void drawApp()      // GDi Draw
{
    //static int n = 0;
    //n++;
    //xprintf("drawGame %d\n", n);
    
    int f = iFPS::instance()->fps();
    float dt = iFPS::instance()->update();

    //if(dt > 0.001)
    //    xprintf("dt %F, %dfps\n", dt, f);
    
    // setRGBA(0.5f, 0.5f, 0.5f, 1.0f);
    // clearRect();

    static igImage* img = createImage("assets/scene.jpeg");
    //drawImage(img, 0, 0, TOP | LEFT);

    static float degree = 0.0f;
    degree += dt;
    if (degree > 360)
    {
        degree -= 360;
    }
    drawImage(img, 0, 0, TOP | LEFT,
        0, 0, ((Image*)img)->GetWidth(), ((Image*)img)->GetHeight(),
        0.5 + 0.5 * degree/360, 1.0,
        2, degree);

    // setRGBA(1, 0, 0, 1);
    // setLineWidth(1);
    // drawLine(0, 0, 200, 100);
    // setLineWidth(2);
    // drawLine(0, 0, 200, 110);
    // 
    // setRGBA(0, 0, 1, 1);
    // setLineWidth(3);
    // drawLine(iPointMake(200, 0), iPointMake(0, 100));
    // 
    // setRGBA(1, 0, 1, 1);
    // setLineWidth(2);
    // drawRect(200, 200, 120, 120, 5);
    // 
    // fillRect(400, 400, 80, 80, 20);

    // Pen      pen(Color(127, 0, 0, 0));    // Color(a, r, g, b)
    // graphics->DrawLine(&pen, 100, 100, 100, 200);   // x축 시작, y축 시작, x축 끝, y축 끝
}

//#define CP_ENCODE CP_ACP
#define CP_ENCODE CP_UTF8 
//CP_ACP
wchar_t* utf8_to_utf16(const char* szFormat, ...)   // kr, jp, cn : 3byte -> 2byte
{
    char szText[1024];
    va_start_end(szText, szFormat);

    int length = MultiByteToWideChar(CP_ENCODE, 0, szText, -1, NULL, 0);
    wchar_t* ws = new wchar_t[length];
    MultiByteToWideChar(CP_ENCODE, 0, szText, strlen(szText) + 1, ws, length);

    return ws;
}

char* utf16_to_utf8(const wchar_t* str)
{
    int length = WideCharToMultiByte(CP_ENCODE, 0, str, lstrlenW(str), NULL, 0, NULL, NULL);
    char* s = new char[length];
    WideCharToMultiByte(CP_ENCODE, 0, str, lstrlenW(str), s, length, NULL, NULL);

    return s;
}

