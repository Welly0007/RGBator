#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QFileDialog>
#include <QDir>
#include "Image_Class.h"
#include <bits/stdc++.h>
#include <QButtonGroup>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->sunFilterApply->hide();
    ui->textSunSlider->hide();
    ui->sunSliderValue->hide();
    ui->sunFilterSlider->hide();

}

MainWindow::~MainWindow()
{
    delete ui;
}


// Some Globals;
Image orImg;
Image currImg;
string tempPath = "-1";
QString QtempPath;
int labelWidth, labelHeight;
stack<Image> undoStack, redoStack;


//  Filters functions prototypes
void rotate90(Image &image);
void rotateI90(Image &image);
void invert_color(Image& image);
void sunlight_filter(Image& image, int sunStrength);
void purple_filter(Image& image);

//  other functions prototpyes
void clear_redo_stack();
void clear_undo_stack();
void MainWindow::hide_others(string curr){
    if(curr!="sunLightFilter"){
        ui->sunLightFilter->setChecked(false);
        ui->sunFilterApply->hide();
        ui->textSunSlider->hide();
        ui->sunSliderValue->hide();
        ui->sunFilterSlider->hide();
    }
}


//  File Events functions


//  Load image

void MainWindow::on_loadImgBtn_clicked()
{
    //  Open File Dialoge to load Image, With specified Extensions
    QString filter = "(*.jpg *.png *.bmp *.tga) ;; (*.jpg) ;; (*.png) ;; (*.bmp) ;; (*.tga)";
    QString filePath = QFileDialog::getOpenFileName(this, "load", "D:/academics/College/Level !/CS 112/GonnaShow/Gui Training/image_load_save_display/sample", filter);
    //  Displaying The image on Input and output Qlabels
    QPixmap img(filePath);
    labelWidth = ui ->inImg->width();
    labelHeight = ui -> inImg -> height();
    ui -> inImg ->setPixmap(img.scaled(labelWidth, labelHeight, Qt::KeepAspectRatio));
    ui -> outImg ->setPixmap(img.scaled(labelWidth, labelHeight, Qt::KeepAspectRatio));
    //  Initializing the Image for Image_class Libirary

    string orImgPath = filePath.toStdString();
    orImg.loadNewImage(orImgPath);

    //  Setting the Current Image
    int lastSlash = orImgPath.find_last_of("/\\");
    int dot = orImgPath.find_last_of('.');
    tempPath = orImgPath.substr(lastSlash+1, dot-(lastSlash+1))+".jpg";
    QtempPath = QString::fromStdString(tempPath);

    orImg.saveImage("original"+tempPath);
    orImg.loadNewImage("original"+tempPath);
    currImg = orImg;
    currImg.saveImage(tempPath);
    //  clear_redo_stack();
    clear_redo_stack();
    clear_undo_stack();
}


//  Save Image


void MainWindow::on_saveImgBtn_clicked()
{
    // Check if the file exists before trying to copy it
    if (QFile::exists(QtempPath)) {
        QString fileName = QFileDialog::getSaveFileName(this, "Save Image", QDir::homePath(), "*.png ;; *.jpg ;; *.tga ;; *.bmp)");
        if (!fileName.isEmpty()) {
            // Copy the file to the chosen location
            QFile::copy(QtempPath, fileName);
        }
    }
}


//  Clear Image

void MainWindow::on_clearImg_clicked()
{
        if(tempPath!="-1"){
            currImg = orImg;
            currImg.saveImage(tempPath);
            QPixmap img = QPixmap(QtempPath);
            ui -> outImg ->setPixmap(img.scaled(labelWidth, labelHeight, Qt::KeepAspectRatio));
            clear_redo_stack();
            clear_undo_stack();
        }
}

//  Redo

void MainWindow::on_redoBtn_clicked()
{
    if(!redoStack.empty()){

        undoStack.push(currImg);
        currImg = redoStack.top();
        redoStack.pop();
        // Save current state for undo
        currImg.saveImage(tempPath);
        QPixmap img = QPixmap(QtempPath);
        ui -> outImg ->setPixmap(img.scaled(labelWidth, labelHeight, Qt::KeepAspectRatio));
    }
}


//  undo


void MainWindow::on_undoBtn_clicked()
{

    if(!undoStack.empty()){
        redoStack.push(currImg); // Save current state for redo
        currImg = undoStack.top();
        undoStack.pop();
        currImg.saveImage(tempPath);
        QPixmap img = QPixmap(QtempPath);
        ui -> outImg ->setPixmap(img.scaled(labelWidth, labelHeight, Qt::KeepAspectRatio));
    }
}


//  Filters Events


