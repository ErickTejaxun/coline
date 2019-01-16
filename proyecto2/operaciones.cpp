#include "operaciones.h"
#include <editor.h>
#include <qdebug.h>
#include <codigo3d.h>
#include <errorT.h>
#include <scanner.h>


extern Codigo3d *code;
extern QList<errorT> *listaErrores;

enum Choice
{
    ID_ = 0 ,
    SENTENCIAS_ = 1,
    IMPRIMIR_ = 2,
    CONCATENAR_ =3,
    IMPORTAR_ = 4,
    PATH_ = 5,
    INSTRUCCIONES_ = 6,
    SOBRESCRIBIR_ = 7,
    DETENER_ =8,
    CONTINUAR_ = 9,
    MOSTRAREDD_ = 10,
    LEER_ = 11,
    PARA_ = 12,
    HACER_ = 13,
    MIENTRAS_ = 14,
    SELECCION_ = 15,
    SI_ = 16,
    SINOSI_ = 17,
    SELECCIONA_ = 18,
    CASO_ = 19,
    DEFECTO_ = 20,
    CASOS_  = 21,
    RETORNO_ = 22,
    DECLATRIB_ = 23,
    PUBLICO_ = 24,
    PRIVADO_ = 25,
    PROTEGIDO_ = 26,
    CONSTRUCTOR_ = 27,
    LPAR_ = 28,
    PARAMETROS_ = 29,
    PRINCIPAL_ = 30,
    FUNCION_ = 31,
    DIMS_ = 32,
    DIM_ = 33,
    CLASE_ = 34,
    HERENCIA_ = 35,
    VARIABLE_ = 36,
    ASIGA_ = 37,
    ASIG_ = 38,
    D_ = 38, // declaración
    DA_= 39, // declaración con asignacion.
    DAR_ = 40, // declaración array
    DARA_ = 41, // declaración array con asignación para cadenas
    LVALORES_ = 42, // Lista de valores funcion(1,3,4,arg5)
    VALORES_ = 43,
    DARAR_ = 44, //  darar declaracion array asignacion -- para arrays
    TBOOLEANO_ = 45,
    TENTERO_ = 46,
    TCARACTER_ = 47,
    TOBJETO_ = 48,
    SS_ = 49, //       expl?  valor1:valor2;
    EXPL_ = 50,
    EXPR_ = 51,
    EXPA_ = 52,
    CONVERTIRACADENA_ = 53,
    CONVERTIRAENTERO_ = 54,
    LLAMADA_ = 55,
    AUMENTO_ = 56,
    DECREMENTO_ = 57,
    IDV_ = 58,
    ACCESO_ =59,
    SETENTENCIASG = 61, // Setnencias globales. Raiz del archivo
    SUMA_ = 62,
    RESTA_ = 63,
    MULTIPLICACION_ = 64,
    DIVISION_ = 65,
    MODULO_ = 66,
    POTENCIA_ = 67,
    MAYORQUE_ = 68,
    MENORQUE_ = 69,
    MENORIGUAL_ = 70,
    MAYORIGUAL_ = 71,
    IGUAL_ = 72,
    DESIGUAL_ = 73,
    AND_ = 74,
    OR_ = 75,
    NO_ = 76,
    TCADENA_ = 77,
    TNADA_ = 78,
    ACCESOARRAY_ = 79,
    TDECIMAL_ = 80,
    LACCESO_=81,
};

Operaciones::Operaciones()
{

}

