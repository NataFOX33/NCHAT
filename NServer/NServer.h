#ifndef NSERVER_H
#define NSERVER_H

#include <QTextStream>
#include <QDebug>
#include <QFile>
#include <QDateTime>
#include <QTime>
#include <qt_windows.h>
#include <stdio.h>
#include <QTcpServer>


#define GET_VARIABLE_NAME(Variable) (#Variable)

namespace NChat {
    class NSocket;
    class NServer : public QTcpServer {
    public:
        NServer(QObject *parent = nullptr);
        bool startServer(quint16 port);
    protected:
        void incomingConnection(qintptr handle);
    private:
        QList<NSocket *> nsSockets;
        QString cc2 = "e";
        int hihih = 52;
        QString hash = "76D2DC3CAF8E3F9FBF81848811FE25A1";
    };
} //NChat
#endif // NSERVER_H
