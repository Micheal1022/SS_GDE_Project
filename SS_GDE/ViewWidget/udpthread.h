#ifndef UDPTHREAD_H
#define UDPTHREAD_H

#include <QObject>
#include <QHostAddress>

#define DATA_HEAD   0
#define DATA_LOOP   1
#define DATA_ID     2
#define DATA_TYPE   3
#define DATA_STATE  4
#define DATA_TAIL   5

#define HEAD_AA     0xAA
#define TAIL_FF     0xFF
#define DATASIZE    6

class QUdpSocket;
class UdpThread : public QObject
{
    Q_OBJECT
public:
    explicit UdpThread(QObject *parent = nullptr);
    UdpThread(QHostAddress host, quint16 port);
    ~UdpThread();
    void initConf(const QHostAddress &host, quint16 port);

private:
    QUdpSocket *m_udpSocket;

signals:
    void sigHostData(QByteArray byteArray);

private slots:
    void slotReadReady();
};

#endif // UDPTHREAD_H
