#ifndef CLIENT_H
#define CLIENT_H

#include <windows.h>
#include <stdio.h>
#include <conio.h>

#include <QtGui>
#include <QApplication>
#include <QString>
#include <QComboBox>

class QTMainForm : public QWidget
{
	Q_OBJECT 

	public:
					QTMainForm(QWidget* parent=0);
					~QTMainForm();
		
		
		
	public slots:
		void	combobox();
		void	findfile();

		
private:
	
	
	
		QPushButton     uploadbtn;
		QPushButton     connbtn;
		QLabel			drivelbl;
		QLabel			seriplbl;
		QLabel			dataplbl;
		QLabel			commplbl;
		QLabel			errorlbl;
		QComboBox       drivelist; 
		QLineEdit			serverip;
		QLineEdit			commport;
		QLineEdit			dataport;
		QProgressBar		pgbar;
	QHBoxLayout         hboxMainLayout;

	QVBoxLayout         vboxMainLayout;
	QVBoxLayout         glout;



		
		
};

#endif