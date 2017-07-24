#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QPoint>
#include <QLine>
#include <QMainWindow>

#include "avlTree.h"

namespace Ui {
class MainWindow;
}

struct pnt
{
    int val;
    QPoint point;
    pnt(int _val, QPoint _point) : val(_val), point(_point) {}
};

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_addButton_clicked();
    void on_removeButton_clicked();
    void on_clearButton_clicked();

private:
    //tree must be here
    void RebuildTree();

    void recursiveBuilder(node * n, int heightLevel, int centerDistance);

    avlTree * tree;
    std::vector<pnt> points;
    std::vector<QLine> lines;
    std::list<int> valuesCache;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
