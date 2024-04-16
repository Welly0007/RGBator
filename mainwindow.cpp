#include "mainwindow.h"
#include <QButtonGroup>
#include <QDir>
#include <QFileDialog>
#include <QPixmap>
#include "Image_Class.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <stack>
#include <cmath>
#include <math.h>
#include <limits> // for std::numeric_limits<int>::max()
#define NCHANNEL 3
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->outImg, &CustomLabel::mouseHolding, this, &MainWindow::handleMouseHolding);


    //  setting some widgets to be initially hidden
    show_cropWidgets(false);
    ui->rotateLeft->setIcon(QIcon("icons/rotate_left.png"));
    ui->rotateRight->setIcon(QIcon("icons/rotate_right.png"));
    ui->undoBtn->setIcon(QIcon("icons/undo_alt.png"));
    ui->redoBtn->setIcon(QIcon("icons/redo_alt.png"));
    ui->titleIcon->setIcon(QIcon("icons/RGB.png"));
    ui->sliderGroup->hide();
    ui->widthEditVal->hide();
    ui->heightEditVal->hide();
    ui->heightLabel->hide();
    ui->widthLabel->hide();
    ui->resizeFilterBtn->hide();
    ui->resizeRatio->hide();
    // ui->rotateLeft->hide();
    // ui->rotateRight->hide();

    //  Disabling Some pushButtons Before loading Image
    ui->invertFilter->setEnabled(false);
    ui->oilFilter->setEnabled(false);
    ui->blurFilter->setEnabled(false);
    ui->rotateLeft->setEnabled(false);
    ui->grayFilter->setEnabled(false);
    ui->B_W_Filter->setEnabled(false);
    ui->SkewFilter->setEnabled(false);
    ui->rotateRight->setEnabled(false);
    ui->purpleFilter->setEnabled(false);
    ui->DetectFilter->setEnabled(false);
    ui->BrightFilter->setEnabled(false);
    ui->oldtvFilter->setEnabled(false);
    ui->sunLightFilter->setEnabled(false);
    ui->FrameFilter->setEnabled(false);
    ui->NeonFilter->setEnabled(false);
    ui->HorizontalFlip->setEnabled(false);
    ui->VerticalFlip->setEnabled(false);
    ui->cropFilter->setEnabled(false);
    ui->infraredFilter->setEnabled(false);
    ui->redoBtn->setEnabled(false);
    ui->undoBtn->setEnabled(false);
    ui->saveImgBtn->setEnabled(false);
    ui->clearImg->setEnabled(false);
}
MainWindow::~MainWindow()
{
    delete ui;
}

// Some Globals;
Image orImg;
Image currImg;
string tempPath;
QString QtempPath;
int labelWidth, labelHeight;
stack<Image> redoStack, undoStack;

//  Filters functions prototypes
void rotate90(Image &image);
void rotateI90(Image &image);
void invert_color(Image &img);
void infrared_color(Image &img);
void grayScale(Image &image);
void Black_and_White(Image &img);
void sunlight_filter(Image &image, int sunStrength);
void blur_filter(Image &image, int blurStr);
void Dark_and_Light(Image &imgage, int strength);
void purple_filter(Image &image);
void Skew(Image &image);
void Frame(Image &img, int r, int g, int b);
void Old_Tv(Image &image);
void oilPainting_filter(Image &image, int strength);
void resize_image(Image &image, int newHeight);
void resize_image(Image &image, int newHeight, int newWidth);
void crop(Image &img, int x, int y, int width, int height);
void edgeDetection(Image &image);
void flip_horizontally(Image &image1);
void flip_vertically(Image &image1);

//  other functions prototpyes
void clear_undo_stack();
void clear_redo_stack();

void hide_others(string curr);
void show_sliderWidgets(bool);
void show_cropWidgets(bool);
// Image Detect_Image(Image &img);
// void Applay_Detect(Image &img);

//  File Events functions