Resultado *Operaciones::aritmetica(nodo *raiz)
{

    QString temp1;
    Resultado *resultado1;
    Resultado *resultado2;

    switch (raiz->tipo_) {
    case SUMA_:
    case RESTA_:
    case MULTIPLICACION_:
    case DIVISION_:
    case MODULO_:
    case POTENCIA_:
        resultado1=aritmetica(&raiz->hijos[0]);
        resultado2=aritmetica(&raiz->hijos[1]);
        break;
    case TENTERO_:
        return new Resultado("entero",TENTERO_,raiz->valor);
    case TDECIMAL_:
        return new Resultado("decimal",TDECIMAL_,raiz->valor);
    case TCARACTER_:
        {
            raiz->valor=raiz->valor.replace("'","");
            char c=raiz->valor.toStdString()[0];
            return new Resultado("caracter",TCARACTER_,QString::number(c));
        }
    case TCADENA_:
        {
            QString cad=almacenarCadena(raiz->valor);
            return new Resultado("cadena",TCADENA_,cad);
        }
        return new Resultado("cadena",TCADENA_,raiz->valor);
    case TBOOLEANO_:
        {
            if(raiz->valor=="verdadero")
            {
                return new Resultado("booleano",TBOOLEANO_,"1");
            }else
            {
                return new Resultado("booleano",TBOOLEANO_,"0");
            }
        }
     case TNADA_:
        {
            return new Resultado("nada",TNADA_,QString::number(code->NADA_));
        }
     case AUMENTO_:
        {
            resultado1=aritmetica(&raiz->hijos[0]);
            QString temp2=code->genTemp();
            code->cadena3d+=temp2+"="+resultado1->valor+"+1;//aumento\n";
            return new Resultado(resultado1->tipo,resultado1->tipo_,temp2);
        }
        case DECREMENTO_:
           {
               resultado1=aritmetica(&raiz->hijos[0]);
               QString temp2=code->genTemp();
               code->cadena3d+=temp2+"="+resultado1->valor+"-1;//decremento\n";
               return new Resultado(resultado1->tipo,resultado1->tipo_,temp2);
           }
        case CONVERTIRACADENA_:
            {
                resultado1=aritmetica(&raiz->hijos[0]);
                return convertirAcadena(resultado1,raiz);
            }
    case LACCESO_:
        {
            return acceso(raiz,"t1");
        }
        break;

    //default:
    //    break;
    }

    switch (raiz->tipo_) {
        case SUMA_:
            switch (resultado1->tipo_) {
                case TENTERO_:
                    switch (resultado2->tipo_) {
                        case TENTERO_:
                            temp1=code->genTemp();
                            code->cadena3d+=temp1+"="+resultado1->valor+"+"+resultado2->valor+";//operacion entero + entero\n";
                            return new Resultado("entero",TENTERO_,temp1);
                        case TDECIMAL_:
                            temp1=code->genTemp();
                            code->cadena3d+=temp1+"="+resultado1->valor+"+"+resultado2->valor+";//operacion entero + decimal\n";
                            return new Resultado("decimal",TDECIMAL_,temp1);
                        case TCARACTER_:
                            temp1=code->genTemp();
                            code->cadena3d+=temp1+"="+resultado1->valor+"+"+resultado2->valor+";//operacion entero + caracter\n";
                            return new Resultado("entero",TENTERO_,temp1);
                        case TCADENA_:
                            addError("Semantico","Operador + no valido en cadenas",raiz->linea,raiz->columna);
                            return new Resultado("error",-1,"");
                            break;
                        case TBOOLEANO_:
                            temp1=code->genTemp();
                            code->cadena3d+=temp1+"="+resultado1->valor+"+"+resultado2->valor+";//operacion entero + booleano\n";
                            return new Resultado("entero",TENTERO_,temp1);
                        case TNADA_:
                            //error
                            addError("Semantico","No se pueden operar valores de tipo nada",raiz->linea,raiz->columna);
                            return new Resultado("error",-1,"");
                        default:
                        //objeto
                            addError("Semantico","Operacion aritmetica no valida entre objetos y datos primitivos",raiz->linea,raiz->columna);
                            return new Resultado("error",-1,"");
                    }
                    break;
                case TDECIMAL_:
                    switch (resultado2->tipo_) {
                        case TENTERO_:
                            temp1=code->genTemp();
                            code->cadena3d+=temp1+"="+resultado1->valor+"+"+resultado2->valor+";//operacion decimal + entero\n";
                            return new Resultado("decimal",TDECIMAL_,temp1);
                        case TDECIMAL_:
                            temp1=code->genTemp();
                            code->cadena3d+=temp1+"="+resultado1->valor+"+"+resultado2->valor+";//operacion decimal + decimal\n";
                            return new Resultado("decimal",TDECIMAL_,temp1);
                        case TCARACTER_:
                            temp1=code->genTemp();
                            code->cadena3d+=temp1+"="+resultado1->valor+"+"+resultado2->valor+";//operacion decimal + caracter\n";
                            return new Resultado("decimal",TDECIMAL_,temp1);
                        case TCADENA_:
                            addError("Semantico","Operador + no valido en cadenas",raiz->linea,raiz->columna);
                            return new Resultado("error",-1,"");
                            break;
                        case TBOOLEANO_:
                            temp1=code->genTemp();
                            code->cadena3d+=temp1+"="+resultado1->valor+"+"+resultado2->valor+";//operacion decimal + booleano\n";
                            return new Resultado("decimal",TDECIMAL_,temp1);
                        case TNADA_:
                            addError("Semantico","No se pueden operar valores de tipo nada",raiz->linea,raiz->columna);
                            return new Resultado("error",-1,"");
                        default:
                        //objeto
                            addError("Semantico","Operacion aritmetica no valida entre objetos y datos primitivos",raiz->linea,raiz->columna);
                            return new Resultado("error",-1,"");
                            break;
                    }
                    break;
                case TCARACTER_:
                    switch (resultado2->tipo_) {
                        case TENTERO_:
                            temp1=code->genTemp();
                            code->cadena3d+=temp1+"="+resultado1->valor+"+"+resultado2->valor+";//operacion caracter + entero\n";
                            return new Resultado("entero",TENTERO_,temp1);
                        case TDECIMAL_:
                            temp1=code->genTemp();
                            code->cadena3d+=temp1+"="+resultado1->valor+"+"+resultado2->valor+";//operacion caracter + decimal\n";
                            return new Resultado("entero",TENTERO_,temp1);
                        case TCARACTER_:
                            temp1=code->genTemp();

                            code->cadena3d+="//operacion caracter + caracter\n";
                            code->cadena3d+=temp1+"=h;\n";
                            code->cadena3d+="heap[h]=s;\n";
                            code->cadena3d+="h=h+1;\n";
                            code->cadena3d+="pool[s]="+resultado1->valor+";\n";
                            code->cadena3d+="s=s+1;\n";
                            code->cadena3d+="pool[s]="+resultado2->valor+";\n";
                            code->cadena3d+="s=s+1;\n";
                            code->cadena3d+="pool[s]=0;\n";
                            code->cadena3d+="s=s+1;\n";

                            code->cadena3d+="//fin operacion caracter + caracter\n";
                            return new Resultado("cadena",TCADENA_,temp1);
                        case TCADENA_:
                            addError("Semantico","Operador + no valido en cadenas",raiz->linea,raiz->columna);
                            return new Resultado("error",-1,"");
                            break;
                        case TBOOLEANO_:
                            temp1=code->genTemp();
                            code->cadena3d+=temp1+"="+resultado1->valor+"+"+resultado2->valor+";//operacion caracter + booleano\n";
                            return new Resultado("entero",TENTERO_,temp1);
                        case TNADA_:
                            addError("Semantico","No se pueden operar valores de tipo nada",raiz->linea,raiz->columna);
                            return new Resultado("error",-1,"");
                        default:
                        //objeto
                            addError("Semantico","Operacion aritmetica no valida entre objetos y datos primitivos",raiz->linea,raiz->columna);
                            return new Resultado("error",-1,"");
                    }
                break;
                case TCADENA_:
                    switch (resultado2->tipo_) {
                        case TENTERO_:
                            addError("Semantico","Operador + no valido en cadenas",raiz->linea,raiz->columna);
                            return new Resultado("error",-1,"");
                        break;
                        case TDECIMAL_:
                            addError("Semantico","Operador + no valido en cadenas",raiz->linea,raiz->columna);
                            return new Resultado("error",-1,"");
                            break;
                        case TCARACTER_:
                            addError("Semantico","Operador + no valido en cadenas",raiz->linea,raiz->columna);
                            return new Resultado("error",-1,"");
                            break;
                            break;
                        case TCADENA_:
                            addError("Semantico","Operador + no valido en cadenas",raiz->linea,raiz->columna);
                            return new Resultado("error",-1,"");
                            break;
                            break;
                        case TBOOLEANO_:
                            addError("Semantico","Operador + no valido en cadenas",raiz->linea,raiz->columna);
                            return new Resultado("error",-1,"");
                            break;
                            break;
                        case TNADA_:
                            addError("Semantico","No se pueden operar valores de tipo nada",raiz->linea,raiz->columna);
                            return new Resultado("error",-1,"");
                        default:
                        //objeto
                            addError("Semantico","Operacion aritmetica no valida entre objetos y datos primitivos",raiz->linea,raiz->columna);
                        return new Resultado("error",-1,"");
                    }
                    break;
                case TBOOLEANO_:
                    switch (resultado2->tipo_) {
                        case TENTERO_:
                            temp1=code->genTemp();
                            code->cadena3d+=temp1+"="+resultado1->valor+"+"+resultado2->valor+";//booleano + entero\n";
                            return new Resultado("entero",TENTERO_,temp1);
                        case TDECIMAL_:
                            temp1=code->genTemp();
                            code->cadena3d+=temp1+"="+resultado1->valor+"+"+resultado2->valor+";//booleano + decimal\n";
                            return new Resultado("decimal",TDECIMAL_,temp1);
                        case TCARACTER_:
                            temp1=code->genTemp();
                            code->cadena3d+=temp1+"="+resultado1->valor+"+"+resultado2->valor+";//booleano + caracter\n";
                            return new Resultado("entero",TENTERO_,temp1);
                        case TCADENA_:
                            //falta
                            break;
                        case TBOOLEANO_:
                            temp1=code->genTemp();
                            code->cadena3d+=temp1+"="+resultado1->valor+"+"+resultado2->valor+";//booleano + boleano\n";
                            return new Resultado("entero",TENTERO_,temp1);
                        case TNADA_:
                            addError("Semantico","No se pueden operar valores de tipo nada",raiz->linea,raiz->columna);
                            return new Resultado("error",-1,"");
                        default:
                        //objeto
                            addError("Semantico","Operacion aritmetica no valida entre objetos y datos primitivos",raiz->linea,raiz->columna);
                            return new Resultado("error",-1,"");
                    }
                    break;
                case TNADA_:
                    addError("Semantico","No se pueden operar valores de tipo nada",raiz->linea,raiz->columna);
                    return new Resultado("error",-1,"");
                default:
                //objeto
                    addError("Semantico","Operacion aritmetica no valida entre objetos y datos primitivos",raiz->linea,raiz->columna);
                    return new Resultado("error",-1,"");
            }
            break;



        case RESTA_:
            switch (resultado1->tipo_) {
                case TENTERO_:
                    switch (resultado2->tipo_) {
                        case TENTERO_:
                            temp1=code->genTemp();
                            code->cadena3d+=temp1+"="+resultado1->valor+"-"+resultado2->valor+";//operacion entero - entero\n";
                            return new Resultado("entero",TENTERO_,temp1);
                        case TDECIMAL_:
                            temp1=code->genTemp();
                            code->cadena3d+=temp1+"="+resultado1->valor+"-"+resultado2->valor+";//operacion entero - decimal\n";
                            return new Resultado("decimal",TDECIMAL_,temp1);
                        case TCARACTER_:
                            temp1=code->genTemp();
                            code->cadena3d+=temp1+"="+resultado1->valor+"-"+resultado2->valor+";//operacion entero - caracter\n";
                            return new Resultado("entero",TENTERO_,temp1);
                        case TCADENA_:
                            addError("Semantico","Operacion - no valida en cadenas",raiz->linea,raiz->columna);
                            return new Resultado("error",-1,"");
                        case TBOOLEANO_:
                            temp1=code->genTemp();
                            code->cadena3d+=temp1+"="+resultado1->valor+"-"+resultado2->valor+";//operacion entero - booleano\n";
                            return new Resultado("entero",TENTERO_,temp1);
                        case TNADA_:
                            addError("Semantico","No se pueden operar valores de tipo nada",raiz->linea,raiz->columna);
                            return new Resultado("error",-1,"");
                        default:
                        //objeto
                            addError("Semantico","Operacion aritmetica no valida entre objetos y datos primitivos",raiz->linea,raiz->columna);
                            return new Resultado("error",-1,"");
                    }
                    break;
                case TDECIMAL_:
                    switch (resultado2->tipo_) {
                        case TENTERO_:
                            temp1=code->genTemp();
                            code->cadena3d+=temp1+"="+resultado1->valor+"-"+resultado2->valor+";//operacion decimal - entero\n";
                            return new Resultado("decimal",TDECIMAL_,temp1);
                        case TDECIMAL_:
                            temp1=code->genTemp();
                            code->cadena3d+=temp1+"="+resultado1->valor+"-"+resultado2->valor+";//operacion decimal - decimal\n";
                            return new Resultado("decimal",TDECIMAL_,temp1);
                        case TCARACTER_:
                            temp1=code->genTemp();
                            code->cadena3d+=temp1+"="+resultado1->valor+"-"+resultado2->valor+";//operacion decimal - caracter\n";
                            return new Resultado("decimal",TDECIMAL_,temp1);
                        case TCADENA_:
                            addError("Semantico","Operacion - no valida en cadenas",raiz->linea,raiz->columna);
                            return new Resultado("error",-1,"");
                        case TBOOLEANO_:
                            temp1=code->genTemp();
                            code->cadena3d+=temp1+"="+resultado1->valor+"-"+resultado2->valor+";//operacion decimal - booleano\n";
                            return new Resultado("decimal",TDECIMAL_,temp1);
                        case TNADA_:
                            addError("Semantico","No se pueden operar valores de tipo nada",raiz->linea,raiz->columna);
                            return new Resultado("error",-1,"");
                        default:
                        //objeto
                            addError("Semantico","Operacion aritmetica no valida entre objetos y datos primitivos",raiz->linea,raiz->columna);
                            return new Resultado("error",-1,"");
                        }
                    break;
                case TCARACTER_:
                    switch (resultado2->tipo_) {
                        case TENTERO_:
                            temp1=code->genTemp();
                            code->cadena3d+=temp1+"="+resultado1->valor+"-"+resultado2->valor+";//operacion caracter - entero\n";
                            return new Resultado("entero",TENTERO_,temp1);
                        case TDECIMAL_:
                            temp1=code->genTemp();
                            code->cadena3d+=temp1+"="+resultado1->valor+"-"+resultado2->valor+";//operacion caracter - decimal\n";
                            return new Resultado("decimal",TDECIMAL_,temp1);
                        case TCARACTER_:
                            temp1=code->genTemp();
                            code->cadena3d+=temp1+"="+resultado1->valor+"-"+resultado2->valor+";//operacion caracter - caracter\n";
                            return new Resultado("entero",TENTERO_,temp1);
                        case TCADENA_:
                            addError("Semantico","Operacion - no valida en cadenas",raiz->linea,raiz->columna);
                            return new Resultado("error",-1,"");
                            break;
                        case TBOOLEANO_:
                            temp1=code->genTemp();
                            code->cadena3d+=temp1+"="+resultado1->valor+"-"+resultado2->valor+";//operacion caracter - booleano\n";
                            return new Resultado("entero",TENTERO_,temp1);
                        case TNADA_:
                            addError("Semantico","No se pueden operar valores de tipo nada",raiz->linea,raiz->columna);
                            return new Resultado("error",-1,"");
                        default:
                        //objeto
                            addError("Semantico","Operacion aritmetica no valida entre objetos y datos primitivos",raiz->linea,raiz->columna);
                            return new Resultado("error",-1,"");
                    }
                    break;
                case TCADENA_:
                    switch (resultado2->tipo_) {
                        case TENTERO_:
                        case TDECIMAL_:
                        case TCARACTER_:
                        case TCADENA_:
                        case TBOOLEANO_:
                            addError("Semantico","Operacion - no valida en cadenas",raiz->linea,raiz->columna);
                            return new Resultado("error",-1,"");
                        case TNADA_:
                            addError("Semantico","No se pueden operar valores de tipo nada",raiz->linea,raiz->columna);
                            return new Resultado("error",-1,"");
                        default:
                        //objeto
                            addError("Semantico","Operacion aritmetica no valida entre objetos y datos primitivos",raiz->linea,raiz->columna);
                            return new Resultado("error",-1,"");
                    }
                    break;
                case TBOOLEANO_:
                    switch (resultado2->tipo_) {
                        case TENTERO_:
                            temp1=code->genTemp();
                            code->cadena3d+=temp1+"="+resultado1->valor+"-"+resultado2->valor+";//booleano - entero\n";
                            return new Resultado("entero",TENTERO_,temp1);
                        case TDECIMAL_:
                            temp1=code->genTemp();
                            code->cadena3d+=temp1+"="+resultado1->valor+"-"+resultado2->valor+";//booleano - decimal\n";
                            return new Resultado("decimal",TDECIMAL_,temp1);
                        case TCARACTER_:
                            temp1=code->genTemp();
                            code->cadena3d+=temp1+"="+resultado1->valor+"-"+resultado2->valor+";//booleano - caracter\n";
                            return new Resultado("entero",TENTERO_,temp1);
                        case TCADENA_:
                            addError("Semantico","Operacion - no valida en cadenas",raiz->linea,raiz->columna);
                            return new Resultado("error",-1,"");
                        case TBOOLEANO_:
                            temp1=code->genTemp();
                            code->cadena3d+=temp1+"="+resultado1->valor+"+"+resultado2->valor+";//booleano - boleano\n";
                            return new Resultado("entero",TENTERO_,temp1);
                        case TNADA_:
                            addError("Semantico","No se pueden operar valores de tipo nada",raiz->linea,raiz->columna);
                            return new Resultado("error",-1,"");
                        default:
                        //objeto
                            addError("Semantico","Operacion aritmetica no valida entre objetos y datos primitivos",raiz->linea,raiz->columna);
                            return new Resultado("error",-1,"");
                    }
                    break;
                case TNADA_:
                    addError("Semantico","No se pueden operar valores de tipo nada",raiz->linea,raiz->columna);
                    return new Resultado("error",-1,"");
                default:
                //objeto
                    addError("Semantico","Operacion aritmetica no valida entre objetos y datos primitivos",raiz->linea,raiz->columna);
                    return new Resultado("error",-1,"");
            }
            break;


        case MULTIPLICACION_:
            switch (resultado1->tipo_) {
                case TENTERO_:
                    switch (resultado2->tipo_) {
                        case TENTERO_:
                            temp1=code->genTemp();
                            code->cadena3d+=temp1+"="+resultado1->valor+"*"+resultado2->valor+";//operacion entero * entero\n";
                            return new Resultado("entero",TENTERO_,temp1);
                        case TDECIMAL_:
                            temp1=code->genTemp();
                            code->cadena3d+=temp1+"="+resultado1->valor+"*"+resultado2->valor+";//operacion entero * decimal\n";
                            return new Resultado("decimal",TDECIMAL_,temp1);
                        case TCARACTER_:
                            temp1=code->genTemp();
                            code->cadena3d+=temp1+"="+resultado1->valor+"*"+resultado2->valor+";//operacion entero * caracter\n";
                            return new Resultado("entero",TENTERO_,temp1);
                        case TCADENA_:
                            addError("Semantico","Operacion * no valida en cadenas",raiz->linea,raiz->columna);
                            return new Resultado("error",-1,"");
                        case TBOOLEANO_:
                            temp1=code->genTemp();
                            code->cadena3d+=temp1+"="+resultado1->valor+"*"+resultado2->valor+";//operacion entero * booleano\n";
                            return new Resultado("entero",TENTERO_,temp1);
                        case TNADA_:
                            addError("Semantico","No se pueden operar valores de tipo nada",raiz->linea,raiz->columna);
                            return new Resultado("error",-1,"");
                        default:
                        //objeto
                            addError("Semantico","Operacion aritmetica no valida entre objetos y datos primitivos",raiz->linea,raiz->columna);
                            return new Resultado("error",-1,"");
                    }
                    break;
                case TDECIMAL_:
                    switch (resultado2->tipo_) {
                        case TENTERO_:
                            temp1=code->genTemp();
                            code->cadena3d+=temp1+"="+resultado1->valor+"*"+resultado2->valor+";//operacion decimal * entero\n";
                            return new Resultado("decimal",TDECIMAL_,temp1);
                        case TDECIMAL_:
                            temp1=code->genTemp();
                            code->cadena3d+=temp1+"="+resultado1->valor+"*"+resultado2->valor+";//operacion decimal * decimal\n";
                            return new Resultado("decimal",TDECIMAL_,temp1);
                        case TCARACTER_:
                            temp1=code->genTemp();
                            code->cadena3d+=temp1+"="+resultado1->valor+"*"+resultado2->valor+";//operacion decimal * caracter\n";
                            return new Resultado("decimal",TDECIMAL_,temp1);
                        case TCADENA_:
                            addError("Semantico","Operacion * no valida en cadenas",raiz->linea,raiz->columna);
                            return new Resultado("error",-1,"");
                        case TBOOLEANO_:
                            temp1=code->genTemp();
                            code->cadena3d+=temp1+"="+resultado1->valor+"*"+resultado2->valor+";//operacion decimal * booleano\n";
                            return new Resultado("decimal",TDECIMAL_,temp1);
                        case TNADA_:
                            addError("Semantico","No se pueden operar valores de tipo nada",raiz->linea,raiz->columna);
                            return new Resultado("error",-1,"");
                        default:
                        //objeto
                            addError("Semantico","Operacion aritmetica no valida entre objetos y datos primitivos",raiz->linea,raiz->columna);
                            return new Resultado("error",-1,"");
                        }
                    break;
                case TCARACTER_:
                    switch (resultado2->tipo_) {
                        case TENTERO_:
                            temp1=code->genTemp();
                            code->cadena3d+=temp1+"="+resultado1->valor+"*"+resultado2->valor+";//operacion caracter * entero\n";
                            return new Resultado("entero",TENTERO_,temp1);
                        case TDECIMAL_:
                            temp1=code->genTemp();
                            code->cadena3d+=temp1+"="+resultado1->valor+"*"+resultado2->valor+";//operacion caracter * decimal\n";
                            return new Resultado("decimal",TDECIMAL_,temp1);
                        case TCARACTER_:
                            temp1=code->genTemp();
                            code->cadena3d+=temp1+"="+resultado1->valor+"*"+resultado2->valor+";//operacion caracter * caracter\n";
                            return new Resultado("entero",TENTERO_,temp1);
                        case TCADENA_:
                            addError("Semantico","Operacion * no valida en cadenas",raiz->linea,raiz->columna);
                            return new Resultado("error",-1,"");
                            break;
                        case TBOOLEANO_:
                            temp1=code->genTemp();
                            code->cadena3d+=temp1+"="+resultado1->valor+"*"+resultado2->valor+";//operacion caracter * booleano\n";
                            return new Resultado("entero",TENTERO_,temp1);
                        case TNADA_:
                            addError("Semantico","No se pueden operar valores de tipo nada",raiz->linea,raiz->columna);
                            return new Resultado("error",-1,"");
                        default:
                        //objeto
                            addError("Semantico","Operacion aritmetica no valida entre objetos y datos primitivos",raiz->linea,raiz->columna);
                            return new Resultado("error",-1,"");
                    }
                    break;
                case TCADENA_:
                    switch (resultado2->tipo_) {
                        case TENTERO_:
                        case TDECIMAL_:
                        case TCARACTER_:
                        case TCADENA_:
                        case TBOOLEANO_:
                            addError("Semantico","Operacion * no valida en cadenas",raiz->linea,raiz->columna);
                            return new Resultado("error",-1,"");
                        case TNADA_:
                            addError("Semantico","No se pueden operar valores de tipo nada",raiz->linea,raiz->columna);
                            return new Resultado("error",-1,"");
                        default:
                        //objeto
                            addError("Semantico","Operacion aritmetica no valida entre objetos y datos primitivos",raiz->linea,raiz->columna);
                            return new Resultado("error",-1,"");
                    }
                    break;
                case TBOOLEANO_:
                    switch (resultado2->tipo_) {
                        case TENTERO_:
                            temp1=code->genTemp();
                            code->cadena3d+=temp1+"="+resultado1->valor+"*"+resultado2->valor+";//booleano * entero\n";
                            return new Resultado("entero",TENTERO_,temp1);
                        case TDECIMAL_:
                            temp1=code->genTemp();
                            code->cadena3d+=temp1+"="+resultado1->valor+"*"+resultado2->valor+";//booleano * decimal\n";
                            return new Resultado("decimal",TDECIMAL_,temp1);
                        case TCARACTER_:
                            temp1=code->genTemp();
                            code->cadena3d+=temp1+"="+resultado1->valor+"*"+resultado2->valor+";//booleano * caracter\n";
                            return new Resultado("entero",TENTERO_,temp1);
                        case TCADENA_:
                            addError("Semantico","Operacion * no valida en cadenas",raiz->linea,raiz->columna);
                            return new Resultado("error",-1,"");
                        case TBOOLEANO_:
                            temp1=code->genTemp();
                            code->cadena3d+=temp1+"="+resultado1->valor+"*"+resultado2->valor+";//booleano * boleano\n";
                            return new Resultado("entero",TENTERO_,temp1);
                        case TNADA_:
                            addError("Semantico","No se pueden operar valores de tipo nada",raiz->linea,raiz->columna);
                            return new Resultado("error",-1,"");
                        default:
                        //objeto
                            addError("Semantico","Operacion aritmetica no valida entre objetos y datos primitivos",raiz->linea,raiz->columna);
                            return new Resultado("error",-1,"");
                    }
                    break;
                case TNADA_:
                    addError("Semantico","No se pueden operar valores de tipo nada",raiz->linea,raiz->columna);
                    return new Resultado("error",-1,"");
                default:
                //objeto
                    addError("Semantico","Operacion aritmetica no valida entre objetos y datos primitivos",raiz->linea,raiz->columna);
                    return new Resultado("error",-1,"");
            }
            break;


        case DIVISION_:
            switch (resultado1->tipo_) {
                case TENTERO_:
                    switch (resultado2->tipo_) {
                        case TENTERO_:
                            temp1=code->genTemp();
                            code->cadena3d+=temp1+"="+resultado1->valor+"/"+resultado2->valor+";//operacion entero / entero\n";
                            return new Resultado("decimal",TDECIMAL_,temp1);
                        case TDECIMAL_:
                            temp1=code->genTemp();
                            code->cadena3d+=temp1+"="+resultado1->valor+"/"+resultado2->valor+";//operacion entero / decimal\n";
                            return new Resultado("decimal",TDECIMAL_,temp1);
                        case TCARACTER_:
                            temp1=code->genTemp();
                            code->cadena3d+=temp1+"="+resultado1->valor+"/"+resultado2->valor+";//operacion entero / caracter\n";
                            return new Resultado("decimal",TDECIMAL_,temp1);
                        case TCADENA_:
                            addError("Semantico","Operacion / no valida en cadenas",raiz->linea,raiz->columna);
                            return new Resultado("error",-1,"");
                        case TBOOLEANO_:
                            temp1=code->genTemp();
                            code->cadena3d+=temp1+"="+resultado1->valor+"/"+resultado2->valor+";//operacion entero / booleano\n";
                            return new Resultado("decimal",TDECIMAL_,temp1);
                        case TNADA_:
                            addError("Semantico","No se pueden operar valores de tipo nada",raiz->linea,raiz->columna);
                            return new Resultado("error",-1,"");
                        default:
                        //objeto
                            addError("Semantico","Operacion aritmetica no valida entre objetos y datos primitivos",raiz->linea,raiz->columna);
                            return new Resultado("error",-1,"");
                    }
                    break;
                case TDECIMAL_:
                    switch (resultado2->tipo_) {
                        case TENTERO_:
                            temp1=code->genTemp();
                            code->cadena3d+=temp1+"="+resultado1->valor+"/"+resultado2->valor+";//operacion decimal / entero\n";
                            return new Resultado("decimal",TDECIMAL_,temp1);
                        case TDECIMAL_:
                            temp1=code->genTemp();
                            code->cadena3d+=temp1+"="+resultado1->valor+"/"+resultado2->valor+";//operacion decimal / decimal\n";
                            return new Resultado("decimal",TDECIMAL_,temp1);
                        case TCARACTER_:
                            temp1=code->genTemp();
                            code->cadena3d+=temp1+"="+resultado1->valor+"/"+resultado2->valor+";//operacion decimal / caracter\n";
                            return new Resultado("decimal",TDECIMAL_,temp1);
                        case TCADENA_:
                            addError("Semantico","Operacion / no valida en cadenas",raiz->linea,raiz->columna);
                            return new Resultado("error",-1,"");
                        case TBOOLEANO_:
                            temp1=code->genTemp();
                            code->cadena3d+=temp1+"="+resultado1->valor+"/"+resultado2->valor+";//operacion decimal / booleano\n";
                            return new Resultado("decimal",TDECIMAL_,temp1);
                        case TNADA_:
                            addError("Semantico","No se pueden operar valores de tipo nada",raiz->linea,raiz->columna);
                            return new Resultado("error",-1,"");
                        default:
                        //objeto
                            addError("Semantico","Operacion aritmetica no valida entre objetos y datos primitivos",raiz->linea,raiz->columna);
                            return new Resultado("error",-1,"");
                        }
                    break;
                case TCARACTER_:
                    switch (resultado2->tipo_) {
                        case TENTERO_:
                            temp1=code->genTemp();
                            code->cadena3d+=temp1+"="+resultado1->valor+"/"+resultado2->valor+";//operacion caracter / entero\n";
                            return new Resultado("decimal",TDECIMAL_,temp1);
                        case TDECIMAL_:
                            temp1=code->genTemp();
                            code->cadena3d+=temp1+"="+resultado1->valor+"/"+resultado2->valor+";//operacion caracter / decimal\n";
                            return new Resultado("decimal",TDECIMAL_,temp1);
                        case TCARACTER_:
                            temp1=code->genTemp();
                            code->cadena3d+=temp1+"="+resultado1->valor+"/"+resultado2->valor+";//operacion caracter / caracter\n";
                            return new Resultado("decimal",TDECIMAL_,temp1);
                        case TCADENA_:
                            addError("Semantico","Operacion / no valida en cadenas",raiz->linea,raiz->columna);
                            return new Resultado("error",-1,"");
                            break;
                        case TBOOLEANO_:
                            temp1=code->genTemp();
                            code->cadena3d+=temp1+"="+resultado1->valor+"/"+resultado2->valor+";//operacion caracter / booleano\n";
                            return new Resultado("decimal",TDECIMAL_,temp1);
                        case TNADA_:
                            addError("Semantico","No se pueden operar valores de tipo nada",raiz->linea,raiz->columna);
                            return new Resultado("error",-1,"");
                        default:
                        //objeto
                            addError("Semantico","Operacion aritmetica no valida entre objetos y datos primitivos",raiz->linea,raiz->columna);
                            return new Resultado("error",-1,"");
                    }
                    break;
                case TCADENA_:
                    switch (resultado2->tipo_) {
                        case TENTERO_:
                        case TDECIMAL_:
                        case TCARACTER_:
                        case TCADENA_:
                        case TBOOLEANO_:
                            addError("Semantico","Operacion / no valida en cadenas",raiz->linea,raiz->columna);
                            return new Resultado("error",-1,"");
                        case TNADA_:
                            addError("Semantico","No se pueden operar valores de tipo nada",raiz->linea,raiz->columna);
                            return new Resultado("error",-1,"");
                        default:
                        //objeto
                            addError("Semantico","Operacion aritmetica no valida entre objetos y datos primitivos",raiz->linea,raiz->columna);
                            return new Resultado("error",-1,"");
                    }
                    break;
                case TBOOLEANO_:
                    switch (resultado2->tipo_) {
                        case TENTERO_:
                            temp1=code->genTemp();
                            code->cadena3d+=temp1+"="+resultado1->valor+"/"+resultado2->valor+";//booleano / entero\n";
                            return new Resultado("decimal",TDECIMAL_,temp1);
                        case TDECIMAL_:
                            temp1=code->genTemp();
                            code->cadena3d+=temp1+"="+resultado1->valor+"/"+resultado2->valor+";//booleano / decimal\n";
                            return new Resultado("decimal",TDECIMAL_,temp1);
                        case TCARACTER_:
                            temp1=code->genTemp();
                            code->cadena3d+=temp1+"="+resultado1->valor+"/"+resultado2->valor+";//booleano / caracter\n";
                            return new Resultado("decimal",TDECIMAL_,temp1);
                        case TCADENA_:
                            addError("Semantico","Operacion / no valida en cadenas",raiz->linea,raiz->columna);
                            return new Resultado("error",-1,"");
                        case TBOOLEANO_:
                            temp1=code->genTemp();
                            code->cadena3d+=temp1+"="+resultado1->valor+"/"+resultado2->valor+";//booleano / boleano\n";
                            return new Resultado("decimal",TDECIMAL_,temp1);
                        case TNADA_:
                            addError("Semantico","No se pueden operar valores de tipo nada",raiz->linea,raiz->columna);
                            return new Resultado("error",-1,"");
                        default:
                        //objeto
                            addError("Semantico","Operacion aritmetica no valida entre objetos y datos primitivos",raiz->linea,raiz->columna);
                            return new Resultado("error",-1,"");
                    }
                    break;
                case TNADA_:
                    addError("Semantico","No se pueden operar valores de tipo nada",raiz->linea,raiz->columna);
                    return new Resultado("error",-1,"");
                default:
                //objeto
                    addError("Semantico","Operacion aritmetica no valida entre objetos y datos primitivos",raiz->linea,raiz->columna);
                    return new Resultado("error",-1,"");
            }
            break;


        case POTENCIA_:
            switch (resultado1->tipo_) {
                case TENTERO_:
                    switch (resultado2->tipo_) {
                        case TENTERO_:
                            temp1=code->genTemp();
                            code->cadena3d+=temp1+"="+resultado1->valor+"^"+resultado2->valor+";//operacion entero ^ entero\n";
                            return new Resultado("entero",TENTERO_,temp1);
                        case TDECIMAL_:
                            temp1=code->genTemp();
                            code->cadena3d+=temp1+"="+resultado1->valor+"^"+resultado2->valor+";//operacion entero ^ decimal\n";
                            return new Resultado("decimal",TDECIMAL_,temp1);
                        case TCARACTER_:
                            temp1=code->genTemp();
                            code->cadena3d+=temp1+"="+resultado1->valor+"^"+resultado2->valor+";//operacion entero ^ caracter\n";
                            return new Resultado("entero",TENTERO_,temp1);
                        case TCADENA_:
                            addError("Semantico","Operacion ^ no valida en cadenas",raiz->linea,raiz->columna);
                            return new Resultado("error",-1,"");
                        case TBOOLEANO_:
                            temp1=code->genTemp();
                            code->cadena3d+=temp1+"="+resultado1->valor+"^"+resultado2->valor+";//operacion entero ^ booleano\n";
                            return new Resultado("entero",TENTERO_,temp1);
                        case TNADA_:
                            addError("Semantico","No se pueden operar valores de tipo nada",raiz->linea,raiz->columna);
                            return new Resultado("error",-1,"");
                        default:
                        //objeto
                            addError("Semantico","Operacion aritmetica no valida entre objetos y datos primitivos",raiz->linea,raiz->columna);
                            return new Resultado("error",-1,"");
                    }
                    break;
                case TDECIMAL_:
                    switch (resultado2->tipo_) {
                        case TENTERO_:
                            temp1=code->genTemp();
                            code->cadena3d+=temp1+"="+resultado1->valor+"^"+resultado2->valor+";//operacion decimal ^ entero\n";
                            return new Resultado("decimal",TDECIMAL_,temp1);
                        case TDECIMAL_:
                            temp1=code->genTemp();
                            code->cadena3d+=temp1+"="+resultado1->valor+"^"+resultado2->valor+";//operacion decimal ^ decimal\n";
                            return new Resultado("decimal",TDECIMAL_,temp1);
                        case TCARACTER_:
                            temp1=code->genTemp();
                            code->cadena3d+=temp1+"="+resultado1->valor+"^"+resultado2->valor+";//operacion decimal ^ caracter\n";
                            return new Resultado("decimal",TDECIMAL_,temp1);
                        case TCADENA_:
                            addError("Semantico","Operacion ^ no valida en cadenas",raiz->linea,raiz->columna);
                            return new Resultado("error",-1,"");
                        case TBOOLEANO_:
                            temp1=code->genTemp();
                            code->cadena3d+=temp1+"="+resultado1->valor+"^"+resultado2->valor+";//operacion decimal ^ booleano\n";
                            return new Resultado("decimal",TDECIMAL_,temp1);
                        case TNADA_:
                            addError("Semantico","No se pueden operar valores de tipo nada",raiz->linea,raiz->columna);
                            return new Resultado("error",-1,"");
                        default:
                        //objeto
                            addError("Semantico","Operacion aritmetica no valida entre objetos y datos primitivos",raiz->linea,raiz->columna);
                            return new Resultado("error",-1,"");
                        }
                    break;
                case TCARACTER_:
                    switch (resultado2->tipo_) {
                        case TENTERO_:
                            temp1=code->genTemp();
                            code->cadena3d+=temp1+"="+resultado1->valor+"^"+resultado2->valor+";//operacion caracter ^ entero\n";
                            return new Resultado("entero",TENTERO_,temp1);
                        case TDECIMAL_:
                            temp1=code->genTemp();
                            code->cadena3d+=temp1+"="+resultado1->valor+"^"+resultado2->valor+";//operacion caracter ^ decimal\n";
                            return new Resultado("decimal",TDECIMAL_,temp1);
                        case TCARACTER_:
                            temp1=code->genTemp();
                            code->cadena3d+=temp1+"="+resultado1->valor+"^"+resultado2->valor+";//operacion caracter ^ caracter\n";
                            return new Resultado("entero",TENTERO_,temp1);
                        case TCADENA_:
                            addError("Semantico","Operacion ^ no valida en cadenas",raiz->linea,raiz->columna);
                            return new Resultado("error",-1,"");
                            break;
                        case TBOOLEANO_:
                            temp1=code->genTemp();
                            code->cadena3d+=temp1+"="+resultado1->valor+"^"+resultado2->valor+";//operacion caracter ^ booleano\n";
                            return new Resultado("entero",TENTERO_,temp1);
                        case TNADA_:
                            addError("Semantico","No se pueden operar valores de tipo nada",raiz->linea,raiz->columna);
                            return new Resultado("error",-1,"");
                        default:
                        //objeto
                            addError("Semantico","Operacion aritmetica no valida entre objetos y datos primitivos",raiz->linea,raiz->columna);
                            return new Resultado("error",-1,"");
                    }
                    break;
                case TCADENA_:
                    switch (resultado2->tipo_) {
                        case TENTERO_:
                        case TDECIMAL_:
                        case TCARACTER_:
                        case TCADENA_:
                        case TBOOLEANO_:
                            addError("Semantico","Operacion ^ no valida en cadenas",raiz->linea,raiz->columna);
                            return new Resultado("error",-1,"");
                        case TNADA_:
                            addError("Semantico","No se pueden operar valores de tipo nada",raiz->linea,raiz->columna);
                            return new Resultado("error",-1,"");
                        default:
                        //objeto
                            addError("Semantico","Operacion aritmetica no valida entre objetos y datos primitivos",raiz->linea,raiz->columna);
                            return new Resultado("error",-1,"");
                    }
                    break;
                case TBOOLEANO_:
                    switch (resultado2->tipo_) {
                        case TENTERO_:
                            temp1=code->genTemp();
                            code->cadena3d+=temp1+"="+resultado1->valor+"^"+resultado2->valor+";//booleano ^ entero\n";
                            return new Resultado("entero",TENTERO_,temp1);
                        case TDECIMAL_:
                            temp1=code->genTemp();
                            code->cadena3d+=temp1+"="+resultado1->valor+"^"+resultado2->valor+";//booleano ^ decimal\n";
                            return new Resultado("decimal",TDECIMAL_,temp1);
                        case TCARACTER_:
                            temp1=code->genTemp();
                            code->cadena3d+=temp1+"="+resultado1->valor+"^"+resultado2->valor+";//booleano ^ caracter\n";
                            return new Resultado("entero",TENTERO_,temp1);
                        case TCADENA_:
                            addError("Semantico","Operacion ^ no valida en cadenas",raiz->linea,raiz->columna);
                            return new Resultado("error",-1,"");
                        case TBOOLEANO_:
                            temp1=code->genTemp();
                            code->cadena3d+=temp1+"="+resultado1->valor+"^"+resultado2->valor+";//booleano ^ boleano\n";
                            return new Resultado("entero",TENTERO_,temp1);
                        case TNADA_:
                            addError("Semantico","No se pueden operar valores de tipo nada",raiz->linea,raiz->columna);
                            return new Resultado("error",-1,"");
                        default:
                        //objeto
                            addError("Semantico","Operacion aritmetica no valida entre objetos y datos primitivos",raiz->linea,raiz->columna);
                            return new Resultado("error",-1,"");
                    }
                    break;
                case TNADA_:
                    addError("Semantico","No se pueden operar valores de tipo nada",raiz->linea,raiz->columna);
                    return new Resultado("error",-1,"");
                default:
                //objeto
                    addError("Semantico","Operacion aritmetica no valida entre objetos y datos primitivos",raiz->linea,raiz->columna);
                    return new Resultado("error",-1,"");
            }
            break;

            default:
            break;

    }

    return new Resultado("error",-1,"");

}

