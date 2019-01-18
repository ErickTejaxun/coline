/********************************************************************************
** Form generated from reading UI file 'editor.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITOR_H
#define UI_EDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_editor
{
public:
    QWidget *centralwidget;
    QPushButton *botonCompilar;
    QTabWidget *contenedorArchivos;
    QWidget *tab;
    QPlainTextEdit *txtinput;
    QWidget *tab_2;
    QPushButton *botonDebuger;
    QPushButton *botonContinuar;
    QPushButton *botonSiguiente;
    QPushButton *botonSaltar;
    QPushButton *botonAutomatico;
    QPushButton *botonExportar;
    QTabWidget *tabWidget_2;
    QWidget *tab_3;
    QTextEdit *txtConsola;
    QWidget *tab_4;
    QTableWidget *tablaSimbolos;
    QWidget *tab_5;
    QTableWidget *tablaErrores;
    QWidget *tab_6;
    QTableView *tablaStack;
    QWidget *tab_7;
    QTableView *tablaHeap;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QPlainTextEdit *txtCodigo3d;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *editor)
    {
        if (editor->objectName().isEmpty())
            editor->setObjectName(QString::fromUtf8("editor"));
        editor->resize(1609, 983);
        centralwidget = new QWidget(editor);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        botonCompilar = new QPushButton(centralwidget);
        botonCompilar->setObjectName(QString::fromUtf8("botonCompilar"));
        botonCompilar->setGeometry(QRect(50, 20, 99, 27));
        contenedorArchivos = new QTabWidget(centralwidget);
        contenedorArchivos->setObjectName(QString::fromUtf8("contenedorArchivos"));
        contenedorArchivos->setGeometry(QRect(10, 50, 781, 511));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        txtinput = new QPlainTextEdit(tab);
        txtinput->setObjectName(QString::fromUtf8("txtinput"));
        txtinput->setGeometry(QRect(10, 10, 751, 461));
        contenedorArchivos->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        contenedorArchivos->addTab(tab_2, QString());
        botonDebuger = new QPushButton(centralwidget);
        botonDebuger->setObjectName(QString::fromUtf8("botonDebuger"));
        botonDebuger->setGeometry(QRect(160, 20, 99, 27));
        botonContinuar = new QPushButton(centralwidget);
        botonContinuar->setObjectName(QString::fromUtf8("botonContinuar"));
        botonContinuar->setGeometry(QRect(270, 20, 99, 27));
        botonSiguiente = new QPushButton(centralwidget);
        botonSiguiente->setObjectName(QString::fromUtf8("botonSiguiente"));
        botonSiguiente->setGeometry(QRect(370, 20, 99, 27));
        botonSaltar = new QPushButton(centralwidget);
        botonSaltar->setObjectName(QString::fromUtf8("botonSaltar"));
        botonSaltar->setGeometry(QRect(470, 20, 99, 27));
        botonAutomatico = new QPushButton(centralwidget);
        botonAutomatico->setObjectName(QString::fromUtf8("botonAutomatico"));
        botonAutomatico->setGeometry(QRect(570, 20, 99, 27));
        botonExportar = new QPushButton(centralwidget);
        botonExportar->setObjectName(QString::fromUtf8("botonExportar"));
        botonExportar->setGeometry(QRect(680, 20, 99, 27));
        tabWidget_2 = new QTabWidget(centralwidget);
        tabWidget_2->setObjectName(QString::fromUtf8("tabWidget_2"));
        tabWidget_2->setGeometry(QRect(10, 570, 1571, 351));
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        txtConsola = new QTextEdit(tab_3);
        txtConsola->setObjectName(QString::fromUtf8("txtConsola"));
        txtConsola->setGeometry(QRect(20, 10, 1461, 291));
        tabWidget_2->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        tablaSimbolos = new QTableWidget(tab_4);
        tablaSimbolos->setObjectName(QString::fromUtf8("tablaSimbolos"));
        tablaSimbolos->setGeometry(QRect(0, 20, 1551, 291));
        tabWidget_2->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        tablaErrores = new QTableWidget(tab_5);
        tablaErrores->setObjectName(QString::fromUtf8("tablaErrores"));
        tablaErrores->setGeometry(QRect(10, 10, 1191, 281));
        tabWidget_2->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QString::fromUtf8("tab_6"));
        tablaStack = new QTableView(tab_6);
        tablaStack->setObjectName(QString::fromUtf8("tablaStack"));
        tablaStack->setGeometry(QRect(0, 0, 1221, 171));
        tabWidget_2->addTab(tab_6, QString());
        tab_7 = new QWidget();
        tab_7->setObjectName(QString::fromUtf8("tab_7"));
        tablaHeap = new QTableView(tab_7);
        tablaHeap->setObjectName(QString::fromUtf8("tablaHeap"));
        tablaHeap->setGeometry(QRect(0, 0, 1221, 171));
        tabWidget_2->addTab(tab_7, QString());
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(800, 70, 691, 491));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 689, 489));
        txtCodigo3d = new QPlainTextEdit(scrollAreaWidgetContents);
        txtCodigo3d->setObjectName(QString::fromUtf8("txtCodigo3d"));
        txtCodigo3d->setGeometry(QRect(10, 10, 661, 461));
        scrollArea->setWidget(scrollAreaWidgetContents);
        editor->setCentralWidget(centralwidget);
        menubar = new QMenuBar(editor);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1609, 20));
        editor->setMenuBar(menubar);
        statusbar = new QStatusBar(editor);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        editor->setStatusBar(statusbar);

        retranslateUi(editor);

        contenedorArchivos->setCurrentIndex(0);
        tabWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(editor);
    } // setupUi

    void retranslateUi(QMainWindow *editor)
    {
        editor->setWindowTitle(QApplication::translate("editor", "MainWindow", nullptr));
        botonCompilar->setText(QApplication::translate("editor", "Compilar", nullptr));
        contenedorArchivos->setTabText(contenedorArchivos->indexOf(tab), QApplication::translate("editor", "Tab 1", nullptr));
        contenedorArchivos->setTabText(contenedorArchivos->indexOf(tab_2), QApplication::translate("editor", "Tab 2", nullptr));
        botonDebuger->setText(QApplication::translate("editor", "Debuger", nullptr));
        botonContinuar->setText(QApplication::translate("editor", "Continuar", nullptr));
        botonSiguiente->setText(QApplication::translate("editor", "Siguiente", nullptr));
        botonSaltar->setText(QApplication::translate("editor", "Saltar", nullptr));
        botonAutomatico->setText(QApplication::translate("editor", "Automatico", nullptr));
        botonExportar->setText(QApplication::translate("editor", "Exportar", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_3), QApplication::translate("editor", "Consola", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_4), QApplication::translate("editor", "Tabla de Simbolos", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_5), QApplication::translate("editor", "Errores", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_6), QApplication::translate("editor", "Stack", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_7), QApplication::translate("editor", "Heap", nullptr));
    } // retranslateUi

};

namespace Ui {
    class editor: public Ui_editor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITOR_H
