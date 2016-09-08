#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "timelapse.h"
#include <QFileDialog>
#include <QFileInfo>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_open_button_clicked()
{
    QString filename;
    filename = QFileDialog::getOpenFileName(this,
        tr("Open Image"), "", tr("Image Files (*.png *.jpg *.bmp)"));
    QFileInfo info(filename);
    ui->directory_edit->setText(info.absolutePath()+"/*."+info.completeSuffix());
}

void MainWindow::on_convert_button_clicked()
{
    QString filename;
    QMessageBox msgBox;
    QByteArray input_ba,output_ba;
    char *input,*output;
    char fps[3],compression[3];

    filename = QFileDialog::getSaveFileName(this,
        tr("Save File"),"",tr("Video (*.avi)"));

    input_ba = ui->directory_edit->text().toLatin1();
    input = input_ba.data();

    output_ba = filename.toLatin1();
    output = output_ba.data();

    sprintf(fps,"%d",ui->fps_spinbox->value());
    sprintf(compression,"%d",ui->compression_spinbox->value());

    if(!timelapse(input,output,fps,compression))
        msgBox.setText("Conversion completed!.");
    else
        msgBox.setText("Something going wrong.");
    msgBox.exec();
}