Resultado *Operaciones::relacionalSimple(Resultado *resultado1,QString operador,Resultado *resultado2,QString tipos)
{
    QString etiV=code->genEti();
    QString etiF=code->genEti();

    code->cadena3d+"//relacional "+operador+" "+tipos+"\n";
    code->cadena3d+="if("+resultado1->valor+operador+resultado2->valor+") goto "+etiV+";\n";
    code->cadena3d+="goto "+etiF+";\n";
    code->cadena3d+"//fin relacional "+operador+" "+tipos+"\n";
    return new Resultado("booleano",TBOOLEANO_,"",etiV,etiF);
}

Resultado *Operaciones::relacionalCadena(Resultado *resultado1,QString operador,Resultado *resultado2,QString tipos){

    QString temp1=code->genTemp();
    QString temp2=code->genTemp();
    QString temp3=code->genTemp();
    QString temp4=code->genTemp();
    QString temp5=code->genTemp();
    QString temp6=code->genTemp();
    QString temp7=code->genTemp();
    QString temp8=code->genTemp();
    QString temp9=code->genTemp();
    QString temp10=code->genTemp();

    code->cadena3d+="//relacional "+operador+" "+tipos+"\n";
    code->cadena3d+=temp1+"=p+x;//cambio de ambito virtual;\n";
    code->cadena3d+=temp2+"="+temp1+"+2;//parametro1\n";
    code->cadena3d+=temp3+"=heap["+resultado1->valor+"];\n";
    code->cadena3d+="stack["+temp2+"]="+temp3+";\n";
    code->cadena3d+="p=p+x;//cambio de ambito real\n";
    code->cadena3d+="getPesoCadena();\n";
    code->cadena3d+=temp4+"=p+1;//retorno\n";
    code->cadena3d+=temp5+"=stack["+temp4+"];//cadena1\n";
    code->cadena3d+="p=p-x;//ambito actual\n";

    code->cadena3d+=temp6+"=p+x;//cambio de ambito virtual;\n";
    code->cadena3d+=temp7+"="+temp6+"+3;//parametro2\n";
    code->cadena3d+=temp8+"=heap["+resultado2->valor+"];\n";
    code->cadena3d+="stack["+temp7+"]="+temp8+";\n";
    code->cadena3d+="p=p+x;//cambio de ambito real\n";
    code->cadena3d+="getPesoCadena();\n";
    code->cadena3d+=temp9+"=p+1;//retorno\n";
    code->cadena3d+=temp10+"=stack["+temp4+"];//cadena2\n";
    code->cadena3d+="p=p-x;//ambito actual\n";

    QString etiV=code->genEti();
    QString etiF=code->genEti();

    code->cadena3d+="if("+temp5+operador+temp10+") goto "+etiV+";\n";
    code->cadena3d+="goto "+etiF+";\n";
    code->cadena3d+="//fin relacional "+operador+" "+tipos+"\n";

    return new Resultado("booleano",TBOOLEANO_,"",etiV,etiF);
}

