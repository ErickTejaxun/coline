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

private slots:
    void on_botonCompilar_clicked();

private:
    Ui::editor *ui;
};

#endif // EDITOR_H
