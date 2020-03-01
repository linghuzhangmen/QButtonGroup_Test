#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_buttonGroup = new QButtonGroup();
    m_buttonGroup->addButton (ui->btn1, 0);
    m_buttonGroup->addButton (ui->btn2, 1);
    m_buttonGroup->addButton (ui->btn3, 2);
    m_buttonGroup->addButton (ui->btn4, 3);
    m_buttonGroup->setExclusive(true);

    //按钮组信号槽
    connect (m_buttonGroup, SIGNAL (buttonClicked(int)), this, SLOT(onBtnFunc(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onBtnFunc(int n)
{
    quint16 a = m_buttonGroup->checkedId();
    ui->lineEdit->setText("btn" + QString::number(n) + " clicked");
}


