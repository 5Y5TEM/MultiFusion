#ifndef __GSELECTION_RECT_H__
#define __GSELECTION_RECT_H__

#include <QObject>
#include <QPainter>
#include <QPainterPath>
#include <QMessageBox>
#include "../PluginTool/plugin.h"
#include "../interfaces/GSRInterface.h"
#include "../interfaces/GObjectInterface.h"
#include "GContainer.h"


/**
*	@file gselectionrect.h ������ ���� �������� �������� ������, ������������ ����� ���������
*		����������� ��������. �� ��� �� ��������� ���������� ��������� �������� � �����������
*		���������, ����� ��� �� �����������, ��������� �� ������� � ������.
*/

/**
*		���� ����� ��������� ����� ��������� ����������� ��������. �� ��� �� ��������� ����������
*	��������� �������� � ����������� ���������, ����� ��� �� �����������, ��������� �� ������� �
*	������.
*/
class GSelectionRect: public GSRInterface
{
	Q_OBJECT
	Q_INTERFACES(GSRInterface)

	signals:

		/**
		 * ������������ ����� ���������� �������, ������� ��� ����� ��������� � �������
		 * @param event ��� �������
		 */
		void StateChanged(QString event);

		/**
		*		������ ������ ������������ ��� ��������� ��������� ����� ���������. ��������,
		*	���� ������������ � ��������. ��� ������ �� ��� �������, � ����� ������� � ������
		*	��������� (��. InputMode ). ���������, ��� � ����� �� ��� ������� ����� ����������
		*	(������� � �� ����� paint( QPainter& ), ��� ��� ���� ���� ��� ������������ �� �����.
		*/
		void changed();

		/**
		*	���� ������ ������������ � ������, ���� ������������ ��������� �����.
		*
		*	@param dx �������� ����� ������������ ������� � ������� �� ��� X.
		*	@param dy �������� ����� ������������ ������� � ������� �� ��� Y.
		*/
		void moved( const qreal dx, const qreal dy );

		/**
		*	������ ������ ������������ �� ��������� ������������� ������� �����.
		*
		*	@param sx �����������, �� ������� ������������ ������������� ����� �� ��� X.
		*	@param sy �����������, �� ������� ������������ ������������� ����� �� ��� X.
		*	@param scaleCenter �����, �� ������� � ���������� ��������� ������� �����.
		*/
		void scaled( const qreal sx, const qreal sy, const QPointF &scaleCenter );

		/**
		*		������ ������������ �� ����������� ������� ������������� ����� �� ������
		*	�������������� �����.
		*
		*	@param sx ����������� ������ �� ��� X.
		*	@param sy ����������� ������ �� ��� Y.
		*	@param scaleCenter �����, �� ������� � ���������� ��������� �����.
		*/
		void sheared( const qreal sx, const qreal sy, const QPointF &shearPoint );

		/**
		*	������ ������������ �� ������� ����� ������ ��������� �����.
		*
		*	@param angle ���� �������� �����.
		*	@param center �����, ������ ������� ������� � ����������.
		*/
		void rotated( const qreal angle, const QPointF &center );

	public:


		/**
		*		���, ��� ������ ����� �� �������� ����������� ��������� ���������� � ����� ������������ ������
		*	��� ����� ���������� �������, ��, ��������������, ��� � �� ����� ���� ����������� �� ���������
		*	�������. ������, ���� ����� ����� ��������� �������, ������� ���������� �������� ��� �����������
		*	��� ��� ���� �������, ������������ � ��� ��������, ������ �������� ��� ��������. ������
		*	����� ���������� �������� ��� ������� ������ ����� �� �������� ����������.
		*
		*	@param button ������, ������� ������������ ������� �� �������. ������������ �����������
		*			Qt::LeftButton, Qt::RightButton � �.�. (��. ������� �� Qt)
		*	@param position ��������� ������� ���� �� ������ � ������� ��������� �������.
		*	@param modifiers ������������, ������� ��� ���� ������������ ������������� (���������
		*			Qt::ControlModifier, Qt::AltModifier � �.�. (��. ������� �� Qt))
		*/
		virtual void mouseDoubleClick( const int button, const QPoint &pos, Qt::KeyboardModifiers modifiers );

