#ifndef RECORDINFO_H
#define RECORDINFO_H

#include <QWidget>

namespace Ui {
class RecordInfo;
}

class RecordInfo : public QWidget
{
    Q_OBJECT

public:
    explicit RecordInfo(QWidget *parent = 0);
    ~RecordInfo();

private:
    Ui::RecordInfo *ui;
};

#endif // RECORDINFO_H
