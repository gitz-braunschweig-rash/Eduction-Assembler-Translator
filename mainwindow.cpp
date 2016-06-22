#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QString lineNumbers;

    for(int i = 0; i < 128; i++)
    {
        lineNumbers += "0x" + QString::number(i,16) + "\n";
    }

    ui->text_line_numbers->setPlainText(lineNumbers);

    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(translate()));
}

QString MainWindow::translateAdd(const QString &_command)
{
    QStringList tokens = _command.split(" ");
    QString operation = tokens.first().toLower().trimmed();

    if(operation != "add")
    {
        qDebug() << "translateAdd wrong command" << _command;
    }

    QString r1 = tokens.at(1);
    QString r2 = tokens.at(2);
    QString r3 = tokens.at(3);

    qDebug() << tokens.first() << r1 << r2 << r3;
    return operationToNumber(operation) + registerToNumber(r1) + registerToNumber(r2) + registerToNumber(r3);
}

QString MainWindow::translateMul(const QString &_command)
{
    QStringList tokens = _command.split(" ");
    QString operation = tokens.first().toLower().trimmed();

    if(operation != "mul")
    {
        qDebug() << "translateMul wrong command" << _command;
    }

    QString r1 = tokens.at(1);
    QString r2 = tokens.at(2);
    QString r3 = tokens.at(3);

    qDebug() << tokens.first() << r1 << r2 << r3;
    return operationToNumber(operation) + registerToNumber(r1) + registerToNumber(r2) + registerToNumber(r3);
}

QString MainWindow::translateDiv(const QString &_command)
{
    QStringList tokens = _command.split(" ");
    QString operation = tokens.first().toLower().trimmed();

    if(operation != "div")
    {
        qDebug() << "translateDiv wrong command" << _command;
    }

    QString r1 = tokens.at(1);
    QString r2 = tokens.at(2);
    QString r3 = tokens.at(3);

    qDebug() << tokens.first() << r1 << r2 << r3;
    return operationToNumber(operation) + registerToNumber(r1) + registerToNumber(r2) + registerToNumber(r3);
}

QString MainWindow::translateLoadFixed(const QString &_command)
{
    QStringList tokens = _command.split(" ");
    QString operation = tokens.first().toLower().trimmed();

    if(operation != "load_fixed")
    {
        qDebug() << "translateLoadFixed wrong command" << _command;
    }

    QString r1 = tokens.at(1);
    QString address = tokens.at(2);

    qDebug() << tokens.first() << r1 << address;
    return operationToNumber(operation) + registerToNumber(r1) + fillHexNumbers(address);
}

QString MainWindow::translateStoreFixed(const QString &_command)
{
    QStringList tokens = _command.split(" ");
    QString operation = tokens.first().toLower().trimmed();

    if(operation != "store_fixed")
    {
        qDebug() << "translateStoreFixed wrong command" << _command;
    }

    QString r1 = tokens.at(1);
    QString address = tokens.at(2);

    qDebug() << tokens.first() << r1 << address;
    return operationToNumber(operation) + registerToNumber(r1) + fillHexNumbers(address);
}

QString MainWindow::translatePush(const QString &_command)
{
    QStringList tokens = _command.split(" ");
    QString operation = tokens.first().toLower().trimmed();

    if(operation != "push")
    {
        qDebug() << "translatePush wrong command" << _command;
    }

    QString r1 = tokens.at(1);

    qDebug() << tokens.first() << r1 << "00";
    return operationToNumber(operation) + registerToNumber(r1) + "00";

}

QString MainWindow::translatePop(const QString &_command)
{
    QStringList tokens = _command.split(" ");
    QString operation = tokens.first().toLower().trimmed();

    if(operation != "pop")
    {
        qDebug() << "translatePop wrong command" << _command;
    }

    QString r1 = tokens.at(1);

    qDebug() << tokens.first() << r1 << "00";
    return operationToNumber(operation) + registerToNumber(r1) +"00";
}

QString MainWindow::translateStackPointer(const QString &_command)
{
    QStringList tokens = _command.split(" ");
    QString operation = tokens.first().toLower().trimmed();

    if(operation != "set_stack_pointer")
    {
        qDebug() << "translatePop wrong command" << _command;
    }

    QString address = tokens.at(1);
    qDebug() << operation << address;
    return operationToNumber(operation) + fillHexNumbersUpToTree(address);
}