//  Load image
void MainWindow::outImageDisplay(){
    float aspectRatio = static_cast<float>(currImg.width)/currImg.height;
    labelHeight = 400;
    labelWidth = labelHeight*aspectRatio;
    if(labelWidth > 700){
        labelWidth = min(currImg.width,700);
        labelHeight = min(currImg.height,400);
    }
    ui->outImg->setMaximumWidth(labelWidth);
    ui->outImg->setMaximumHeight(labelHeight);
    QPixmap currImageDis(QtempPath);
    ui->outImg->setPixmap(currImageDis.scaled(labelWidth, labelHeight));

}
void MainWindow::on_loadImgBtn_clicked()
{
    //  Open File Dialoge to load Image, With specified Extensions
    QString filter = "(*.jpg *.png *.bmp *.tga) ;; (*.jpg) ;; (*.png) ;; (*.bmp) ;; (*.tga)";
    QString filePath = QFileDialog::getOpenFileName(this, "load", QDir::homePath(), filter);

    //  Check if File is Checked or not
    if (filePath != "") {
        //  Initializing the OrImage and CurrentImage for Image_class Libirary
        string orImgPath = filePath.toStdString();
        orImg.loadNewImage(orImgPath);
        //  getting the absolute paths and saving the original in the app directory if needed
        int lastSlash = orImgPath.find_last_of("/\\");
        int dot = orImgPath.find_last_of('.');
        tempPath = orImgPath.substr(lastSlash + 1, dot - (lastSlash + 1)) + ".jpg";
        QtempPath = QString::fromStdString(tempPath);

        orImg.saveImage("original" + tempPath);
        orImg.loadNewImage("original" + tempPath);
        currImg = orImg;
        currImg.saveImage(tempPath);

        //Displaying the in and out Image;
        QPixmap img(filePath);
        labelHeight = 400;
        ui->inImg->setPixmap(img.scaled(700, labelHeight, Qt::KeepAspectRatio));
        outImageDisplay();



        ui->widthEditVal->setText(QString::number(orImg.width));
        ui->heightEditVal->setText(QString::number(orImg.height));
        //  Show specific widgets after the Image Has been Loaded
        ui->widthEditVal->show();
        ui->heightEditVal->show();
        ui->heightLabel->show();
        ui->widthLabel->show();
        ui->resizeRatio->show();
        // ui->rotateLeft->show();
        // ui->rotateRight->show();
        //Enabling Filters buttons
        ui->invertFilter->setEnabled(true);
        ui->oilFilter->setEnabled(true);
        ui->grayFilter->setEnabled(true);
        ui->B_W_Filter->setEnabled(true);
        ui->blurFilter->setEnabled(true);
        ui->rotateLeft->setEnabled(true);
        ui->DetectFilter->setEnabled(true);
        ui->BrightFilter->setEnabled(true);
        ui->rotateRight->setEnabled(true);
        ui->FrameFilter->setEnabled(true);
        ui->purpleFilter->setEnabled(true);
        ui->SkewFilter->setEnabled(true);
        ui->sunLightFilter->setEnabled(true);
        ui->oldtvFilter->setEnabled(true);
        ui->cropFilter->setEnabled(true);
        ui->NeonFilter->setEnabled(true);
        ui->HorizontalFlip->setEnabled(true);
        ui->VerticalFlip->setEnabled(true);
        ui->infraredFilter->setEnabled(true);
        ui->redoBtn->setEnabled(true);
        ui->undoBtn->setEnabled(true);
        ui->saveImgBtn->setEnabled(true);
        ui->clearImg->setEnabled(true);
        //  clear_undo_stack();
        clear_undo_stack();
        clear_redo_stack();
        ui->redoBtn->setEnabled(false);
        ui->undoBtn->setEnabled(false);
    }
    hide_others();
}

//  Save Image

void MainWindow::on_saveImgBtn_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this,
                                                    "Save Image",
                                                    QDir::homePath(),
                                                    "*.png ;; *.jpg ;; *.tga ;; *.bmp)");
    if (!fileName.isEmpty()) {
        // Copy the file to the chosen location
        QFile::copy(QtempPath, fileName);
    }
}

//  Clear Image

void MainWindow::on_clearImg_clicked()
{
    currImg = orImg;
    currImg.saveImage(tempPath);
    outImageDisplay();
    clear_undo_stack();
    clear_redo_stack();
    hide_others();
}

//  undo

void MainWindow::on_undoBtn_clicked()
{
    if (!undoStack.empty()) {
        redoStack.push(currImg);
        currImg = undoStack.top();
        undoStack.pop();
        // Save current state for redo
        currImg.saveImage(tempPath);
    }
    outImageDisplay();
    hide_others();
}

//  redo

void MainWindow::on_redoBtn_clicked()
{
    if (!redoStack.empty()) {
        undoStack.push(currImg); // Save current state for undo
        currImg = redoStack.top();
        redoStack.pop();
        currImg.saveImage(tempPath);
    }
    outImageDisplay();
    hide_others();
}

//  Filters Events

void MainWindow::on_NeonFilter_clicked()
{
    undoStack.push(currImg);
    edgeDetection(currImg);
    clear_redo_stack();
    currImg.saveImage(tempPath);
    QPixmap img = QPixmap(QtempPath);
    ui->outImg->setPixmap(img.scaled(labelWidth, labelHeight, Qt::KeepAspectRatio));
    hide_others();
}


void MainWindow::on_HorizontalFlip_clicked()
{
    undoStack.push(currImg);
    flip_horizontally(currImg);
    clear_redo_stack();
    currImg.saveImage(tempPath);
    QPixmap img = QPixmap(QtempPath);
    ui->outImg->setPixmap(img.scaled(labelWidth, labelHeight, Qt::KeepAspectRatio));
    hide_others();
}