Resultado *Operaciones::relacional(nodo *raiz,int flag)
{
    Resultado *resultado1;
    Resultado *resultado2;

    switch (raiz->tipo_) {
        case SUMA_:
        case RESTA_:
        case MULTIPLICACION_:
        case DIVISION_:
        case MODULO_:
        case POTENCIA_:
             return aritmetica(raiz);
        case IGUAL_:
        case DESIGUAL_:
        case MAYORQUE_:
        case MAYORIGUAL_:
        case MENORQUE_:
        case MENORIGUAL_:
            {
                resultado1=aritmetica(&raiz->hijos[0]);
                resultado2=aritmetica(&raiz->hijos[1]);
                break;
            }
        default:
            {
                resultado1=aritmetica(raiz);
                if((resultado1->tipo_==TBOOLEANO_||resultado1->tipo_==TENTERO_||resultado1->tipo_==TCARACTER_||resultado1->tipo_==TDECIMAL_)&&flag==1)
                {
                    QString etiV=code->genEti();
                    QString etiF=code->genEti();
                    code->cadena3d+="if("+resultado1->valor+"!=0) goto "+etiV+";\n";
                    code->cadena3d+="goto "+etiF+";\n";
                    return new Resultado("booleano",TBOOLEANO_,resultado1->valor,etiV,etiF);
                }else
                {
                    return resultado1;
                }
                break;
            }
    }




    switch (resultado1->tipo_) {
        case TENTERO_:
           {
                switch (resultado2->tipo_) {
                    case TENTERO_:
                       {
                            return relacionalSimple(resultado1,raiz->tipo,resultado2,"entero-entero");
                        }
                        break;
                    case TDECIMAL_:
                       {
                            return relacionalSimple(resultado1,raiz->tipo,resultado2,"entero-decimal");
                        }
                        break;
                    case TCARACTER_:
                       {
                            return relacionalSimple(resultado1,raiz->tipo,resultado2,"entero-caracter");
                        }
                        break;
                    case TCADENA_:
                       {
                            addError("Semantico","operacion relacional "+raiz->tipo+" invalida entre entero y cadena",raiz->linea,raiz->columna);
                            return new Resultado("error",-1,"");
                        }
                        break;
                    case TBOOLEANO_:
                       {
                            return relacionalSimple(resultado1,raiz->tipo,resultado2,"entero-booleano");
                        }
                    case TNADA_:
                       {
                            addError("Semantico","operacion relacional "+raiz->tipo+ " invalida entre entero y nada",raiz->linea,raiz->columna);
                            return new Resultado("error",-1,"");
                        }
                        break;
                    default:
                        addError("Semantico","operacion relacional "+raiz->tipo+ " invalida entre entero y objeto",raiz->linea,raiz->columna);
                        return new Resultado("error",-1,"");
                }
            }
            break;
        case TDECIMAL_:
           {
                switch (resultado2->tipo_) {
                    case TENTERO_:
                       {
                            return relacionalSimple(resultado1,raiz->tipo,resultado2,"entero-entero");
                        }
                        break;
                    case TDECIMAL_:
                       {
                            return relacionalSimple(resultado1,raiz->tipo,resultado2,"decimal-decimal");
                        }
                        break;
                    case TCARACTER_:
                       {
                            return relacionalSimple(resultado1,raiz->tipo,resultado2,"caracter-entero");
                        }
                        break;
                    case TCADENA_:
                       {
                            addError("Semantico","operacion relacional "+raiz->tipo+" invalida entre decimal y cadena",raiz->linea,raiz->columna);
                            return new Resultado("error",-1,"");
                        }
                        break;
                    case TBOOLEANO_:
                       {
                            return relacionalSimple(resultado1,raiz->tipo,resultado2,"decimal-booleano");
                        }
                    case TNADA_:
                       {
                            addError("Semantico","operacion relacional "+raiz->tipo+" invalida entre entero y nada",raiz->linea,raiz->columna);
                            return new Resultado("error",-1,"");
                        }
                        break;
                    default:
                        addError("Semantico","operacion relacional "+raiz->tipo+ " invalida entre decimal y objeto",raiz->linea,raiz->columna);
                        return new Resultado("error",-1,"");
                }
            }
            break;
        case TCARACTER_:
           {
                switch (resultado2->tipo_) {
                    case TENTERO_:
                       {
                            return relacionalSimple(resultado1,raiz->tipo,resultado2,"caracter-entero");
                        }
                        break;
                    case TDECIMAL_:
                       {
                            return relacionalSimple(resultado1,raiz->tipo,resultado2,"caracter-decimal");
                        }
                        break;
                    case TCARACTER_:
                       {
                            return relacionalSimple(resultado1,raiz->tipo,resultado2,"caracter-caracter");
                        }
                        break;
                    case TCADENA_:
                       {
                            QString temp1=code->genTemp();
                            QString temp2=code->genTemp();
                            QString temp3=code->genTemp();
                            QString temp4=code->genTemp();
                            QString temp5=code->genTemp();

                            code->cadena3d+="//relacional "+raiz->tipo+" caracter-cadena \n";
                            code->cadena3d+=temp1+"=p+x;//cambio de ambito virtual;\n";
                            code->cadena3d+=temp2+"="+temp1+"+2;//parametro1\n";
                            code->cadena3d+=temp3+"=heap["+resultado2->valor+"];\n";
                            code->cadena3d+="stack["+temp2+"]="+temp3+";\n";
                            code->cadena3d+="p=p+x;//cambio de ambito real\n";
                            code->cadena3d+="getPesoCadena();\n";
                            code->cadena3d+=temp4+"=p+1;//retorno\n";
                            code->cadena3d+=temp5+"=stack["+temp4+"];//cadena1\n";
                            code->cadena3d+="p=p-x;//ambito actual\n";

                            QString etiV=code->genEti();
                            QString etiF=code->genEti();

                            code->cadena3d+="if("+resultado1->valor+raiz->tipo+temp5+") goto "+etiV+";\n";
                            code->cadena3d+="goto "+etiF+";\n";

                            code->cadena3d+="//fin relacional "+raiz->tipo+" caracter-cadena \n";


                            return new Resultado("booleano",TBOOLEANO_,"",etiV,etiF);
                        }
                        break;
                    case TBOOLEANO_:
                       {
                            return relacionalSimple(resultado1,raiz->tipo,resultado2,"caracter-caracter");
                        }
                    case TNADA_:
                       {
                            addError("Semantico","operacion relacional "+raiz->tipo+" invalida entre caracter y nada",raiz->linea,raiz->columna);
                            return new Resultado("error",-1,"");
                        }
                        break;
                    default:
                        addError("Semantico","operacion relacional "+raiz->tipo+ " invalida entre caracter y objeto",raiz->linea,raiz->columna);
                        return new Resultado("error",-1,"");
                }
            }
            break;
        case TCADENA_:
           {
                switch (resultado2->tipo_) {
                    case TENTERO_:
                       {
                            addError("Semantico","operacion relacional "+raiz->tipo+" invalida entre cadena-entero",raiz->linea,raiz->columna);
                            return new Resultado("error",-1,"");
                        }
                        break;
                    case TDECIMAL_:
                       {
                            addError("Semantico","operacion relacional "+raiz->tipo+ "invalida entre cadena-decimal",raiz->linea,raiz->columna);
                            return new Resultado("error",-1,"");
                        }
                        break;
                    case TCARACTER_:
                       {
                            QString temp1=code->genTemp();
                            QString temp2=code->genTemp();
                            QString temp3=code->genTemp();
                            QString temp4=code->genTemp();
                            QString temp5=code->genTemp();

                            code->cadena3d+="//relacional "+raiz->tipo+" caracter-cadena \n";
                            code->cadena3d+=temp1+"=p+x;//cambio de ambito virtual;\n";
                            code->cadena3d+=temp2+"="+temp1+"+2;//parametro1\n";
                            code->cadena3d+=temp3+"=heap["+resultado1->valor+"];\n";
                            code->cadena3d+="stack["+temp2+"]="+temp3+";\n";
                            code->cadena3d+="p=p+x;//cambio de ambito real\n";
                            code->cadena3d+="getPesoCadena();\n";
                            code->cadena3d+=temp4+"=p+1;//retorno\n";
                            code->cadena3d+=temp5+"=stack["+temp4+"];//cadena1\n";
                            code->cadena3d+="p=p-x;//ambito actual\n";

                            QString etiV=code->genEti();
                            QString etiF=code->genEti();

                            code->cadena3d+="if("+temp5+raiz->tipo+resultado2->valor+") goto "+etiV+";\n";
                            code->cadena3d+="goto "+etiF+";\n";

                            code->cadena3d+="//fin relacional "+raiz->tipo+" caracter-cadena \n";

                            return new Resultado("booleano",TBOOLEANO_,"",etiV,etiF);
                        }
                        break;
                    case TCADENA_:
                       {
                            return relacionalCadena(resultado1,raiz->tipo,resultado2,"cadena-cadena");
                        }
                        break;
                    case TBOOLEANO_:
                       {
                            addError("Semantico","operacion relacional "+raiz->tipo+" invalida entre cadena-booleano",raiz->linea,raiz->columna);
                            return new Resultado("error",-1,"");
                        }
                    case TNADA_:
                       {
                            QString etiV=code->genEti();
                            QString etiF=code->genEti();
                            code->cadena3d+="if("+resultado1->valor+raiz->tipo+code->NADA_+") goto"+etiV+";\n";
                            code->cadena3d+="goto "+etiF+";\n";
                            return new Resultado("booleano",TBOOLEANO_,"",etiV,etiF);

                        }
                        break;
                    default:
                        addError("Semantico","operacion relacional "+raiz->tipo+ " invalida entre cadena y objeto",raiz->linea,raiz->columna);
                        return new Resultado("error",-1,"");
                }
            }
            break;
        case TBOOLEANO_:
           {
                switch (resultado2->tipo_) {
                    case TENTERO_:
                       {
                            return relacionalSimple(resultado1,raiz->tipo,resultado2,"booleano-entero");
                        }
                        break;
                    case TDECIMAL_:
                       {
                            return relacionalSimple(resultado1,raiz->tipo,resultado2,"booleano-decimal");
                        }
                        break;
                    case TCARACTER_:
                       {
                            return relacionalSimple(resultado1,raiz->tipo,resultado2,"booleano-caracter");
                        }
                        break;
                    case TCADENA_:
                       {
                            addError("Semantico","operacion relacional "+raiz->tipo+" invalida entre booleano-cadena",raiz->linea,raiz->columna);
                            return new Resultado("error",-1,"");
                        }
                        break;
                    case TBOOLEANO_:
                       {
                            return relacionalSimple(resultado1,raiz->tipo,resultado2,"booleano-booleano");
                        }
                    case TNADA_:
                       {
                            addError("Semantico","operacion relacional "+raiz->tipo+" invalida entre booleano y nada",raiz->linea,raiz->columna);
                            return new Resultado("error",-1,"");
                        }
                        break;
                    default:
                        addError("Semantico","operacion relacional "+raiz->tipo+ "invalida entre cadena-nada",raiz->linea,raiz->columna);
                        return new Resultado("error",-1,"");
                }
            }
        case TNADA_:
           {
                switch (resultado2->tipo_) {
                    case TENTERO_:
                       {
                            addError("Semantico","operacion relacional "+raiz->tipo+" invalida entre nada-entero",raiz->linea,raiz->columna);
                            return new Resultado("error",-1,"");
                        }
                        break;
                    case TDECIMAL_:
                       {
                            addError("Semantico","operacion relacional "+raiz->tipo+" invalida entre nada-decimal",raiz->linea,raiz->columna);
                        }
                        break;
                    case TCARACTER_:
                       {
                            addError("Semantico","operacion relacional "+raiz->tipo+" invalida entre nada-caracter",raiz->linea,raiz->columna);
                            return new Resultado("error",-1,"");
                        }
                        break;
                    case TCADENA_:
                       {
                            QString etiV=code->genEti();
                            QString etiF=code->genEti();
                            code->cadena3d+="if("+code->NADA_+raiz->valor+resultado2->valor+") goto"+etiV+";\n";
                            code->cadena3d+="goto "+etiF+";\n";
                            return new Resultado("booleano",TBOOLEANO_,"",etiV,etiF);
                        }
                        break;
                    case TBOOLEANO_:
                       {
                            addError("Semantico","operacion relacional "+raiz->tipo+" invalida entre nada-booleano",raiz->linea,raiz->columna);
                            return new Resultado("error",-1,"");
                        }
                    case TNADA_:
                       {
                            return relacionalSimple(resultado1,raiz->tipo,resultado2,"nada-nada");
                        }
                        break;
                    default:
                        QString etiV=code->genEti();
                        QString etiF=code->genEti();
                        code->cadena3d+="if("+code->NADA_+raiz->valor+resultado2->valor+") goto"+etiV+";\n";
                        code->cadena3d+="goto "+etiF+";\n";
                        return new Resultado("booleano",TBOOLEANO_,"",etiV,etiF);

                }
            }
            break;
        default:
            {
                switch (resultado2->tipo_) {
                    case TNADA_:
                        {
                            QString etiV=code->genEti();
                            QString etiF=code->genEti();
                            code->cadena3d+="if("+resultado1->valor+raiz->valor+code->NADA_+") goto"+etiV+";\n";
                            code->cadena3d+="goto "+etiF+";\n";
                            return new Resultado("booleano",TBOOLEANO_,"",etiV,etiF);
                         }
                    default:
                        addError("Semantico","Los objetos solamente se puede comparar con el tipo nada",raiz->linea,raiz->columna);
                        return new Resultado("error",-1,"");
                        break;
                }
            }
            break;
    }



    return new Resultado("error",-1,"");

}

