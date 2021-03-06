/*
    mainwindow.h (part of GNSS-Stylus)
    Copyright (C) 2019 Pasi Nuutinmaki (gnssstylist<at>sci<dot>fi)

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

/**
 * @file mainwindow.h
 * @brief Declaration for the main application form.
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCloseEvent>

#include "serialthread.h"
#include "ubloxdatastreamprocessor.h"
#include "messagemonitorform.h"
#include "relposnedform.h"
#include "essentialsform.h"
#include "postprocessform.h"

namespace Ui {
class MainWindow;
}

/**
 * @brief Main application form.
 *
 * Doesn't really have much functionality on it's own, processing is mostly done under other forms/classes.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr); //!< Constructor
    ~MainWindow();

private slots:

    void commThread_Base_ErrorMessage(const QString& errorMessage);
    void commThread_Base_WarningMessage(const QString& warningMessage);
    void commThread_Base_InfoMessage(const QString& infoMessage);
    void commThread_Base_DataReceived(const QByteArray& byte);
    void commThread_Base_SerialTimeout(void);

    void ubloxProcessor_Base_rtcmMessageReceived(const RTCMMessage&);

    void commThread_RoverA_ErrorMessage(const QString& errorMessage);
    void commThread_RoverA_WarningMessage(const QString& warningMessage);
    void commThread_RoverA_InfoMessage(const QString& infoMessage);
    void commThread_RoverA_DataReceived(const QByteArray& byte);
    void commThread_RoverA_SerialTimeout(void);
    void ubloxProcessor_RoverA_ubxMessageReceived(const UBXMessage&);

    void commThread_RoverB_ErrorMessage(const QString& errorMessage);
    void commThread_RoverB_WarningMessage(const QString& warningMessage);
    void commThread_RoverB_InfoMessage(const QString& infoMessage);
    void commThread_RoverB_DataReceived(const QByteArray& byte);
    void commThread_RoverB_SerialTimeout(void);
    void ubloxProcessor_RoverB_ubxMessageReceived(const UBXMessage&);

    void on_pushButton_StartThread_Base_clicked();

    void on_pushButton_TerminateThread_Base_clicked();

    void on_checkBox_SuspendThread_Base_stateChanged(int arg1);

    void on_pushButton_ShowMessageWindow_Base_clicked();

    void on_pushButton_ClearRTCMCounter_Base_clicked();

    void on_pushButton_ClearErrorMessage_Base_clicked();

    void on_pushButton_ClearWarningMessage_Base_clicked();

    void on_pushButton_ClearInfoMessage_Base_clicked();

    void on_pushButton_StartThread_RoverA_clicked();

    void on_pushButton_TerminateThread_RoverA_clicked();

    void on_pushButton_ShowMessageWindow_RoverA_clicked();

    void on_checkBox_SuspendThread_RoverA_stateChanged(int arg1);

    void on_pushButton_ClearRTCMCounter_RoverA_clicked();

    void on_pushButton_ClearErrorMessage_RoverA_clicked();

    void on_pushButton_ClearWarningMessage_RoverA_clicked();

    void on_pushButton_ClearInfoMessage_RoverA_clicked();

    void on_pushButton_ShowRELPOSNEDForm_RoverA_clicked();

    void on_pushButton_StartThread_RoverB_clicked();

    void on_pushButton_TerminateThread_RoverB_clicked();

    void on_pushButton_ShowMessageWindow_RoverB_clicked();

    void on_pushButton_ShowRELPOSNEDForm_RoverB_clicked();

    void on_checkBox_SuspendThread_RoverB_stateChanged(int arg1);

    void on_pushButton_ClearRTCMCounter_RoverB_clicked();

    void on_pushButton_ClearErrorMessage_RoverB_clicked();

    void on_pushButton_ClearWarningMessage_RoverB_clicked();

    void on_pushButton_ClearInfoMessage_RoverB_clicked();

    void on_pushButton_ShowEssentialsWindow_clicked();

    void on_pushButton_ShowPostProcessingWindow_clicked();

private:
    Ui::MainWindow *ui;

    MessageMonitorForm* messageMonitorForm_Base;
    SerialThread* serialThread_Base;
    UBloxDataStreamProcessor ubloxDataStreamProcessor_Base;
    int messageCounter_RTCM_Base;

    MessageMonitorForm* messageMonitorForm_RoverA;
    SerialThread* serialThread_RoverA;
    UBloxDataStreamProcessor ubloxDataStreamProcessor_RoverA;
    int messageCounter_RELPOSNED_RoverA;
    RELPOSNEDForm* relposnedForm_RoverA;

    MessageMonitorForm* messageMonitorForm_RoverB;
    SerialThread* serialThread_RoverB;
    UBloxDataStreamProcessor ubloxDataStreamProcessor_RoverB;
    int messageCounter_RELPOSNED_RoverB;
    RELPOSNEDForm* relposnedForm_RoverB;

    EssentialsForm* essentialsForm;

    PostProcessingForm* postProcessingForm;

    void closeEvent (QCloseEvent *event);

};

#endif // MAINWINDOW_H
