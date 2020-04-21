#ifndef VOTE_H
#define VOTE_H

#include <QWidget>
#include <vector>

namespace Ui {
class Vote;
}

class VoteEditor : public QWidget
{
	Q_OBJECT
	
public:
	explicit VoteEditor(QWidget *parent = nullptr);
	~VoteEditor();
	void setCandidateList(std::vector<std::string> candidateList);
	
private:
	Ui::Vote *ui;
};

#endif // VOTE_H
