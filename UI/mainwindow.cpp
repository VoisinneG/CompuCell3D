#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include<QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //this->requestHandler = new RequestHandler();
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


/**
 * This slot is triggered when Open Simulation is clicked under File Menu.
 *
 */
void MainWindow::on_actionOpenSimulation_triggered()
{
    QString filePath = QFileDialog::getOpenFileName(this, tr("Open Simulation"), ".", tr("CompuCell3D File (*.cc3d)"));

    qDebug() << "File path to Open: " << filePath;

    // filePath will be null if user has not selected any file and clicked cancel on the dialog
    if(filePath != NULL)
    {
        // Check if selected file exists
        if(QFileInfo(filePath).exists())
        {
            bool isOpenSuccess = requestHandler.openCompuCellModel(filePath);
            if(isOpenSuccess)
            {
                // Get the model XML tree
                //requestHandler.getModelXMLObject();

                // Populate the model editor tree view
                //this->ui->tree

            }
        }
        else
        {
            // Error file does not exists but sent to open
            qCritical() << "File does not exists. Invalid File Path:" << filePath;
        }
    }
}


