#ifndef SEAFILE_CLIENT_LOGIN_DIALOG_H
#define SEAFILE_CLIENT_LOGIN_DIALOG_H

#include <QDialog>
#include "ui_login-dialog.h"

#include <QUrl>
#include <QString>
#include <QNetworkReply>

struct Account;
class LoginRequest;
class QNetworkReply;
class QSslError;
class ApiError;

class LoginDialog : public QDialog,
                    public Ui::LoginDialog
{
    Q_OBJECT
public:
    LoginDialog(QWidget *parent=0);

private slots:
    void doLogin();
    void loginSuccess(const QString& token);
    void loginFailed(const ApiError& error);

private:
    Q_DISABLE_COPY(LoginDialog);
    bool validateInputs();
    void disableInputs();
    void enableInputs();
    void showWarning(const QString& msg);

    void onNetworkError(const QNetworkReply::NetworkError& error, const QString& error_string);
    void onSslErrors(QNetworkReply *reply, const QList<QSslError>& errors);
    void onHttpError(int code);

    QUrl url_;
    QString username_;
    QString password_;
    QString computer_name_;
    LoginRequest *request_;
};

#endif // SEAFILE_CLIENT_LOGIN_DIALOG_H
