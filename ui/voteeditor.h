#ifndef VOTE_H
#define VOTE_H

#include <QWidget>
#include <vector>
#include <optional>
#include <functional>

namespace Ui {
class VoteEditor;
}

class MainWindow;

class VoteEditor : public QWidget
{
	Q_OBJECT
	
public:
	explicit VoteEditor(QWidget *parent = nullptr);
	~VoteEditor();
	void setInitialCandidateList(std::vector<std::string> candidateList);
	void setMainWindow(MainWindow& mainWindow);
	void addElectorName(std::string name);
	
public slots:
	void submit();
	void cancel();
	void electorNameChanged();
	void showResults();
	
private:
	void reset();
	void setCandidateList(std::vector<std::string> candidateList);	
	
private:
	Ui::VoteEditor *ui;
	std::optional<std::reference_wrapper<MainWindow>> mainWindow_;
	std::vector<std::string> initialCandidateList_;
};

#endif // VOTE_H
