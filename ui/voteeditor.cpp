#include "voteeditor.h"
#include "ui_voteeditor.h"
#include "mainwindow.h"
#include "model/voteresult.h"

VoteEditor::VoteEditor(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::VoteEditor)
{
	ui->setupUi(this);
}

VoteEditor::~VoteEditor()
{
	delete ui;
}

void VoteEditor::setInitialCandidateList(std::vector<std::string> candidateList)
{
	initialCandidateList_ = candidateList;
	setCandidateList(initialCandidateList_);
}

void VoteEditor::setCandidateList(std::vector<std::string> candidateList)
{
	ui->candidateList->clear();
	for (const auto& candidate : candidateList){
		ui->candidateList->addItem(candidate.c_str());
	}
}

void VoteEditor::setMainWindow(MainWindow &mainWindow)
{
	mainWindow_ = mainWindow;	
}

void VoteEditor::addElectorName(std::string name)
{
	ui->electorList->addItem(name.c_str());
}

void VoteEditor::reset()
{
	ui->electorName->clear();
	setCandidateList(initialCandidateList_);
}

void VoteEditor::submit()
{
	std::vector<std::string> orderedCandidates;
	for (int i = 0; i < ui->candidateList->count(); ++i){
		orderedCandidates.emplace_back(ui->candidateList->item(i)->text().toStdString());
	}
	
	std::string electorName = ui->electorName->text().toStdString();
	
	VoteResult result{orderedCandidates, electorName};
	
	if(mainWindow_){
		mainWindow_->get().addVoteResult(result);
	}
	
	reset();
}

void VoteEditor::cancel()
{
	reset();
}

void VoteEditor::electorNameChanged()
{
	ui->submitButton->setEnabled(!ui->electorName->text().isEmpty());
}

void VoteEditor::showResults()
{
	if(mainWindow_){
		mainWindow_->get().showResults();
	}
}


