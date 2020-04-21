#include "propositionseditor.h"
#include "ui_propositionseditor.h"
#include "mainwindow.h"
#include <QKeyEvent>
#include <vector>
#include <string>

PropositionsEditor::PropositionsEditor(QWidget *parent) :
	QWidget(parent),
	ui_(new Ui::PropositionsEditor)
{
	ui_->setupUi(this);
}

PropositionsEditor::~PropositionsEditor()
{
	delete ui_;
}

void PropositionsEditor::setMainWindow(MainWindow &mainWindow)
{
	mainWindow_ = mainWindow;
}

void PropositionsEditor::keyPressEvent(QKeyEvent *event)
{
	if (event->key() == Qt::Key_Delete) { //Quand on appuie sur delete ça appelle delete selection
		deleteSelection();
	}
}

void PropositionsEditor::addCandidate()
{
	auto candidateName = ui_->candidateName->text();
	ui_->candidateList->addItem(candidateName);
	ui_->candidateName->clear();
}

void PropositionsEditor::deleteSelection()
{
	auto selectedCandidates = ui_->candidateList->selectedItems();
	for (auto candidate : selectedCandidates){
		delete candidate;
	}
}

void PropositionsEditor::submitList()
{
	std::vector<std::string> candidates;
	auto candidateList = ui_->candidateList;
	for (int i = 0; i < candidateList->count(); ++i){
		candidates.emplace_back(candidateList->item(i)->text().toStdString());
	}
	if(mainWindow_){
		mainWindow_->get().setCandidateList(candidates);
	}
}
