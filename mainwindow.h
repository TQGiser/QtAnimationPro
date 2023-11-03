#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QDir>

#include <QVBoxLayout>
#include <QHBoxLayout>

#include <QPropertyAnimation>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QVBoxLayout *ct1;
    QVBoxLayout *ct2;
    QHBoxLayout *ct3;

    QPropertyAnimation *m_animation;

    void test();
};
#endif // MAINWINDOW_H
