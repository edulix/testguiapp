#include "testguiapp.h"

#include <QtGui/QLabel>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QAction>
#include <QDockWidget>
#include <QToolBar>
#include <QDebug>

testguiapp::testguiapp()
{
    resize(400, 500);
    QToolBar* toolbar = new QToolBar(this);
    toolbar->setObjectName("toolbar");
    QAction* a = new QAction(this);
    a->setText( "save" );
    connect(a, SIGNAL(triggered()), this, SLOT(save()));
    toolbar->addAction(a);

    a = new QAction(this);
    a->setText( "restore" );
    connect(a, SIGNAL(triggered()), this, SLOT(restore()));
    toolbar->addAction(a);
    addToolBar(toolbar);

    createGui();
}

testguiapp::~testguiapp()
{}

void testguiapp::save()
{
    qDebug() << "save";
    mState = saveState();
}

void testguiapp::createGui()
{
    mLabel = new QLabel(this);
    mLabel->setText("Hello World!");
    mLabel->setObjectName("mainwidget");
    setCentralWidget(mLabel);

    mLeftDock = new QDockWidget(this);
    mLeftDock->setObjectName("leftdock");
    QLabel* label = new QLabel(mLeftDock);
    label->setObjectName("labelDock");
    addDockWidget(Qt::RightDockWidgetArea, mLeftDock);
    mLeftDock->setWidget(label);
}

void testguiapp::deleteGui()
{
    delete mLabel;
    delete mLeftDock;
    mLabel = 0;
    mLeftDock = 0;
}

void testguiapp::restore()
{
    qDebug() << "restore";
    deleteGui();
    createGui();
    restoreState(mState);
}


#include "testguiapp.moc"
