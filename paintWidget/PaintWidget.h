
/**
*	@mainpage ������������ �� GCore
*
*		� ������ ������� �� ������ ������������ �� GCore - ����������, ����������� ���������
*	������������ ������, ������������� �� �, ��� ��, �������������.
*/

#ifndef PAINT_WIDGET_H
#define PAINT_WIDGET_H

#include "PWE.h"
#include "RPW.h"
#include "./../interfaces/PaintWidgetInterface.h"
#include "./../interfaces/GObjectInterface.h"

#include "../interfaces/MainWindowInterface.h"

/**
*	@file paintwidget.h ������ ���� �������� �������� ������, ����������������, ����������, �������
*				����������, ����������� ������������� �������� �/��� ����������� �.
*/

/**
*		�����, ����������� ������� ����������,
*	����������� ������������� �������� �/��� ����������� �.
*
*	@warning ������ ������ � ��������� ����� ������� �� ��������� ��������. ���:<br>
*			Background<br>
*			BrushEditor<br>
*		������, BrushEditor, �� ����� ����, ��������� ������� Background. � �������� �������,
*	��������, ������ ����������� ����� ���������.
*/
class PaintWidget:public PaintWidgetInterface
{
	Q_OBJECT
	Q_INTERFACES(PaintWidgetInterface)
	signals:

		 /**
		 * ������������ ����� ���������� �������, ������� ��� ����� ��������� � �������
		 * @param event ��� �������
		 */
		void StateChanged(QString event);

		/**
		 * ������������ ��� ����������� �� ������� �������
		 */
		void undoEvents();

		/**
		 * ������������ ��� ����������� ���� ��� ������
		 */
		void movedObject();

		/**
		*	������������ � ������ �������� ������ ������.
		*/
		void objectCreated();

		/**
		*	������������ ������ ���, ����� ��������� ������� ������������ ����.
		*
		*	@param frame ����� ������� ����.
		*/
		void frameChanged( qreal frame );

		/**
		*	������������ ������ ���, ����� ���������� ����� ���������� ������ � ��������.
		*/
		void countFramesChanged( int count );

		/**
		*	������������ ������ ��� ��� �������� ���������.
		*
		*	@param layer ����� ���������� ����, ��� -1, ���� �� ���� ���� �� ������.
		*/
		void layerSelected( );

		/**
		*		���������� � ��� ������, ����� ��������� ���������� ��������� ����
		*	(��������, ��� ���� ��� �������).
		*/
		void allLayersChanged();

		/**
		 * ����������, ����� � ������� ��������� ��� �����
		 */
		void isFrame(bool value);

		void figureSelected(int layer , int obj);

		/**
		*		������ ��� ����������� �������������, ���������� � ��� ������, ����� ����������
		*	��������� ������� ���� ��� ������� �������.
		*/
		void backgroundChanged( QWidget *from );

	public:
                MainWindowInterface* mainWin;

		/**
		 * ������ �������� ������ � ������� ���� ��� ���
		 */
		virtual void setHideFigures(int layer, bool value);

		/**
		 * ��������� �������� ������ � ������� ���� ��� ���
		 */
		virtual bool getHideFigures(int layer);

		/**
		 * �������� ����� ����� ���������� ����� ����� ������ �����
		 * @return ���������� �����
		 */
		virtual int getFigureHideLines();

		/**
		 * ����� ����� ����� ���������� ����� ����� ������ �����
		 * @param value ���������� �����
		 */
		virtual void setFigureHideLines(int value);

		/**
		 * ��������� �������� �� ������ � ����������
		 * @return 1 ���� ��, 0 ���� ��� -1 ���� ��� ���������
		 */
		virtual int FigureIsSpline();

		/**
		 * ��������� ������ � ���������� ����� ��� ���������� � ���������� �� spline
		 */
		virtual void FigureSetStyle(bool spline);

		/**
		 * ����� ��������� ��� ������ ����� ����� ��� ���
		 * @param value true ���� ����������
		 */
		virtual void FigureSetShowBezier(bool value);

		/**
		 * ����� ��������� ��� ������ ����� ����� ��� ���
		 * @return 1 ���� ��, 0 ���� ��� -1 ���� ��� ���������
		 */
		virtual int FigureIsShowBezier();

		/**
		 * ���������� ������������ ����
		 */
		virtual int maxFrame();