void MainWindow::on_VerticalFlip_clicked()
{
    undoStack.push(currImg);
    flip_vertically(currImg);
    clear_redo_stack();
    currImg.saveImage(tempPath);
    QPixmap img = QPixmap(QtempPath);
    ui->outImg->setPixmap(img.scaled(labelWidth, labelHeight, Qt::KeepAspectRatio));
    hide_others();
}

void MainWindow::on_rotateRight_clicked()
{
    undoStack.push(currImg);
    rotate90(currImg);
    clear_redo_stack();
    currImg.saveImage(tempPath);
    outImageDisplay();
    hide_others();
}

void MainWindow::on_rotateLeft_clicked()
{
    undoStack.push(currImg);
    rotateI90(currImg);
    clear_redo_stack();
    currImg.saveImage(tempPath);
    outImageDisplay();
    hide_others();
}

void MainWindow::on_invertFilter_clicked()
{
    undoStack.push(currImg);
    invert_color(currImg);
    clear_redo_stack();
    currImg.saveImage(tempPath);
    QPixmap img = QPixmap(QtempPath);
    ui->outImg->setPixmap(img.scaled(labelWidth, labelHeight, Qt::KeepAspectRatio));
    hide_others();
}
void MainWindow::on_infraredFilter_clicked()
{
    undoStack.push(currImg);
    infrared_color(currImg);
    clear_redo_stack();
    currImg.saveImage(tempPath);
    QPixmap img = QPixmap(QtempPath);
    ui->outImg->setPixmap(img.scaled(labelWidth, labelHeight, Qt::KeepAspectRatio));
    hide_others();
}

void MainWindow::on_grayFilter_clicked()
{
    undoStack.push(currImg);
    grayScale(currImg);
    clear_redo_stack();
    currImg.saveImage(tempPath);
    QPixmap img = QPixmap(QtempPath);
    ui->outImg->setPixmap(img.scaled(labelWidth, labelHeight, Qt::KeepAspectRatio));
    hide_others();
}

void MainWindow::on_B_W_Filter_clicked()
{
    undoStack.push(currImg);
    Black_and_White(currImg);
    clear_redo_stack();
    currImg.saveImage(tempPath);
    QPixmap img = QPixmap(QtempPath);
    ui->outImg->setPixmap(img.scaled(labelWidth, labelHeight, Qt::KeepAspectRatio));
    hide_others();
}

void MainWindow::on_DetectFilter_clicked()
{
    undoStack.push(currImg);
    grayScale(currImg);
    edgeDetection(currImg);
    clear_redo_stack();
    currImg.saveImage(tempPath);
    QPixmap img = QPixmap(QtempPath);
    ui->outImg->setPixmap(img.scaled(labelWidth, labelHeight, Qt::KeepAspectRatio));
    hide_others();
}

void MainWindow::on_SkewFilter_clicked()
{
    undoStack.push(currImg);
    Skew(currImg);
    clear_redo_stack();
    currImg.saveImage(tempPath);
    QPixmap img = QPixmap(QtempPath);
    ui->outImg->setPixmap(img.scaled(labelWidth, labelHeight, Qt::KeepAspectRatio));
    hide_others();
}


void MainWindow::on_oldtvFilter_clicked()
{
    undoStack.push(currImg);
    Old_Tv(currImg);
    clear_redo_stack();
    currImg.saveImage(tempPath);
    QPixmap img = QPixmap(QtempPath);
    ui->outImg->setPixmap(img.scaled(labelWidth, labelHeight, Qt::KeepAspectRatio));
    hide_others();
}


void MainWindow::on_FrameFilter_clicked()
{
    QColor ColorValue = QColorDialog::getColor(Qt::white, this, tr("Selcet Color"));
    int red = ColorValue.red();
    int green = ColorValue.green();
    int blue = ColorValue.blue();
    undoStack.push(currImg);
    Frame(currImg, red, green, blue);
    clear_redo_stack();
    currImg.saveImage(tempPath);
    QPixmap img = QPixmap(QtempPath);
    ui->outImg->setPixmap(img.scaled(labelWidth, labelHeight, Qt::KeepAspectRatio));
    hide_others();

}

void MainWindow::on_filterSlider_valueChanged(int value)
{   //  special vals for brightness filter
    if(ui->BrightFilter->isChecked()){
        int brightVal = value - 50;
        if(brightVal == 0){
            ui->sliderValue->setText("Normal Brightness");
        }else{
            ui->sliderValue->setText(QString::number(brightVal));
        }
        //  normal Condition
    }else{
        ui->sliderValue->setText(QString::number(value));
    }

}