QString MainWindow::translateAddRegisterFirstHalf(const QString &_command)
{
    QStringList tokens = _command.split(" ");
    QString operation = tokens.first().toLower().trimmed();

    if(operation != "add_register_first_half")
    {
        qDebug() << "translateAddRegisterFirstHalf wrong command" << _command;
    }

    QString r1 = tokens.at(1);
    QString value = tokens.at(2);

    qDebug() << tokens.first() << r1 << value;
    return operationToNumber(operation) + registerToNumber(r1) + fillHexNumbers(value);
}

QString MainWindow::translateAddRegisterSecondHalf(const QString &_command)
{
    QStringList tokens = _command.split(" ");
    QString operation = tokens.first().toLower().trimmed();

    if(operation != "add_register_second_half")
    {
        qDebug() << "translateAddRegisterSecondHalf wrong command" << _command;
    }

    QString r1 = tokens.at(1);
    QString value = tokens.at(2);

    qDebug() << tokens.first() << r1 << value;
    return operationToNumber(operation) + registerToNumber(r1) + fillHexNumbers(value);
}

QString MainWindow::translateJumpFixed(const QString &_command)
{
    QStringList tokens = _command.split(" ");
    QString operation = tokens.first().toLower().trimmed();

    if(operation != "jump_fixed")
    {
        qDebug() << "translateJumpFixed wrong command" << _command;
    }

    QString address = tokens.at(1);

    qDebug() << tokens.first() << address;
    return operationToNumber(operation) + fillHexNumbersUpToTree(address);
}

QString MainWindow::translateJumpRegister(const QString &_command)
{
    QStringList tokens = _command.split(" ");
    QString operation = tokens.first().toLower().trimmed();

    if(operation != "jump_register")
    {
        qDebug() << "translateJumpRegister wrong command" << _command;
    }

    QString r1 = tokens.at(1);

    qDebug() << tokens.first() << r1 << "00";
    return operationToNumber(operation) + registerToNumber(r1) + "00";
}

QString MainWindow::translateBranchOnEqual(const QString &_command)
{
    QStringList tokens = _command.split(" ");
    QString operation = tokens.first().toLower().trimmed();

    if(operation != "branch_on_equal")
    {
        qDebug() << "translateBranchOnEqual wrong command" << _command;
    }

    QString r1 = tokens.at(1);
    QString r2 = tokens.at(2);
    QString r3 = tokens.at(3);

    qDebug() << tokens.first() << r1 << r2 << r3;
    return operationToNumber(operation) + registerToNumber(r1) + registerToNumber(r2) + registerToNumber(r3);
}

QString MainWindow::translateLoadRegister(const QString &_command)
{
    QStringList tokens = _command.split(" ");
    QString operation = tokens.first().toLower().trimmed();

    if(operation != "load_register")
    {
        qDebug() << "translateLoadRegister wrong command" << _command;
    }

    QString r1 = tokens.at(1);
    QString r2 = tokens.at(2);

    qDebug() << tokens.first() << r1 << r2 << "0";
    return operationToNumber(operation) + registerToNumber(r1) + registerToNumber(r2) + "0";
}

QString MainWindow::translateStoreRegister(const QString &_command)
{
    QStringList tokens = _command.split(" ");
    QString operation = tokens.first().toLower().trimmed();

    if(operation != "store_register")
    {
        qDebug() << "translateStoreRegister wrong command" << _command;
    }

    QString r1 = tokens.at(1);
    QString r2 = tokens.at(2);

    qDebug() << tokens.first() << r1 << r2 << "0";
    return operationToNumber(operation) + registerToNumber(r1) + registerToNumber(r2) + "0";
}


QString MainWindow::translateMinus(const QString &_command)
{
    QStringList tokens = _command.split(" ");
    QString operation = tokens.first().toLower().trimmed();

    if(operation != "sub")
    {
        qDebug() << "translateAdd wrong command" << _command;
    }

    QString r1 = tokens.at(1);
    QString r2 = tokens.at(2);
    QString r3 = tokens.at(3);

    qDebug() << tokens.first() << r1 << r2 << r3;
    return operationToNumber(operation) + registerToNumber(r1) + registerToNumber(r2) + registerToNumber(r3);
}

QString MainWindow::registerToNumber(const QString &_register)
{
    QString temp = _register;
    return temp.replace("r", "");
}

