#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QString number1, number2;
    short operand;  // operandi
    int state;     // Katsotaan mikä numero annetaan
    float result;   //tulos

    void numberClickHandler(); //Numerot
    void addSubMulDivClickHandler(); //Operaatiot
    void clearAndEnterClickHandler(); //clear ja enter
    void resetLineEdits();  //Resetataan kaikki line editit
};

#endif // MAINWINDOW_H
