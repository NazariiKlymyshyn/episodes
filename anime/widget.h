#ifndef WIDGET_H
#define WIDGET_H
#include <sortcombobox.h>
#include <QWidget>
#include <QApplication>
#include <QCoreApplication>
#include <QDebug>
#include <QtNetwork>
#include <QString>
#include <QByteArray>
#include <QtWidgets>
#include <QScrollBar>
#include <QAbstractItemModel>
#include <QAbstractTableModel>
#include <algorithm>
#include <mutex>
#include <atomic>
#include <chrono>
#include <numeric>
#include <string>
#include <vector>
#include <boost/asio.hpp>
#include <QFileDialog>
#include <QTextStream>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include <type_traits>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT
    
public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private slots:
     void GetInput();
     void OpenFile();

     //void on_pushButton_2_clicked();
     
private:
     struct TitleInfo
     {
         std::string title;
         std::size_t episodes;
         std::size_t position;
     };
     struct userInfo
     {
         double hours = 0.;
         double days = 0.;
         std::size_t titles_ = 0;
         std::size_t minuts = 0;
         std::size_t episode = 0;
     };
     QTableWidget * ptableWidget;
     QComboBox *pidComboBoxList;
     SortComboBox * sortComboBox;
     QPushButton * pcallDialogWindow, *pcallOpenLink, *pOpenJsonFile;
     QHBoxLayout * pHorizontalbxLayout;
     QVBoxLayout * pVerticallbxLayout;
     //std::vector<std::vector<std::pair<std::string,std::pair<std::size_t,std::size_t>>>> allUsersTitles;
     std::vector<std::vector<TitleInfo>> allUsersTitles;
     std::mutex mux;
     std::atomic<std::size_t> size;
     std::vector <std::string> idVector , allTitles, allImages;
     void do_work(const std::string &e) noexcept; 
     void FormTable() noexcept; 
     //void FormLogFiles() noexcept; 
     //void SaveFile( const std::vector<std::pair<std::string,std::pair<std::size_t,std::size_t>>> * v,  std::string & str) noexcept;
     
     std::vector <userInfo> userInfoVector;
     Ui::Widget *ui;
     std::chrono::time_point <std::chrono::system_clock,std::chrono::duration<double>> tp,tp2;
};
#endif // WIDGET_H

    /*
     *
269705
729512
430622
676306
771703
486214
536964
454905
701345
    */
