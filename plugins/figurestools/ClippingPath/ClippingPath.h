/**********************************
 *        ClippingPath.h
 *        Maxim Finojenok
 *             2015
 *********************************/

#ifndef CLIPPINGPATH_H
#define CLIPPINGPATH_H

#include <QMainWindow>
#include <QMenu>
#include <QAction>
#include <QToolButton>
#include <QWidget>
#include <QObject>
#include <QMouseEvent>
#include "./../../../pluginTool/InterfacePlugin.h"
#include "./../../../interfaces/MainWindowInterface.h"
#include "./../../../interfaces/PaintWidgetInterface.h"
#include "./../../../interfaces/RPWInterface.h"
#include "./../../../interfaces/GSRInterface.h"
#include "./../../../interfaces/ToolButtonInterface.h"
#include "./../../../paintWidget/GVectorFigure.h"

class ToolButton;

class ClippingPath:public FigureToolInterface, public InterfacePlugin
{
    Q_OBJECT
    Q_INTERFACES( FigureToolInterface )
    Q_INTERFACES( InterfacePlugin )

    signals:
        void setActive(QString);

    public slots:
        void clip();

    public:
        ClippingPath( const plugin::PluginsManager *manager );
        void cutFigureOnPath(GVectorFigure* figureForClip, GVectorFigure* clippingPath);
        ~ClippingPath();

        void createPlugin(QObject *parent, QString idParent, plugin::PluginsManager *manager);
        QWidget* getWidget();
        QString getName() const;
        QIcon icon();
        CreateStyle createStyle() const;
        FiguresInfo figure() const;
        QString description() const;
        QString figureName() const;
        void toolSelected();

    private:
        GVectorFigure* getLastFigure();
        GVectorFigure* getFigureByIndex( int index );
        int getIndexOfLastFigure();
        QPolygonF getPointsOfFigure( GVectorFigure *figure );
        QPolygonF intersectOfPoints( QPolygonF pointsOfFigureForClip, QPolygonF pointsOfClippingPath, bool closedOfFigureForClip, bool closedOfClippingPath );
        int getCountSplinePoints(QPolygonF points);
        QPainterPath paintPath(QPolygonF points);
        QPolygonF polygonToPointsOfFigure(QPolygonF polygon);


        GSRInterface *selectionRect;
        QAction *ActionClippingPath;
        ToolButton *button;
        static bool resourcesInited;
};

class ToolButton:public ToolButtonInterface
{
    Q_OBJECT
    Q_INTERFACES( ToolButtonInterface )

    signals:
        void toolSelected( FigureToolInterface *tool );

    public:
        QObject* getTool();
        void setTool(QObject* t);
        ToolButton( FigureToolInterface *_tool, QWidget *parent );
        virtual ~ToolButton();

    private slots:
        void onClicked( bool checked );

    private:
        FigureToolInterface *tool;
};

#endif // CLIPPINGPATH_H
