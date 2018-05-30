#include "NServer.h"
#include "md5.cpp"
#include "NSocket.h"

#define GET_VARIABLE_NAME(Variable) (#Variable)

namespace NChat {

    void next() {
        CONTEXT ctx;
        ctx.ContextFlags = CONTEXT_DEBUG_REGISTERS;
        GetThreadContext(GetCurrentThread(), &ctx);
        if (ctx.Dr0 != 0 || ctx.Dr1 != 0 || ctx.Dr2 != 0 || ctx.Dr3 != 0) {
            exit(-1);
        }
        else
            return;
    }

    NServer::NServer(QObject *parent)
        : QTcpServer(parent)
    {

    }

    bool NServer::startServer(quint16 port){
        QTime r;
        r.start();
        bool check = IsDebuggerPresent();
        next();
        if (check) {
            exit(0);
        }
        else {
            cc2 = cc2.append(QString::number(hihih)).append(QString(GET_VARIABLE_NAME(cc2)));
            QString v = "";
            QString a = v;
            QString s = GET_VARIABLE_NAME(n);
            QString o = GET_VARIABLE_NAME(r);
            QString p = GET_VARIABLE_NAME(v);
            QByteArray w;
            QByteArray line;
            QString b = "";
            QString d = "CDEFGHIJK";
            int a5df = 16692;
            next();
            a = a.append(s.toUpper()); //N
            cc2 = cc2.append(QString::number(a5df/hihih)).append(QString::number(hihih+d.length()+2));
            cc2 = cc2.append(QString(GET_VARIABLE_NAME(a5df))).append(QString(GET_VARIABLE_NAME(d))).append(QString::number(hihih+21));
            b = cc2;
            b = b.append(QString(GET_VARIABLE_NAME(b))).append(QString::number(hihih+5)).append(QString(GET_VARIABLE_NAME(d)));
            b = b.append(QString::number(d.length()*10+1)).append(QString(GET_VARIABLE_NAME(a))).append(QString(GET_VARIABLE_NAME(d)));
            b = b.append("cf").append(QString(GET_VARIABLE_NAME(d))).append("e").append(QString::number((d.length()*10+1)-10));
            a = a.append(QString(GET_VARIABLE_NAME(s)).toUpper()); //S
            a = a.append(d[2]); //E
            a = a.append(o.toUpper()); //R
            a = a.append(p.toUpper()); //V
            a = a.append(d[2]); //E
            a = a.append(o.toUpper()); //R
            a = a.append(QString(GET_VARIABLE_NAME(p)).toUpper()); //P
            a = a.append(QString(GET_VARIABLE_NAME(a)).toUpper()); //А
            a = a.append(QString(GET_VARIABLE_NAME(s)).toUpper()).append(QString(GET_VARIABLE_NAME(s)).toUpper()); //SS
            a = a.append(QString(GET_VARIABLE_NAME(w)).toUpper()); //W
            a = a.append(QString(GET_VARIABLE_NAME(o)).toUpper()); //O
            a = a.append(o.toUpper()); //R
            a = a.append(QString(GET_VARIABLE_NAME(d)).toUpper()); //D
            for (int i=0; i<d.length(); i++){
                next();
                v = d[i] + ":\\License";
                QFile file(v);
                if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
                    file.close();
                }
                else {
                    while (!file.atEnd()) {
                        line = file.read(1024);
                        w.append(line);
                    }

                    if ((r.elapsed() < 500)) {
                        if (QString(w) == a) {
                            if (checkMdsum(v)==b) {
                                qDebug()<< "Hello, admin!";
                                qDebug()<< "License accepted!";
                                return listen(QHostAddress::Any, port);
                            }
                            else {
                                qDebug()<< "Authorization failed!";
                                break;
                                exit(-1);
                            }
                        }
                        else {
                            qDebug()<< "Authorization failed!";
                            break;
                            exit(-1);
                        }
                    }
                    else {
                        exit(0);
                    }
                }
            }
        }
        return false;
    }

    void NServer::incomingConnection(qintptr handle) {
        next();
        QDateTime date = QDateTime::currentDateTime();
        qDebug() << "Client connected with handle:" << handle;
        auto socket = new NSocket(handle, this);
        nsSockets << socket;
        for (auto i: nsSockets) {
            QTextStream T(i);
            T << "Server: connection at " << date.toString("HH:mm:ss dd.MM.yyyy");
            i->flush();
        }

        connect(socket, &NSocket::NReadyRead, [&](NSocket *S) {
            qDebug() << "Ready Read...";
            QTextStream T(S);
            auto text = T.readAll();
            for (auto i : nsSockets) {
                QTextStream K(i);
                K << text;
                i->flush();
            }
        });

        connect(socket, &NSocket::NStateChanged, [&](NSocket *S, int ST) {
            if (ST == QTcpSocket::UnconnectedState){
                nsSockets.removeOne(S);
                for (auto i : nsSockets) {
                    QTextStream K(i);
                    K << "Client is off!";
                    i->flush();
                }
            }
        });
    }
} // NChat
