#include "voteeditor.h"
#include "ui_vote.h"

VoteEditor::VoteEditor(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::Vote)
{
	ui->setupUi(this);
}

VoteEditor::~VoteEditor()
{
	delete ui;
}

void VoteEditor::setCandidateList(std::vector<std::string> candidateList)
{
	ui->candidateList->clear();
	for (const auto& candidate : candidateList){
		ui->candidateList->addItem(candidate.c_str());
	}
}
