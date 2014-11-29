#include "client.h"
#include <QtGui>
#include <QApplication>


int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	//QTMainForm pMainForm;
	QTMainForm progclient;
	progclient.show();
	return app.exec();
}