#include "client.h"


QTMainForm::QTMainForm(QWidget* parent)
{
	
	seriplbl.setText("Server IP");
	dataplbl.setText("Data Port");
	commplbl.setText("Comman Port");
	
	drivelbl.setText("select drive");
	uploadbtn.setText("Upload");
	connbtn.setText("Connect");
	connect(&uploadbtn, SIGNAL(clicked()), this, SLOT(findfile()));

	//vboxMainLayout.addWidget(&textBox);
	glout.addWidget(&seriplbl);
	glout.addWidget(&serverip);
	glout.addWidget(&commplbl);
	glout.addWidget(&commport);
	glout.addWidget(&dataplbl);
	glout.addWidget(&dataport);
	glout.addWidget(&connbtn);
	vboxMainLayout.addWidget(&drivelbl);
	vboxMainLayout.addWidget(&drivelist);
	vboxMainLayout.addWidget(&uploadbtn);
	vboxMainLayout.addWidget(&pgbar);
	vboxMainLayout.addWidget(&errorlbl);
	//vboxMainLayout.addWidget(&pgbar);
	
	hboxMainLayout.addLayout(&vboxMainLayout);
	hboxMainLayout.addLayout(&glout);
	//hboxMainLayout.addLayout(&hlout);
	setLayout(&hboxMainLayout);
	combobox();
}


void QTMainForm::combobox()
{
	//char buffer[1024]; 
	DWORD drives = GetLogicalDrives();
	int i;

	
     for (i=1; i<26; i++)
     {
        if( ( drives & (  1<< i ) ) )
        {
			
           char driveName[] = { L'A' + i, L':', L'\\', L'\0'};
           //printf("\n %s",driveName);
		   drivelist.addItem(driveName);
        }
	 }
QString 	str2=drivelist.currentText();

	 
	
}

void QTMainForm::findfile()
{

	WIN32_FIND_DATA FindFileData; 
HANDLE hFind = INVALID_HANDLE_VALUE; 
char DirSpec[260]; // directory specification 
int j=1;
QString str;
strcpy (DirSpec, str.toLocal8Bit());
strncat(DirSpec, "\\*", 3);
hFind = FindFirstFile(DirSpec, &FindFileData);

     if(hFind == INVALID_HANDLE_VALUE)
     {
		 errorlbl.setText("Error: invalid path");
     }
	 else
	 {

		 errorlbl.setText(QString::fromLocal8Bit(FindFileData.cFileName));
	 
	 }
	
	// textBox.append(" "+FindFileData.cFileName);

     while(FindNextFile(hFind, &FindFileData) != 0)
     {
		  errorlbl.setText(QString::fromLocal8Bit(FindFileData.cFileName));
     
	 j++;
     }

FindClose(hFind);
errorlbl.setText(QString("%1").arg(j));
}


QTMainForm::~QTMainForm()
{ 
	//client.close();
}