Resultado *Operaciones::logica(nodo *raiz,int flag)
{
    Resultado *resultado1;
    Resultado *resultado2;

    switch (raiz->tipo_) {
        case OR_:
            {
                resultado1=logica(&raiz->hijos[0],flag);
                code->cadena3d+=resultado1->etiF+":\n";
                resultado2=logica(&raiz->hijos[1],flag);
                return new Resultado("booleano",TBOOLEANO_,"",resultado1->etiV+","+resultado2->etiV,resultado2->etiF);
            }
            break;
        case AND_:
            {
                 resultado1=logica(&raiz->hijos[0],flag);
                 code->cadena3d+=resultado1->etiV+":\n";
                 resultado2=logica(&raiz->hijos[1],flag);
                 return new Resultado("booleano",TBOOLEANO_,"",resultado2->etiV,resultado1->etiF+","+resultado2->etiF);
            }
            break;
        case NO_:
            {
                resultado1=logica(&raiz->hijos[0],flag);
                return new Resultado("booleano",TBOOLEANO_,"",resultado1->etiF,resultado1->etiV);

            }
            break;
        default:
            return relacional(raiz,flag);
            break;
    }

}

void Operaciones::addError(QString tipo,QString desc,int linea,int columna)
{
    errorT *error=new errorT(tipo,desc,linea,columna);
    listaErrores->append(*error);
}