void MainWindow::on_rotateRight_clicked()
{
    hide_others();
    redoStack.push(currImg);
    rotate90(currImg);
    clear_undo_stack();
    currImg.saveImage(tempPath);
    QPixmap img = QPixmap(QtempPath);
    ui -> outImg ->setPixmap(img.scaled(labelWidth, labelHeight, Qt::KeepAspectRatio));
}


void MainWindow::on_rotateLeft_clicked()
{
    hide_others();
    redoStack.push(currImg);
    rotateI90(currImg);
    clear_undo_stack();
    currImg.saveImage(tempPath);
    QPixmap img = QPixmap(QtempPath);
    ui -> outImg ->setPixmap(img.scaled(labelWidth, labelHeight, Qt::KeepAspectRatio));
}


void MainWindow::on_invertFilter_clicked()
{
    hide_others();
    redoStack.push(currImg);
    invert_color(currImg);
    clear_undo_stack();
    currImg.saveImage(tempPath);
    QPixmap img = QPixmap(QtempPath);
    ui -> outImg ->setPixmap(img.scaled(labelWidth, labelHeight, Qt::KeepAspectRatio));
}


void MainWindow::on_sunFilterSlider_valueChanged(int value)
{
    ui -> sunSliderValue -> setText(QString::number(value));
}

void MainWindow::on_sunFilterApply_clicked()
{
    redoStack.push(currImg);
    int sunStrength = ui->sunSliderValue->text().toInt();
    sunlight_filter(currImg, sunStrength);
    clear_undo_stack();
    currImg.saveImage(tempPath);
    QPixmap img = QPixmap(QtempPath);
    ui -> outImg ->setPixmap(img.scaled(labelWidth, labelHeight, Qt::KeepAspectRatio));
    hide_others();
}

void MainWindow::on_sunLightFilter_clicked(bool checked)
{
    hide_others("sunLightFilter");
    if(checked){
        ui->sunFilterApply->show();
        ui->textSunSlider->show();
        ui->sunSliderValue->show();
        ui->sunFilterSlider->show();
    }else{
        ui->sunFilterApply->hide();
        ui->textSunSlider->hide();
        ui->sunSliderValue->hide();
        ui->sunFilterSlider->hide();
    }
}


void MainWindow::on_purpleFilter_clicked()
{
    hide_others();
    redoStack.push(currImg);
    purple_filter(currImg);
    clear_undo_stack();
    currImg.saveImage(tempPath);
    QPixmap img = QPixmap(QtempPath);
    ui -> outImg ->setPixmap(img.scaled(labelWidth, labelHeight, Qt::KeepAspectRatio));
}






//  Filter Functions Declaration

void rotate90(Image& image){
    Image newImage(image.height, image.width);
        //  rotate 90
    for (int i = 0; i < newImage.width; i++) {
        for (int j = 0; j < newImage.height; j++) {
            for (int k = 0; k < 3; k++) {
                newImage(i, j, k) = image(j, (newImage.width -1) - i , k);
            }
        }
    }
    image = newImage;
}
void rotateI90(Image& image){
    Image newImage(image.height, image.width);
    for (int i = 0; i < newImage.width; i++) {
        for (int j = 0; j < newImage.height; j++) {
            for(int k=0; k < 3;k++){
                newImage(i, j,k)=image((newImage.height - 1) -j, i, k);
            }
        }
    }
    image = newImage;
}
void invert_color(Image& image) {
    for(int i = 0; i < image.width ; i++) {
        for(int j = 0; j < image.height; j++) {
            for(int k = 0; k < 3; k++) {
                image(i, j, k) = 255 - image(i, j, k);
            }
        }
    }
}

void purple_filter(Image& image){
    int R, G, B;
    for(int i=0; i < image.width ; i++){
        for(int j=0; j < image.height ; j++){
            R= image(i, j ,0) +  255 * 0.627, G= image(i, j, 1) + 255 * 0.125, B= image(i, j, 2) + 255 * 0.941;
            if(R >255){
                R=255;
            }
            if(B>255){
                B=255;
            }
            if(G > 255){
                G=255;
            }
            image(i, j, 0) = R;
            image(i, j, 1) = G;
            image(i, j, 2) = B;
        }
    }
}



void sunlight_filter(Image& image, int sunStrength){
    int R,G;
    for(int i=0; i < image.width ; i++){
        for(int j=0; j < image.height ; j++){
            R= image(i,j,0) + sunStrength, G=image(i,j,1) + sunStrength;
            if(R >255){
                R=255;
            }
            if(G>255){
                G=255;
            }
            image(i, j, 0) = R;
            image(i, j, 1) = G;
            image(i, j, 2) = image(i,j,2);
        }
    }
}

//  Other Functions Declaration
void clear_redo_stack(){
    while(!redoStack.empty()){
        redoStack.pop();
    }
}
void clear_undo_stack(){
    while(!undoStack.empty()){
        undoStack.pop();
    }
}
