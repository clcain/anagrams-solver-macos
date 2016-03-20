#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "anagramssolvermodel.h"
#include <QVBoxLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    AnagramsSolverModel m_Model;
    QLineEdit* m_LineEdit;
    QTextEdit* m_TextEdit;
    QPushButton* m_SubmitButton;

private slots:
    void submitAnagram();
};

#endif // MAINWINDOW_H
