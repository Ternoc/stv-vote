#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	ui->propositionEditor->setMainWindow(*this);
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::setCandidateList(std::vector<std::string> candidateList)
{
	ui->voteEditor->setCandidateList(candidateList);
}

