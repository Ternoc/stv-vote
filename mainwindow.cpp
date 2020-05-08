#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	ui->propositionEditor->setMainWindow(*this);
	ui->voteEditor->setMainWindow(*this);
	
	//on affiche uniquement proposition editor
	ui->voteEditor->hide();
	ui->resultsViewer->hide();
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::setCandidateList(std::vector<std::string> candidateList)
{
	ui->voteEditor->setInitialCandidateList(candidateList);
	ui->resultsViewer->setInitialCandidates(candidateList);
	
	//on cache proposition editor et on affiche vote editor
	ui->propositionEditor->hide();
	ui->voteEditor->show();
}

void MainWindow::addVoteResult(VoteResult voteResult)
{
	ui->resultsViewer->addVoteResult(voteResult);
	ui->voteEditor->addElectorName(voteResult.electorName);
}

void MainWindow::showResults()
{
	ui->voteEditor->hide();
	ui->resultsViewer->show();
	ui->resultsViewer->computeResults();
}

