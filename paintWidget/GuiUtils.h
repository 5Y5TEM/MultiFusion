#ifndef __G_UI_UTILS_H__
#define __G_UI_UTILS_H__

#include <QWidget>
#include <QDialog>
#include <QSlider>
#include <QLCDNumber>
#include <QDialogButtonBox>

#include "PaintWidget.h"

/**
*	@file guiutils.h � ������ ����� ������� ��������� ��������������� �������, ����������� ���������
*			����������� ��� GUI �������.
*/

/**	@example SimpleFrameView ������� ������ ������������� ������ FrameView.
*
*		�����������, ��� � ��� ��� ���� ������� ����� ������ PaintWidget � ������ <B>editor</B>.
*	� �� ����� (�� ��� ����� �����) ���������� ���� � ������� 3.56. ���������� �� ��� �����
*	� ���� ���������� �������� ���������� � ������� ���� ����������. ������ �������� ����,
*	�����������, ����� ��� MainWindow. ��� ����� �� ������ �������� ���������:
*
*	@code
*
*	#include "guiutils.h"
*
*	// ... ��� ��������� ��� ����� ���������
*
*	...
*
*	FrameView view( editor, &MainWindow );
*
*	view.setFrame( 3.56 );
*	view.show();
*
*	// � ���, ��������, ����.
*
*	...
*
*	@endcode
*
*		����� ����� ����� ������ ����� ������� ����������, ������� � ����� ����������
*	�� ����� ���� � ��� �� ����������� ����.
*
*	@warning ����� �����������, ������ ������ PaintWidget �� ������ ���� ���������
*		������ ������� FrameView, ������������� �� PaintWidget-� ��������.
*/

/**
*		���� ����� ��������� ������, ����������� ���������� ����� �� ������ ��������, �������
*	�������� � ������ ������ ������ ������ PaintWidget. ������, �� ����������� ��� ������ ����
*	�������� ����. ��� ����� ���� � ����� ������������� ����.
*/
class FrameView:public QWidget
{
	Q_OBJECT

	public:

		/**
		*		���������� ����, ������� � ������ ������ ������������ (�.�. ������� � ������������ ������).
		*	�.�. ���� ����� ���� �����, �� ��� ������������� �������� - qreal.
		*
		*	@return ������������ � ������ ������ ����.
		*/
		virtual qreal frame() const
		{
			return _frame;
		}

		/**
		*	������������� ������� ������������ ����.
		*
		*	@param frame ��������������� ��� ����������� ����.
		*/
		virtual void setFrame( qreal frame )
		{
			_frame = frame;
			update();
		}

				/**
				*	�����������.
				*
				*	@param _paintWidget ��� ��� ����� PaintWidget, ������� �������� ������������
				*		������� ������� ������ ��������.
				*
				*	@param parent ������������ ��� ������� ������.
				*/
				FrameView( PaintWidget *_paintWidget, QWidget *parent = 0 ):
					QWidget( parent ), paintWidget( _paintWidget ), _frame( 0.0 )
				{
					setMinimumSize( QSize( 128, 128 ) );
				}

		/**
		*	����������.
		*/
		virtual ~FrameView()
		{
		}

	protected:
		virtual void paintEvent( QPaintEvent *event )
		{
			QPainter p( this );

			if( paintWidget != 0 )
				paintWidget->paintFrameTo( p, rect(), _frame );
		}

	private:
		PaintWidget *paintWidget;
		qreal _frame;
};

/**
*	@example FrameSelectionDialogExample ������� ������ ������������� ������ FrameSelectionDialog.
*
*	@code
*
*	#include "guiutils.h"
*
*	// ��������� ��� ���
*
*	...
*
*	// � ��� ��� ������ ���������� �������� ������������ � ���, ����� ���� �� �� �����...
*	// �����������, �������.
*
*	qreal selectedFrame = FrameSelectionDialog::selectFrame( editor, // editor - ��� ������ ������
*																	// PaintWidget, ���������� ��������,
*																	// �� ������� �� ������� ����.
*					tr( "����������, �������� ���� ��� ��������" ), // ��������� ����, � ������� ������������
*																	// ����� �������� ����.
*					true,	// ��� ��� ������� ����� ������ �������� �����, �� ��� �� ������� ������
*							// ������ � ������� - ��������� ������������ �������� ������ �������� �����.
*					&MainWindow ); // ���� ������ ����������. �� ����������� ��� ������ ���� �������, �,
*								// ���� �� ����� ������� ������ �� ���������, �� ������ �� ������ ���������
*								// ���� ��������.
*
*	if( selectedFrame != -1 ) // ���������, �� ����� �� ����������� ������ "������".
*	{
*		// � ��� �� ������ ������� ���� �� ��������.
*		editor->setFrame( selectedFrame );
*		editor->deleteCurrentFrame();
*	}
*
*	// ��������, ����� ��� ���.
*
*	...
*
*	@endcode
*/