QString Operaciones::almacenarCadena(QString cadena)
{
    cadena=cadena.replace("\"","");
    QString temp1=code->genTemp();

    code->cadena3d+=temp1+"=h;//posicion de la cadena\n";
    code->cadena3d+="heap[h]=s;\n";
    code->cadena3d+="h=h+1;\n";

    for(int i=0;i<cadena.length();i++)
    {
        char c=cadena.toStdString()[i];
        code->cadena3d+="pool[s]="+QString::number(c)+";//"+cadena[i]+"\n";
        code->cadena3d+="s=s+1;\n";
    }
    code->cadena3d+="pool[s]=0;\n";
    code->cadena3d+="s=s+1;\n";
    return temp1;
}

QString Operaciones::getCadena(Resultado *resultado)
{
    code->cadena3d+="//casteando entero a cadena\n";
    QString temp1=code->genTemp();
    code->cadena3d+=temp1+"="+resultado->valor+";\n";
    QString temp2=code->genTemp();
    //code->cadena3d+=temp2+"=p+"+getDesplazamientoP()+";//simulacion de cambio de ambito\n";
    code->cadena3d+=temp2+"=p+"+QString::number(10)+";//simulacion de cambio de ambito\n";
    QString temp3=code->genTemp();
    code->cadena3d+=temp3+"="+temp2+"+2; //parametro\n";
    code->cadena3d+="stack["+temp3+"]="+temp1+";\n";
    //code->cadena3d+="p=p+"+getDesplazamientoP()+";//cambio de ambito real\n";
    code->cadena3d+="p=p+"+QString::number(10)+";//cambio de ambito real\n";
    code->cadena3d+="getStr();\n";
    QString temp4=code->genTemp();
    code->cadena3d+=temp4+"=p+1;//retorno\n";
    QString temp5=code->genTemp();
    code->cadena3d+=temp5+"=stack["+temp4+"];//puntero a pool de la cadena\n";
    //code->cadena3d+="p=p-"+getDesplazamientoP()+";//regreso al ambito actual\n";
    code->cadena3d+="p=p-"+QString::number(10)+";//regreso al ambito actual\n";
    code->cadena3d+="//fin casteo entero a cadena\n\n";

    return temp5;
}


