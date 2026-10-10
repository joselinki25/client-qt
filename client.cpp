#include "client.h"
#include "ui_client.h"

Client::Client(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Client)
{
    ui->setupUi(this);
    // init scoket
    clientSocket = new QTcpSocket(this);
    // asociando con el dispositivo de entrada con el socket
    in.setDevice(clientSocket);
    // conexiones entre señales y slots
    // cerrar la ventana
    connect(ui->pb_close, &QAbstractButton::clicked, this, &QWidget::close);
    // conectar con el servidor
    connect(ui->pb_request, &QAbstractButton::clicked, this, &Client::requestMessage);
    // lectura del mensaje recibido
    connect(clientSocket, &QAbstractSocket::readyRead, this, &Client::readMEssage);
}

Client::~Client()
{
    delete ui;
}

void Client::requestMessage()
{
    qDebug() << "requestMessage !!!";
    // datos del servidor
    QString ip = ui->le_ip->text();
    QString port = ui->le_port->text();
    qDebug() << "ip: " << ip << ", port: " << port;
    // conexion con el servidor
    clientSocket->connectToHost(ip, port.toInt());
}

void Client::readMEssage()
{
    // configuracion de la transaccion
    in.startTransaction();
    QString msg;
    // configuracion del objeto que recibe
    in >> msg;
    // ejecutar la transaccion o transferencia de datos
    if (!in.commitTransaction()) {
        qDebug() << "Error en el flujo de datos recibido !!!";
        return;
    }
    qDebug() << "mensaje recibido: " << msg;
    ui->lbl_message->setText(msg);
}