/**
*	������ ����� ��������� ������ ������ �����.
*
*/
class FrameSelectionDialog:public QDialog
{
	Q_OBJECT

	public:
		/**
		*		������������ ��������� �������� ����� ������� ������. ��-�� � ���������� ������� ����,
		*	� ������� ������������ ����� ������� ��������� ���� ��������.
		*
		*	@param paintWidget ����� ������ PaintWidget, ���������� ��������, ���� �� ������� �� ��������.
		*	@param title ��������� ����������� ����, ������� ����� ��������.
		*	@param _onlyIntactFrames ���� ������ ������� ���������� � true, �� ����� ������������
		*				������ �������� ������ ������� ����� ��������. � ��������� ������, ��
		*				������ �������� ����� �����. �� ��������� ������ �������� ��������� �������� false,
		*				�.�. ������������ ������ �������� ����� �����.
		*
		*	@param parent ������������ ���� ��� ������������� ����������. ���� �� ������ ��������
		*			������ ����������, �� ������ �� ��������� ����� ��������.
		*
		*	@return ��������� ������������� ����, ��� -1, ���� ������������ ������� ����.
		*
		*/
		static qreal selectFrame( PaintWidget *paintWidget, const QString title,
				bool _onlyIntactFrames = false, QWidget *parent = 0 )
		{
			if( paintWidget == 0 )
				return -1;

			FrameSelectionDialog dialog( paintWidget, _onlyIntactFrames, parent );

			dialog.setFrame( paintWidget->frame() );
			dialog.setWindowTitle( title );
			if( dialog.exec() == Accepted )
				return dialog.frame();

			return -1;
		}

	private slots:
		void onFrameChanged( int value )
		{
			qreal frame = value;

			if( !onlyIntactFrames )
				frame /= 100.0;

			frameView.setFrame( frame );
			frameNumber.display( frame );
		}

	private:
		bool onlyIntactFrames;
		FrameView frameView;
		QSlider	position;
		QLCDNumber frameNumber;
		QDialogButtonBox buttons;

		virtual qreal frame() const
		{
			return frameView.frame();
		}

		virtual void setFrame( qreal frame )
		{
			if( onlyIntactFrames )
				frame = int( frame );

			frameView.setFrame( frame );
			frameNumber.display( frame );
			position.setValue( (int)frame );
		}

				FrameSelectionDialog( PaintWidget *paintWidget,
					bool _onlyIntactFrames = false, QWidget *parent = 0 ):QDialog( parent ),
						onlyIntactFrames( _onlyIntactFrames ),
						frameView( paintWidget, this ),
						position( Qt::Horizontal, this ), frameNumber( this ),
						buttons( QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
							Qt::Horizontal, this )
				{
					QVBoxLayout *l = new QVBoxLayout( this );
					l->addWidget( &frameView );

					QHBoxLayout *l2 = new QHBoxLayout;
					l->addLayout( l2 );
					l2->addWidget( &frameNumber );
					l2->addWidget( &position );

					l->setStretchFactor( &frameView, 1 );

					l->addWidget( &buttons );

					position.setMinimum( 0 );
					if( _onlyIntactFrames )
						position.setMaximum( paintWidget->countFrames() - 1 );
					else
						position.setMaximum( ( paintWidget->countFrames() - 1 ) * 100 );

					if( position.maximum() < 0 )
						position.setMaximum( 0 );

					connect( &buttons, SIGNAL( accepted() ), this, SLOT( accept() ) );
					connect( &buttons, SIGNAL( rejected() ), this, SLOT( reject() ) );
					connect( &position, SIGNAL( valueChanged ( int ) ),
						this, SLOT( onFrameChanged( int ) ) );

					resize( 350, 400 );
				}

		virtual ~FrameSelectionDialog()
		{
		}
};

#endif /* __G_UI_UTILS_H__ */
