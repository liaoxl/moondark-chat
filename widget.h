#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QUdpSocket>
#include <QTextFormat>
#include "tcpclient.h"
#include "tcpserver.h"

namespace Ui {
class Widget;
}

class TcpServer;

enum MessageType{Message, NewParticipant, ParticipantLeft, FileName, Refuse};


class Widget : public QWidget
{
    Q_OBJECT
    
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

protected:
    void newParticipant(QString userName, QString localHostName, QString ipAddress);
    void participantLeft(QString userName, QString localHostName, QString time);
    void sendMessage(MessageType type, QString serverAddress="");

    void hasPendingFile(QString userName, QString serverAddress, QString clientAddress, QString fileName);

    QString getIP();
    QString getUserName();
    QString getMessage();

    void closeEvent(QCloseEvent *);
    
private:
    Ui::Widget *ui;
    QUdpSocket *udpSocket;
    qint16 port;
    QString fileName;
    TcpServer *server;
    QColor color;

private slots:
    void processPendingDatagrams();
    void getFileName(QString);
    void currentFormatChanged(const QTextCharFormat &format);

    void on_sendButton_clicked();
    void on_sendToolBtn_clicked();
    void on_fontComboBox_currentFontChanged(const QFont &f);
    void on_sizeComboBox_currentIndexChanged(const QString &arg1);
    void on_boldToolBtn_clicked(bool checked);
    void on_italicToolBtn_clicked(bool checked);
    void on_underlineToolBtn_clicked(bool checked);
    void on_colorToolBtn_clicked();
    void on_clearToolBtn_clicked();
    void on_exitButton_clicked();
};

#endif // WIDGET_H
