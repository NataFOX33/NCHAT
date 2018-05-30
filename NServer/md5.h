#ifndef MD5_H
#define MD5_H

#include <QtGlobal>
#include <QByteArray>
#include <QFile>
#include <QCryptographicHash>
#include <QString>

#ifndef PROTOTYPES
#define PROTOTYPES 0
#endif

typedef unsigned char *POINTER;

#if PROTOTYPES
#define PROTO_LIST(list) list
#else
#define PROTO_LIST(list) ()
#endif

class QString;

class MD5
{
public:
    MD5();
    ~MD5();
    MD5 & update(const QString &);
    MD5 & update(uchar *input, uint len);
    const QString final(void);
    QString checkMdsum (QString f);
private:
    bool isFinalized;
    uchar digest[16];
    struct MD5_CTX{
        quint32 state[4];
        quint32 count[2];
        unsigned char buffer[64];
    } context;
    void transform(quint32 state[4], uchar block[64]);
    void encode(uchar *output, quint32 *input, uint len);
    void decode(quint32 *output, uchar *input, uint len);
    void memcpy(POINTER output, POINTER input, uint len);
    void memset(POINTER output, int value, uint len);

};

#endif // MD5_H
