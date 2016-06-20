#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    QString translateAdd(const QString& _command);
    QString translateMul(const QString &_command);
    QString translateDiv(const QString &_command);
    QString translateMinus(const QString &_command);

    QString translateLoadFixed(const QString &_command);
    QString translateStoreFixed(const QString &_command);

    QString translatePush(const QString &_command);
    QString translatePop(const QString &_command);

    QString translateAddRegisterFirstHalf(const QString &_command);
    QString translateAddRegisterSecondHalf(const QString &_command);

    QString translateJumpFixed(const QString &_command);
    QString translateJumpRegister(const QString &_command);
    QString translateBranchOnEqual(const QString &_command);

    QString translateLoadRegister(const QString &_command);
    QString translateStoreRegister(const QString &_command);

    QString registerToNumber(const QString &_register);
    QString operationToNumber(const QString &_operation);

    ~MainWindow();

public slots:
    void translate();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