void MainWindow::on_filterApply_clicked()
{
    ui->progressLabel->setText("In Progress...");
    ui->progressLabel->show();
    QApplication::processEvents();
    //  adjusting undo - redo stacks
    undoStack.push(currImg);
    clear_redo_stack();

    // getting the strength from the slider
    int strength = ui->sliderValue->text().toInt();

    // choosing the filter according to the button clicked;

    if (ui->sunLightFilter->isChecked()) {
        sunlight_filter(currImg, strength);
    }

    else if (ui->blurFilter->isChecked()) {
        int imgHeight = currImg.height;

        if (strength != 0) {
            if (imgHeight > 1000) {
                resize_image(currImg, 720);
            }

            blur_filter(currImg, strength);

            if (imgHeight > 1000) {
                resize_image(currImg, imgHeight);
            }
        }
    }

    else if (ui->oilFilter->isChecked()) {
        int imgHeight = currImg.height;
        if (strength != 0) {
            if (imgHeight > 1000) {
                resize_image(currImg, 720);
            }

            oilPainting_filter(currImg, strength);

            if (imgHeight > 1000) {
                resize_image(currImg, imgHeight);
            }
        }
    }

    else if (ui->BrightFilter->isChecked()) {
        //  +50 because we have manipulated the image
        Dark_and_Light(currImg, strength+50);
    }

    //  Displaying the Image;
    currImg.saveImage(tempPath);
    QPixmap img = QPixmap(QtempPath);
    ui->outImg->setPixmap(img.scaled(labelWidth, labelHeight, Qt::KeepAspectRatio));

    ui->progressLabel->setText("Done !");

    ui->undoBtn->setEnabled(true);
    ui->redoBtn->setEnabled(false);
}

void MainWindow::on_sunLightFilter_clicked(bool checked)
{
    hide_others("sunLightFilter");
    ui->filterSlider->setValue(20);
    ui->sliderGroup->setTitle("Sunlight Filter");
    show_sliderWidgets(checked);
}

void MainWindow::on_blurFilter_clicked(bool checked)
{
    hide_others("blurFilter");
    ui->filterSlider->setValue(20);
    ui->sliderGroup->setTitle("Blur Filter");
    show_sliderWidgets(checked);
}

void MainWindow::on_BrightFilter_clicked(bool checked)
{
    hide_others("BrightFilter");
    ui->filterSlider->setValue(50);
    ui->sliderGroup->setTitle("Brightnees Filter");
    show_sliderWidgets(checked);
}
void MainWindow::on_oilFilter_clicked(bool checked)
{
    hide_others("oilFilter");
    ui->filterSlider->setValue(20);
    ui->sliderGroup->setTitle("Oil Painting Filter");
    show_sliderWidgets(checked);
}


void MainWindow::on_purpleFilter_clicked()
{
    undoStack.push(currImg);
    purple_filter(currImg);
    clear_redo_stack();
    currImg.saveImage(tempPath);
    QPixmap img = QPixmap(QtempPath);
    ui->outImg->setPixmap(img.scaled(labelWidth, labelHeight, Qt::KeepAspectRatio));
    hide_others();
}

void MainWindow::on_resizeFilterBtn_clicked()
{
    undoStack.push(currImg);
    int newHeight = ui->heightEditVal->text().toInt();
    int newWidth = ui->widthEditVal->text().toInt();
    resize_image(currImg, newHeight, newWidth);
    clear_redo_stack();
    currImg.saveImage(tempPath);
    outImageDisplay();
    hide_others();
}

void MainWindow::on_widthEditVal_textEdited()
{
    ui->resizeFilterBtn->show();
    ui->resizeRatio->show();
    if (ui->resizeRatio->isChecked()) {
        int width = ui->widthEditVal->text().toInt();
        float aspectRatio = static_cast<float>(currImg.height) / currImg.width;
        int newHeight = static_cast<int>(width * aspectRatio);
        ui->heightEditVal->setText(QString::number(newHeight));
    }
}

void MainWindow::on_heightEditVal_textEdited()
{
    ui->resizeFilterBtn->show();
    ui->resizeRatio->show();
    if (ui->resizeRatio->isChecked()) {
        int height = ui->heightEditVal->text().toInt();
        float aspectRatio = static_cast<float>(currImg.width) / currImg.height;
        int newWidth = static_cast<int>(height * aspectRatio);
        ui->widthEditVal->setText(QString::number(newWidth));
    }
}




