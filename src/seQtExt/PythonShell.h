#pragma once

#include <QWidget>

#include "seQtExt.h"

class QLineEdit;
class QTextEdit;
class QDebugStream;

class SEQTEXT_EXPORT PythonShell : public QWidget
{
	Q_OBJECT

public:

	PythonShell(QWidget *parent = 0L);
	virtual ~PythonShell();


private:

	QLineEdit *_lineEdit;
	QTextEdit *_textEdit;
	QDebugStream *_stdoutStream;
};