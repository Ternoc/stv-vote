#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <vector>
#include <string>
#include "model/voteresult.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QWidget
{
	Q_OBJECT
	
public:
	MainWindow(QWidget *parent = nullptr);
	~MainWindow();
	void setCandidateList(std::vector<std::string> candidateList);
	void addVoteResult(VoteResult voteResult);
	void showResults();
	
private:
	Ui::MainWindow *ui;
	
};
#endif // MAINWINDOW_H
