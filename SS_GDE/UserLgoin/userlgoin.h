#ifndef USERLGOIN_H
#define USERLGOIN_H

#include <QDialog>

namespace Ui {
class UserLgoin;
}

class UserLgoin : public QDialog
{
    Q_OBJECT

public:
    explicit UserLgoin(QWidget *parent = 0);
    ~UserLgoin();

private:
    Ui::UserLgoin *ui;
};

#endif // USERLGOIN_H