//  Other Functions Declaration
void clear_undo_stack()
{
    while (!undoStack.empty()) {
        undoStack.pop();
    }
}
void clear_redo_stack()
{
    while (!redoStack.empty()) {
        redoStack.pop();
    }
}
void MainWindow::hide_others(string curr)
{
    if (curr != "sunLightFilter") {
        ui->sunLightFilter->setChecked(false);
    }
    if (curr != "blurFilter") {
        ui->blurFilter->setChecked(false);
    }
    if (curr != "oilFilter") {
        ui->oilFilter->setChecked(false);
    }
    if (curr != "BrightFilter") {
        ui->BrightFilter->setChecked(false);
    }
    ui->sliderGroup->hide();
    show_cropWidgets(false);
    ui->cropFilter->setChecked(false);
    ui->heightEditVal->setText(QString::number(currImg.height));
    ui->widthEditVal->setText(QString::number(currImg.width));
    ui->resizeFilterBtn->hide();
    ui->resizeRatio->setChecked(true);
    ui->justFrame->hide();
    // ui->cropApply->hide();
    if (redoStack.empty()) {
        ui->redoBtn->setEnabled(false);
    } else {
        ui->redoBtn->setEnabled(true);
    }
    if (undoStack.empty()) {
        ui->undoBtn->setEnabled(false);
    } else {
        ui->undoBtn->setEnabled(true);
    }
}

void MainWindow::show_sliderWidgets(bool checked)
{
    if (checked) {
        ui->sliderGroup->show();
    } else {
        ui->sliderGroup->hide();
    }
    ui->progressLabel->hide();
}
void MainWindow::show_cropWidgets(bool checked){
    if(checked){
        ui->justFrame->show();
        ui->cropGroup->show();
        ui->justFrame->move(ui->outImg->pos().x()+ ui->outFrame->pos().x(), ui->outImg->pos().y()+ui->outFrame->pos().y());
        ui->justFrame->resize(labelWidth/2,labelHeight/2);
        ui->cropWidth->setText(QString::number(labelWidth/2));
        ui->cropHeight->setText(QString::number(labelHeight/2));
    }else{
        ui->cropGroup->hide();
        ui->justFrame->hide();
    }

}

// void Applay_Detect(Image &img)
// {
//     int img_h = img.height;
//     int img_w = img.width;
//     if (img_h >= 500 && img_w >= 500) {
//         resize_image(img, 200,200);
//     }
//     Detect_Image(img);
//     if (img_h >= 500 && img_w >= 500) {
//         resize_image(img, img_h, img_w);
//     }
// }
//  Filter Functions Declaration

void grayScale(Image &image)
{
    // Filter
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            unsigned int avg = 0;
            for (int k = 0; k < 3; ++k) {
                avg += image(i, j, k);
            }
            avg /= 3;
            for (int l = 0; l < 3; ++l) {
                image(i, j, l) = avg;
            }
        }
    }
}

void rotate90(Image &image)
{
    Image newImage(image.height, image.width);
    //  rotate 90
    for (int i = 0; i < newImage.width; i++) {
        for (int j = 0; j < newImage.height; j++) {
            for (int k = 0; k < 3; k++) {
                newImage(i, j, k) = image(j, (newImage.width - 1) - i, k);
            }
        }
    }
    image = newImage;
}
void rotateI90(Image &image)
{
    Image newImage(image.height, image.width);
    for (int i = 0; i < newImage.width; i++) {
        for (int j = 0; j < newImage.height; j++) {
            for (int k = 0; k < 3; k++) {
                newImage(i, j, k) = image((newImage.height - 1) - j, i, k);
            }
        }
    }
    image = newImage;
}
void invert_color(Image &img)
{

    for(int i = 1; i < img.width; i++) {
        for(int j = 1; j < img.height; j++) {
            for(int k = 0; k<3;k++){
                img(i, j, k) = 255 -img(i, j, k);
            }
        }
    }
}
void infrared_color(Image &img)
{

    for(int i = 1; i < img.width; i++) {
        for(int j = 1; j < img.height; j++) {

            int red = img(i, j, 0);
            int green = img(i, j, 1);
            int blue = img(i, j, 2);

            red = 255;
            green = 255 - green;
            blue = 255 - blue;
            // Setting new RGB values
            img(i, j, 0) = red;
            img(i, j, 1) = green;
            img(i, j, 2) = blue;
        }
    }
}

void purple_filter(Image& image){
    Image newImage(image.width, image.height);
    int purpleStrength = 50;
    float R, G, B;
    for(int i=0; i < image.width ; i++){
        for(int j=0; j < image.height ; j++){
            R = image(i, j ,0) +  purpleStrength * 0.927;
            G = image(i, j, 1) -  purpleStrength * 0.570;
            B = image(i, j, 2) +  purpleStrength * 0.941;

            // Ensure R, G, B values are within the valid range [0, 255]
            R = (R > 255) ? 255 : (R < 0) ? 0 : R;
            G = (G > 255) ? 255 : (G < 0) ? 0 : G;
            B = (B > 255) ? 255 : (B < 0) ? 0 : B;

            newImage(i, j, 0) = R;
            newImage(i, j, 1) = G;
            newImage(i, j, 2) = B;
        }
    }

    // Replace the original image with the new image
    image = newImage;
}

