#include <windows.h> // заголовочный файл, содержащий функции API

LRESULT CALLBACK WndProc(HWND hWnd, // дескриптор окошка
                         UINT uMsg, // сообщение, посылаемое ОС
                         WPARAM wParam, // параметры
                         LPARAM lParam); // сообщений, для последующего обращения
WCHAR mainMessage[] = L"Какой-то текст!"; 
// Основная функция - аналог int main() в консольном приложении:
int WINAPI WinMain(HINSTANCE hInstance, // дескриптор экземпляра приложения
                   HINSTANCE hPrevInstance, // в Win32 не используется
                   LPSTR lpCmdLine, // нужен для запуска окна в режиме командной строки
                   int nCmdShow) // режим отображения окна
{
    // создаём дескриптор окна
    WCHAR szClassName[] = L"Мой класс"; // строка с именем класса
    HWND hMainWnd;
    MSG msg;
    // описываем класс окна
    WNDCLASSEXW wc;
    wc.cbSize = sizeof(wc);
    wc.style = CS_HREDRAW|CS_VREDRAW;
    wc.lpfnWndProc = WndProc;
    wc.lpszMenuName = NULL;
    wc.lpszClassName = szClassName;
    wc.hInstance = hInstance;
    // создаём окошко, показываем его на экране
    hMainWnd = CreateWindowExW(WS_EX_APPWINDOW, wc.lpszClassName, // имя класса
                    L"Полноценная оконная процедура", // имя окна (то что сверху)
                    WS_OVERLAPPEDWINDOW | WS_VSCROLL, // режимы отображения окошка
                    CW_USEDEFAULT, // положение окна по оси х (по умолчанию)
                    NULL, // позиция окна по оси у (раз дефолт в х, то писать не нужно)
                    CW_USEDEFAULT, // ширина окошка (по умолчанию)
                    NULL, // высота окна (раз дефолт в ширине, то писать не нужно)
                    (HWND)NULL, // дескриптор родительского окошка (у нас нет род. окон)
                    NULL, // дескриптор меню (у нас его нет)
                    HINSTANCE(hInstance), // .... экземпляра приложения
                    NULL); // ничего не передаём из WndProc
    if(!hMainWnd)
    {
        // в случае некорректного создания окна (неверные параметры и тп):
        MessageBoxW(NULL, L"Ошибка",  L"Не получилось создать окно!", MB_OK);
        return NULL; // выходим из приложения
    }
    ShowWindow(hMainWnd, nCmdShow);
    UpdateWindow(hMainWnd);
    // возвращаем значение при неудаче или при выходе
    while(GetMessageW(&msg, NULL, NULL, NULL)){ // извлекаем сообщения из очереди, посылаемые фу-циями, ОС
        TranslateMessage(&msg); // интерпретируем сообщения
        DispatchMessageW(&msg); // передаём сообщения обратно ОС
    }
    return msg.wParam; // возвращаем код выхода из приложения
}

LRESULT CALLBACK WndProc(HWND hWnd, // дескриптор окошка
                         UINT uMsg, // сообщение, посылаемое ОС
                         WPARAM wParam, // параметры
                         LPARAM lParam) // сообщений, для последующего обращения
{
       // 1) создаём нужные переменные
    HDC hDC;
    PAINTSTRUCT ps;
    RECT rect;
       // 2) расписываем условия, при которых нужно выполнить нужное действие (switch)
    COLORREF colorText = RGB(255, 0, 0);
    switch(uMsg)
    {
        case WM_PAINT:
         //something paint
            hDC = BeginPaint(hWnd, &ps); // инициализируем контекст устройства
            GetClientRect(hWnd, &rect); // получаем ширину и высоту области для рисования
            //SetTextColor(hDC, colorText); // устанавливаем цвет контекстного устройства
            DrawTextW(hDC, mainMessage, -1, &rect, DT_SINGLELINE|DT_CENTER|DT_VCENTER); // рисуем текст
            EndPaint(hWnd, &ps); // заканчиваем рисовать
            break;    
        case WM_DESTROY:
         //switch close window
            PostQuitMessage(NULL);
            break;
        default:
            return DefWindowProcW(hWnd, uMsg, wParam, lParam); //
    }
       // 3) Возвращаем значение функции
    return NULL;
} 