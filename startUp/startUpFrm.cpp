/*=============================
	系统检测界面
=============================*/

#include "startUpFrm.h"
#include <QWidget>
#include <QMovie>
#include <QLabel>

StartUp::StartUp(QWidget *parent): QWidget(parent),Ui_startUpFrm()
{
	setupUi(this);
        //setWindowFlags(Qt::FramelessWindowHint);//窗口没有没有边
	connect(&timer,SIGNAL(timeout()),this,SLOT(slot_timer()));//显示系统时间
	setAttribute(Qt::WA_DeleteOnClose);
    //Print::init();
	timer.start(200);
    show();
	myFlag = 0;

//    QMovie*movie=new QMovie(":/img/images/gif.gif");//("url(:/img/images/gif.gif)");//:/display/Resources/loading.gif
//    main_gif->setMovie(movie);
//    movie->start();
	printf("init StartUp ok\n");
}
StartUp::~StartUp()
{
	delete main;
	printf("exit StartUp\n");
}
void StartUp::slot_timer()
{
	timer.stop();
	main = new Main(progressBar);
	if (myFlag == 0) {
        //connect(this, SIGNAL(startupClear()), main, SLOT(clearScreenCount()));
		myFlag = 1;
	}
	hide();
}

void StartUp::emitClear()
{
        emit startupClear();
}

