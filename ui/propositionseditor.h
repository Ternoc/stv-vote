#ifndef PROPOSITIONSEDITOR_H
#define PROPOSITIONSEDITOR_H

#include <QWidget>

namespace Ui {
class PropositionsEditor;
}

class MainWindow;

class PropositionsEditor : public QWidget
{
	Q_OBJECT
	
public:
	explicit PropositionsEditor(MainWindow& mainWindow,QWidget *parent = nullptr);
	~PropositionsEditor();
	
protected:
   virtual void keyPressEvent(QKeyEvent *event) override;

private slots:
	void addCandidate();
	void deleteSelection();
	void submitList();
	
private:
	Ui::PropositionsEditor *ui_;
	MainWindow& mainWindow_;
};

#endif // PROPOSITIONSEDITOR_H
