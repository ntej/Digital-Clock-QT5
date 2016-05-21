#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow  //class MainWindow inheriting QMainWindow
{
    Q_OBJECT  //macro

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QPoint m_mousePos;
    void setColour();

private slots:
    void updateTime();
    void showContextMenu(const QPoint &pos);
    void showPreference();
    
protected:
    void mouseReleaseEvent(QMouseEvent*); //reimplementation

    void mousePressEvent(QMouseEvent*); //reimplementation
    void mouseMoveEvent(QMouseEvent*); //reimplementation

    void closeEvent(QCloseEvent*); //reimplementation
};

#endif // MAINWINDOW_H
