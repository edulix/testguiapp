#ifndef testguiapp_H
#define testguiapp_H

#include <QtGui/QMainWindow>
#include <QLabel>
#include <QDockWidget>

class testguiapp : public QMainWindow
{
    Q_OBJECT

public:
    testguiapp();
    virtual ~testguiapp();

protected Q_SLOTS:
    void save();
    void restore();

protected:
    void createGui();
    void deleteGui();

private:
    QByteArray mState;
    QLabel* mLabel;
    QDockWidget* mLeftDock;
    QByteArray mWidgetState;
    QByteArray mCentralWidgetState;
};

#endif // testguiapp_H
