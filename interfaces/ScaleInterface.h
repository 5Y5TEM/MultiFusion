#ifndef __SCALE_INTERFACE_H__
#define __SCALE_INTERFACE_H__

/**
*	@file timelineinterface.h � ������ ����� ������ ���������, ������� ������ �������������
*		����� ������, ���������� �� �.�. ��������.
*/

/**
*		���������, ������� ������ ������������� ����� ������, ���������� �� �.�. ��������.
*	������, ����������� ������ ��������� ������ ������������� �� ������ ������� ������
*	QWidget ��� �� ���� ������.
*
*		����� ���������� ������� ����������, ����� ����� ������ ������ �������������
*	��������� �������:
*
*	@code
*
*
*	@endcode
*/
class ScaleInterface
{
	public:
		/**
		*	�����������.
		*/
		ScaleInterface() {}
		
		//virtual int getFps() = 0;
		/**
		*	����������.
		*/
		virtual ~ScaleInterface(){}
};

Q_DECLARE_INTERFACE( ScaleInterface, "com.alxn1.MultiFusion.ScaleInterface/1.0" )

/**
*	�������� ��������� �� ����� ������ � ���������� �� ��������� TimelineInterface.
*
*	@return ���������� ��������� ��� 0, ���� ��������� ������.
*/
template < class T > inline ScaleInterface* SCALE( T *o )
{
	return qobject_cast< ScaleInterface* >( o );
}

#endif /* __SCALE_INTERFACE_H__ */
