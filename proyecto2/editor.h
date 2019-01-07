#ifndef EDITOR_H
#define EDITOR_H

#include <stdio.h>
#include <stdlib.h>
#include <parser.h>
#include <QTextEdit>
#include <QString>
#include <iostream>
#include <nodo.h>
#include <graficador.h>
#include <errorT.h>
#include <primerRecorrido.h>

extern int yyrestart(QString codigo);
extern int yyparse();
extern void setSalida(QTextEdit * salida, QTextEdit * entrada, QString texto);

#include <QMainWindow>

namespace Ui {
class editor;
}

class editor : public QMainWindow
{
    Q_OBJECT

public:
    explicit editor(QWidget *parent = 0);
    ~editor();
    void imprimirErrores();
    void imprimirTabla();
    primerRecorrido *recorrido1;
    QList<nodo> * listaArboles;

private slots:
    void on_botonCompilar_clicked();

    void on_txtinput_selectionChanged();

private:
    Ui::editor *ui;
};

#endif // EDITOR_H
