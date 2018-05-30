#include "NSocket.h"

namespace NChat {
    NSocket::NSocket(qintptr handle, QObject *parent)
        : QTcpSocket(parent) {
        setSocketDescriptor(handle);
        connect(this, &NSocket::readyRead, [&]() {
            emit NReadyRead(this);
        });
        connect(this, &NSocket::stateChanged, [&](int S) {
            emit NStateChanged(this, S);
        });
    }
} // NChat
