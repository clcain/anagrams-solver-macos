#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // model setup
    m_Model.importDictionaryFile();

    // line edit setup
    m_LineEdit = new QLineEdit();

    // text box setup
    m_TextEdit = new QTextEdit();
    m_TextEdit->setReadOnly(true);

    // buttons setup
    m_SubmitButton = new QPushButton();

    // set button names
    m_SubmitButton->setText("Find Anagrams");

    // window setup
    setWindowTitle("Anagrams Solver");

    // layout setup
    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(m_LineEdit);
    layout->addWidget(m_SubmitButton);
    layout->addWidget(m_TextEdit);

    // set layout in QWidget
    QWidget* window = new QWidget();
    window->setLayout(layout);

    // set QWidget as the central layout of the main window
    setCentralWidget(window);

    // connect slots
    QObject::connect(m_SubmitButton, SIGNAL(clicked(bool)),
                     this, SLOT(submitAnagram(void)));

}

MainWindow::~MainWindow()
{
    // not that this actually matters since the program is exiting anyway
    delete m_LineEdit;
    delete m_TextEdit;
    delete m_SubmitButton;
}

void MainWindow::submitAnagram()
{
    QString anagramString = m_LineEdit->text().toLower();
    QList<QString> solutions = m_Model.generateSolutions(anagramString);
    QString solutionsText;
    for (int i = 0; i < solutions.length(); i++)
    {
        solutionsText.append(solutions.at(i));
        if (i < solutions.length() - 1)
        {
            solutionsText.append("\n");
        }
    }
    m_TextEdit->setText(solutionsText);
}
