#include "sqlmanager.h"


QMutex SqlManager::mutex;
QWaitCondition SqlManager::waitConnection;
SqlManager* SqlManager::instance = NULL;
SqlManager::SqlManager()
{
    dataBaseName = "./SS_GDE.db";
    dataBaseType = "QSQLITE";
    testOnBorrow = true;

    maxWaitTime  = 1000;
    waitInterval = 200;
    maxConntCount = 10;
}

QSqlDatabase SqlManager::createConnection(const QString &connectionName)
{
    // 连接已经创建过了,复用它,而不是重新创建
    if (QSqlDatabase::contains(connectionName)) {
        QSqlDatabase dbPre = QSqlDatabase::database(connectionName);

        if (testOnBorrow) {
            //返回连接前访问数据库，如果连接断开，重新建立连接
            //qDebug() << "Test connection on borrow, execute:" << testOnBorrowSql << ", for" << connectionName;
            QSqlQuery query(dbPre);
            if (query.lastError().type() != QSqlError::NoError && !dbPre.open())
            {
                //qDebug() << "Open datatabase error:" << dbPre.lastError().text();
                return QSqlDatabase();
            }
        }
        return dbPre;
    }

    // 创建一个新的连接
    QSqlDatabase db = QSqlDatabase::addDatabase(dataBaseType, connectionName);
    db.setDatabaseName(dataBaseName);
    if (!db.open()){
        //qDebug() << "Open datatabase error:" << db.lastError().text();
        return QSqlDatabase();
    }

    return db;
}

void SqlManager::release()
{
    QMutexLocker locker(&mutex);
    delete instance;
    instance = nullptr;
}

QSqlDatabase SqlManager::openConnection()
{
    SqlManager& pool = SqlManager::getInstance();
    QMutexLocker locker(&mutex);

    // 已创建连接数
    int conntCount = pool.unusedConntNames.size() + pool.usedConntNames.size();

    // 如果连接已经用完,等待 waitInterval 毫秒看看是否有可用连接,最长等待 maxWaitTime 毫秒
    for(int i=0;i<pool.maxWaitTime&&pool.unusedConntNames.size()==0&&conntCount==pool.maxConntCount;i+=pool.waitInterval)
    {
        waitConnection.wait(&mutex,pool.waitInterval);
        // 重新计算已创建连接数
        conntCount = pool.unusedConntNames.size() + pool.usedConntNames.size();
    }
    QString connectionName;
    if(pool.unusedConntNames.size() > 0)
    {
        // 有已经回收的连接，复用它们
        connectionName = pool.unusedConntNames.dequeue();
    }
    else if(conntCount < pool.maxConntCount)
    {
        // 没有已经回收的连接，但是没有达到最大连接数，则创建新的连接
        connectionName = QString("Connection-%1").arg(conntCount + 1);
    }
    else
    {
        // 已经达到最大连接数
        //qDebug() << "Cannot create more connections.";
        return QSqlDatabase();
    }

    // 创建连接
    QSqlDatabase db = pool.createConnection(connectionName);

    // 有效的连接才放入 usedConnectionNames
    if (db.isOpen())
    {
        pool.usedConntNames.enqueue(connectionName);
    }

    return db;
}

void SqlManager::closeConnection(QSqlDatabase connection)
{
    SqlManager& pool = SqlManager::getInstance();
    QString connectionName = connection.connectionName();

    // 如果是我们创建的连接，从 used 里删除,放入 unused 里
    if (pool.usedConntNames.contains(connectionName))
    {
        QMutexLocker locker(&mutex);
        pool.usedConntNames.removeOne(connectionName);
        pool.unusedConntNames.enqueue(connectionName);
        waitConnection.wakeOne();
    }
}

SqlManager::~SqlManager()
{
    // 销毁连接池的时候删除所有的连接
    foreach(QString connectionName, usedConntNames)
    {
        QSqlDatabase::removeDatabase(connectionName);
    }
}

bool SqlManager::insertAlarmRecord(QSqlDatabase db, QStringList stringList)
{
    QString pHost = stringList.value(0);
    QString pLoop = stringList.value(1);
    QString pID   = stringList.value(2);
    QString pType = stringList.value(3);
    QString pSts  = stringList.value(4);
    QString pTime = stringList.value(5);

    QString pSqlQuery = QString("insert into RECORD values(%1,%2,%3,%4,%5.%6);").arg(pHost).arg(pLoop).arg(pID).arg(pType).arg(pSts).arg(pTime);
    QSqlQuery pQuery(db);
    if (!pQuery.exec(pSqlQuery)) {
        return false;
    }
    pQuery.finish();
    pQuery.clear();
    return true;
}
//返回图片的缩放倍数
qreal SqlManager::getPngZoom(QSqlDatabase db, QString host, int index)
{
    qreal pZoom = 1.0;
    QString pSqlQuery = QString("select PNG_%1 from ZOOMLEVEL where HOST = %2;").arg(index).arg(host);
    QSqlQuery pQuery(db);
    if (pQuery.exec(pSqlQuery)) {
        if(pQuery.next()) {
            pZoom = pQuery.value(0).toReal();
        }
    }
    pQuery.finish();
    pQuery.clear();
    return pZoom;
}

