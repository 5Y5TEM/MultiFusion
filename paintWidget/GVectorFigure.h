#ifndef __GVECTOR_FIGURE_H__
#define __GVECTOR_FIGURE_H__

#include <QObject>
#include <QGradient>
#include <QPainter>
#include <QPainterPath>

#include "GObject.h"
#include "GFramesProperties.h"
/**
*	@file gvectorfigure.h ������ ���� �������� �������� ������, ������������ ��������� ������,
*			�������� �� �����.
*/

/**
*		�����, ����������� ��������� ������,
*			�������� �� �����.
*/
class GVectorFigure:public GObject
{
	Q_OBJECT

	public:

		virtual void setHideLines(int value);

		virtual int getHideLines();

		/**
		 * ��������� ������ � ������������ �����
		 */
		virtual void toNormal();
		/**
		 * ��������� ������ � ���������� �����
		 */
		virtual void toSpline();

		/**
		 * ��������� �������� �� ������ � ����������
		 */
		virtual bool isSpline();

		/**
		 * ����� ��������� ��� ������ ����� ����� ��� ���
		 * @param value true ���� ����������
		 */
		virtual void setShowBezier(bool value);

		/**
		 * ��������� ��������� ��� ������ ����� ����� ��� ���
		 * @return true ���� ����������
		 */
		virtual bool isShowBezier();

		/**
		 *  ����������� �������� �������
		 */
		virtual GObjectInterface* copyObject();

		/**
		*	������� ���� � ��������� �������, ���� ���� ���� ����������.
		*
		*	@param frame ����� ���������� �����.
		*/
		virtual void deleteFrame( int position );

		/**
		 * ������� ��� ����� ����� frame
		 * @param frame, ���� ����� -1 ������� ��������� ��� �����
		 */
		virtual void deleteFrames( int frame );

		/**
		*	��������� ���� �� �������.
		*
		*	@param position - ������� �� ���������;
		*/
		virtual void addFrame( int position, bool visible );

		/**
		*	��������� ���� �� ������� c ������������ �������.
		*	@param polF - �����
		*	@param position - ������� �� ���������;
		*/
		virtual void addFrameWithPoints( int position, QPolygonF polF);

		/**
		*	��������� ��������� ���� � ��������� ��� ����� ����������.
		*
		*	@param frame ����, ������� ���������� ������������.
		*	@param pasteTo ����, ����� �������� ����� �������� ����� ����.
		*/
		virtual void cloneFrameBefore( int frame, int pasteTo );

		/**
		*	��������� ��������� ���� � ��������� ��� ����� ���������.
		*
		*	@param frame ����, ������� ���������� ������������.
		*	@param pasteTo ����, ����� ������� ����� �������� ����� ����.
		*/
		virtual void cloneFrameAfter( int frame, int pasteTo );

		/**
		*	���������� ��� �������������� ����� �������.
		*
		*	@return ��� �������������� �����.
		*/
		virtual GLinesType type() const;

		/**
		 * ���������� ������ ����� � ������ �� ������� � ���������
		 */
		virtual int getIndexFrameByPosition(qreal frame) const;

		/**
		*	���������� true, ���� � ������ ������ ������ ����� �������������.
		*
		*	@return true, ���� � ������ ������ ������ ����� �������������.
		*/
		virtual bool isEditable() const;

		/**
		*	���������� true, ���� ������ �������� �����������.
		*
		*	@return true, ���� ������ �������� �����������.
		*/
		virtual bool isContainer() const;

		/**
		*	���������� true, ���� ������ � ������ ����� �������� ����������������.
		*	@param frame ������ ����
		*	@return true, ���� ������ � ������ ������ ����������
		*/
		virtual bool isTransformed(int frame) const;

		/**
		*	������������� ������ � ������ ����� ���������������� ���� transform ����� true.
		*	@param frame ������ ����
		*/
		virtual void setTransformed(int frame, bool transform);

		/**
		*	���������� true, ���� ������ � ������ ������ ����������.
		*
		*	@return true, ���� ������ � ������ ������ ����������
		*/
		virtual bool isBlocked() const;