		/**
		*		���, ��� ������ ����� �� �������� ����������� ��������� ���������� � ����� ������������ ������
		*	��� ����� ���������� �������, ��, ��������������, ��� � �� ����� ���� ����������� �� ���������
		*	�������. ������, ���� ����� ����� ��������� �������, ������� ���������� �������� ��� �����������
		*	��� ��� ���� �������, ������������ � ��� ��������, ������ �������� ��� ��������. ������
		*	����� ���������� �������� ��� ������ ����� �� �������� ����������.
		*
		*	@param button ������, ������� ������������ ������� �� �������. ������������ �����������
		*			Qt::LeftButton, Qt::RightButton � �.�. (��. ������� �� Qt)
		*	@param position ��������� ������� ���� �� ������ � ������� ��������� �������.
		*	@param modifiers ������������, ������� ��� ���� ������������ ������������� (���������
		*			Qt::ControlModifier, Qt::AltModifier � �.�. (��. ������� �� Qt))
		*
		*	@return true, ���� ������� ���� ���������� ������ ��������� � false, ���� ������ �������� ����.
		*/
		virtual bool mousePress( const int button, const QPoint &pos, Qt::KeyboardModifiers modifiers );

		/**
		*		���, ��� ������ ����� �� �������� ����������� ��������� ���������� � ����� ������������ ������
		*	��� ����� ���������� �������, ��, ��������������, ��� � �� ����� ���� ����������� �� ���������
		*	�������. ������, ���� ����� ����� ��������� �������, ������� ���������� �������� ��� �����������
		*	��� ��� ���� �������, ������������ � ��� ��������, ������ �������� ��� ��������. ������
		*	����� ���������� �������� ��� ����������� ���� ��� ��������� ����������.
		*
		*	@param button ������, ������� ������������ ������� �� �������. ������������ �����������
		*			Qt::LeftButton, Qt::RightButton � �.�. (��. ������� �� Qt)
		*	@param position ��������� ������� ���� �� ������ � ������� ��������� �������.
		*	@param modifiers ������������, ������� ��� ���� ������������ ������������� (���������
		*			Qt::ControlModifier, Qt::AltModifier � �.�. (��. ������� �� Qt))
		*/
		virtual void mouseMove( const int button, const QPoint &pos, Qt::KeyboardModifiers modifiers );

		/**
		*		���, ��� ������ ����� �� �������� ����������� ��������� ���������� � ����� ������������ ������
		*	��� ����� ���������� �������, ��, ��������������, ��� � �� ����� ���� ����������� �� ���������
		*	�������. ������, ���� ����� ����� ��������� �������, ������� ���������� �������� ��� �����������
		*	��� ��� ���� �������, ������������ � ��� ��������, ������ �������� ��� ��������. ������
		*	����� ���������� �������� � ������, ����� ������������ �������� ������� ����, � ������,
		*	���� ��� ���� ������ ��� ��������� ����������.
		*
		*	@param button ������, ������� ������������ ������� �� �������. ������������ �����������
		*					Qt::LeftButton, Qt::RightButton � �.�. (��. ������� �� Qt)
		*	@param position ��������� ������� ���� �� ������ � ������� ��������� �������.
		*	@param modifiers ������������, ������� ��� ���� ������������ ������������� (���������
		*					Qt::ControlModifier, Qt::AltModifier � �.�. (��. ������� �� Qt))
		*/
		virtual void mouseRelease( const int button, const QPoint &pos, Qt::KeyboardModifiers modifiers );

		/**
		*		���� ����� ���������� �������� ��� ��������� �������, � ������� ������ ��������� ������ �����.
		*	�� �, ��� �����, ��� ��� � ������������.
		*
		*	@param p ������ ������ QPainter, ������� ������ ����� � ����� ����������.
		*
		*	@warning ������ ����� ����� �������� ��������� ������� p.
		*/
		virtual void paint( QPainter &p );

		/**
		*		���� ����� ��������� ��������� ������ ������ ������� Ctrl �, �� �������� �,
		*	��������� ����� ������, �� ��� ����� ��������� ������������� ���������� �����
		*	(��� ������ ��� �������� ���������� �����������).
		*	��� ���, � ���� ������ �������� ������ �� ������� ���������� ������� Ctrl ����
		*	����� ����� ���������� true - �.�. ����� ��������� � ������ �������� ����������
		*	������.
		*
		*	@return ���� � ������ �������� ������ ���� ������ ������� Ctrl,
		*	�� �� ������� � ���������� ���� ����� ����� ���������� true.
		*
		*	@todo �������� ����������� � ������������� ����� �� ���-������ ����� ��������.
		*/
		virtual bool isInCreateFigureMode() const;

		/**
		*		���� ����� ��������� ��������� ������ ������ ������� Ctrl �, �� �������� �,
		*	��������� ����� ������, �� ��� ����� ��������� ������������� ���������� �����
		*	(��� ������ ��� �������� ���������� �����������).
		*	��� ���, ��� �� ��� ����������� ������ ���, ����� ��������� ������ ���������� �������
		*	������ ����� �� ��������� ��������� true. ���� ����� �� �������, �� �� ������� Ctrl
		*	����� ����������� ����� �� �����.
		*
		*	@param enabled ��� ���� �������� � ����� ������������� � true ����� ��������� �����-����
		*				������ � ����������� � � ������ �����.
		*
		*	@todo �������� ����������� � ������������� ����� �� ���-������ ����� ��������.
		*/
		virtual void setCreateFigureMode( bool enabled );

