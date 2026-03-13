#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mAdjacencyMatrix = nullptr;
    mVertexsCount = 0;

    connect(ui->dijkstra, &QPushButton::clicked, this, &MainWindow::onDijkstra);
    connect(ui->importGraph, &QPushButton::clicked, this, &MainWindow::onImportGraph);
    connect(ui->vertexsCount, &QSpinBox::valueChanged, this, &MainWindow::onVertexValueChange);
}

MainWindow::~MainWindow()
{
    eraseMatrix();
    delete ui;
}

void MainWindow::onImportGraph()
{
    ui->vertexsCount->setValue(4);

    eraseMatrix();
    alocationMemmory();
    mAdjacencyMatrix[0][1] = 6;
    mAdjacencyMatrix[1][0] = 6;
    mAdjacencyMatrix[0][2] = 1;
    mAdjacencyMatrix[2][0] = 1;
    mAdjacencyMatrix[0][3] = 5;
    mAdjacencyMatrix[3][0] = 5;
    mAdjacencyMatrix[1][2] = 7;
    mAdjacencyMatrix[2][1] = 7;
    mAdjacencyMatrix[3][2] = 2;
    mAdjacencyMatrix[2][3] = 2;
    writeMatrix();
}


void MainWindow::onDijkstra()
{
    initDikstra();
    calculatePath();
    printResult();
}

void MainWindow::onVertexValueChange()
{
    eraseMatrix();
    mVertexsCount = ui->vertexsCount->value();
    alocationMemmory();
    writeMatrix();

    ui->startingVertex->clear();
    for (int i = 0; i < mVertexsCount; ++i) {
        ui->startingVertex->addItem(QString::number(i));
    }
}

void MainWindow::alocationMemmory()
{
    int verticesCount = ui->vertexsCount->value();

    mAdjacencyMatrix = new int*[verticesCount];

    for (int i = 0; i < verticesCount; ++i) {
        mAdjacencyMatrix[i] = new int[verticesCount];
        for (int j = 0; j < verticesCount; ++j) {
            mAdjacencyMatrix[i][j] = 0;
        }
    }
}

void MainWindow::createMatrix()
{

}

void MainWindow::eraseMatrix()
{
    if (mAdjacencyMatrix == nullptr) {
        return;
    }
    for (int i = 0; i < mVertexsCount; ++i) {
        delete [] mAdjacencyMatrix[i];
    }
    delete [] mAdjacencyMatrix;
    mAdjacencyMatrix = nullptr;
}

void MainWindow::writeMatrix()
{
    ui->result->clear();
    QString matrix;
    int edgeCount = ui->vertexsCount->value();
    for (int i = 0; i < edgeCount; ++i) {
        for (int j = 0; j < edgeCount; ++j) {
            matrix += QString::number(mAdjacencyMatrix[i][j]) + " ";
        }
        matrix += "\n";
    }
    ui->result->setText(matrix);
}

void MainWindow::initDikstra()
{
    int verticesCount = ui->vertexsCount->value();
    if (verticesCount < 1) {
        return;
    }

    mVertexs.clear();
    mPathes.clear();

    for (int i = 0; i < verticesCount; ++i) {
        Vertex vertex;
        vertex.mVertexValue = INT_MAX;
        mVertexs.push_back(vertex);
    }

    int starting = ui->startingVertex->currentIndex();
    mVertexs[starting].mVertexValue = 0;
    mPathes.insert({0, starting});

}

void MainWindow::calculatePath()
{

}

void MainWindow::printResult()
{

}

