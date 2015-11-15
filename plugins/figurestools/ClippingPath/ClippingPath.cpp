#include "ClippingPath.h"

bool J_ClippingPath::resourcesInited = false;

void J_ClippingPath::clip(){
    GVectorFigure *figureForClip( 0 );
    GVectorFigure *clippingPath = getLastFigure();
    int indexOfLastFigureForClip = getIndexOfLastFigure() - 1;
    for (int i = 0; i < indexOfLastFigureForClip; i++){
        figureForClip = getFigureByIndex( i );
        cutFigure( figureForClip, clippingPath );
    }

    clippingPath->setVisible(false);
    selectionRect->reset();
}

int J_ClippingPath::getIndexOfLastFigure(){
    return selectionRect->countSelected();
}

GVectorFigure* J_ClippingPath::getLastFigure(){
    int countClipFigures = selectionRect->countSelected() - 1;
    return dynamic_cast<GVectorFigure*>( selectionRect->selected( countClipFigures ));
}

GVectorFigure* J_ClippingPath::getFigureByIndex( int index ){
    return dynamic_cast<GVectorFigure*>( selectionRect->selected( index ) );
}

void J_ClippingPath::cutFigure( GVectorFigure *figureForClip, GVectorFigure *clippingPath ){
    QPolygonF pointsOfFigure = getPointsOfFigure( figureForClip );
    QPolygonF pointsOfPath  = getPointsOfFigure( clippingPath );
    QPolygonF clippedPoints = intersectOfPoints( pointsOfFigure, pointsOfPath, figureForClip->isClosed(), clippingPath->isClosed() );
    figureForClip->setPoints( clippedPoints, figureForClip->frame() );
    //оепедекюрэ setPoints() !!!!!!!!!!!!!!!!!!!!
}

QPolygonF J_ClippingPath::getPointsOfFigure( GVectorFigure *figure ){
    return figure->points(figure->frame());
}

QPolygonF J_ClippingPath::intersectOfPoints( QPolygonF pointsOfFigure, QPolygonF pointsOfPath, bool closedOfFigure, bool closedOfPath ){

    QPainterPath pone;
    pone.moveTo( pointsOfFigure[0] );
    int countSplinePointsOfFigure = getCountSplinePoints( pointsOfFigure );
    for( int i = 1; i < ( countSplinePointsOfFigure + 1 ); i += 3 )
        pone.cubicTo(pointsOfFigure[i], pointsOfFigure[i + 1], pointsOfFigure[i + 2] );
    if( closedOfFigure )
        pone.closeSubpath();

    QPainterPath ptwo;
    ptwo.moveTo( pointsOfPath[0] );
    int countSplinePointsOfPath = getCountSplinePoints( pointsOfPath );
    for( int i = 1; i < ( countSplinePointsOfPath + 1 ); i += 3 )
        ptwo.cubicTo(pointsOfPath[i], pointsOfPath[i + 1], pointsOfPath[i + 2] );
    if( closedOfPath )
        ptwo.closeSubpath();

    QPainterPath unioin=pone.intersected(ptwo);
    pone=unioin;
    QMatrix qm;
    QPolygonF pmain=pone.toFillPolygon(qm);
    QPolygonF newMain;
    int countPoints=pmain.size();
    for( int i = 0; i < countPoints; i++ )
    {
        QPointF curPoint=pmain[i];
        if(i == 0 || i == (countPoints-1))
            newMain << curPoint<< curPoint;
        else
            newMain << curPoint<< curPoint<< curPoint;
    }
    return newMain;
}

int J_ClippingPath::getCountSplinePoints(QPolygonF points){
    return ( ( points.size() - 1 ) / 3 ) * 3;
}

void J_ClippingPath::createPlugin(QObject *parent, QString idParent,
        plugin::PluginsManager *manager)
{
    if(idParent == "Main")
    {
        MainWindowInterface *mainWin = MAINWINDOW(parent);
        if(mainWin!=0)
        {

            PaintWidgetInterface *painter = PAINTWIDGETINTERFACE(mainWin->getPaintWidget());
            RPWInterface *rpwi = RPWINTEFACE(painter->getRealPaintWidget());
            selectionRect = GSRINTEFACE(rpwi->getSelection());
            QMenu* ObjectMenu = mainWin->getObjectMenu();
            ActionClippingPath = new QAction(tr("&Clip"), this);
            ActionClippingPath->setEnabled(true);
            ObjectMenu->addAction( ActionClippingPath );
            connect(ActionClippingPath,SIGNAL( triggered( bool ) ),
                    this, SLOT( clip() ) );
        }
    }
    connect( this, SIGNAL( setActive( QString ) ), getBeep(), SIGNAL( setActive( QString ) ) );
    manager->addPlugins(this,"ClippingPath");
}

QWidget* J_ClippingPath::getWidget() {
    return 0;
}

QString J_ClippingPath::getName()const
{
    return "ClippingPath";
}

QIcon J_ClippingPath::icon()
{
    return QIcon( ":/clippingpath/images/clippingpath.png" );
}

FigureToolInterface::CreateStyle J_ClippingPath::createStyle() const
{
    return createAndResize;
}

FigureToolInterface::FiguresInfo J_ClippingPath::figure() const
{
    FigureInfo info;
    return ( FiguresInfo() << info );
}

QString J_ClippingPath::description() const
{
    return tr( "ClippingPath" );
}

QString J_ClippingPath::figureName() const
{
    return tr( "ClippingPath" );
}

void J_ClippingPath::toolSelected()
{
    emit setActive(getName());
}

J_ClippingPath::J_ClippingPath(const plugin::PluginsManager *manager )
{
    if( !resourcesInited )
    {
        Q_INIT_RESOURCE( ClippingPath );
        resourcesInited = true;
    }

}

J_ClippingPath::~J_ClippingPath()
{
    delete ActionClippingPath;
}

EXPORT_PLUGIN( J_ClippingPath, FigureToolInterface )


