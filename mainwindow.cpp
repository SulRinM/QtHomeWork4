#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->gb_radio_buttons->setTitle("Value");
    ui->rb_upper->setText("Value + 10");
    ui->rb_lower->setText("Value + 20");
    ui->pb_button->setText("Add");

    ui->rb_upper->setChecked(true);
    ui->pb_button->setCheckable(true);
    ui->prbr_bar->setMinimum(0);
    ui->prbr_bar->setMaximum(10);
    ui->prbr_bar->setValue(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_button_clicked()
{
    if(ui->rb_upper->isChecked()) {
        int tmp = ui->prbr_bar->value() + (ui->prbr_bar->maximum() - ui->prbr_bar->minimum()) / 10;
        if(tmp <= ui->prbr_bar->maximum())
            ui->prbr_bar->setValue(tmp);
        else
            ui->prbr_bar->setValue(0);
    } else {
        int tmp = ui->prbr_bar->value() + (ui->prbr_bar->maximum() - ui->prbr_bar->minimum()) / 5;
        if(tmp <= ui->prbr_bar->maximum())
            ui->prbr_bar->setValue(tmp);
        else
            ui->prbr_bar->setValue(0);
    }
}