SqlManager &SqlManager::getInstance()
{
    if (nullptr == instance) {
        QMutexLocker locker(&mutex);
        if (nullptr == instance) {
            instance = new SqlManager();
        }
    }
    return *instance;
}

bool SqlManager::insertHostList(QSqlDatabase db, QStringList stringList)
{

    QString pHost    = stringList.value(0);
    QString pPort_1  = stringList.value(1);
    QString pSheet_1 = stringList.value(2);
    QString pPort_2  = stringList.value(3);
    QString pSheet_2 = stringList.value(4);
    QString pPort_3  = stringList.value(5);
    QString pSheet_3 = stringList.value(6);
    QString pPort_4  = stringList.value(7);
    QString pSheet_4 = stringList.value(8);
    QString pPort_5  = stringList.value(9);
    QString pSheet_5 = stringList.value(10);
    QString pPort_6  = stringList.value(11);
    QString pSheet_6 = stringList.value(12);
    QString pPort_7  = stringList.value(13);
    QString pSheet_7 = stringList.value(14);
    QString pPort_8  = stringList.value(15);
    QString pSheet_8 = stringList.value(16);
    QString pDbPath  = stringList.value(17);
    QString pAble    = stringList.value(18);
    QString pAdrress = stringList.value(19);

    QString sqlQuery = QString("insert into HOSTINFO values('%1',%2,'%3',%4,"
                               "'%5',%6,'%7',%8,'%9',%10,"
                               "'%11',%12,'%13',%14,'%15',"
                               "%16,'%17','%18',%19,'%20');").\
            arg(pHost).arg(pPort_1).arg(pSheet_1).\
            arg(pPort_2).arg(pSheet_2).arg(pPort_3).\
            arg(pSheet_3).arg(pPort_4).arg(pSheet_4).\
            arg(pPort_5).arg(pSheet_5).arg(pPort_6).\
            arg(pSheet_6).arg(pPort_7).arg(pSheet_7).\
            arg(pPort_8).arg(pSheet_8).arg(pDbPath).arg(pAble).arg(pAdrress);

    QSqlQuery query(db);
    if(!query.exec(sqlQuery))
    {
        return false;
    }
    query.finish();
    query.clear();
    return true;
}

bool SqlManager::delelteHostItem(QSqlDatabase db, QString host)
{
    QString pSqlQuery = "delete from HOSTINFO where HOST = '"+host+"';";

    QSqlQuery query(db);
    if(!query.exec(pSqlQuery)) {
        return false;
    }
    query.finish();
    query.clear();

    return true;
}

QList<QStringList> SqlManager::getRecordList(QSqlDatabase db, QString sqlQuery)
{
    QList<QStringList> pRecordList;
    QSqlQuery pQuery(db);
    if (pQuery.exec(sqlQuery)) {
        while(pQuery.next()) {
            QStringList pNodeList;
            for(int index = 0;index < 6;index++) {
                pNodeList.append(pQuery.value(index).toString());
            }
            pRecordList.append(pNodeList);
        }
    }
    pQuery.finish();
    pQuery.clear();
    return pRecordList;
}

bool SqlManager::delAllData(QSqlDatabase db,const QString &sqlQuery)
{

    QSqlQuery query(db);
    if(!query.exec(sqlQuery)) {
        return false;
    }
    query.finish();
    query.clear();

    return true;
}

bool SqlManager::delelteRecordItem(QSqlDatabase db, QStringList stringList)
{
    QString pHost = stringList.value(0);
    QString pLoop = stringList.value(1);
    QString pID   = stringList.value(2);
    QString pSts  = stringList.value(3);
    QString pTime = stringList.value(4);
    QString sqlQuery = QString("delete from RECORD where "
                               "HOST = '%1' and LOOP = %2 and ID = %3 and STS = '%4' and TIME = %5;").arg(pHost).arg(pLoop).arg(pID).arg(pSts).arg(pTime);

    QSqlQuery query(db);
    if (!query.exec(sqlQuery)) {
        return false;
    }
    query.finish();
    query.clear();

    return true;
}

QList<QStringList> SqlManager::getHostList(QSqlDatabase db, const QString sqlQuery, ListMode listMode)
{
    QList<QStringList> list;
    QSqlQuery query(db);
    if (query.exec(sqlQuery)) {
        while(query.next()) {
            QStringList nodeList;
            for(int index = 0;index < listMode;index++) {
                nodeList.append(query.value(index).toString());
            }
            list.append(nodeList);
        }
    }
    query.finish();
    query.clear();

    return list;
}
