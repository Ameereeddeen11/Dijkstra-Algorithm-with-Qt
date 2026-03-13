#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include <map>
#include <vertex.h>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void onImportGraph();
    void onDijkstra();
    void onVertexValueChange();

private:
    Ui::MainWindow *ui;

    int mVertexsCount;
    int **mAdjacencyMatrix;
    std::vector<Vertex> mVertexs;
    std::multimap<int, int> mPathes;

    void alocationMemmory();

    void createMatrix();
    void eraseMatrix();

    void writeMatrix();

    void initDikstra();
    void calculatePath();
    void printResult();
};
#endif // MAINWINDOW_H