QString Operaciones::concatenarNumeroCadena(Resultado *resultado1,Resultado *resultado2)
{
    code->cadena3d+="//concatenacion de numero casteado y cadena\n";
    QString temp6=code->genTemp();
    code->cadena3d+=temp6+"=p+"+QString::number(10)+";//simulacion de cambio de ambito\n";
    QString temp7=code->genTemp();
    code->cadena3d+=temp7+"="+temp6+"+2;//direccion parametro1\n";
    code->cadena3d+="stack["+temp7+"]="+resultado1->valor+";\n";
    QString temp8=code->genTemp();
    code->cadena3d+=temp8+"="+temp6+"+3; //direccion parametro2\n";
    if(resultado2->ref==1){
    QString tempAux1=code->genTemp();
    code->cadena3d+=tempAux1+"=heap["+resultado2->valor+"];\n";
    code->cadena3d+="stack["+temp8+"]="+tempAux1+";\n";
    }else{
    code->cadena3d+="stack["+temp8+"]="+resultado2->valor+";\n";
    }
    code->cadena3d+="p=p+"+QString::number(10)+";//cambio de ambito real\n";
    code->cadena3d+="concat();\n";
    QString temp9=code->genTemp();
    code->cadena3d+=temp9+"=p+0;//direccion del retorno\n";
    QString temp10=code->genTemp();
    code->cadena3d+=temp10+"=stack["+temp9+"];//puntero al pool de la concatenacion\n";
    code->cadena3d+="p=p-"+QString::number(10)+";//regreso al ambito actual\n";
    code->cadena3d+="//fin concatenacino numero casteado y cadena\n\n";

    return temp10;
}

