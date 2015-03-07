/**
*	@mainpage ������������ �� PluginSDK
*
*		� ������ ������� �� ������ ������������ �� PluginSDK - SDK, ������� �������� ��� ���������
*	��� �������� ������ ��������� ����� ���������, �������������� ����������� ������� ������������ ������
*	���� ��������� �� ���� ������������� ��������� ������ ��������. ������������� ������ � ��������� ��������
*	(� ����������� �����: @ref FirstPlugin ).
*/

/**
*	@file Plugin.h ������������ ����, � ������� ��������� �������� �����, ��� ����� �����������
*			��� �������� ������������� ��������. �.�. ������������ ���� � pluginSDK :)
*
*	@author ������ ���������
*
*	@example FirstPlugin ������ �������� � ������������� �������� ������� (�� ������ �� ������ ������,
*					�� ��� ������� ����� :) )
*
*		��� ������ ����� ��������� ��������� �������. �.�. �� ������, ��� ��� ����� ���������� � ������-�������.
*	������ ��������� ���������� � ��������� ������������ ����� � ��� ������ ��� ������ ���� ������������ �
*	������������. ��� ������:
*
*	<b>���� <i>FirstPluginInterface.h</i></b>
*
*	@code
*
*	#ifndef __FIRST_PLUGIN_INTERFACE__
*	#define __FIRST_PLUGIN_INTERFACE__
*
*	#include <QString>
*
*	class FirstPluginInterface
*	{
*		public:
*			virtual QString getTestString( QString param ) const = 0;
*			virtual void printMessage( QString message ) = 0;
*
*					 FirstPluginInterface() {};
*			virtual ~FirstPluginInterface() {};
*	};
*
*	//�, ��� �������, �� �������� �������� ��� ��������� �����������:
*	Q_DECLARE_INTERFACE( FirstPluginInterface,
*                     "com.alex.test.FirstPluginInterface/1.0")
*
*	#endif // __FIRST_PLUGIN_INTERFACE__
*
*	@endcode
*
*		�����, ������� ��� ������, ������� ��������� ������ ���������. �� ������ ����������� ���� �����������
*	������ QObject ��� ������ ��� ������������ ������ (��������, QWidget). ��� �� ������ ������ ������ �������������
*	��� ������, ��������� � ������-����������. ��, � � ����������, �� � ������������ ������ ��������� ����
*	�������� - ��������� �� plugin::PluginsManager. ��� ��������� �� ��� ����� �������� ��������, �������
*	��������� ������ ������.
*
*	<b>���� <i>FirstPlugin.h</i></b>
*
*	@code
*
*	#ifndef __FIRST_PLUGIN__
*	#define __FIRST_PLUGIN__
*
*	#include <QObject>
*	#include "Plugin.h" //	������������ ����, � ������� ���������� ������
*						//������ ��� �������� �������� ������� � ������ :)
*	#include "FirstPluginInterface.h"
*
*	class FirstPlugin:public QObject, public FirstPluginInterface
*	{
*		Q_OBJECT	//	������ ������ ��� ���������, ��� ��� ��� ������
*					//����������� �� ������ QObject (��, ��� �� ������� ������ QObject - ��� �� ��� �����).
*		Q_INTERFACES( FirstPluginInterface ) //		� ������� ������� ������� �� ���������, ��� ����������
*											 //�� ��� ���� ����������. ��, � ���� ������� ��� FirstPluginInterface.
*		public:
*			virtual QString getTestString( QString param ) const;
*			virtual void printMessage( QString message );
*
					 // ������� �� ������ ��� ���� ������������ ��������. � �� ��������������� ��� �� �����.
*					 FirstPlugin( const plugin::PluginsManager *manager ) {};
*			virtual ~FirstPlugin() {};
*	};
*
*	#endif // __FIRST_PLUGIN__
*
*	@endcode
*
*	<b>���� <i>FirstPlugin.cpp</i></b>
*
*	@code
*
*	#include <QMessageBox>
*	#include "FirstPlugin.h"
*
*	//	��� ��������� ����� ������� ���������� ������� �������. ��, ������, ������� ����������� �� ���������
*	//� ������������� ��� ��� ���� ����� ���.
*
*	QString FirstPlugin::getTestString( QString param ) const
*	{
*		return param + " :)";
*	}
*
*	void FirstPlugin::printMessage( QString message )
*	{
*		QMessageBox::information( 0, "Message", message );
*	}
*
*	EXPORT_PLUGIN( FirstPlugin, FirstPluginInterface ) 	//	��, � ������� ���������� ��������� � ���� ������.
*														//�� ������� ����� ���� ������������ ��� ����������������
*														//�������, ��� ������� �� ������ ���� ����� ������ ������ ���.
*
*	@endcode
*
*		��, ���������� ��. ������ ����� �������������� ������. ��� ����� ����� �������� �������� ��������� ���� �������
*	��� ������:
*
*	@code
*
*	TEMPLATE = lib
*	TARGET = FirstPlugin
*	DEPENDPATH += .
*	INCLUDEPATH += .
*	HEADERS += FirstPluginInterface.h FirstPlugin.h Plugin.h
*	SOURCES += FirstPlugin.cpp
*
*	@endcode
*
*		������ ���� ����� ��������� � ����������� *.pro � �������� ����� �� ����� ������� �������. ���� �� ����������
*	����������� � ���� Plugin.h. ����� ���� ����� ������� ��������� ������� � ������������� �������:
*
*	@code
*	qmake
*	make (��� nmake ��� Microsoft Visual Studio)
*	@endcode
*
*	��, ��� ������ ������ ����� :)
*
*		�������� ������ �������� ���������, ������� ������������ �� ������� ������� ����. ��� ���� �������� ������.
*	�������� ���:
*
*	<b>���� <i>FirstPluginTest.cpp</i></b>
*
*	@code
*
*	#include "FirstPluginInterface.h"
*	#include "Plugin.h"
*
*	int main( int argC, char *argV[] )
*	{
*		plugin::PluginsManager manager( "./" );	//������ ������, ������� ������� ��� �������� ��� ������.
*												//��� ����� ��������� � �������, �� ��� ������� �������.
*
*		FirstPluginInterface *testPlugin =
*			qobject_cast< FirstPluginInterface* >( manager.create( "FirstPlugin" ) );
*					//������ ��������� ������ �������. ��� ��� ��� �������� ������� �� �������� ��������� ��
*					//������ QObject, �� ����� �������� ������ ��������� � ���� ��������� �� ��� ���������.
*					//���� ��������� ������ (��������, �� ��������� �� ��� ������ ��������) � ������ ������
*					//�� ������������ ������������� ���������, �� qobject_cast ����� ��� 0.
*
*		if( testPlugin != 0 ) //��������� ��, ��� ������ ���������� � ������������ ������ ��� ���������.
*		{
*			//�������� ������ ����������. �����������, ��� ����� ������� ������ ��������� ������.
*			testPlugin->printMessage( testPlugin->getTestString( "Hello wordl!" ) );
*			delete testPlugin; //������� ��� �� ������ ��� ������.
*		}
*
*		return 0;
*	}
*
*	@endcode
*
*		������ �������� ����� FirstPluginInterface.h, Plugin.h, libplugin.a (plugin.lib ��� Windows) � FirstPluginTest.cpp � ���� �����
*	� ���������� ���� �� ������������ ������. ��� �� �������� ��������� ���� � ��������� ��� ����������:
*
*	<b>���� <i>FirstPluginTest.pro</i></b>
*
*	@code
*
*	TEMPLATE = app
*	TARGET = FirstPluginTest
*	DEPENDPATH += .
*	INCLUDEPATH += .
*	HEADERS += FirstPluginInterface.h Plugin.h
*	SOURCES += FirstPluginTest.cpp
*	LIB += -L./ -lplugin
*
*	@endcode
*
*	� ����� �������� ���������� ��� ���������� ���������:
*
*	@code
*	qmake
*	make (��� nmake ��� Microsoft Visual Studio)
*	@endcode
*
*		��������� ���������� ���������. ��� ������ ��������� ������ � �������� ������ � ���������� � ��������� �������:
*	"Hello wordl! :)"
*
*		������� ��������, ��� � ������, ���� ��� �� ����� ������������ �����-���� ���������� �
*	��� ���������� ����� ������������ ���������� ������ ������, ������������� �������� QObject,
*	�� �� ������ �� ��������� ���� ���������. � � ���� ������ �� ������ �� ����������� ������
*	Q_INTERFACES � ������ ������� EXPORT_PLUGIN ����������� EXPORT_QOBJECT_PLUGIN.
*/
#ifndef __PLUGIN_H__
#define __PLUGIN_H__

