#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QMouseEvent>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE


class CustomLabel : public QLabel {
    Q_OBJECT
public:
    explicit CustomLabel(QWidget* parent = nullptr);
    void mouseMoveEvent(QMouseEvent* event) override;
protected:
    void mousePressEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
private:
    bool isHolding = false;
signals:
    void mousePressed(const QPoint&);
    void mouseHolding(const QPoint& pos);
};


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void hide_others(std::string curr = "");
    void show_sliderWidgets(bool checked);
    void show_cropWidgets(bool checked);
    //s
private slots:
    // customLabel slots
    void handleMouseHolding(const QPoint& pos);
    //  End custom

    void on_loadImgBtn_clicked();
    void on_saveImgBtn_clicked();
    void outImageDisplay();
    void on_clearImg_clicked();

    void on_redoBtn_clicked();
    void on_undoBtn_clicked();

    void on_invertFilter_clicked();
    void on_rotateRight_clicked();
    void on_rotateLeft_clicked();

    void on_purpleFilter_clicked();

    void on_filterApply_clicked();

    void on_sunLightFilter_clicked(bool checked);

    void on_filterSlider_valueChanged(int value);

    void on_blurFilter_clicked(bool checked);

    void on_oilFilter_clicked(bool checked);

    void on_resizeFilterBtn_clicked();

    void on_widthEditVal_textEdited();

    void on_heightEditVal_textEdited();

    void on_grayFilter_clicked();

    void on_B_W_Filter_clicked();


    void on_DetectFilter_clicked();

    void on_BrightFilter_clicked(bool checked);

    // void on_cropAp_clicked(bool checked);

    void on_cropFilter_clicked(bool checked);

    void on_cropWidth_textEdited(const QString &arg1);

    void on_cropHeight_textChanged(const QString &arg1);

    void on_cropApply_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
