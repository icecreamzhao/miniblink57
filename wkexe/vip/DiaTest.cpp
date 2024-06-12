#include <windows.h>
#include <commdlg.h>
#include <stdio.h>

/*===============================*/
/* Initialize DOCINFO structure  */
/* ==============================*/
void InitPrintJobDoc(DOCINFO* di, const wchar_t* docname)
{
    memset(di, 0, sizeof(DOCINFO));
    /* Fill in the required members. */
    di->cbSize = sizeof(DOCINFO);
    di->lpszDocName = docname;
}

/*===============================*/
/* Drawing on the DC on Page     */
/* ==============================*/
void DrawPage(HDC hdc, UINT Page)
{
    wchar_t line[150];
    int nWidth, nHeight;

    int offsetX = ::GetDeviceCaps(hdc, PHYSICALOFFSETX);
    int offsetY = ::GetDeviceCaps(hdc, PHYSICALOFFSETY);
    int dpiX = ::GetDeviceCaps(hdc, LOGPIXELSX);
    int dpiY = ::GetDeviceCaps(hdc, LOGPIXELSY);
    int physicalWidth = ::GetDeviceCaps(hdc, PHYSICALWIDTH);
    int physicalHeight = ::GetDeviceCaps(hdc, PHYSICALHEIGHT);

    nWidth = GetDeviceCaps(hdc, HORZRES);
    nHeight = GetDeviceCaps(hdc, VERTRES);

    SelectObject(hdc, CreatePen(PS_SOLID, 2, RGB(255, 0, 0)));
    Rectangle(hdc, 0, 0, nWidth - 4, nHeight - 2);
    wsprintf(line,
        L"Test Printing, page#%u width x height (%dx%d), (%d,%d,%d,%d)(%d,%d)",
        Page,
        nWidth, nHeight,
        offsetX, offsetY, dpiX, dpiY,
        physicalWidth, physicalHeight
        );
    SetBkMode(hdc, TRANSPARENT);
    TextOutW(hdc, 4, 4, line, lstrlen(line));
}

/*===============================*/
/* The Abort Procudure           */
/* ==============================*/
BOOL CALLBACK AbortProc(HDC hDC, int Error)
{
    MSG   msg;
    while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return TRUE;
}
/*===============================*/
/* Obtain printer device context */
/* ==============================*/
HDC GetPrinterDC(void)
{
    PRINTDLG pdlg;

    /* Initialize the PRINTDLG structure. */
    memset(&pdlg, 0, sizeof(PRINTDLG));
    pdlg.lStructSize = sizeof(PRINTDLG);
    /* Set the flag to return printer DC. */
    pdlg.Flags = PD_RETURNDC;

    /* Invoke the printer dialog box. */
    PrintDlg(&pdlg);

    /* hDC member of the PRINTDLG structure contains
    the printer DC. */
    return pdlg.hDC;
}
/*==============================================*/
/* Sample code :  Typical printing process      */
/* =============================================*/
void PrintJob(void)
{
    HDC        hDC;
    DOCINFO    di;

    /* Need a printer DC to print to. */
    hDC = GetPrinterDC();

    /* Did you get a good DC? */
    if (!hDC) {
        MessageBoxW(NULL,
            L"Error creating DC",
            L"Error",
            MB_APPLMODAL | MB_OK);
        return;
    }

    /* You always have to use an AbortProc(). */
    if (SetAbortProc(hDC, AbortProc) == SP_ERROR) {
        MessageBox(NULL,
            L"Error setting up AbortProc",
            L"Error",
            MB_APPLMODAL | MB_OK);
        return;
    }

    /* Init the DOCINFO and start the document. */
    InitPrintJobDoc(&di, L"MyDoc");
    StartDoc(hDC, &di);

    /* Print 1st page. */
    StartPage(hDC);
    DrawPage(hDC, 1);
    EndPage(hDC);

    /* Print 2nd page.  */
//     StartPage(hDC);
//     DrawPage(hDC, 2);
//     EndPage(hDC);

    /* Indicate end of document.*/
    EndDoc(hDC);
    /* Clean up */
    DeleteDC(hDC);
}

/* Print DC demo with 2 pages */
int winMainPrint()
{
    PrintJob();
    return 0;
}