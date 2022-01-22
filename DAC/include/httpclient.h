#pragma once

#include <QObject>
//#include <QNetworkAccessManager>
//#include <QNetworkReply>
#include <QCoreApplication>
#include <iostream>
#include <string>
#include "http_client.h"

//namespace lib
//{
//    namespace qt
//    {
//        class http_client: public QObject, public lib::httpclient
//        {
//            //The Q_OBJECT macro must appear in the private section of a class definition that declares its own
//            // signals and slots or that uses other services provided by Qt's meta-object system.
//            Q_OBJECT
//
//            public:
//                explicit http_client(QObject *parent);
//
//                void get(const std::string &url, const lib::headers &headers,
//                         lib::callback<std::string> &callback) const override;
//
//                void put(const std::string &url, const std::string &body,
//                         const lib::headers &headers, lib::callback<std::string> &callback) const override;
//
//                void post(const std::string &url, const std::string &body,
//                          const lib::headers &headers, lib::callback<std::string> &callback) const override;
//
//                auto post(const std::string &url, const lib::headers &headers,
//                          const std::string &post_data) const -> std::string override;
//
//                void del(const std::string &url, const std::string &body, const lib::headers &headers,
//                         lib::callback<std::string> &callback) const override;
//                //httpclient();
//
//            private:
//                QNetworkAccessManager *network_manager = nullptr;
//
//                static auto request(const std::string &url,
//                    const lib::headers &headers) -> QNetworkRequest;
//
//                void await(QNetworkReply *reply, lib::callback<QByteArray> &callback) const;
//        };
//    };
//};
//
