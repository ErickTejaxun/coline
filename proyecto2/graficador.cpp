#include "graficador.h"
#include <QString>
#include <fstream>
#include <iostream>
#include <QtWidgets>
graficador::graficador()
{
    this->contador = 0;
}

graficador::graficador(nodo *raiz)
{
    this->grafo = "";
    this->raiz = raiz;
    this->contador = 0;
}

QString graficador::graficar()
{
    grafo = "digraph G{";
    grafo += "node[shape=\"box\"];";
    grafo += "nodo0[label=\"" + escapar("[" +raiz->tipo +"," + QString::number(raiz->tipo_)+ "("+ QString::number(raiz->linea)+","+ QString::number(raiz->columna)+")"+"]"+raiz->valor)  + "\"];\n";
    this->contador = 1;
    recorrerAST("nodo0", raiz);
    grafo += "}";
    return grafo;
}

void graficador::recorrerAST(QString padre, nodo *hijo)
{
/*    for (nodo nodo: hijo->hijos )
    {
        QString nombreHijo = "nodo" +  QString::number(contador);//  this->contador;
        grafo += nombreHijo + "[label=\"" + escapar("[" +nodo.tipo +"]"+nodo.valor)  + "\"];\n";
        grafo += padre + "->" + nombreHijo + ";\n";
        contador++;
        recorrerAST(nombreHijo, &nodo);
    }
*/
    int x = 0;
    for (x = 0 ; x < hijo->hijos.count() ; x++)
    {
        nodo nodo = hijo->hijos[x];
        QString nombreHijo = "nodo" +  QString::number(contador);//  this->contador;
        grafo += nombreHijo + "[label=\"" + escapar("[" +nodo.tipo +"," + QString::number(nodo.tipo_)+ "("+ QString::number(nodo.linea)+","+ QString::number(nodo.columna)+")"+nodo.valor)  + "\"];\n";
        grafo += padre + "->" + nombreHijo + ";\n";
        contador++;
        recorrerAST(nombreHijo, &nodo);
    }
}

QString graficador::escapar(QString cadena)
{
    cadena = cadena.replace("\\", "\\\\");
    cadena = cadena.replace("\"", "\\\"");
    return cadena;
}

void graficador:: generarImagen()
{
    graficar();
    QString grafoDOT = this->grafo;
    QString path = "C:\\Users\\erick\\Documents\\Graficas\\qt\\";
    QFile qFile(path+"grafo.txt");
    if(qFile.open(QIODevice::WriteOnly))
    {
        QTextStream out(&qFile); out << grafoDOT;
        qFile.close();
    }
    //"dot -Tjpg " + fileName + " -o " + fileName.Replace(".txt", ".jpg")
    QString cadenaComando = "dot -Tjpg " + path + "grafo.txt -o " + path+"grafo.jpg ";
    std::cout << cadenaComando.toStdString() << "\n" << endl;

    system(cadenaComando.toUtf8().constData());
/*    std::ofstream myfile;
    myfile.open ("grafo.txt",std::ios_base::app);
    myfile << grafoDOT.toStdString();
    myfile.close();
*/
}
