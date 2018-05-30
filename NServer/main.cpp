#include <QCoreApplication>
#include "NServer.h"
#include "check.cpp"
#include "md5.h"
#include <QDebug>
#include <Winternl.h>
#include <x86intrin.h>
#include <Tlhelp32.h>
#include <windows.h>

QTextStream cin(stdin);

using namespace NChat;

#define QUANT 2048 // Читать по 2048 байт файла
#define CRCPOLY 0xEDB88320
#define CRCINIT 0xFFFFFFFF

static unsigned long t[256]; // Таблица для подсчета CRC
void CRCInit() {
    for (int i = 0; i < 0xFF; i++) {
        t[i]=i;
    for (int j = 8; j > 0; j--) // Для каждого бита
        if(t[i] & 1) t[i] = (t[i]>>1) ^ CRCPOLY;
        else
            t[i] >>= 1;
    }
}
int CRCCheckThisExe() { // Проверить целостность exe (возвращает 1, если программа была изменена)
    char FileName[MAX_PATH]; HANDLE hFile; DWORD bytesread;
    char data[QUANT], *p; unsigned long crc, x;
    GetModuleFileName(NULL, LPWCH(FileName), MAX_PATH);
    hFile = CreateFile(LPWCH(FileName), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL | FILE_FLAG_SEQUENTIAL_SCAN, NULL);
    if(hFile == INVALID_HANDLE_VALUE)  return 0;
    // Читать со смещения 40
    SetFilePointer(hFile, 0x40, NULL, FILE_BEGIN);
    CRCInit(); // Создать массив t
    crc = CRCINIT;
    for(;;) {
        ReadFile(hFile, data, QUANT, &bytesread, NULL);
        p = data;
        if(bytesread != QUANT) {
            while(bytesread--)
                crc = t[(crc ^ *p++) & 0xFF] ^ (crc >> 8);
        break; // Выйти, когда файл закончился
        }
        // Так как bytesread == QUANT, bytesread кратно 4
        bytesread /= 4;
        while(bytesread--) {
            x = *(long*)p;
            crc = t[(crc ^ x) & 0xFF] ^ (crc >> 8);
            crc = t[(crc ^ x >> 8) & 0xFF] ^ (crc >> 8);
            crc = t[(crc ^ x >> 16) & 0xFF] ^ (crc >> 8);
            crc = t[(crc ^ x >> 24) & 0xFF] ^ (crc >> 8);
            p += 4;
        }
    }
    return crc;
}

int main(int argc, char *argv[]) {
    QTime t;
    t.start();
    QCoreApplication a(argc, argv);
    a.setApplicationName(QStringLiteral("NServer"));
    int pow = CRCCheckThisExe();
    CheckForDebugger();
    NServer Server;
    quint16 p;
    qDebug() << "***Welcome to NSERVER***\n";
    qDebug() << "Enter the port: ";
    p = cin.readLine().toInt();
    int dr = CRCCheckThisExe();
    if (pow!=dr) {
        exit(-777);
    }
    else {
    qDebug() << "***\n";
    if (!Server.startServer(p)) {
        return 1;
    }
    qDebug() << "Server started...";
    return a.exec();
    }
}