		/**
		*	���������� ������� ������� ����� � ������� ��������� ������������� �������.
		*
		*	@return ������� ������� ����� � ������� ��������� ������������� �������.
		*/
		virtual QRect getPosition() const;

		virtual void setPosition( const QRect &p );

		/**
		*	������� � ��� ��� ��������� ����� ������
		*/
		virtual void setIsNewFigure(bool inf);

		virtual bool getIsNewFigure();

		/**
		*	���������� ���������� ������������� �������, � ������� ����� ��������� ����� ���������.
		*
		*	@return ���������� ������������� �������, � ������� ����� ��������� ����� ���������.
		*/
		virtual QRect getViewport() const;

		/**
		*		� ������� ������� ������ ����� ���������� ������������� ������� � ������� � ������ �
		*	������� ����� ��������� ������ ����� ���������.
		*
		*	@param v ���������� ������������� �������.
		*/
		virtual void setViewport( const QRect &v );

		/**
		*	���������� ���������, � ������� �� ������ ����� ��������� ����� ���������. (��. InputMode)
		*
		*	@return ��������, � ������� �� ������ ������ ��������� ����� ���������.
		*/
		virtual GSRInterface::InputMode getInputMode() const;

		virtual void setInputMode( const GSRInterface::InputMode m );

		/**
		*	���������� true, ���� � ������ ������ ����� ������ ���� ����� �� ������.
		*
		*	@return true, ���� ����� ������ ���� ����� �� ������ � false � ��������������� ������.
		*/
		virtual bool isVisible() const;

		/**
		*	�������� ���������� ����� �� ������.
		*
		*	@param v ���������� ��������� ����� �� ������.
		*/
		virtual void setVisible( bool v );

		/**
		*	���������� ��� � ��������� ����� ������� �� ���������� ��������.
		*
		*	@return ��� � ��������� ����� ������� �� ���������� ��������.
		*/
		virtual QPen pen();

		/**
		*	���������� ��� � ��������� ������� ������� �� ���������� ��������.
		*
		*	@return ��� � ��������� ������� ������� �� ���������� ��������.
		*/
		virtual QBrush brush();

		/**
		*	������������� ��� � ��������� ����� ���� ���������� ������� �����.
		*
		*	@param p ��� � ��������� �����, ������� ����� ������������ ���� ���������� ��������.
		*/
		virtual void setPen( const QPen &p );

		/**
		*	������������� ��� � ��������� ������� ���� ���������� ������� �����.
		*
		*	@param p ��� � ��������� �������, ������� ����� ������������ ���� ���������� ��������.
		*/
		virtual void setBrush( const QBrush &b );

		/**
		*	��������� �� ����������� ������ �� ���������� �����.
		*
		*	@return true, ���� ������ �� ���������� ����� ��������.
		*/
		virtual bool isClosed() const;

		/**
		*	������������� ����������� ��� ���� ���������� �����.
		*
		*	@param closed ������ ���� ����������� � true, ���� �� ������ �������� ��� ���������
		*			������, � false, ���� ����������.
		*/
		virtual void setClosed( bool closed );
		/**
		*	������������� ��������� ���������.
		*
		*	@param closed ������ ���� ����������� � true, ���� �� ������ ���������� ���������
		*		, � false, ���� ���.
		*/

		virtual int countSelected() const;

		/**
		*	��������� ��������� �� ��������� ������ ���������� � ������� ������ ����� ���������.
		*
		*	@return true, ���� ������ ������� � false � ��������� ������.
		*/

		virtual bool isInside( GObjectInterface *o );

		/**
		*	���������� ��������� �� ���� �� ��������� �������� �� ��� �������.
		*
		*	@param index ���������� ����� (������) ����������� � ������ ������ �������.
		*			������� ���������� � ������� �� ���������.
		*
		*	@return ��������� �� ����������� ������, ��� 0, ���� ������� � ����� ������� ���.
		*/
		virtual GObjectInterface *selected( int index );

		/**
		*		������������� ���������� ���� ��������� ������. ���� �� ����� ���� ��������� ������
		*	�������, ��� ����������� �� ���������.
		*
		*	@param o ������, ������� ���������� �������� ������ ���������.
		*/
		virtual void setSelected( GObjectInterface *o );

		/**
		*	�������� ���������� �������
		*
		*	@param o ������, ������� ������� ������ ���������.
		*/
		virtual QObject * getSelected();

