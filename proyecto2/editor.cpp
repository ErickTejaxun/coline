#include "editor.h"
#include "ui_editor.h"
#include <iostream> //libreria para imprimir en cosola de C
#include <QString>
#include "nodo.h"
#include <QMessageBox>

extern int yyparse();
extern nodo *raiz; // Raiz del arbol
extern int linea; // Linea del token
extern int columna; // Columna de los tokens

#include "parser.h"
#include "scanner.h"


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
    QString texto;
    texto = ui->txtinput->toPlainText();
    std::cout << texto.toStdString() << std::endl;
    YY_BUFFER_STATE buffer = yy_scan_string(texto.toUtf8().constData());
    linea =0;
    columna =0;
    if(yyparse()==0)
    {
        ui->txtConsola->setText("Analisis completado.");
        graficador *graf = new graficador(raiz);
        graf->generarImagen();

    }
    else
    {
        ui->txtConsola->setText("Errores sintacticos en la entrada");
    }
    yy_delete_buffer(buffer);

}
