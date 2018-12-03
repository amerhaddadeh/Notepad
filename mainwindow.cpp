#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_triggered()
{
    mFilename = "";
    ui->textEdit->setPlainText("");
}

void MainWindow::on_actionOpen_triggered()
{

    QString file = QFileDialog::getOpenFileName(this,"Open a file");

    if(!file.isEmpty())
    {
        QFile sFile(file);
        if(sFile.open(QFile::ReadOnly | QFile::Text))
        {
            mFilename = file;
            QTextStream in(&sFile);
            QString text = in.readAll();

            sFile.close();

            ui->textEdit->setPlainText(text);


          //  void CheckFormat(*text);

            //void CppHighlighter(text);
        }

    }

}

void MainWindow::on_actionSave_triggered()
{
    QFile sFile(mFilename);
    if(sFile.open(QFile::WriteOnly | QFile::Text))
    {
        QTextStream out(&sFile);

        out << ui->textEdit->toPlainText();

        sFile.flush();
        sFile.close();



    }

}

void MainWindow::on_actionSave_As_triggered()
{

    QString file = QFileDialog::getSaveFileName(this,"Open a file");

    if(!file.isEmpty())
    {
        mFilename = file;
       on_actionSave_triggered();

    }


}

//void MyHighlighter::highlightBlock(const QString &text)
//{
//    QTextCharFormat myClassFormat;
//    myClassFormat.setFontWeight(QFont::Bold);
//    myClassFormat.setForeground(Qt::darkMagenta);
//    QString pattern = "\\bMy[A-Za-z]+\\b";

//    QRegExp expression(pattern);
//    int index = text.indexOf(expression);
//    while (index >= 0) {
//        int length = expression.matchedLength();
//        setFormat(index, length, myClassFormat);
//        index = text.indexOf(expression, index + length);
//     }
// }





//void CppHighlighter::highlightBlock(const QString &text)
//{
//    enum { NormalState = -1, InsideCStyleComment };

//    int state = previousBlockState();
//    int start = 0;

//    for (int i = 0; i < text.length(); ++i) {

//        if (state == InsideCStyleComment) {
//            if (text.mid(i, 2) == "*/") {
//                state = NormalState;
//                setFormat(start, i - start + 2, Qt::blue);
//            }
//        } else {
//            if (text.mid(i, 2) == "//") {
//                setFormat(i, text.length() - i, Qt::red);
//                break;
//            } else if (text.mid(i, 2) == "/*") {
//                start = i;
//                state = InsideCStyleComment;
//            }
//        }
//    }
//    if (state == InsideCStyleComment)
//        setFormat(start, text.length() - start, Qt::blue);

//    setCurrentBlockState(state);
//}

void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

void MainWindow::on_actionCut_triggered()
{
   ui->textEdit->cut();
}

void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}

void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}

void MainWindow::on_actionRedo_triggered()
{
   ui->textEdit->redo();
}
