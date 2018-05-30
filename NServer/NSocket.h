#ifndef NSOCKET_H
#define NSOCKET_H

#include <QTcpSocket>

namespace NChat {
    class NSocket : public QTcpSocket {
        Q_OBJECT
    public:
        NSocket(qintptr handle, QObject *parent = nullptr);
    signals:
        void NReadyRead(NSocket *);
        void NStateChanged(NSocket *, int);
    };
} // NChat
#endif // NSOCKET_H
