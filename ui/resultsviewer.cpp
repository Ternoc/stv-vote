#include "resultsviewer.h"
#include "ui_resultsviewer.h"
#include <unordered_map>

ResultsViewer::ResultsViewer(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::ResultsViewer)
{
	ui->setupUi(this);

}

ResultsViewer::~ResultsViewer()
{
	delete ui;
}

void ResultsViewer::addVoteResult(VoteResult voteResult)
{
	voteResults_.emplace_back(voteResult);	
}

void ResultsViewer::setInitialCandidates(std::vector<std::string> candidates)
{
	initialCandidates_ = candidates;
	ui->resultsTable->setColumnCount(candidates.size());
	ui->resultsTable->setRowCount(candidates.size());
	
	QStringList verticalHeaders, horizontalHeaders;
	
	for (size_t i = 0; i < candidates.size(); ++i) {
		verticalHeaders.append(candidates[i].c_str());
		horizontalHeaders.append("TOUR " + QString::number(i+1));
	}
	
	ui->resultsTable->setVerticalHeaderLabels(verticalHeaders);
	ui->resultsTable->setHorizontalHeaderLabels(horizontalHeaders);	
}

void ResultsViewer::computeResults()
{
	std::unordered_map<std::string, int> votes;
	for (auto candidate : initialCandidates_) {
		votes[candidate] = 0;
	}
	
	for (size_t turn = 0; votes.size() > 0; ++turn) {
		for (auto result : voteResults_) {
			for (auto candidate : result.orderedCandidates) {
				if (votes.find(candidate) != votes.end()) {
					votes[candidate] += 1;
					break;
				}
			}
		}
		
		for (size_t i = 0; i < initialCandidates_.size(); ++i) {
			auto candidate = initialCandidates_[i];
			if (votes.find(candidate) != votes.end()) {
				ui->resultsTable->setItem(i, turn, new QTableWidgetItem(QString::number(votes[candidate])));
			}
		}
		
		std::pair<std::string, int> worstCandidate = {"", std::numeric_limits<int>::max()};
		for (auto [candidate, vote] : votes) {
			if(vote <= worstCandidate.second) {
				worstCandidate = {candidate, vote};
			}
		}
		
		votes.erase(worstCandidate.first);
		
		for (auto& [candidate, vote] : votes) {
			vote = 0;
		}
		
	}
}

