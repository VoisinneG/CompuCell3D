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

void MainWindow::on_actionOpenSimulation_triggered()
{
    // Open FileDialog and get the file path to open
    QString filePath = QFileDialog::getOpenFileName(this, tr("Open Simulation"), ".", tr("CompuCell3D File (*.cc3d)"));

    qDebug() << "File path to Open: " << filePath;

    // filePath will be null if user has not selected any file and clicked cancel on the dialog
    if(filePath != NULL) {

        // Check if selected file exists
        if (QFileInfo(filePath).exists()) {
            bool isOpenSuccess = requestHandler.openCompuCellModel(filePath);

            if (isOpenSuccess) {
                qDebug() << "File Open Successful.";

                // Populate the model editor tree view
                this->setupModelEditor();
            }
        } else {
            // Error file does not exists but sent to open
            qCritical() << "File does not exists. Invalid File Path:" << filePath;
        }
    }
}

void MainWindow::setupModelEditor()
{

    // Get the model XML tree
    requestHandler.getModelXML();

//    // Intialize the model with column count and headers
//    QStandardItemModel *model = new QStandardItemModel();
//
//    QStringList modelEditorHeaderLabels;
//    modelEditorHeaderLabels.append("Property");
//    modelEditorHeaderLabels.append("Value");
//
//    model->setColumnCount(2);
//    model->setHorizontalHeaderLabels(modelEditorHeaderLabels);
//
//    preOrder(modelDomDocument.firstChild(), model);
//
//    this->ui->treeViewModelEditor->setModel(model);
}

//void MainWindow::preOrder(QDomNode dom, QStandardItemModel *model, QStandardItem *item){
/**
    while (!dom.isNull()) {
        QStandardItem* itemProperty = new QStandardItem(dom.nodeName());
        QStandardItem* itemValue = new QStandardItem(dom.nodeValue());
        itemProperty->
        QList<QStandardItem*> itemList;
        itemList.append(itemProperty);
        itemList.append(itemValue);

        if(item == NULL)
        {
            model->appendRow(itemList);
        }
        else
        {
            item->appendRow(itemList);
        }

        if(dom.hasChildNodes())
        {
            QDomNodeList childList = dom.childNodes();
            for(int i =0; i <childList.count(); i++)
            {

                QDomNode childNode = childList.at(i);
                preOrder(childNode, model, itemProperty);
            }
        }

        dom = dom.nextSibling();
    }
    **/
//}


