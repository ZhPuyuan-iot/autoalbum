#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{

    ui->setupUi(this);

    just = cursor().pos();
    i = 0;
    k = 0;
    is = false;
    //Mountusb();
    openfile();

    timer = new QTimer(this);
    connect( timer, SIGNAL(timeout()), this, SLOT(PictureShow()) );

    timer_play = new QTimer(this);
    connect( timer_play, SIGNAL(timeout()), this, SLOT(disappear()) );

    point = new QTimer(this);
    connect( point, SIGNAL(timeout()), this, SLOT(btnshow()) );

    ui->pushButton_play->click();
}

Widget::~Widget()
{
    delete ui;
}

void Widget :: PictureShow()
{

    //Mountusb();
    int width = QApplication::desktop()->width();
    int height = QApplication::desktop()->height();
    //QStringList list = QFileDialog::getOpenFileNames(this, tr("添加图片"),"","*.jpg *.jpeg *.gif *.png *.bmp");

    pix.load(imageList[i]);
    if(i<k){i++;}
    if(i>=k){i=0;}
    //if(imageList[i].isNull())
    QDir dt("/udisk");
    /*
    QStringList nofilter;
    nofilter<<QString("*.jpeg")<<QString("*.jpg")<<QString("*.png")<<QString("*.gif")<<QString("*.bmp");
    dt.setNameFilters(nofilter);
    QFileInfoList li = dt.entryInfoList();
    if(li.empty())
    */
    if(!dt.exists())
    {
        ui->label->setText("NOTHING TO SHOW");
        ui->label->show();
    }
    else
    {
    ui->label->setGeometry(0,0,width,height);
    pix = pix.scaled(width,height,Qt::KeepAspectRatio);
    ui->label->setPixmap(pix);
    ui->label->setAlignment(Qt::AlignCenter);
    //ui->label->setScaledContents(true);
    ui->label->show();
    }
}
void Widget :: disappear()
{

    //ui->pushButton->setVisible(false);
    ui->pushButton_play->setVisible(false);
    ui->pushButton->setVisible(false);
    ui->pushButton_2->setVisible(false);
}

void Widget :: btnshow()
{
    now = cursor().pos();
    if(now != just)
    {
        just = now;
        //ui->pushButton->setVisible(true);
        ui->pushButton_play->setVisible(true);
        ui->pushButton->setVisible(true);
        ui->pushButton_2->setVisible(true);
    }
}

void Widget::openfile()
{
    QDir dir("/udisk");

    QStringList filters;
    filters<<QString("*.jpeg")<<QString("*.jpg")<<QString("*.png")<<QString("*.gif")<<QString("*.bmp");
    dir.setNameFilters(filters);

    QFileInfoList list = dir.entryInfoList();
    QStringList name;
    QFileInfo fileInfo;

    for (int i = 0; i < list.count(); i++)
    {

        fileInfo = list.at(i);

        QString path = fileInfo.absoluteFilePath();

        name.append(path);

    }
    for (it = name.begin(); it < name.end();it++)
    {

        imageList[k] = *it;
        k++;
    }

}

void Widget::on_pushButton_play_clicked()
{

    if(is == false)
    {
        ui->pushButton_play->setText("stop");
        timer->start(2000);
        timer_play->start(3000);
    }
    if(is == true)
    {
        ui->pushButton_play->setText("play");
        timer->stop();
    }
    point->start(500);
    is = !is;
}


void Widget::on_pushButton_clicked()
{
    timer->stop();
    ui->pushButton_play->setText("play");
    i++;
    if(i>k-1){i=0;}
    int width = QApplication::desktop()->width();
    int height = QApplication::desktop()->height();

    pix.load(imageList[i]);
    QDir dt("/udisk");
    if(!dt.exists())
    {
        ui->label->setText("NOTHING TO SHOW");
        ui->label->show();
    }
    else
    {
    ui->label->setGeometry(0,0,width,height);
    pix = pix.scaled(width,height,Qt::KeepAspectRatio);
    ui->label->setPixmap(pix);
    ui->label->setAlignment(Qt::AlignCenter);
    //ui->label->setScaledContents(true);
    ui->label->show();
    }
}

void Widget::on_pushButton_2_clicked()
{
    timer->stop();
    ui->pushButton_play->setText("play");
    i--;
    if(i<0){i=k-1;}

    int width = QApplication::desktop()->width();
    int height = QApplication::desktop()->height();
    //QStringList list = QFileDialog::getOpenFileNames(this, tr("添加图片"),"","*.jpg *.jpeg *.gif *.png *.bmp");

    pix.load(imageList[i]);

    QDir dt("/udisk");
    if(!dt.exists())
    {
        ui->label->setText("NOTHING TO SHOW");
        ui->label->show();
    }
    else
    {
    ui->label->setGeometry(0,0,width,height);
    pix = pix.scaled(width,height,Qt::KeepAspectRatio);
    ui->label->setPixmap(pix);
    ui->label->setAlignment(Qt::AlignCenter);
    //ui->label->setScaledContents(true);
    ui->label->show();
    }
}

/*
void Widget :: Mountusb()
{
    QProcess::execute("mount -t vfat /dev/sda4 /mnt/usb");
    QProcess::execute("mount -t vfat /dev/sdb4 /mnt/usb");
    QProcess::execute("mount -t vfat /dev/sdc4 /mnt/usb");
    QProcess::execute("mount -t vfat /dev/sdd4 /mnt/usb");
    QProcess::execute("mount -t vfat /dev/sde4 /mnt/usb");
    QProcess::execute("mount -t vfat /dev/sdf4 /mnt/usb");
}
*/