		/**
		 * ��������� ���� �� � ������� ������� ��������� ���� ��� ������� ����
		 * @param layer ������ ����
		 */
		virtual bool isContainsFrame(int layer);

		/**
		 * 	���������� ������� ����� �� ���������
		 * @param i ������� � ������
		 * @return ������� �� ���������
		 */
		virtual int getPositionFrame(int i);

		/**
		*	������������� ������� ���� ��������.
		*
		*	@param frame ��������������� ���� ��������.
		*/
		virtual void setFrame( qreal frame, bool played );

		/**
		*	���������� ������� ���� ��������.
		*
		*	@return ������� ���� ��������.
		*/
		virtual int frame() const;

		/**
		*	���������� ������� ����.
		*
		*	@return ������� ����.
		*/
		virtual int layer() const;

		/**
		*	���������� ����� ���������� ������, ������������ � ������.
		*/
		virtual int countFrames() const;

		/**
		*	������������ ������� ����.
		*
		*	@param s ����������� ���������������.
		*
		*	@warning �������������� ������ ������� ����.
		*/
		virtual void scale( qreal s );

		/**
		*	��������� �� ����������� ����������� ���������� ��������.
		*
		*	@return true, ���� ����������� ��������.
		*/
		virtual bool canGroup();

		/**
		*	��������� �� ����������� �������������� ���������� ��������.
		*
		*	@return true, ���� �������������� ��������.
		*/
		virtual bool canUngroup();

		/**
		*	���������� ���������� �������, ���� ��� ��������.
		*/
		virtual void group();

		/**
		*	����������������� ���������� �������, ���� ��� ��������.
		*/
		virtual void ungroup();

		/**
		 * �������� �������� �� ������ �����������
		 * @param layer ���� � ������� ��������� ������
		 * @param object ������
		 */
		virtual bool objectIsContainer(int layer, int object);

		/**
		*	���������� ��� � ��������� ����� ����������� �������.
		*
		*	@return ��� � ��������� ����� ����������� �������.
		*/
		virtual QPen pen();

		/**
		*	���������� ��� � ��������� ������� ����������� �������.
		*
		*	@return ��� � ��������� ������� ����������� �������.
		*/
		virtual QBrush brush();

		/**
		*	������������� ��� � ��������� ����� ����������� �������.
		*
		*	@param p ��� � ��������� ����� ����������� �������.
		*/
		virtual void setPen( const QPen &p );

		/**
		*	������������� ��� � ��������� ������� ����������� �������.
		*
		*	@param p ��� � ��������� ������� ����������� �������.
		*/
		virtual void setBrush( const QBrush &b );

		/**
		*	��������� ���������� ������ �� �����������.
		*
		*	@return true, ���� ������ ��������.
		*/
		virtual bool isClosed() const;

		/**
		*	������������� ����������� ���������� ������.
		*
		*	@param closed ����������� ������.
		*/
		virtual void setClosed( bool closed );

		virtual int countFigures(int layer) const;

		/**
		*	��������� ��������� ������ �� ���������������.
		*
		*	@param layer ����, ������� �������� ������.
		*
		*	@param object ������, ����������� �� ���������������.
		*/
		virtual bool isFigureBlocked(  int layer, int object  ) const;

		/**
		 * ������ ��������������� ������ � ����
		 * @param layer - ����� ����
		 * @param obj - ����� ������
		 * @param visible �������� ����������
		 */
		virtual void setFigureBlocked( int layer, int obj, bool blocked );

		virtual bool isFigureVisible(  int layer, int object  ) const;

		virtual void setFigureVisible( int layer, int obj, bool visible );

		/**
		 * ��������� �������� �� ������ ����������������
		 * @param layer ���� � ������� ��������� ������
		 * @param object ����� ������
		 * @return true ���� ���������������
		 */
		virtual bool isFigureTransformed(  int layer, int object  ) const;

		/**
		 * ���������� ������������������ ������
		 * @param layer ���� � ������� ��������� ������
		 * @param object ����� ������
		 * @param trns �������� ������������������
		 */
		virtual void setFigureTransformed( int layer, int obj, bool trns );

		virtual QString figureName( int layer, int object  ) const;

		virtual void renameFigure( int layer, int obj,  const QString &name );

		virtual void deleteFigure(int layer, int obj );

		/**
		*	������������� ��������� �� ��������� ���� � ��������� ������
		*
		*	@param layer ���������� ����.
		*
		*	@param obj ���������� ������.
		*/
		virtual void selectFigure( int layer, int obj);

