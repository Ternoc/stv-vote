#include "mainwindow.h"
#include "ui/propositionseditor.h"

#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow w;
	PropositionsEditor b(w);
	b.show();
	w.show();
	return a.exec();
}
