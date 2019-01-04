#include "editor.h"
#include "ui_editor.h"
#include <iostream> //libreria para imprimir en cosola de C
#include <QString>
#include "nodo.h"
#include <QMessageBox>
#include <qlist.h>
extern int yyparse();
extern nodo *raiz; // Raiz del arbol
extern int linea; // Linea del token
extern int columna; // Columna de los tokens
extern int yylineno;
extern QList<errorT> *listaErrores;// = new QList<errorT>();
QList<nodo> *listaArboles  = new QList<nodo>();
#include "parser.h"
#include "scanner.h"
#include "primerRecorrido.h"

editor::editor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::editor)
{
    ui->setupUi(this);
}

editor::~editor()
{
    delete ui;
}

void editor::on_botonCompilar_clicked()
{
    this->listaArboles  = new QList<nodo>();
    QString texto;
    texto = ui->txtinput->toPlainText();
    //std::cout << texto.toStdString() << std::endl;
    YY_BUFFER_STATE buffer = yy_scan_string(texto.toUtf8().constData());
    linea =0;
    columna =0;
    yylineno = 0;
    if(yyparse()==0)
    {
        ui->txtConsola->setText("Analisis completado.");
        graficador *graf = new graficador(raiz);
        graf->generarImagen();        
        primerRecorrido *inter = new primerRecorrido();
        this->listaArboles->append(*raiz);
        inter->interpretar(this->listaArboles);


    }
    else
    {
        ui->txtConsola->setText("Errores sintacticos en la entrada");
    }
    yy_delete_buffer(buffer);
    imprimirErrores();

}

void editor::on_txtinput_selectionChanged()
{
    QPlainTextEdit *editor = ui->txtinput;
    QTextCursor cursor = editor->textCursor();
    std::cout << cursor.blockNumber() << std::endl;
}


void editor::imprimirErrores()
{
    QString errores = "";
    for(int i =0; i<listaErrores->count(); i++)
    {
        errorT error = listaErrores->first();
        errores = errores + error.tipo
                +"\t" + error.desc
                +"\t" + QString::number(error.linea)
                +"\t" + QString::number(error.columna);
        errores = errores + "\n";
    }
    ui->txtConsola->setText(errores);
}