		virtual int selectedFigure();

		/**
		 * ��������� ����� ����
		 */
		virtual void addLayer(bool visible, bool blocked, const QString &name);

		/**
		*	���������� ������� ���������� ����.
		*
		*	@return ������� ���������� ����.
		*/
		virtual int countLayers() const;

		/**
		 * ������ ������� ����.
		 */
		virtual void setLayer(int layer);

		/**
		*	���������� ��� ���������� ����.
		*
		*	@param layer ����, ��� �������� �������������.
		*
		*	@return ��� �������������� ����.
		*/
		virtual QString layerName( int layer );

		/**
		*	��������������� ��������� ����.
		*
		*	@param layer ����.
		*	@param name ����� ��� ����.
		*/
		virtual void renameLayer( int layer, const QString &name );

		/**
		*	���������� ����� ���������� ����. ��� -1, ���� �� ������.
		*
		*	@return ����� ���������� ����. ��� -1, ���� �� �� ������.
		*/
		virtual int selectedLayer();

		/**
		*	��������� ��������� ���� �� ��������������� �� ������.
		*
		*	@param layer ����, ����������� �� ���������������.
		*
		*	@return true, ���� ���� ����������.
		*/
		virtual bool isLayerBlocked( int layer ) const;

		/**
		*	������������� ��������������� ���������� ���� � ������ �����.
		*
		*	@param layer ����.
		*	@param blocked ��������������� ���� � ������ �����.
		*/
		virtual void setLayerBlocked( int layer, bool blocked );

		/**
		*	��������� ��������� ���� �� ��������� �� ������.
		*
		*	@param layer ����, ����������� �� ���������.
		*
		*	@return true, ���� ���� �����.
		*/
		virtual bool isLayerVisible( int layer ) const;

		/**
		*	������������� ��������� ���������� ���� � ������ �����.
		*
		*	@param layer ����.
		*	@param visible ��������� ���� � ������ �����.
		*/
		virtual void setLayerVisible( int layer, bool visible );

		/**
		*	������� ���� �� �������.
		*/
		virtual void deleteFrame(int position);

		/**
		 * ��������� ���� � ����������� �������
		 * @param position
		 */
		virtual void addFrame(int position);

		/**
		*		������������� ����������, ���������� �� ����� �������� � �� �� �����������
		*	(����������� �����), ��� �������.
		*/
		virtual void setSelectionTool();

		/**
		*		������������� ����������, ���������� �� ���������� ����� �
		*	��������� ������, ��� �������.
		*/
		virtual void setAddPointTool();

		/**
		*	������������� ����� ����������, ��� �������.
		*
		*	@param tool ������, ����������� ��������� �����������.
		*/
		virtual void setTool( QObject *tool );


		/**
		*	������������� ��������� ���� �������� ����.
		*
		*	@param to ��� ��, ���� ����� ��������� ����������� ����.
		*	@param r �������������, � ������� ����� �������������� ����.
		*	@param frame ����, ������� ����� ���������.
		*/
		virtual void paintFrameTo( QPainter &to, const QRect &r, qreal frame );

		/**
		*	������������� ��������� ����.
		*
		*	@param to ��� ��, ���� ����� ��������� ����������� ����.
		*	@param r �������������, � ������� ����� �������������� ����.
		*	@param frame ����, ������� ����� ���������.
		*/
		//virtual void paintWholeFrameTo( QPainter &to, const QRect &r, qreal frame );

		/**
		*		���������� ����� ������������� ��������.
		*	��������� ��� �������, �� ������� ������� ��������.
		*/
		virtual bool reset();

		/**
		*	��������� ��������� ������� � �����.
		*
		*	@param stream �����, � ������� ������������ ������.
		*/
		virtual void save( QDataStream &stream ) ;

		/**
		*	��������� ��������� ������� �� ������.
		*
		*	@param stream �����, �� �������� �������� ��������.
		*/
		virtual bool load( QDataStream &stream );

		/**
		*	��������� ����������� �������� ��������� ��������.
		*
		*	@return true, ���� ��� ��������.
		*/
		virtual bool canDeleteSelected() const;

		/**
		*	������� ��������� �������, ���� ��� ��������.
		*/
		virtual void deleteSelected();

		/**
		*	��������� ����������� ����������� ��� �������� � ������ ������ ��������� �������.
		*
		*	@return true, ���� ��� ��������.
		*/
		virtual bool canCopyOrCutToClipboard() const;

