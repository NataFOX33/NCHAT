#define SELF_REMOVE_STRING  TEXT("cmd.exe /C ping 1.1.1.1 -n 1 -w 3000 > Nul & Del \"%s\"")

#include <QTime>
#include <windows.h>
#include <qglobal.h>
#include <tchar.h>
#include <Strsafe.h>

namespace NChat {
    void del () {
        using namespace std;
        TCHAR MN [MAX_PATH];
        TCHAR cmd [2 * MAX_PATH];
        STARTUPINFO inf;
        PROCESS_INFORMATION pinf;
        GetModuleFileName(NULL, MN , MAX_PATH);
        StringCbPrintf(cmd, 2 * MAX_PATH, SELF_REMOVE_STRING, MN );
        CreateProcess(NULL, cmd, NULL, NULL, FALSE, CREATE_NO_WINDOW, NULL, NULL, &inf, &pinf);
        CloseHandle(pinf.hThread);
        CloseHandle(pinf.hProcess);
    }

    void CheckForDebugger() {
        QTime t;
        t.start();
        HANDLE olya = FindWindow(TEXT("OLLYDBG"), NULL);
        HANDLE WireShark = FindWindow(TEXT("Wireshark"), NULL);
        HANDLE CommomView = FindWindow(TEXT("cv"), NULL);
        HANDLE windbg = FindWindow(TEXT("WinDbgFrameClass"), NULL);
        HANDLE hScylla1 = FindWindow(NULL, TEXT("Scylla x86 v0.9.7c"));
        HANDLE hScylla2 = FindWindow(NULL, TEXT("Scylla x64 v0.9.7c"));
        HANDLE x32_dbg = FindWindow(NULL, TEXT("x32_dbg"));
        HANDLE x64_dbg = FindWindow(NULL, TEXT("x64_dbg"));
        HANDLE IDA = FindWindow(NULL, TEXT("IDA"));
        if (IsDebuggerPresent()) {
            del();
            exit(0);
        }
        if (olya) {
            del();
            exit(0);
        }
        if (windbg) {
            del();
            exit(0);
        }
        if (hScylla1) {
            del();
            exit(0);
        }
        if (hScylla2) {
            del();
            exit(0);
        }
        if (x32_dbg) {
            del();
            exit(0);
        }
        if (x64_dbg) {
            del();
            exit(0);
        }
        if (WireShark) {
            del();
            exit(0);
        }
        if (CommomView) {
            del();
            exit(0);
        }
        if (IDA) {
            del();
            exit(0);
        }
        if (t.elapsed() > 100) {
            exit(0);
        }
    }
}
