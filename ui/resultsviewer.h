#ifndef RESULTSVIEWER_H
#define RESULTSVIEWER_H

#include <QWidget>
#include <vector>
#include "model/voteresult.h"

namespace Ui {
class ResultsViewer;
}

class ResultsViewer : public QWidget
{
	Q_OBJECT
	
public:
	explicit ResultsViewer(QWidget *parent = nullptr);
	~ResultsViewer();
	void addVoteResult(VoteResult voteResult);
	void computeResults();
	void setInitialCandidates(std::vector<std::string> candidates);
	
private:
	Ui::ResultsViewer *ui;
	std::vector<VoteResult> voteResults_;
	std::vector<std::string> initialCandidates_;
};

#endif // RESULTSVIEWER_H