		/**
		*	��������� ����������� �������� ������ �� ������� ������.
		*
		*	@return true, ���� ��� ��������.
		*/
		virtual bool canPasteFromClipboard() const;

		/**
		*	�������� � ������ ������ ���������� �������, ���� ��� ��������.
		*/
		virtual void cutToClipboard();

		/**
		*	�������� � ������ ������ ���������� �������, ���� ��� ��������.
		*/
		virtual void copyToClipboard();

		/**
		*	��������� �� ������� ������ �������, ���� ��� ��������.
		*/

		virtual void pasteFromClipboard();

		/**
		*	����� ������������ ���� ��� ������� ���������.
		*	@*qMenu - ����������� ������������ ����
		*/
        virtual void setContextMenu(QMenu *qMenu);

		/**
		*	�������� ������������ ���� ��� ������� ���������.
		*	@return - ��������� �� ������������ ����
		*/
        virtual QMenu* getContextMenu();

		/**
		*	�������� ������ �������� ������� �������. ��������.
		*/
		virtual void showConfig();

		/**
		*	���������� ��� ������������� ������������/������������� ������.
		*
		*	@return ��� ������������� ������������/������������� ������.
		*/
		virtual ViewportType viewportType()const;

		virtual void setViewportType( const ViewportType t );

		virtual QSize viewportFixedSize() const;

		virtual void setViewportFixedSize( const QSize &s );

		///virtual QColor& getViewportColor();

		virtual void setViewportColor( const QColor &c );

        virtual QObject* getRealPaintWidget();

		virtual void updateAllViews( QWidget *from );

		virtual void doViewportTransparent();

		/**
		*	�����������.
		*
		*	@param parent ������������ ��� ������� ������� ������.
		*		����� ��������� �������� 0.
		*
		*	@param manager �������� ��������. ��������� ��� ��������
		*		Background � BrushEditor ��� ����� ������ Background.
		*/
		PaintWidget( QWidget *parent, plugin::PluginsManager *manager);

		/**
		*	����������.
		*/
		virtual ~PaintWidget();

	public slots:

		/**
		*  ���������� ������ ����� ������ � ������ ���� �� �������
		*/
		void moveFigure( int layerOld, int objOld, int layerNew, int objNew );

		/**
		*  ���������� ���� �� �������
		*/
		void moveLayer(int layerOld, int layerNew);

	private:

        RealPaintWidget painter;
		bool transparent;
		QColor viewportColor;
		friend class PaintWidgetEditor;
};

/**
*	@example AnimPlayer ������, ������������ ��� � ������� PaintWidget-� ��������� ����� ��������,
*		��������� � ������� ���������� GCore.
*
*	@code
*
*	// ���������� ����������� ������������ �����:
*	#include <QApplication>
*	#include "paintwidget.h"	//��� ��� PaintWidget
*	#include "plugin.h"			//� ���, ����������, �������� ��������, �������
*								//����� PaintWidget-� ��� �������� ������ ��� ��������.
*
*	int main( int argC, char *argV[] )
*	{
*		QApplication app( argC, argV );			//������ ������ QApplication - ��� ���� ����� ������ �� ��������� :)
*		plugin::PluginsManager manager( "./" );	//������ PluginsManager � ��������� ���, ��� ������� ����� ������ � ������� �����.
*		PaintWidget player( 0, manager );		//������ ��� ������, ������� ����� ���������� �����.
*
*		QFile file( "./test.sacs2" );	//��������� ���� � ������������ �������.
*		QDataStream s( &file );			//������ �� ����� �����.
*		s.setVersion( QDataStream::Qt_4_2 ); //��� ����� ��� ������������� � ��������� ������� Qt.
*
*		player.load( s );	//��������� ��������.
*		player.setEnabled( false );	//�� ������ ������ ��������� ����� ����������� �������������� ������.
*		player.show();	//���������� �������������.
*		player.play();	//��������� ������������.
*
*		return app.exec();	//��������� ���� ��������� ���������.
*	}
*
*	@endcode
*
*	��, ��� ����� ������� ������ ������������� ����� :)
*
*	@warning ����� ���������� �� ������� �������� � ����� � ������������ ���������� ������ � �������,
*		����������� ��� ������ PaintWidget-� (��� Background � BrushEditor).
*
*/

#endif