QString Operaciones::concatenarCadenaNumero(Resultado *resultado1,Resultado *resultado2)
{
    code->cadena3d+="//concatenacion de cadena y numero casteado\n";
    QString temp6=code->genTemp();
    code->cadena3d+=temp6+"=p+"+QString::number(10)+";//simulacion de cambio de ambito\n";
    QString temp7=code->genTemp();
    code->cadena3d+=temp7+"="+temp6+"+2;//direccion parametro1\n";
    if(resultado1->ref==1){
    QString tempAux1=code->genTemp();
    code->cadena3d+=tempAux1+"=heap["+resultado1->valor+"];\n";
    code->cadena3d+="stack["+temp7+"]="+tempAux1+";\n";
    }else{
    code->cadena3d+="stack["+temp7+"]="+resultado2->valor+";\n";
    }
    QString temp8=code->genTemp();
    code->cadena3d+=temp8+"="+temp6+"+3; //direccion parametro2\n";
    code->cadena3d+="stack["+temp8+"]="+resultado2->valor+";\n";
    code->cadena3d+="p=p+"+QString::number(10)+";//cambio de ambito real\n";
    code->cadena3d+="concat();\n";
    QString temp9=code->genTemp();
    code->cadena3d+=temp9+"=p+0;//direccion del retorno\n";
    QString temp10=code->genTemp();
    code->cadena3d+=temp10+"=stack["+temp9+"];//puntero al pool de la concatenacion\n";
    code->cadena3d+="p=p-"+QString::number(10)+";//regreso al ambito actual\n";
    code->cadena3d+="//fin concatenacino cadena y numero casteado\n\n";

    return temp10;
}

Resultado *Operaciones::convertirAcadena(Resultado *resultado,nodo *raiz)
{

    if(resultado->tipo_==TENTERO_||resultado->tipo_==TDECIMAL_)
    {
        QString temp1=getCadena(resultado);
        return new Resultado("cadena",TCADENA_,temp1);

    }else if(resultado->tipo_==TBOOLEANO_)
    {
        QString temp1=code->genTemp();
        QString temp2=code->genTemp();
        QString temp3=code->genTemp();
        code->cadena3d+=temp1+"=p+tamMetodo"+";//cambio de ambito virtual\n";
        code->cadena3d+="stack["+temp1+"]="+resultado->valor+";\n";
        code->cadena3d+="p=p+tamMetodo"+QString::number(10)+";//cambio de ambito real\n";
        code->cadena3d+="booleanoToCadena();\n";
        code->cadena3d+=temp2+"=p+1;//direccion del retorno\n";
        code->cadena3d+=temp3+"=stack["+temp2+"];\n";
        code->cadena3d+="p=p-tamMetodo"+QString::number(10)+";//regreso al ambito actual\n";
        return new Resultado("cadena",TCADENA_,temp3);
    }else if(resultado->tipo_==TCARACTER_)
    {
        addError("Semantico","Expresion tipo caracter invalida en el metodo convertir a cadena",raiz->linea,raiz->columna);
        return new Resultado("error",-1,"");

    }else if(resultado->tipo_==TCADENA_)
    {
        addError("Semantico","Expresion tipo cadena invalida en el metodo convertir a cadena",raiz->linea,raiz->columna);
        return new Resultado("error",-1,"");
    }
}

Resultado *Operaciones::acceso(nodo *raiz,QString posicion)
{

    int este=0;
    int contador=code->getTamanoAmbitoActual();

    for(int i=0;i<raiz->hijos.count();i++)
    {
      if(raiz->hijos[i].tipo=="esteacceso")
      {
        QString temp1=code->genTemp();
        QString temp2=code->genTemp();
        este=1;
        code->cadena3d+=temp1+"=p+0;\n";
        code->cadena3d+=temp2+"=stack["+temp1+"];\n";

      }else if(raiz->hijos[i].tipo=="acceso")
      {
          if(este==1)
          {


          }else
          {

          }

          contador++;

      }else if(raiz->hijos[i].tipo=="accesoarray")
      {

          contador++;

      }else if(raiz->hijos[i].tipo=="llamada")
      {

        contador++;
    }

  }




  Simbolo s;
  QString valor=code->genTemp();
  code->apilarMetodo("persona");

  for(int i=0;i<raiz->hijos.count();i++)
  {
      if(raiz->hijos[i].tipo=="acceso")
      {
          if(i==0)
          {
              if(posicion!="")
              {
                  QString nombre=raiz->hijos[i].hijos[0].valor;
                  s=code->getSimboloPorNombre(nombre);

                  if(s.id=="")
                  {
                      return new Resultado("error",-1,"");
                  }

                  QString temp1=code->genTemp();

                  code->cadena3d+=temp1+"="+posicion+"+"+QString::number(s.direccionLocal)+";//"+s.nombre+"\n";
                  code->cadena3d+=valor+"=heap["+temp1+"];\n";
              }else
              {

                  QString nombre=raiz->hijos[i].valor;
                  s=code->getSimboloPorNombre(nombre);

                  if(s.id=="")
                  {
                      return new Resultado("error",-1,"");
                  }

                  QString temp1=code->genTemp();

                  code->cadena3d+=temp1+"=p"+s.direccionLocal+";//"+s.nombre+"\n";
                  code->cadena3d+=valor+"=stack["+temp1+"];\n";

              }

          }else
          {

              QString nombre=raiz->hijos[i].hijos[0].valor;
              s=code->getSimboloPorId("global$"+s.tipo+"$"+nombre);
              if(s.id=="")
              {
                  return new Resultado("error",-1,"");
              }

              QString temp1=code->genTemp();
              code->cadena3d+=temp1+"="+valor+"+"+QString::number(s.direccionLocal)+";\n";
              code->cadena3d+=valor+"=heap["+temp1+"];\n";
          }

      }else if(raiz->hijos[i].tipo=="llamada")
      {



      }
  }

  return new Resultado(s.tipo,1,valor);

}





























