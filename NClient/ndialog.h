#ifndef NDIALOG_H
#define NDIALOG_H

#include <QDialog>

namespace Ui {
    class NDialog;
}
namespace NChat {
class NDialog : public QDialog {
    Q_OBJECT
public:
    explicit NDialog(QWidget *parent = 0);
    ~NDialog();
    QString hostname() const;
    quint16 port() const;
private slots:
    void on_ok_clicked();
    void on_cancel_clicked();
private:
    Ui::NDialog *ui;
    QString nHostname;
    quint16 nPort;
};
inline QString NDialog::hostname() const {
    return nHostname;
}
inline quint16 NDialog::port() const {
    return nPort;
}
} // NChat
#endif // NDIALOG_H