		/**
		*		��������� � ��������� ��� ���� ������. ���� �� ���� ��������� �� ������, �� ������
		*	������ ���������� ������������ ����������.
		*
		*	@param o ��������� �� ������, ������� ���������� �������� �� ���������.
		*/
		virtual void addSelected( GObjectInterface *o );

		/**
		*	��������� �� ��������� ��� ����� ����������� � ���� �������.
		*/
		virtual void reset();

		/**
		*		������ ����� ���������, ����� ��� ����������� ��������, �� �������� � �������,
		*	����� ��� �� ��������� �������������� ����� � ���������� ������, ���� �� ������� ����.
		*	������ ������� ���������, ��������� �� ��� ���� ����� � ������ ���������� ����� � ������.
		*
		*	@return true, ���� ����� ��������� � ������ ���������� ����� ����� � ���������� ������.
		*/
		virtual bool isInAddPointMode() const;

		/**
		*		������ ����� ���������, ����� ��� ����������� ��������, �� �������� � �������,
		*	����� ��� �� ��������� �������������� ����� � ���������� ������, ���� �� ������� ����.
		*	������ ������� ������������� ��� ���������� ���� �����.
		*
		*	@param enabled � ����������� �� �������� ���� �������� (true), ���� ���������
		*		����� ���������� ����� ����� � ������.
		*/
		virtual void enableAddPointMode( bool enabled );

		/**virtual MarksPositions getMovedMark();

		virtual void setMovedMark(MarksPositions mm);

		virtual QPoint getLastHitPoint();

		virtual void setLastHitPoint(QPoint lhp);

		virtual QPointF get�enterPoint();

		virtual void set�enterPoint(QPointF cp);*/

		virtual QPoint getShearPoint();

		virtual void setShearPoint(QPoint sp);

		virtual QPointF getShearOffsets();

		virtual void setShearOffsets(QPointF so);

		virtual qreal getRotateAngle();

		virtual void setRotateAngle(qreal ra);

		virtual int getSelectedObjectPoint();

		virtual void setSelectedObjectPoint(int sop);

		virtual QWidget * getParent();

		virtual void setParent(QWidget * p);

		QVector< QRect > marksRects(); // ������� ��������� � �������� (������� ��������� ��� ������� �������) �������� ���������

				/**
				*	�����������.
				*
				*	@param parent ��������� �� ������� ����������, � ������� ����� ������������ ������
				*			����� ���������.
				*	@param viewport ������������� ������� �������� ����������, � ������� �����
				*			��������� ������ �����.
				*	@param pos ��������� ������� �����.
				*
				*	@warning ������� ����������, � ������� ������������ ������ �����,
				*		������ ���������� "�����" �� �����, ���� "����" ����� ���������.
				*/
				GSelectionRect( plugin::PluginsManager *manager, QWidget *parent, const QRect viewport,
						const QRect &pos = QRect( 10, 10, 120, 100 ) );

		/**
		*	����������.
		*
		*	@warning ��� �������� �����, ��� ������� ������ ����������� �� ���������, �� �� ���������.
		*/
		virtual ~GSelectionRect();

	public slots:
		void onMoved( const qreal dx, const qreal dy );
		void onScaled( const qreal sx, const qreal sy, const QPointF &scaleCenter );
		void onSheared( const qreal sx, const qreal sy, const QPointF &shearPoint );
		void onRotated( const qreal angle, const QPointF &center );

	private:

		QRect position;
		QRect maxRect;
		QPoint lastHitPoint;
		GSRInterface::MarksPositions movedMark;
		QPointF centerPoint;
		QPoint shearPoint;
		QPointF shearOffsets;
		qreal rotateAngle;
		GSRInterface::InputMode _inputMode;
		bool visible;
		int selectedObjectPoint;
		bool addPointMode;
		QWidget *_parent;
		bool createFigureMode;
		bool isNewFigure;
		GContainer *selectedObjects;
		GContainer *selectedLayer;
		bool isMove;
		bool isShear;
		bool isRotate;
		bool isScale;
		bool isPoint;
		/** ������ �������� ��������� */
		const static int marksRadius;
		/** �������� �������� ��������� */
		const static int displacement;




		GSRInterface::MarksPositions selectedMark( const QPoint &p );
		void moveMark( const  GSRInterface::MarksPositions mark, QPoint p, Qt::KeyboardModifiers modifiers );

		void recalcCenter( const QRect &oldPosition );


		void normalize();

		static void drawShiftArrow( QPainter &p, const QPoint &pos, const ShiftArrowDirection dir );
		static void drawRotateArrow( QPainter &p, const QPoint &pos );
		static qreal calcSheareAngle( qreal height, qreal width );
		static qreal calcRotateAngle( const QPointF &center, const QPoint &beginPoint, const QPoint &endPoint );
};

#endif /* __GSELECTION_RECT_H__ */
