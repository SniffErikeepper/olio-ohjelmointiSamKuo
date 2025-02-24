#include <QRegularExpression>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Yhdistä numerot ja käsittelijä
    QList<QPushButton*> numberButtons = findChildren<QPushButton*>(QRegularExpression("^N[0-9]$"));
    for (QPushButton *button : numberButtons) {
        connect(button, &QPushButton::clicked, this, &MainWindow::numberClickHandler);
    }

    // Yhdistä operaattorit
    connect(ui->add, &QPushButton::clicked, this, &MainWindow::addSubMulDivClickHandler);
    connect(ui->sub, &QPushButton::clicked, this, &MainWindow::addSubMulDivClickHandler);
    connect(ui->mul, &QPushButton::clicked, this, &MainWindow::addSubMulDivClickHandler);
    connect(ui->div, &QPushButton::clicked, this, &MainWindow::addSubMulDivClickHandler);

    // Yhdistä tyhjennys ja enter
    connect(ui->clear, &QPushButton::clicked, this, &MainWindow::clearAndEnterClickHandler);
    connect(ui->enter, &QPushButton::clicked, this, &MainWindow::clearAndEnterClickHandler);
}

void MainWindow::numberClickHandler()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (!button) return;

    QString buttonText = button->text();

    if (operand == 0) { // Jos operaattoria ei ole valittu, lisätään numero1:een
        number1 += buttonText;
        ui->num1->setText(number1);
    } else { // Muuten lisätään numero2:een
        number2 += buttonText;
        ui->num2->setText(number2);
    }

    qDebug() << "number1:" << number1 << "number2:" << number2;
}

void MainWindow::addSubMulDivClickHandler() //Operaatioiden handlaaminen
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (!button || number1.isEmpty()) return;

    QString op = button->text();
    if (op == "+") operand = '+';
    else if (op == "-") operand = '-';
    else if (op == "*") operand = '*';
    else if (op == "/") operand = '/';
}

void MainWindow::clearAndEnterClickHandler()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());

    if (button == ui->clear) {
        // Tyhjennä kentät
        number1.clear();
        number2.clear();
        operand = 0;
        result = 0.0;
        ui->num1->clear();
        ui->num2->clear();
        ui->result->clear();
    } else if (button == ui->enter) {
        // Lasku toimitukset
        if (number1.isEmpty() || number2.isEmpty() || operand == 0)
            return;

        float num1 = number1.toFloat();
        float num2 = number2.toFloat();
        result = 0.0;

        switch (operand) {
        case '+': result = num1 + num2; break;
        case '-': result = num1 - num2; break;
        case '*': result = num1 * num2; break;
        case '/': result = (num2 != 0) ? num1 / num2 : 0; break;
        }

        ui->result->setText(QString::number(result));
        qDebug() << "Tulos:" << result;
    }
}

void MainWindow::resetLineEdits()   //Tyhjennetään UI
{
    ui->num1->clear();
    ui->num2->clear();
    ui->result->clear();
}

MainWindow::~MainWindow()
{
    delete ui;
}
