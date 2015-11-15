#include "ClippingPath.h"

bool ClippingPath::resourcesInited = false;

void ClippingPath::clip(){
    GVectorFigure *figureForClip( 0 );
    GVectorFigure *clippingPath = getLastFigure();
    int indexOfLastFigureForClip = getIndexOfLastFigure() - 1;
    for (int i = 0; i < indexOfLastFigureForClip; i++){
        figureForClip = getFigureByIndex( i );
        cutFigureOnPath( figureForClip, clippingPath );
    }
    clippingPath->setVisible(false);
    selectionRect->reset();
}

GVectorFigure* ClippingPath::getLastFigure(){
    int countClipFigures = selectionRect->countSelected() - 1;
    return dynamic_cast<GVectorFigure*>( selectionRect->selected( countClipFigures ));
}

GVectorFigure* ClippingPath::getFigureByIndex( int index ){
    return dynamic_cast<GVectorFigure*>( selectionRect->selected( index ) );
}

int ClippingPath::getIndexOfLastFigure(){
    return selectionRect->countSelected();
}

void ClippingPath::cutFigureOnPath( GVectorFigure *figureForClip, GVectorFigure *clippingPath ){
    QPolygonF pointsOfFigure = getPointsOfFigure( figureForClip );
    QPolygonF pointsOfPath  = getPointsOfFigure( clippingPath );
    QPolygonF pointsOfClippedFigure = intersectOfPoints( pointsOfFigure, pointsOfPath, figureForClip->isClosed(), clippingPath->isClosed() );
    figureForClip->setPoints( pointsOfClippedFigure, figureForClip->frame() );
}

QPolygonF ClippingPath::getPointsOfFigure( GVectorFigure *figure ){
    return figure->points( figure->frame() );
}

QPolygonF ClippingPath::intersectOfPoints( QPolygonF pointsOfFigure, QPolygonF pointsOfPath, bool closedOfFigure, bool closedOfPath ){
    QPainterPath painterFigure = paintPath( pointsOfFigure );
    if( closedOfFigure )
        painterFigure.closeSubpath();
    QPainterPath painterPath = paintPath( pointsOfPath );
    if( closedOfPath )
        painterPath.closeSubpath();
    QPolygonF polygonIntersection = ( painterFigure.intersected( painterPath )).toFillPolygon();
    QPolygonF pointsOfClippedFigure = polygonToPointsOfFigure( polygonIntersection );
    return pointsOfClippedFigure;
}

int ClippingPath::getCountSplinePoints(QPolygonF points){
    return ( ( points.size() - 1 ) / 3 ) * 3;
}

QPainterPath ClippingPath::paintPath(QPolygonF points){
    QPainterPath painterFigure;
    painterFigure.moveTo( points[0] );
    int countSplinePointsOfFigure = getCountSplinePoints( points );
    for( int i = 1; i < ( countSplinePointsOfFigure + 1 ); i += 3 )
        painterFigure.cubicTo(points[i], points[i + 1], points[i + 2] );
    return painterFigure;
}

QPolygonF ClippingPath::polygonToPointsOfFigure(QPolygonF polygon){
    QPolygonF pointsOfFigure;
    int countPolygon = polygon.size();
    for( int i = 0; i < countPolygon; i++ ){
        if( i == 0 || i == ( countPolygon - 1 ))
            pointsOfFigure << polygon[i] << polygon[i];
        else
            pointsOfFigure << polygon[i] << polygon[i] << polygon[i];
    }
    return pointsOfFigure;
}

void ClippingPath::createPlugin(QObject *parent, QString idParent, plugin::PluginsManager *manager)
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

QWidget* ClippingPath::getWidget()
{
    return 0;
}

QString ClippingPath::getName()const
{
    return "ClippingPath";
}

QIcon ClippingPath::icon()
{
    return QIcon( ":/clippingpath/images/clippingpath.png" );
}

FigureToolInterface::CreateStyle ClippingPath::createStyle() const
{
    return createAndResize;
}

FigureToolInterface::FiguresInfo ClippingPath::figure() const
{
    FigureInfo info;
    return ( FiguresInfo() << info );
}

QString ClippingPath::description() const
{
    return tr( "ClippingPath" );
}

QString ClippingPath::figureName() const
{
    return tr( "ClippingPath" );
}

void ClippingPath::toolSelected()
{
    emit setActive(getName());
}

ClippingPath::ClippingPath(const plugin::PluginsManager *manager )
{
    if( !resourcesInited )
    {
        Q_INIT_RESOURCE( ClippingPath );
        resourcesInited = true;
    }

}

ClippingPath::~ClippingPath()
{
    delete ActionClippingPath;
}

QObject* ToolButton::getTool()
{
    return tool;
}

void ToolButton::setTool(QObject* t)
{
    tool = FIGURETOOL(t);
}

ToolButton::ToolButton( FigureToolInterface *_tool, QWidget *parent ):
    ToolButtonInterface( parent ), tool( _tool )
{
    setIcon( tool->icon() );
    setToolTip( tool->description() );

    connect( this, SIGNAL( clicked( bool ) ),
            this, SLOT( onClicked( bool ) ) );
}

ToolButton::~ToolButton()
{
    delete tool;
}

void ToolButton::onClicked( bool checked )
{
    if( !checked ) return;

    tool->toolSelected();
    emit toolSelected( tool );
}

EXPORT_PLUGIN( ClippingPath, FigureToolInterface )


