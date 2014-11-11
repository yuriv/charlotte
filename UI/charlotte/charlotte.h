#ifndef CHARLOTTE_H
#define CHARLOTTE_H

#include <QMainWindow>

#include <ch_core.h>

#include "ui_charlotte.h"

class charlotte : public QMainWindow
{
	Q_OBJECT

public:
	charlotte(QWidget *parent = 0);
	~charlotte();
public slots:
	void runNewProject();
	void runOpenProject();
	void runDataIntegration();
	void runReportDesigner();
	void runCharlotteHelp();
	void runCharlotteAbout();

private:
	Ui::charlotteClass ui;
};

#endif // CHARLOTTE_H
