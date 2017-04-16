#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QtCore/QString>
#include <QtSql/QSqlDatabase>


class DbManager {
    public:
        DbManager(const QString& path);
    private:
        QSqlDatabase m_db;
};



#endif // DBMANAGER_H