void sunlight_filter(Image &image, int sunStrength)
{
    int R, G;
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            R = image(i, j, 0) + sunStrength, G = image(i, j, 1) + sunStrength;
            if (R > 255) {
                R = 255;
            }
            if (G > 255) {
                G = 255;
            }
            image(i, j, 0) = R;
            image(i, j, 1) = G;
            image(i, j, 2) = image(i, j, 2);
        }
    }
}

void resize_image(Image &image, int newHeight)
{
    float aspectRatio = static_cast<float>(image.width) / image.height;
    int newWidth = static_cast<int>(newHeight * aspectRatio);

    Image newImage(newWidth, newHeight);

    float xRatio = static_cast<float>(image.width - 1) / newWidth;
    float yRatio = static_cast<float>(image.height - 1) / newHeight;

    for (int i = 0; i < newWidth; i++) {
        for (int j = 0; j < newHeight; j++) {
            int x = static_cast<int>(xRatio * i);
            int y = static_cast<int>(yRatio * j);
            newImage(i, j, 0) = image(x, y, 0);
            newImage(i, j, 1) = image(x, y, 1);
            newImage(i, j, 2) = image(x, y, 2);
        }
    }

    image = newImage;
}

void resize_image(Image &image, int newHeight, int newWidth)
{
    Image newImage(newWidth, newHeight);

    float xRatio = static_cast<float>(image.width - 1) / newWidth;
    float yRatio = static_cast<float>(image.height - 1) / newHeight;

    for (int i = 0; i < newWidth; i++) {
        for (int j = 0; j < newHeight; j++) {
            int x = static_cast<int>(xRatio * i);
            int y = static_cast<int>(yRatio * j);
            newImage(i, j, 0) = image(x, y, 0);
            newImage(i, j, 1) = image(x, y, 1);
            newImage(i, j, 2) = image(x, y, 2);
        }
    }

    image = newImage;
}

void blur_filter(Image &image, int blurStr)
{
    Image newImage(image.width, image.height);
    int kernelSize = 21.0 * blurStr / 100.0;

    if (kernelSize < 3) {
        kernelSize = 3;
    }

    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            int avgR = 0;
            int avgG = 0;
            int avgB = 0;
            int count = 0;

            // Iterate over the kernel centered at pixel (i, j)
            for (int a = i - (kernelSize - 1) / 2; a <= i + (kernelSize - 1) / 2; a++) {
                for (int b = j - (kernelSize - 1) / 2; b <= j + (kernelSize - 1) / 2; b++) {
                    // Check if the current pixel is within the image boundaries
                    if (a >= 0 && a < image.width && b >= 0 && b < image.height) {
                        avgR += image(a, b, 0);
                        avgG += image(a, b, 1);
                        avgB += image(a, b, 2);
                        count++;
                    }
                }
            }

            // Calculate average color values
            avgR /= count;
            avgG /= count;
            avgB /= count;

            // Assign the average color to the corresponding pixel in the new image
            newImage(i, j, 0) = avgR;
            newImage(i, j, 1) = avgG;
            newImage(i, j, 2) = avgB;
        }
    }

    // Update the original image with the blurred image
    image = newImage;
}

void Dark_and_Light(Image &image, int strength)
{
    if(strength >50){
        float brightStrength = ((static_cast<float>(strength) -50.0)/50.0) * 255.0;
        for(int i = 0;i<image.width; i++){
            for(int j = 0; j < image.height; j++){
                for (int k = 0; k < 3; k++) {
                    int adjustedValue = brightStrength;
                    if(image(i,j,k) +  adjustedValue>255){
                        adjustedValue = 255 - image(i,j,k);
                    }
                    image(i,j,k) += adjustedValue;
                }
            }
        }
    }else if(strength<50){
        float darkStrength = ((50.0 - static_cast<float>(strength))/50.0) * 255.0;
        for(int i = 0;i<image.width; i++){
            for(int j = 0; j < image.height; j++){
                for (int k = 0; k < 3; k++) {
                    int adjustedValue = darkStrength;
                    if(image(i,j,k) -  adjustedValue < 0){
                        adjustedValue = image(i,j,k);
                    }
                    image(i,j,k) -= adjustedValue;
                }
            }
        }
    }
}

