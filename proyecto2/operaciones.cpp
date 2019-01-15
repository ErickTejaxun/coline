#include "operaciones.h"
#include <editor.h>
#include <qdebug.h>
#include <codigo3d.h>
#include <errorT.h>
#include <scanner.h>


extern Codigo3d *code;
extern QList<errorT> *listaErrores;
Operaciones::Operaciones()
{

}

Resultado *Operaciones::aritmetica(nodo *raiz)
{
    QString temp1;
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
        NADA_ = 60,
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
        TDECIMAL_=80
    };

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
                            //falta
                            temp1=code->genTemp();
                            return new Resultado("cadena",TCADENA_,temp1);
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
                            //falta
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
                            return new Resultado("decimal",TDECIMAL_,temp1);
                        case TCARACTER_:
                            temp1=code->genTemp();
                            code->cadena3d+=temp1+"="+resultado1->valor+"+"+resultado2->valor+";//operacion caracter + caracter\n";
                            return new Resultado("entero",TENTERO_,temp1);
                        case TCADENA_:
                            //falta
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
                            //falta
                            break;
                        case TDECIMAL_:
                            //falta
                            break;
                        case TCARACTER_:
                            //falta
                            break;
                        case TCADENA_:
                            //falta
                            break;
                        case TBOOLEANO_:
                            //falta
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

void Operaciones::addError(QString tipo,QString desc,int linea,int columna)
{
    errorT *error=new errorT(tipo,desc,linea,columna);
    listaErrores->append(*error);
}

QString Operaciones::almacenarCadena(QString cadena)
{
    cadena=cadena.replace("\"","");
    QString temp1=code->genTemp();
    code->cadena3d+=temp1+"=s;//posicion de la cadena\n";       
    std::string arrayChar = cadena.toStdString();
    for(int i=0;i<cadena.length();i++)
    {                
        char c = arrayChar[i];
        code->cadena3d+="pool[s]="+ QString::number(c) +";//"+cadena[i]+"\n";
        code->cadena3d+="s=s+1;\n";
    }
    code->cadena3d+="pool[s]=0;\n";
    code->cadena3d+="s=s+1;\n";
    return temp1;
}

QString Operaciones::getCadena(Resultado *resultado)
{

    return "";
}

