#ifndef SQLMANAGER_H
#define SQLMANAGER_H

#include <QDebug>
#include <QMutex>
#include <QQueue>
#include <QString>
#include <QVariant>
#include <QDateTime>
#include <QtSql/QSql>
#include <QMutexLocker>
#include <QWaitCondition>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQueryModel>


class SqlManager
{

public:

    //PUBLIC
    ~SqlManager();

    enum ListMode{
        DisplayList = 4,
        HostList = 5,
        RecordList = 7
    };

    // 关闭所有的数据库连接
    static void release();
    // 获取数据库连接
    static QSqlDatabase openConnection();
    // 释放数据库连接回连接池
    static void closeConnection(QSqlDatabase connection);


    //hostList
    static QList<QStringList> getHostList(QSqlDatabase db, const QString sqlQuery, int columnCount);
    //
    static bool insertHostList(QSqlDatabase db, QStringList stringList);
    static bool delelteHostItem(QSqlDatabase db, QString name, QString host);
    //record
    static QList<QStringList> getRecordList(QSqlDatabase db, QString sqlQuery, int columnCount);
    static bool delAllData(QSqlDatabase db,const QString &sqlQuery);
    static bool delelteRecordItem(QSqlDatabase db, QStringList stringList);
    static bool insertAlarmRecord(QSqlDatabase db, QStringList stringList);
    //
    static qreal getPngZoom(QSqlDatabase db, QString host, int index);


private:
    //互斥锁
    static QMutex mutex;
    SqlManager();
    static QWaitCondition waitConnection;
    static SqlManager *instance;
    static SqlManager &getInstance();

    // 创建数据库连接
    QSqlDatabase createConnection(const QString &connectionName);
    // 已使用的数据库连接名
    QQueue<QString> usedConntNames;
    // 未使用的数据库连接名
    QQueue<QString> unusedConntNames;
    // 数据库信息 ./S2N.db
    QString dataBaseName;
    // 数据库类型 QSQLITE
    QString dataBaseType;
    // 取得连接的时候验证连接是否有效
    bool testOnBorrow;
    // 测试访问数据库的 SQL
    QString testOnBorrowSql;
    // 获取连接最大等待时间
    int maxWaitTime;
    // 尝试获取连接时等待间隔时间
    int waitInterval;
    // 最大连接数
    int maxConntCount;
};

#endif // SQLMANAGER_H