void oilPainting_filter(Image &image, int strength)
{
    Image newImage(image.width, image.height);

    int KernelSize = 10.0 * static_cast<double>(strength) / 100.0;
    double IntensityLevel = 20.0;
    if (KernelSize < 3) {
        return;
    }

    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            vector<int> frequencyLevels(IntensityLevel + 1, 0);
            vector<int> r_pixels(IntensityLevel + 1, 0);
            vector<int> g_pixels(IntensityLevel + 1, 0);
            vector<int> b_pixels(IntensityLevel + 1, 0);

            //  Kernel loop to find most frequent color
            for (int a = i - (KernelSize - 1) / 2; a <= i + (KernelSize + 1) / 2; a++) {
                for (int b = j - (KernelSize - 1) / 2; b <= j + (KernelSize + 1) / 2; b++) {
                    if (a >= 0 && b >= 0 && a < image.width && b < image.height) {
                        float avgPixel = 0;
                        for (int k = 0; k < 3; k++) {
                            avgPixel += image(a, b, k);
                        }
                        avgPixel /= 3.0;
                        int currIntensity = avgPixel * IntensityLevel / 255.0f;
                        frequencyLevels[currIntensity]++;
                        r_pixels[currIntensity] += image(a, b, 0);
                        g_pixels[currIntensity] += image(a, b, 1);
                        b_pixels[currIntensity] += image(a, b, 2);
                    }
                }
            }
            int max_index = 0;
            int freq_max = frequencyLevels[0];
            for (int i = 0; i < IntensityLevel + 1; i++) {
                if (freq_max < frequencyLevels[i]) {
                    freq_max = frequencyLevels[i];
                    max_index = i;
                }
            }
            newImage(i, j, 0) = r_pixels[max_index] / freq_max;
            newImage(i, j, 1) = g_pixels[max_index] / freq_max;
            newImage(i, j, 2) = b_pixels[max_index] / freq_max;
        }
    }
    image = newImage;
}

void Black_and_White(Image &img)
{
    for (int i = 0; i < img.width; ++i) {
        for (int j = 0; j < img.height; ++j) {
            unsigned int avg = 0;
            for (int k = 0; k < img.channels; ++k) {
                avg += img(i, j, k);
            }
            avg = avg / 3;
            for (int k = 0; k < 3; ++k) {
                if (avg > 127) {
                    img(i, j, k) = 255;
                } else {
                    img(i, j, k) = 0;
                }
            }
        }
    }
}


void edgeDetection(Image &image) {
    Image imageout = image;
    // Sobel kernels for horizontal and vertical gradients
    int sobel_kernel_x[3][3] = {
        {-1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1}
    };

    int sobel_kernel_y[3][3] = {
        {-1, -2, -1},
        {0, 0, 0},
        {1, 2, 1}
    };

    int width = image.width;
    int height = image.height;

    //Image resultImage(width, height, NCHANNEL);

    for (int y = 1; y < height - 1; ++y) {
        for (int x = 1; x < width - 1; ++x) {
            for (int c = 0; c < NCHANNEL; ++c) {
                int sumX = 0;
                int sumY = 0;

                for (int m = -1; m <= 1; m++) {
                    for (int n = -1; n <= 1; n++) {
                        sumX += image(x + m, y + n, c) * sobel_kernel_x[m + 1][n + 1];
                        sumY += image(x + m, y + n, c) * sobel_kernel_y[m + 1][n + 1];
                    }
                }

                // Calculate magnitude using both horizontal and vertical gradients
                int magnitude = sqrt(sumX * sumX + sumY * sumY);

                // Clipping to ensure the result is within [0, 255]
                magnitude = min(max(magnitude, 0), 255);

                // Assign the magnitude to the result image
                imageout(x, y, c) = magnitude;
            }
        }
    }
    image = imageout;
}



void crop(Image &img, int x, int y, int width, int height) {

    Image newImage(width, height);


    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            for (int k = 0; k < 3; ++k) {
                newImage(i, j, k) = img(x + i, y + j, k);
            }
        }
    }

    img = newImage;
}

//  Section for the crop custom label
void MainWindow::on_cropFilter_clicked(bool checked)
{
    hide_others();
    ui->cropFilter->setChecked(checked);
    show_cropWidgets(checked);

}
void MainWindow::on_cropWidth_textEdited(const QString &arg1)
{

    if(arg1.toInt() > labelWidth){
        ui->cropWidth->setText(QString::number(labelWidth));
    }
    int width = ui->cropWidth->text().toInt();
    int height = ui->cropHeight->text().toInt();
    ui->justFrame->resize(width, height);
    ui->justFrame->move(ui->outImg->pos().x()+ ui->outFrame->pos().x(), ui->outImg->pos().y()+ui->outFrame->pos().y());
}


void MainWindow::on_cropHeight_textChanged(const QString &arg1)
{

    if(arg1.toInt() > labelHeight){
        ui->cropHeight->setText(QString::number(labelHeight));
    }
    int width = ui->cropWidth->text().toInt();
    int height = ui->cropHeight->text().toInt();
    ui->justFrame->resize(width, height);
    ui->justFrame->move(ui->outImg->pos().x()+ ui->outFrame->pos().x(), ui->outImg->pos().y()+ui->outFrame->pos().y());
}
CustomLabel::CustomLabel(QWidget* parent) : QLabel(parent), isHolding(false) {
    // constructor implementation (optional)
}
void CustomLabel::mousePressEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton) {
        isHolding = true; // Flag to track hold state
        emit mousePressed(event->pos());
    }else{
        isHolding= false;
    }
}

