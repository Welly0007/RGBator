#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void hide_others(std::string curr = "");
//s
private slots:
    void on_loadImgBtn_clicked();
    void on_saveImgBtn_clicked();

    void on_redoBtn_clicked();
    void on_undoBtn_clicked();


    void on_invertFilter_clicked();
    void on_rotateRight_clicked();
    void on_rotateLeft_clicked();


    void on_purpleFilter_clicked();

    void on_clearImg_clicked();

    void on_sunFilterSlider_valueChanged(int value);

    void on_sunFilterApply_clicked();

    void on_sunLightFilter_clicked(bool checked);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
