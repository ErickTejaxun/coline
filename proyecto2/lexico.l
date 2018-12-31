%option case-insensitive
%option yylineno
%{
#include <cstdlib>
#include "parser.h"
#include <QString>
#include <stdio.h>
#include <iostream>
#include <nodo.h>

int yylex();
void yyerror(const char *s);
int linea=0; // Para contar lineas
int columna = 1; // para las columnas
nodo *raiz;
%}

%option header-file="scanner.h"
%option outfile="scanner.cpp"
%option noyywrap
%option nounput

letra [a-zñA-ZÑ]+
numero [0-9]+
booleano ("verdadero"|"falso")
decimal [0-9]+"."[0-9]+
caracter "\'"("\\")?({letra}|{numero})"\'"
iden {letra}({letra}|{numero}|"_")*
cadena "\""[^"\""]*"\""
sinosi ("sino")("si")



%%
{numero}          {  strcpy(yylval.TEXT, yytext); columna=columna+strlen(yytext); return entero;}
{decimal}          {  strcpy(yylval.TEXT, yytext); columna=columna+strlen(yytext); return decimal;}
{caracter}          {  strcpy(yylval.TEXT, yytext); columna=columna+strlen(yytext); return caracter;}
{booleano}          {  strcpy(yylval.TEXT, yytext); columna=columna+strlen(yytext); return booleano;}
{cadena}          {  strcpy(yylval.TEXT, yytext); columna=columna+strlen(yytext); return cadena;}
"("          {  strcpy(yylval.TEXT, yytext); columna=columna+strlen(yytext); return parA; }
")"          {  strcpy(yylval.TEXT, yytext); columna=columna+strlen(yytext); return parC; }
"{"          {  strcpy(yylval.TEXT, yytext); columna=columna+strlen(yytext); return illave; }
"}"          {  strcpy(yylval.TEXT, yytext); columna=columna+strlen(yytext); return fllave; }
"["          {  strcpy(yylval.TEXT, yytext); columna=columna+strlen(yytext); return iCor; }
"]"          {  strcpy(yylval.TEXT, yytext); columna=columna+strlen(yytext); return fCor; }
":"          {  strcpy(yylval.TEXT, yytext); columna=columna+strlen(yytext); return dosP; }
"."          {  strcpy(yylval.TEXT, yytext); columna=columna+strlen(yytext); return punto; }
","          {  strcpy(yylval.TEXT, yytext); columna=columna+strlen(yytext); return coma; }
";"          {  strcpy(yylval.TEXT, yytext); columna=columna+strlen(yytext); return puntoComa; }
"+"         {  strcpy(yylval.TEXT, yytext); columna=columna+strlen(yytext); return suma; }
"-"         {  strcpy(yylval.TEXT, yytext); columna=columna+strlen(yytext); return menos; }
"*"         {  strcpy(yylval.TEXT, yytext); columna=columna+strlen(yytext); return multi; }
"/"         {  strcpy(yylval.TEXT, yytext); columna=columna+strlen(yytext); return division; }
"^"         {  strcpy(yylval.TEXT, yytext); columna=columna+strlen(yytext); return potencia; }
">"         {  strcpy(yylval.TEXT, yytext); columna=columna+strlen(yytext); return mayor; }
"<"         {  strcpy(yylval.TEXT, yytext); columna=columna+strlen(yytext); return menor; }
"="         {  strcpy(yylval.TEXT, yytext); columna=columna+strlen(yytext); return igual; }
"++"         {  strcpy(yylval.TEXT, yytext); columna=columna+strlen(yytext); return aumento;}
"--"         {  strcpy(yylval.TEXT, yytext); columna=columna+strlen(yytext); return decremento;}
"+="         {  strcpy(yylval.TEXT, yytext); columna=columna+strlen(yytext); return masigual; }
"*="         {  strcpy(yylval.TEXT, yytext); columna=columna+strlen(yytext); return porigual; }
"-="         {  strcpy(yylval.TEXT, yytext); columna=columna+strlen(yytext); return menosigual; }
"/="         {  strcpy(yylval.TEXT, yytext); columna=columna+strlen(yytext); return divigual; }
">="         {  strcpy(yylval.TEXT, yytext); columna=columna+strlen(yytext); return mayorigual; }
"<="         {  strcpy(yylval.TEXT, yytext); columna=columna+strlen(yytext); return menorigual; }
"=="         {  strcpy(yylval.TEXT, yytext); columna=columna+strlen(yytext); return igualigual; }
"!="         {  strcpy(yylval.TEXT, yytext); columna=columna+strlen(yytext); return desigual; }
"||"         {  strcpy(yylval.TEXT, yytext); columna=columna+strlen(yytext); return o; }
"&&"         {  strcpy(yylval.TEXT, yytext); columna=columna+strlen(yytext); return y; }
"!"         {  strcpy(yylval.TEXT, yytext); columna=columna+strlen(yytext); return no; }
"?"         {  strcpy(yylval.TEXT, yytext); columna=columna+strlen(yytext); return interrogacion; }
"booleano"          {  strcpy(yylval.TEXT, yytext); columna=columna+strlen(yytext); return tipoBooleano;}
"entero"          {  strcpy(yylval.TEXT, yytext); columna=columna+strlen(yytext); return tipoEntero; }
"caracter"          {  strcpy(yylval.TEXT, yytext); columna=columna+strlen(yytext); return tipoCaracter; }
"decimal"          {  strcpy(yylval.TEXT, yytext); columna=columna+strlen(yytext); return tipoDecimal; }
"imprimir"          {  strcpy(yylval.TEXT, yytext); columna=columna+strlen(yytext); return imprimir; }
"concatenar"          {  strcpy(yylval.TEXT, yytext); columna=columna+strlen(yytext); return concatenar; }
"tamanio"          {  strcpy(yylval.TEXT, yytext); columna=columna+strlen(yytext); return tamanio; }
"convertiracadena" { strcpy(yylval.TEXT, yytext); columna=columna+strlen(yytext); return convertirAcadena;}
"convertiraentero" { strcpy(yylval.TEXT, yytext); columna=columna+strlen(yytext); return convertirAentero;}
"clase"          {  strcpy(yylval.TEXT, yytext); columna=columna+strlen(yytext); return clase;}
"este"          {  strcpy(yylval.TEXT, yytext); columna=columna+strlen(yytext); return este;}
"publico"          {  strcpy(yylval.TEXT, yytext); columna=columna+strlen(yytext); return publico;}
"privado"          {  strcpy(yylval.TEXT, yytext); columna=columna+strlen(yytext); return privado;}
"protegido"          {  strcpy(yylval.TEXT, yytext); columna=columna+strlen(yytext); return protegido;}
"vacio"          { strcpy(yylval.TEXT, yytext); columna=columna+strlen(yytext); return vacio;}
"hereda_de"          {  strcpy(yylval.TEXT, yytext); columna=columna+strlen(yytext); return heredade;}
"retornar"          {  strcpy(yylval.TEXT, yytext); columna=columna+strlen(yytext); return retornar;}
"importar"          {  strcpy(yylval.TEXT, yytext); columna=columna+strlen(yytext); return importar;}
"@sobrescribir"      {  strcpy(yylval.TEXT, yytext); columna=columna+strlen(yytext); return sobreescribir;}
"principal"          {  strcpy(yylval.TEXT, yytext); columna=columna+strlen(yytext); return principal;}
"nuevo"          {  strcpy(yylval.TEXT, yytext); columna=columna+strlen(yytext); return nuevo;}
"nada"          {  strcpy(yylval.TEXT, yytext); columna=columna+strlen(yytext); return nada; }
"detener"          {  strcpy(yylval.TEXT, yytext); columna=columna+strlen(yytext); return detener;}// Sentencias de flujo de control
"continuar"          {  strcpy(yylval.TEXT, yytext); columna=columna+strlen(yytext); return continuar;}
"si"          {  strcpy(yylval.TEXT, yytext); columna=columna+strlen(yytext); return si; }// IF
{sinosi}        {  strcpy(yylval.TEXT, yytext); columna=columna+strlen(yytext); return sinosi; }
"sino"          {  strcpy(yylval.TEXT, yytext); columna=columna+strlen(yytext); return sino; }
"seleccionar"          {  strcpy(yylval.TEXT, yytext); columna=columna+strlen(yytext); return seleccionar;}// Switch case
"caso"          {  strcpy(yylval.TEXT, yytext); columna=columna+strlen(yytext); return caso; }
"defecto"          {  strcpy(yylval.TEXT, yytext); columna=columna+strlen(yytext); return defecto; }
"mientras"          {  strcpy(yylval.TEXT, yytext); columna=columna+strlen(yytext); return mientras;}
"hacer"          {  strcpy(yylval.TEXT, yytext); columna=columna+strlen(yytext); return hacer; }
"para"          {  strcpy(yylval.TEXT, yytext); columna=columna+strlen(yytext); return para; }
"lista"          {  strcpy(yylval.TEXT, yytext); columna=columna+strlen(yytext); return lista; }
"insertar"          {  strcpy(yylval.TEXT, yytext); columna=columna+strlen(yytext); return insertar; }
"obtener"          {  strcpy(yylval.TEXT, yytext); columna=columna+strlen(yytext); return obtener; }
"buscar"          {  strcpy(yylval.TEXT, yytext); columna=columna+strlen(yytext); return buscar; }
"pila"          {  strcpy(yylval.TEXT, yytext); columna=columna+strlen(yytext); return pila; }
"apliar"          {  strcpy(yylval.TEXT, yytext); columna=columna+strlen(yytext); return apilar; }
"desapilar"          {  strcpy(yylval.TEXT, yytext); columna=columna+strlen(yytext); return desapilar; }
"cola"          {  strcpy(yylval.TEXT, yytext); columna=columna+strlen(yytext); return cola; }
"encolar"          {  strcpy(yylval.TEXT, yytext); columna=columna+strlen(yytext); return encolar; }
"desencolar"          {  strcpy(yylval.TEXT, yytext); columna=columna+strlen(yytext); return desencolar; }
"mostraredd"          {  strcpy(yylval.TEXT, yytext); columna=columna+strlen(yytext); return mostraredd; }
"leer_teclado"          {  strcpy(yylval.TEXT, yytext); columna=columna+strlen(yytext); return leer_teclado; }
{iden}          {  strcpy(yylval.TEXT, yytext); columna=columna+strlen(yytext); return id; }
"\t"            {
                    strcpy(yylval.TEXT, yytext); columna=26;
                }
[[:blank:]]     { columna++; }
"\n"            {linea++; columna = 0;}
.               {
                    strcpy(yylval.TEXT, yytext); columna=columna+strlen(yytext);
                    std::cout <<yytext <<" Error Lexico en la linea "<< linea << " Columna:"<< columna<<  std::endl;
                }
%%