#include <QObject>
#include <QString>
#include <QStringList>
#include <QMap>
#include <QtXml>
#include <QtXmlPatterns>

#define CREATE_PLUGIN_PROC_NAME createPluginInstance
#define GET_PLUGIN_SUPPORTED_INTERFACES_PROC_NAME getSupportedInterfaces
#define GET_PLUGIN_NAME_PROC_NAME getPluginName
#define CREATE_PLUGIN_PROC_NAME_STR "createPluginInstance"
#define GET_PLUGIN_SUPPORTED_INTERFACES_PROC_NAME_STR "getSupportedInterfaces"
#define GET_PLUGIN_NAME_PROC_NAME_STR "getPluginName"

namespace plugin
{
	class PluginsManager;
} /** namespace plugin **/


typedef QObject* (*CreatePluginInstanceProc)( plugin::PluginsManager *manager );
typedef QString (*GetPluginSupportedInterfacesProc)();
typedef QString (*GetPluginNameProc)();

/**
*	@name EXPORT_PLUGIN
*
*		������ EXPORT_PLUGIN ������ ���� �������� � ���� ������, ������� ������ ����� � �������
*	��������. ��, ����������, ������� ��� ��, ��� ����� ��� �������, �� ��� ���� �� �����������
*	������ ��� ������ ��������������, ������ ������.
*
*	@param className ��� ������, ��������������� �� �������. � ������ �� �������� ����� ��������� ������
*				���� �����. ������ ����������� :)
*
*	@param supportedInterfaces ������ �������������� �����������. � ����� �� �������� �����, �� ����� �
*				����������� ��� ����� ������� ������. ������ ������ ������������ ����� ������ ������������
*				�������������� �����������, ����������� ���������
*
*	@note �� ���� �� ���������� �� ������ ���� �������� � �������.
*
*	@example SimplePlugin ������� ������ ������������� ������� ������� EXPORT_PLUGIN:
*	@code
*
*	// ���� SimplePlugin.h
*	class SimplePlugin:public QObject, public SomeInterface, public NextSomeInterface
*	{
*		Q_OBJECT
*		Q_INTERFACES( SomeInterface NextSomeInterface )
*
*		public:
*			...
*	};
*
*	//���� SimplePlugin.cpp
*
*	SimplePlugin::SimplePlugin():QObject( 0 )
*	{
*	}
*
*	...
*
*	EXPORT_PLUGIN( SimplePlugin, SomeInterface NextSomeInterface )
*
*	@endcode
*/
#define EXPORT_PLUGIN( className, supportedInterfaces )\
	extern "C"\
	{\
		Q_DECL_EXPORT QObject* CREATE_PLUGIN_PROC_NAME( plugin::PluginsManager *manager )\
		{\
			return new className( manager );\
		}\
		\
		Q_DECL_EXPORT QString GET_PLUGIN_SUPPORTED_INTERFACES_PROC_NAME()\
		{\
			return #supportedInterfaces;\
		}\
		\
		Q_DECL_EXPORT QString GET_PLUGIN_NAME_PROC_NAME()\
		{\
			return #className;\
		}\
	}