void CustomLabel::mouseMoveEvent(QMouseEvent* event) {
    if (isHolding) {
        emit mouseHolding(event->pos());
    }
}
void CustomLabel::mouseReleaseEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton) {
        isHolding = false; // Reset flag on left button release
    }
}

int clamp(int value, int min, int max) {
    return std::min(std::max(value, min), max);
}

void MainWindow::handleMouseHolding(const QPoint& pos) {


    // Helper function to clamp a value within a range
    if(ui->cropFilter->isChecked()){
        int frameWidth = ui->justFrame->width();
        int frameHeight = ui->justFrame->height();
        int initialOffsetX = ui->outFrame->pos().x() + ui->outImg->pos().x();
        int initialOffsetY = ui->outFrame->pos().y() + ui->outImg->pos().y();

        // Calculate boundaries with descriptive variable names
        int rightBound = ui->outImg->width() - frameWidth + initialOffsetX;
        int lowerBound = labelHeight - frameHeight +initialOffsetY;

        // Move the frame based on position and boundaries
        int clampedX = clamp(pos.x(), 0, rightBound - initialOffsetX);
        int clampedY = clamp(pos.y(), 0, lowerBound - initialOffsetY);
        ui->justFrame->move(clampedX + initialOffsetX, clampedY + initialOffsetY);
    }
}


void MainWindow::on_cropApply_clicked()
{
    int startX =  ui->justFrame->pos().x() - ui->outFrame->pos().x() - ui->outImg->pos().x();
    int startY =  ui->justFrame->pos().y() - ui->outFrame->pos().y() - ui->outImg->pos().y();
    int width = ui->justFrame->width(), height = ui->justFrame->height();
    float aspectRatioH = static_cast<float>(currImg.height) / labelHeight;
    float aspectRatioW = static_cast<float>(currImg.width) / labelWidth;
    startX *=aspectRatioW;
    startY *=aspectRatioH;
    width*=aspectRatioW;
    height*=aspectRatioH;
    undoStack.push(currImg);
    crop(currImg, startX,startY,width,height);
    clear_redo_stack();
    currImg.saveImage(tempPath);
    outImageDisplay();
    hide_others();
}



void Skew(Image& image){
    // int angle;
    // cout << "Enter the skew angle in degrees: \n";
    // while (true){
    //     cin >> angle;
    //     cin.ignore();
    //     if (cin.fail() || angle >= 90 || angle < 0) {
    //         cin.clear();
    //         cin.ignore(numeric_limits<streamsize>::max(), '\n');
    //         cout << "Invalid input. Please enter an angle less than 90 degrees.\n";
    //     }
    //     else {
    //         break;
    //     }
    // }
    double skew = tan(45 * M_PI / 180);
    Image new_image(image.width + static_cast<int>(image.height * fabs(skew)), image.height);
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            int newi = i + static_cast<int>((image.height-1-j) * skew);
            for (int k = 0; k < 3; ++k) {
                new_image(newi, j, k) = image(i, j, k);
            }
        }
    }

}


void Old_Tv(Image &image){
    srand(static_cast<unsigned int>(time(nullptr)));
    for (int i = 0; i < image.height; ++i) {
        for (int j = 0; j < image.width; ++j) {
            int random = rand() % 256 - 128;
            for (int k = 0; k < 3; ++k) {
                int newValue = image(j, i, k) + random;
                newValue = max(0, min(255, newValue));
                image(j, i, k) = static_cast<unsigned char>(newValue);
            }
        }
    }

}


void Frame(Image &img, int r, int g, int b) {
    Image newImage(img.width, img.height);
    int border = img.width / 50; // Width of the frame
    int innerBorder = img.width / 100; // Width of the inner frame
    for (int i = 0; i < img.width; i++) {
        for (int j = 0; j < img.height; j++) {
            if (i < border || i >= img.width - border || j < border || j >= img.height - border) {
                img(i, j, 0) = r;
                img(i, j, 1) = g;
                img(i, j, 2) = b;
            }
        }
    }

for (int i = 0; i < img.width; ++i) {
    for (int j = 0; j < img.height; ++j) {
        for (int k = 0; k <3 ; ++k) {
            newImage(i,j,k)=img(i,j,k);
        }
    }
}
img = newImage;

}


void flip_horizontally(Image &image1){
    for (int i = 0; i < image1.width/2; i++)
    {
        for (int j = 0; j < image1.height; j++)
        {
            for (int k = 0; k < image1.channels; k++)
            {
                swap(image1(i,j,k), image1(image1.width-i-1,j,k));
            }

        }

    }
}

void flip_vertically(Image &image1){
    for (int i = 0; i < image1.width; i++)
    {
        for (int j = 0; j < image1.height/2; j++)
        {
            for (int k = 0; k < image1.channels; k++)
            {
                swap(image1(i,j,k), image1(i,image1.height-j-1,k));
            }

        }

    }
}







