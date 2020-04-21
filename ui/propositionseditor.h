#ifndef PROPOSITIONSEDITOR_H
#define PROPOSITIONSEDITOR_H

#include <QWidget>
#include <optional>
#include <functional>

namespace Ui {
class PropositionsEditor;
}

class MainWindow;

class PropositionsEditor : public QWidget
{
	Q_OBJECT
	
public:
	explicit PropositionsEditor(QWidget *parent = nullptr);
	~PropositionsEditor();
	void setMainWindow(MainWindow& mainWindow);
	
protected:
   virtual void keyPressEvent(QKeyEvent *event) override;

private slots:
	void addCandidate();
	void deleteSelection();
	void submitList();
	
private:
	Ui::PropositionsEditor *ui_;
	std::optional<std::reference_wrapper<MainWindow>> mainWindow_; //référence optionnel
};

#endif // PROPOSITIONSEDITOR_H