/**
*	@name EXPORT_QOBJECT_PLUGIN
*
*		������ EXPORT_QOBJECT_PLUGIN ������ ���� �������� � ���� ������, ������� ������ ����� � �������
*	��������, �� ������� �� ��������� ������� �������������� �����������
*	(����� ���������� ������ ���������� QObject).
*	��, ����������, ������� ��� ��, ��� ����� ��� �������, �� ��� ���� �� �����������
*	������ ��� ������ ��������������, ������ ������.
*
*	@param className ��� ������, ��������������� �� �������. � ������ �� �������� ����� ��������� ������
*				���� �����. ������ ����������� :)
*
*	@note ��� ������ �� ������� ���� ��������� � �������.
*
*	@example SimplePlugin2 ������� ������ ������������� ������� EXPORT_QOBJECT_PLUGIN:
*	@code
*
*	// ���� SimplePlugin2.h
*	class SimplePlugin2:public QWidget
*	{
*		Q_OBJECT
*		public:
*			...
*	};
*
*	//���� SimplePlugin2.cpp
*
*	SimplePlugin2::SimplePlugin2():QObject( 0 )
*	{
*	}
*
*	...
*
*	EXPORT_QOBJECT_PLUGIN( SimplePlugin2 )
*
*	@endcode
*/
#define EXPORT_QOBJECT_PLUGIN( className )\
				EXPORT_PLUGIN( className,  )


class PluginContainer /**����� ���������� ������ ������� � ���������� � ��**/
{	public:
		PluginContainer(QObject* _plugin,QString _idPlugin,QStringList _idsWidget,QString _path):
			plugin(_plugin), idPlugin(_idPlugin), idsWidget(_idsWidget), path(_path){}

		bool isWidget(QString idWidget) /**��������� �������� �� � ������ �������� ������**/
		{
			return idsWidget.contains(idWidget);
		}

		QObject* getPlugin() /** ���������� ��������� �� ������**/
		{
			return plugin;
		}

		QString getPluginId()
		{
			return idPlugin;
		}

		QString getPath()
		{
			return path;
		}
	private:
		QObject* plugin;
		QString idPlugin; /** Id ������� **/
		QStringList idsWidget;/**Id �������� � �������� �������� ������**/
		QStringList interfaces;
		QString path;
};