		/**
		*	������������� ���������� �������.
		*
		*	@param blocked ���������� �������.
		*/
		virtual void setBlocked( bool blocked );

		/**
		*	���������� true, ���� ������ � ������ ������ ����� ������ �� ������.
		*
		*	@return true, ���� ������ � ������ ������ ����� ������ �� ������.
		*/
		virtual bool isVisible() const;

		/**
		*	������������� ��������� �������.
		*
		*	@param visible ��������� �������.
		*/
		virtual void setVisible( bool visible );

		/**
		*	���������� ��������� �� ������, ������� �������� ������ �����.
		*
		*	@param p ��������� �����, �� ������� ���������� ���������� ������.
		*
		*	@return ��������� �� ������, ������� �������� ������ �����.
		*
		*	@warning ���� �� ���� ������ � ���������� �� �������� ��� �����,
		*		�� ����� ��������� 0.
		*/
		virtual GObject* contains( const QPoint &p );

		/**
		*	���������� ������� ������� ������� � �������� (������� ����).
		*
		*	@return ������� ������� ������� � �������� (������� ����).
		*/
		virtual qreal frame() const;

		/**
		*	������������ ������� ���� ��� �������.
		*
		*	@param f ��������������� ����.
		*/
		virtual void setFrame( qreal f );

		/**
		*	���������� ����� ���������� ������, ������� ��� ������� ��� ����� �������.
		*
		*	@return ����� ���������� ������, ������� ��� ������� ��� ����� �������.
		*/
		virtual int countFrames() const;

		/**
		*	���������� ���������� ��������������, � ������� ������ ������ ������.
		*
		*	@return ���������� ��������������, � ������� ������ ������ ������.
		*/
		virtual QRectF boundingRect();

		/**
		*	���������� ��� �����, �� ������� ������� ������ ������.
		*
		*	@return �����, �� ������� ������� ������ ������.
		*/
		virtual QPolygonF points(int frame);

		/**
		*	��������� ����� ����� � ������.
		*
		*	@param p ���������� ����������� �����.
		*
		*	@return ������ ��������������� �����.
		*/
		virtual int addPoint( const QPoint &p );

		/**
		*	��������� ����� ����� � ������, �� ��������� ��������� ��������� ������ ������� -
		*		�.�. ����� ������ ����������� � ����� ������.
		*
		*	@param p ���������� ����������� �����.
		*
		*	@return ������ ��������������� �����.
		*/
		virtual int addPointToEnd( const QPoint &p );

		/**
		*	������� ����� �� � ������� �� �������.
		*
		*	@param index ������ ��������� �����.
		*
		*	@return true, ���� ����� ���� �������.
		*/
		virtual bool deletePoint( int index );

		/**
		*	���������� ���� �� ����� ������ �� ����� �����.
		*
		*	@param index ������ ������������ �����.
		*	@param newPosition ����� ��������� �����.
		*/
		virtual void movePoint( int index, const QPointF &newPosition );

		/**
		*	��������� ���� �� ������ ����� �������, ��� �� �������� ��� ��������� �����.
		*
		*	@param frame ����������� ����.
		*/
		virtual void cloneFrameToAll( int frame );

		/**
		*	���������� ����������� ������� �������.
		*
		*	@param dx �������� �� ��� X.
		*	@param dy �������� �� ��� Y.
		*/
		virtual void move( qreal dx, qreal dy );

		/**
		*	���������� ��������������� �������.
		*
		*	@param sx ����������� ��������������� �� ��� X.
		*	@param sy ����������� ��������������� �� ��� Y.
		*	@param scaleCenter �����, ������������ ������� ������������ ��������������.
		*/
		virtual void scale( qreal sx, qreal sy, const QPointF &scaleCenter );

		/**
		*	���������� ����������� ����� ��������� ����� �������.
		*
		*	@param sx ����������� ������ �� ��� X.
		*	@param sy ����������� ������ �� ��� Y.
		*	@param scaleCenter �����, ������������ ������� ������������ �����
		*					(�.�., ����������, �����, ������� �� ���������� �����).
		*/
		virtual void sheare( qreal sx, qreal sy, const QPointF &shearPoint );