QString MainWindow::operationToNumber(const QString &_operation)
{
    if(_operation.toLower() == "add")
    {
        return "0x0";
    }
    else if(_operation.toLower() == "sub")
    {
        return "0x1";
    }
    else if(_operation.toLower() == "mul")
    {
        return "0x2";
    }
    else if(_operation.toLower() == "div")
    {
        return "0x3";
    }
    else if(_operation.toLower() == "load_fixed")
    {
        return "0x4";
    }
    else if(_operation.toLower() == "store_fixed")
    {
        return "0x5";
    }
    else if(_operation.toLower() == "add_register_first_half")
    {
        return "0x6";
    }
    else if(_operation.toLower() == "add_register_second_half")
    {
        return "0x7";
    }
    else if(_operation.toLower() == "push")
    {
        return "0x8";
    }
    else if(_operation.toLower() == "pop")
    {
        return "0x9";
    }
    else if(_operation.toLower() == "jump_fixed")
    {
        return "0xA";
    }
    else if(_operation.toLower() == "jump_register")
    {
        return "0xB";
    }
    else if(_operation.toLower() == "branch_on_equal")
    {
        return "0xC";
    }
    else if(_operation.toLower() == "set_stack_pointer")
    {
        return "0xD";
    }
    else if(_operation.toLower() == "load_register")
    {
        return "0xE";
    }
    else if(_operation.toLower() == "store_register")
    {
        return "0xF";
    }

    else
    {
        return ("error");
    }
}

QString MainWindow::fillHexNumbers(const QString &_operation)
{
    QString temp = _operation;
    if(temp.length() == 1)
    {
        temp = "0" + _operation;
    }

    return temp;
}

QString MainWindow::fillHexNumbersUpToTree(const QString &_operation)
{
    QString temp = fillHexNumbers(_operation);
    if(temp.length() == 2)
    {
        temp = "0" + _operation;
    }
    return temp;
}

void MainWindow::translate()
{
    QString no_commata = ui->text_assembler->toPlainText();
    no_commata.replace(", ", " ");
    no_commata.replace(",", " ");
    ui->text_assembler->setPlainText(no_commata);


    QStringList commands = ui->text_assembler->toPlainText().split("\n");

    QString binaryResult;

    for(int i = 0; i < commands.size(); i++)
    {
        QString command = commands.at(i).split("#").first();
        QString operation = command.split(" ").first();

        if(operation.toLower() == "add")
        {
            binaryResult += translateAdd(command) + "\n";
        }
        else if(operation.toLower() == "mul")
        {
            binaryResult += translateMul(command) + "\n";
        }
        else if(operation.toLower() == "sub")
        {
            binaryResult += translateMinus(command) + "\n";
        }
        else if(operation.toLower() == "div")
        {
            binaryResult += translateDiv(command) + "\n";
        }
        else if(operation.toLower() == "load_fixed")
        {
            binaryResult += translateLoadFixed(command) + "\n";
        }
        else if(operation.toLower() == "store_fixed")
        {
            binaryResult += translateStoreFixed(command) + "\n";
        }
        else if(operation.toLower() == "add_register_first_half")
        {
            binaryResult += translateAddRegisterFirstHalf(command) + "\n";
        }
        else if(operation.toLower() == "add_register_second_half")
        {
            binaryResult += translateAddRegisterSecondHalf(command) + "\n";
        }
        else if(operation.toLower() == "push")
        {
            binaryResult += translatePush(command) + "\n";
        }
        else if(operation.toLower() == "pop")
        {
            binaryResult += translatePop(command) + "\n";
        }
        else if(operation.toLower() == "jump_fixed")
        {
            binaryResult += translateJumpFixed(command) + "\n";
        }
        else if(operation.toLower() == "jump_register")
        {
            binaryResult += translateJumpRegister(command) + "\n";
        }
        else if(operation.toLower() == "branch_on_equal")
        {
            binaryResult += translateBranchOnEqual(command) + "\n";
        }
        else if(operation.toLower() == "set_stack_pointer")
        {
            binaryResult += translateStackPointer(command) + "\n";
        }
        else if(operation.toLower() == "load_register")
        {
            binaryResult += translateLoadRegister(command) + "\n";
        }
        else if(operation.toLower() == "store_register")
        {
            binaryResult += translateStoreRegister(command) + "\n";
        }
        else if(operation.toLower() == "nop")
        {
            binaryResult += "0x6000\n";
        }

        qDebug() << binaryResult;
    }

    ui->text_binary->setPlainText(binaryResult);
}

MainWindow::~MainWindow()
{
    delete ui;
}