/**
*		� ������ ������������ ���� ��������� ��� ������, ���������� �� ������ � ���������.
*	�� ������� � ��� ������ �� �������� :)
*/
namespace plugin
{
	/**
	*		������ ����� �������� �� �������� �������� � ��������� �������������� ���������� � ���,
	*	����� ��� ������ �������������� ����������� ������-���� �������, ����� �������� � �������.
	*	��� �� �� ����� ����������� ���������� ��������, ���� ��� ���� ��������� � ��� �������.
	*/
	class PluginsManager
	{
		public:
			virtual QDomDocument* getPluginsDom();

			virtual QObject* createFromPath( QString path );

			virtual void addPlugins(QObject* parent, QString idParent);

			virtual bool writeXml(const QString &fileName);

			virtual QObject* getPluginById(const QString &Id);

			/**
			*	������� ����� ��������� (���� �����) �������. ������ �� ��������, � ������ �������.
			*
			*	@param plugin ��� ��������� ��������� �������
			*
			*	@return ����� ��������� �������
			*/
			virtual QObject* copy( QString IdPlugin ) ;

			/**
			*	������� ����� ��������� ������� �� ��� �����.
			*
			*	@param name ��� ������������ �������
			*
			*	@return ������������� ��������� �������
			*/
			virtual QObject* create( QString name ) ;

			/**
			*	���������� ������ �������������� �������� �����������.
			*
			*	@param name ��� �������
			*
			*	@return ������ ���� �������������� �����������
			*/
			virtual QStringList supportedInterfaces( QString name )const ;

			/**
			*		��������� ����� �������� �� ��� �����, ������� ���� ������� � ������������.
			*	����� ���� ����������� � ��� ������, ���� ���� ����������� ����, ��� �����-�� �������
			*	���� ������� ��� ��������, ��������� � �� �����, � ������� �� ����� ������������ �����.
			*/
			virtual void research();



			/**
			*	���������� ������ ���� ��������� ��������.
			*
			*	@return ������ ���� ��������� ��������
			*/
			virtual QStringList pluginsList()const;

				/**
				*		����������� ����� ���. ����� �� ���������� ������ ��������, ������� ��������� ��
				*	���������� ����.
				*
				*	@param pathToPlugins ����, �� �������� ����� ����� �������
				*/
				PluginsManager( QString pathToPlugins );

				/**
				*		����������� ����� ���. ����� �� ���������� ������ ��������, ������� ��������� ��
				*	��������� �����, ������������� � ������.
				*
				*	@param pathToPlugins ������ �����, �� ������� ����� ����� �������
				*/
				PluginsManager( QStringList pathToPlugins );

				/**
				*		����������� ����� ���. ����� ����� ��� ������� �� ���������� �� XML
				*
				*	@param pathToXMl ���� � XML-�����
				*/
				PluginsManager( QString pathToXMl, QWidget* main);

			/**
			*	������ ����������.
			*
			*	@note ����������� ������� ����� ������������ � ����� ����, ��� ������ ������� ������,
			*		����������� ������, ��� ���������.
			*/
			virtual ~PluginsManager();

		private:
			/**
			*	@internal
			*/
			QDomDocument* pluginsDom;
			/**
			*	@internal
			*/
			QVector <PluginContainer* > pluginsContainer;

			/**
			*	@internal
			*/
			QStringList pathToFind;

			/**
			*	@internal
			*/
			QMap< QString, QString > findedPlugins;

			/**
			*	@internal
			*/
			Q_DISABLE_COPY( PluginsManager )

			/**
			*	@internal
			*/
			static bool isPlugin( QString pluginFile );

			/**
			*	@internal
			*/
			static QString getPluginName( QString pluginFile );

			/**
			*	@internal
			*/
			static QStringList getSupportedPluginInterfaces( QString pluginFile );

			/**
			*	@internal
			*/
			static QObject *createPluginInstance( QString pluginFile, PluginsManager *manager );
	};

} /* namespace plugin */

/**
*		�������� ������������� ����� ��������� �� ������, ���������� ����������� QObject
*	� ��������� �� ������ ���� QWidget. ���� ��� ������� ���������� (������ �������� �� ��������),
*	�� ������� ���������� 0.
*
*	@param o ��������� �� ������, ������� ����� �������� ��� � ��������.
*			������ ���� ��� ������� ���������� ������� �� QObject, �, ���
*			��� �����, �� QWidget.
*
*	@return ��������� �� ���-�� ������, �� ��� ��� ��������� �� QWidget.
*			� ������, ���� �������������� �� ��������, ����� ��������� 0.
*/
template < class T > inline QWidget* WIDGET( T *o )
{
	return qobject_cast< QWidget* >( o );
}

#endif /* __PLUGIN_H__ */
