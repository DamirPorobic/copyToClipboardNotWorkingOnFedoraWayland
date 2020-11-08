#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , mClipboard(QGuiApplication::clipboard())
{
    ui->setupUi(this);

    connect(mClipboard, &QClipboard::changed, [this](){
        auto pixmap = mClipboard->pixmap();
        if(!pixmap.isNull()){
            this->ui->resultLabel->setPixmap(pixmap);
        } else {
            this->ui->resultLabel->setText(mClipboard->text());
        }
    });

    connect(ui->copyImage, &QPushButton::clicked, [this](){
        QPixmap pixmap(200,200);
        pixmap.fill(QColor("red"));
        mClipboard->setImage(pixmap.toImage());
    });

    connect(ui->copyText, &QPushButton::clicked, [this](){
        mClipboard->setText("This text was added to the clipboard");
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

