#include <QRegularExpression>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Yhdistä numerot ja handlerin
    QList<QPushButton*> numberButtons = findChildren<QPushButton*>(QRegularExpression("^N[0-9]$"));
    for (QPushButton *button : numberButtons) {
        connect(button, &QPushButton::clicked, this, &MainWindow::numberClickHandler);
    }

    // Yhdoistä operaatiot
    connect(ui->add, &QPushButton::clicked, this, &MainWindow::addSubMulDivClickHandler);
    connect(ui->sub, &QPushButton::clicked, this, &MainWindow::addSubMulDivClickHandler);
    connect(ui->mul, &QPushButton::clicked, this, &MainWindow::addSubMulDivClickHandler);
    connect(ui->div, &QPushButton::clicked, this, &MainWindow::addSubMulDivClickHandler);

    // Yhdistä clear ja enter
    connect(ui->clear, &QPushButton::clicked, this, &MainWindow::clearAndEnterClickHandler );
}

void MainWindow::numberClickHandler()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (!button) return;

    QString buttonText = button->text();

    if (operand.isEmpty()) {
        number1 += buttonText;
        ui->num1->setText(number1);
    } else {
        number2 += buttonText;
        ui->num2->setText(number2);
    }

    qDebug() << "number1:" << number1 << "number2:" << number2;
}

void MainWindow::addSubMulDivClickHandler()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (!button || number1.isEmpty()) return;

    QString op = button->text();
    operand = op; // Store operator as string
    operand = op[0].toLatin1(); // Store operator as char for calculation
}

void MainWindow::clearAndEnterClickHandler()
{
    if (sender() == ui->clear) {
        // Clear all fields
        number1.clear();
        number2.clear();
        operand.clear();
        ui->num1->clear();
        ui->num2->clear();
        ui->result->clear();
        operand = 0; // Reset operand
    } else if (sender() == ui->enter) {
        // Perform calculation when "Enter" is clicked
        if (number1.isEmpty() || number2.isEmpty() || selectedOperator.isEmpty())
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
        qDebug() << "Result:" << result;
    }
}

void MainWindow::resetLineEdits()
{
    ui->num1->clear();
    ui->num2->clear();
    ui->result->clear();
}

MainWindow::~MainWindow()  // Destruktori
{
    delete ui;
}
