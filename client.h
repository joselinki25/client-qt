#ifndef CLIENT_H
#define CLIENT_H

#include <QWidget>
#include <QTcpSocket>

QT_BEGIN_NAMESPACE
namespace Ui {
class Client;
}
QT_END_NAMESPACE

class Client : public QWidget
{
    Q_OBJECT

public:
    explicit Client(QWidget *parent = nullptr);
    ~Client() override;

private:
    Ui::Client *ui;
    // socket
    QTcpSocket *clientSocket = nullptr;
    // flujo de datos recibido
    QDataStream in;

private slots:
    // solicitar la conexion al Servidor
    void requestMessage();
    // leet el mensaje recibido
    void readMEssage();
};
#endif // CLIENT_H