		/**
		*	���������� �������� ������.
		*
		*	@param angle ����, �� ������� ������������ �������.
		*	@param center �����, ������ ������� ������������ �������.
		*/
		virtual void rotate( qreal angle, const QPointF &center );

		/**
		*	���������� ��� � ��������� ����� �������.
		*
		*	@return ��� � ��������� ����� �������.
		*/
		virtual QPen pen() const;

		/**
		*	���������� ��� � ��������� ������� �������.
		*
		*	@return ��� � ��������� ������� �������.
		*/
		virtual QBrush brush() const;

		/**
		*	������������� ��� � ��������� ����� �������.
		*
		*	@param p ��� � ��������� ����� �������.
		*/
		virtual void setPen( const QPen &p );

		/**
		*	������������� ��� � ��������� ������� �������.
		*
		*	@param p ��� � ��������� ������� �������.
		*/
		virtual void setBrush( const QBrush &b );

		/**
		*	��������� ������ �� �����������.
		*
		*	@return true, ���� ������ ��������.
		*/
		virtual bool isClosed() const;

		/**
		*	������������� ����������� ������.
		*
		*	@param closed ����������� ������.
		*/
		virtual void setClosed( bool _closed );

		/**
		*	��������� �������� ������������ ������.
		*
		*	@return �������� ������������(�� 0 �� 255%).
		*/
		virtual int getAlpha();

		/**
		*	����� ������������ ������.
		*
		*	@param _alpha �������� ������������(�� 0 �� 255).
		*/
		virtual void setAlpha( int _alpha );

		/**
		 * ���������� ������� ������� ����� �������� ��������� ������
		 */
		virtual bool getIndexFrames();

		/**
		*	������������ ������� ���� ������.
		*
		*	@param p ��, ���� ����� ������������ ���������.
		*/
		virtual void paint( QPainter &p );

				/**
				*	�����������.
				*
				*	@param points �����, �� ������� ����� ������� ������������� ������.
				*		�������� �� ��������� - ������ QPolygonF (�.�. ������ �� ����� ��������� �� ����� �����).
				*
				*	@param _spline �������� �� ��, ����� �� ��������� ����� ��������� ��� �������.
				*		�������� �� ��������� - false (�.�. ������ ����� ��������� �������).
				*
				*	@param _closed �������� �� ����������� ������.
				*		�������� �� ��������� - false (�.�. ������ �� ����� ��������).
				*/
				GVectorFigure( const QPolygonF &points = QPolygonF(),
								bool _spline = false, bool _closed = false, int position = 0);

				/**
				 * ���������� �����������
				 */
				GVectorFigure( GVectorFigure* vf );

		/**
		*	����������.
		*/
		virtual ~GVectorFigure();

	protected:

		/**
		*	��������� ���� ������ ������� � �����.
		*
		*	@param stream �����, � ������� ����������� ������.
		*/
		virtual void save( QDataStream &stream ) const;

		/**
		*	������ ���� ������ ������� �� ������.
		*
		*	@param stream �����, �� �������� ���������� ������.
		*/
		virtual void load( QDataStream &stream );

	private:
		GFramesProperties properties;
		bool showBiese;
		qreal _frame;
		int itemMax;
		int itemMin;
		GLinesType	_linesType;
		QPen alphaPen;
		QBrush alphaBrush;
		QPen _pen;
		int hideLines;
		QBrush _brush;
		bool closed;

		virtual GProperties currentFrame() const;
		virtual void paintObject( QPainter &p, const GProperties &props ) const;

		void drawSplines( QPainter &p, const GProperties &props ) const;

		QPen interpolatedPen() const;
		QBrush interpolatedBrush() const;

		int addPointToPolygon( const QPointF &p );
		int addPointToEndOfPolygon( const QPointF &p );
		int addPointToSpline( const QPointF &p );
};

template < class T > inline GVectorFigure* GVECTORFIGURE( T *o )
{
	return qobject_cast< GVectorFigure* >( o );
}


#endif /* __GVECTOR_FIGURE_H__ */
