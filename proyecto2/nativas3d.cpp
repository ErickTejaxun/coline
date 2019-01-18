#include "nativas3d.h"
#include <codigo3d.h>
extern Codigo3d *code;
Nativas3d::Nativas3d()
{
    this->etiqueta=0;
    this->temporal=0;
}

QString Nativas3d::genEti()
{
    return "L"+QString::number(etiqueta++);
}

QString Nativas3d::genTemp()
{
    return "t"+QString::number(temporal++);
}

void Nativas3d::concatenar()
{
    QString temp1=genTemp();
    QString temp2=genTemp();
    QString temp3=genTemp();
    QString temp4=genTemp();
    QString temp5=genTemp();
    QString temp6=genTemp();
    QString temp7=genTemp();
    QString temp8=genTemp();

    QString eti1=genEti();
    QString eti2=genEti();
    QString eti3=genEti();
    QString eti4=genEti();
    QString eti5=genEti();
    QString eti6=genEti();

    code->cadena3d+="//metodo 3d que concatena 2 cadenas\n";
    code->cadena3d+="void concat(){\n";
    code->cadena3d+=temp1+"=p+2;//cadena1\n";
    code->cadena3d+=temp2+"=stack["+temp1+"];//puntero al pool\n";

    //acceso al heap si hay otro caso

    code->cadena3d+=temp3+"=s;//nueva cadena\n";

    //asignacion al heap si hay otro caso

    code->cadena3d+=eti1+":\n";
    code->cadena3d+=temp4+"=pool["+temp2+"];//extrayendo caracter\n";
    code->cadena3d+="if("+temp4+"!=0) goto "+eti2+";\n";
    code->cadena3d+="goto "+eti3+";\n";

    code->cadena3d+=eti2+":\n";
    code->cadena3d+="pool[s]="+temp4+";//almacenando caracter\n";
    code->cadena3d+="s=s+1;\n";
    code->cadena3d+=temp2+"="+temp2+"+1;\n";
    code->cadena3d+="goto "+eti1+";\n";

    code->cadena3d+=eti3+":\n";
    code->cadena3d+=temp5+"=p+3;//cadena2\n";
    code->cadena3d+=temp6+"=stack["+temp5+"];//puntero al pool\n";

    //acceso al heap si hay otro caso

    code->cadena3d+=eti4+":\n";
    code->cadena3d+=temp7+"=pool["+temp6+"];//extrayendo caracter\n";
    code->cadena3d+="if("+temp7+"!=0) goto "+eti5+";\n";
    code->cadena3d+="goto "+eti6+";\n";

    code->cadena3d+=eti5+":\n";
    code->cadena3d+="pool[s]="+temp7+";//almacenando caracter\n";
    code->cadena3d+="s=s+1;\n";
    code->cadena3d+=temp6+"="+temp6+"+1;\n";
    code->cadena3d+="goto "+eti4+";\n";

    code->cadena3d+=eti6+":\n";
    code->cadena3d+="pool[s]=0;\n";
    code->cadena3d+="s=s+1;\n";

    code->cadena3d+=temp8+"=p+1;//retorno del metodo\n";
    code->cadena3d+="stack["+temp8+"]="+temp3+";\n";
    code->cadena3d+="}\n\n";

}


void Nativas3d::coreIgualIgual(){

    code->cadena3d+="void igualIgual(){\n";

    QString temp1=genTemp();
    QString temp2=genTemp();
    QString temp3=genTemp();
    QString temp4=genTemp();

    QString temp5=genTemp();
    QString temp6=genTemp();

    QString temp7=genTemp();

    QString eti1=genEti();
    QString eti2=genEti();
    QString eti3=genEti();

    QString eti4=genEti();
    QString eti5=genEti();
    QString eti6=genEti();

    code->cadena3d+=temp1+"=p+2; //direccion de parametro1\n";
    code->cadena3d+=temp2+"=stack["+temp1+"]; //cadena1\n";

    code->cadena3d+=temp3+"=p+3; //direccion de parametro2\n";
    code->cadena3d+=temp4+"=stack["+temp3+"]; //cadena2\n";

    code->cadena3d+=eti1+":\n";
    code->cadena3d+=temp5+"=pool["+temp2+"];\n";
    code->cadena3d+=temp6+"=pool["+temp4+"];\n";

    code->cadena3d+="if("+temp5+"=="+temp6+") goto "+eti2+"; //si son iguales\n";
    code->cadena3d+="goto "+eti3+"; //si no son iguales\n";

    code->cadena3d+=eti2+":\n";
    code->cadena3d+=temp2+"="+temp2+"+1;\n";
    code->cadena3d+=temp4+"="+temp4+"+1;\n";

    code->cadena3d+="if("+temp5+"!=0) goto "+eti1+"; //si es caracter de fin de cadena\n";
    code->cadena3d+="goto "+eti4+";\n";

    code->cadena3d+=eti3+":\n";
    code->cadena3d+=temp7+"=p+0;\n";
    code->cadena3d+="stack["+temp7+"]=0; //false\n";
    code->cadena3d+="goto "+eti5+";\n";

    code->cadena3d+=eti4+":\n";
    code->cadena3d+=temp7+"=p+1;\n";
    code->cadena3d+="stack["+temp7+"]=1; //true\n";
    code->cadena3d+="goto "+eti5+";\n";

    code->cadena3d+=eti5+": ;\n";

    code->cadena3d+="}\n\n";
}

void Nativas3d::coreNoIgual(){
    code->cadena3d+="void noIgual(){\n";

    QString temp1=genTemp();
    QString temp2=genTemp();
    QString temp3=genTemp();
    QString temp4=genTemp();

    QString temp5=genTemp();
    QString temp6=genTemp();

    QString temp7=genTemp();

    QString eti1=genEti();
    QString eti2=genEti();
    QString eti3=genEti();

    QString eti4=genEti();
    QString eti5=genEti();
    QString eti6=genEti();

    code->cadena3d+=temp1+"=p+2; //direccion de parametro1\n";
    code->cadena3d+=temp2+"=stack["+temp1+"]; //cadena1\n";

    code->cadena3d+=temp3+"=p+3; //direccion de parametro2\n";
    code->cadena3d+=temp4+"=stack["+temp3+"]; //cadena2\n";

    code->cadena3d+=eti1+":\n";
    code->cadena3d+=temp5+"=pool["+temp2+"];\n";
    code->cadena3d+=temp6+"=pool["+temp4+"];\n";

    code->cadena3d+="if("+temp5+"=="+temp6+") goto "+eti2+"; //si son iguales\n";
    code->cadena3d+="goto "+eti3+"; //si no son iguales\n";

    code->cadena3d+=eti2+":\n";
    code->cadena3d+=temp2+"="+temp2+"+1;\n";
    code->cadena3d+=temp4+"="+temp4+"+1;\n";

    code->cadena3d+="if("+temp5+"!=0) goto "+eti1+"; //si es caracter de fin de cadena\n";
    code->cadena3d+="goto "+eti4+";\n";

    code->cadena3d+=eti3+":\n";
    code->cadena3d+=temp7+"=p+0;\n";
    code->cadena3d+="stack["+temp7+"]=1; //no es igual\n";
    code->cadena3d+="goto "+eti5+";\n";

    code->cadena3d+=eti4+":\n";
    code->cadena3d+=temp7+"=p+1;\n";
    code->cadena3d+="stack["+temp7+"]=0; //es igual\n";
    code->cadena3d+="goto "+eti5+";\n";

    code->cadena3d+=eti5+": ;\n";

    code->cadena3d+="}\n\n";

}

void Nativas3d::imprimir(){

    QString temp1=genTemp();
    QString temp2=genTemp();
    QString temp3=genTemp();

    QString eti1=genEti();
    QString eti2=genEti();
    QString eti3=genEti();

    code->cadena3d+="void outStr(){\n";

    code->cadena3d+=temp1+"=p+1; //referencia de la cadena a imprimir\n";
    code->cadena3d+=temp2+"=stack["+temp1+"]; //direccion del la cadena\n";

    code->cadena3d+=eti1+":\n";
    code->cadena3d+=temp3+"=pool["+temp2+"]; //caracter a imprimir\n";
    code->cadena3d+="if("+temp3+"!=0) goto "+eti2+";\n";
    code->cadena3d+="goto "+eti3+";\n";

    code->cadena3d+=eti2+":\n";
    code->cadena3d+="printf(%c,"+temp3+");\n";
    code->cadena3d+=temp2+"="+temp2+"+1;\n";
    code->cadena3d+="goto "+eti1+";\n";

    code->cadena3d+=eti3+": ;\n";

    code->cadena3d+="}\n\n";
}



void Nativas3d::coreMayorIgual(){

    code->cadena3d+="void mayorIgual(){\n";

    QString temp1=genTemp();
    QString temp2=genTemp();
    QString temp3=genTemp();
    QString temp4=genTemp();

    QString temp5=genTemp();
    QString temp6=genTemp();

    QString temp7=genTemp();

    QString eti1=genEti();
    QString eti2=genEti();
    QString eti3=genEti();

    QString eti4=genEti();
    QString eti5=genEti();
    QString eti6=genEti();

    code->cadena3d+=temp1+"=p+2; //direccion de parametro1\n";
    code->cadena3d+=temp2+"=stack["+temp1+"]; //cadena1\n";

    code->cadena3d+=temp3+"=p+3; //direccion de parametro2\n";
    code->cadena3d+=temp4+"=stack["+temp3+"]; //cadena2\n";

    code->cadena3d+=eti1+":\n";
    code->cadena3d+=temp5+"=pool["+temp2+"];\n";
    code->cadena3d+=temp6+"=pool["+temp4+"];\n";

    code->cadena3d+="if("+temp5+">="+temp6+") goto "+eti2+"; //si cad1 es mayor igual\n";
    code->cadena3d+="goto "+eti3+"; //si cad1 no es mayor igual\n";

    code->cadena3d+=eti2+":\n";
    code->cadena3d+=temp2+"="+temp2+"+1;\n";
    code->cadena3d+=temp4+"="+temp4+"+1;\n";

    code->cadena3d+="if("+temp5+"!=0) goto "+eti4+"; //si es caracter de fin de cadena\n";
    code->cadena3d+="goto "+eti5+";\n";

    code->cadena3d+=eti4+":\n";
    code->cadena3d+="if("+temp6+"!=0) goto "+eti1+"; //si es caracter de fin de cadena\n";
    code->cadena3d+="goto "+eti5+";\n";


    code->cadena3d+=eti3+":\n";
    code->cadena3d+=temp7+"=p+0;\n";
    code->cadena3d+="stack["+temp7+"]=0; //false\n";
    code->cadena3d+="goto "+eti5+";\n";

    code->cadena3d+=eti5+":\n";
    code->cadena3d+=temp7+"=p+1;\n";
    code->cadena3d+="stack["+temp7+"]=1; //true\n";
    code->cadena3d+="goto "+eti6+";\n";

    code->cadena3d+=eti6+": ;\n";

    code->cadena3d+="}\n\n";
}

void Nativas3d::coreMayor(){

    code->cadena3d+="void mayor(){\n";

    QString temp1=genTemp();
    QString temp2=genTemp();
    QString temp3=genTemp();
    QString temp4=genTemp();

    QString temp5=genTemp();
    QString temp6=genTemp();

    QString temp7=genTemp();

    QString eti1=genEti();
    QString eti2=genEti();
    QString eti3=genEti();

    QString eti4=genEti();
    QString eti5=genEti();
    QString eti6=genEti();

    QString eti7=genEti();

    QString tempRes1=genTemp();
    QString tempRes2=genTemp();

    code->cadena3d+=temp1+"=p+2; //direccion de parametro1\n";
    code->cadena3d+=temp2+"=stack["+temp1+"]; //cadena1\n";

    code->cadena3d+=temp3+"=p+3; //direccion de parametro2\n";
    code->cadena3d+=temp4+"=stack["+temp3+"]; //cadena2\n";

    code->cadena3d+=tempRes1+"=0;\n";
    code->cadena3d+=tempRes2+"=0;\n";

    code->cadena3d+=eti1+":\n";
    code->cadena3d+=temp5+"=pool["+temp2+"];\n";
    code->cadena3d+=temp6+"=pool["+temp4+"];\n";


    code->cadena3d+="if("+temp5+"==0) goto "+eti2+"; //si son iguales\n";
    code->cadena3d+="goto "+eti3+"; //si no son iguales\n";

    code->cadena3d+=eti3+":\n";//t5!=0 && t6!=0
    code->cadena3d+="if("+temp6+"==0) goto "+eti2+"; //si son iguales\n";
    code->cadena3d+="goto "+eti4+"; //si no son iguales\n";


    code->cadena3d+=eti2+":\n";
    code->cadena3d+="if("+tempRes1+">"+tempRes2+") goto "+eti5+"; //si son iguales\n";
    code->cadena3d+="goto "+eti6+"; //si no son iguales\n";

    code->cadena3d+=eti4+":\n";
    code->cadena3d+=tempRes1+"="+tempRes1+"+"+temp5+";\n";
    code->cadena3d+=tempRes2+"="+tempRes2+"+"+temp6+";\n";
    code->cadena3d+=temp2+"="+temp2+"+1;\n";
    code->cadena3d+=temp4+"="+temp4+"+1;\n";

    code->cadena3d+="if("+temp5+"!="+temp6+") goto "+eti2+"; //si son iguales\n";
    code->cadena3d+="goto "+eti1+"; //si no son iguales\n";

    code->cadena3d+=eti5+":\n";
    code->cadena3d+=temp7+"=p+0;\n";
    code->cadena3d+="stack["+temp7+"]=1; //true\n";
    code->cadena3d+="goto "+eti7+";\n";

    code->cadena3d+=eti6+":\n";
    code->cadena3d+=temp7+"=p+1;\n";
    code->cadena3d+="stack["+temp7+"]=0; //false\n";
    code->cadena3d+="goto "+eti7+";\n";


    code->cadena3d+=eti7+": ;\n";

    code->cadena3d+="}\n\n";
}

void Nativas3d::booleanoToCadena()
{
    QString temp1=genTemp();
    QString temp2=genTemp();
    QString temp3=genTemp();
    QString temp4=genTemp();

    QString eti1=genEti();
    QString eti2=genEti();
    QString eti3=genEti();

    code->cadena3d+="void booleanoToCadena(){\n";
    code->cadena3d+=temp1+"=p+2;//parametro\n";
    code->cadena3d+=temp2+"=stack["+temp1+"];\n";
    code->cadena3d+="if("+temp2+"==1) goto "+eti1+";\n";
    code->cadena3d+="goto "+eti2+";\n";
    code->cadena3d+=eti1+":\n";
    code->cadena3d+=temp3+"=s;\n";
    code->cadena3d+="pool[s]=118;//v\n";
    code->cadena3d+="s=s+1;\n";
    code->cadena3d+="pool[s]=101;//e\n";
    code->cadena3d+="s=s+1;\n";
    code->cadena3d+="pool[s]=114;//r\n";
    code->cadena3d+="s=s+1;\n";
    code->cadena3d+="pool[s]=100;//d\n";
    code->cadena3d+="s=s+1;\n";
    code->cadena3d+="pool[s]=97;//a\n";
    code->cadena3d+="s=s+1;\n";
    code->cadena3d+="pool[s]=100;//d\n";
    code->cadena3d+="s=s+1;\n";
    code->cadena3d+="pool[s]=101;//e\n";
    code->cadena3d+="s=s+1;\n";
    code->cadena3d+="pool[s]=114;//r\n";
    code->cadena3d+="s=s+1;\n";
    code->cadena3d+="pool[s]=111;//o\n";
    code->cadena3d+="s=s+1;\n";
    code->cadena3d+="pool[s]=0;//0\n";
    code->cadena3d+="s=s+1;\n";
    code->cadena3d+="goto "+eti3+";\n";
    code->cadena3d+=eti2+":\n";
    code->cadena3d+=temp3+"=s;\n";
    code->cadena3d+="pool[s]=101;//f\n";
    code->cadena3d+="s=s+1;\n";
    code->cadena3d+="pool[s]=97;//a\n";
    code->cadena3d+="s=s+1;\n";
    code->cadena3d+="pool[s]=108;//l\n";
    code->cadena3d+="s=s+1;\n";
    code->cadena3d+="pool[s]=115;//s\n";
    code->cadena3d+="s=s+1;\n";
    code->cadena3d+="pool[s]=111;//o\n";
    code->cadena3d+="s=s+1;\n";
    code->cadena3d+="pool[s]=0;//0\n";
    code->cadena3d+="s=s+1;\n";
    code->cadena3d+=temp4+"=p+1;//retorno\n";
    code->cadena3d+="stack["+temp4+"]="+temp3+";\n";
    code->cadena3d+=eti3+":;\n";
    code->cadena3d+="}\n\n";

}

void Nativas3d::numeroToCadena(){
    QString temp1=genTemp();
    QString temp2=genTemp();
    QString temp3=genTemp();
    QString temp4=genTemp();
    QString temp5=genTemp();
    QString temp6=genTemp();//puntero al pool
    QString temp7=genTemp();
    QString temp8=genTemp();
    QString temp9=genTemp();
    QString temp10=genTemp();
    QString temp11=genTemp();
    QString temp12=genTemp();
    QString temp13=genTemp();
    QString temp14=genTemp();
    QString temp15=genTemp();
    QString temp16=genTemp();
    QString temp17=genTemp();
    QString temp18=genTemp();

    QString eti1=genEti();
    QString eti2=genEti();
    QString eti3=genEti();
    QString eti4=genEti();
    QString eti5=genEti();
    QString eti6=genEti();
    QString eti7=genEti();
    QString eti8=genEti();
    QString eti9=genEti();
    QString eti10=genEti();

    code->cadena3d+="void numertoToCadena(){\n";

    code->cadena3d+=temp1+"=p+2;\n";
    code->cadena3d+=temp2+"=stack["+temp1+"];//numero a convertir\n";
    code->cadena3d+=temp3+"="+temp2+"%1;//decimal\n";
    code->cadena3d+=temp4+"="+temp2+"-"+temp3+";//entera\n";

    code->cadena3d+=eti1+":\n";
    code->cadena3d+=temp5+"="+temp4+"%10;\n";
    code->cadena3d+=temp6+"="+temp5+"+48;\n";
    code->cadena3d+="pool[s]="+temp6+";\n";
    code->cadena3d+="s=s+1;\n";
    code->cadena3d+=temp7+"="+temp4+"-"+temp5+";\n";
    code->cadena3d+=temp4+"="+temp7+"/10;\n";
    code->cadena3d+="if("+temp4+">"+"0) goto "+eti1+";\n";
    code->cadena3d+="goto "+eti2+";\n";
    code->cadena3d+=eti2+":\n";
    code->cadena3d+="pool[s]=0;\n";
    code->cadena3d+=temp8+"=s;//fin cadena entero\n";
    code->cadena3d+="s=s+1;\n";

    code->cadena3d+=eti3+":\n";
    code->cadena3d+=temp3+"="+temp3+"*10;\n";
    code->cadena3d+=temp9+"="+temp3+"%1;\n";
    code->cadena3d+=temp10+"="+temp3+"-"+temp9+";\n";
    code->cadena3d+=temp11+"="+temp10+"%10;\n";
    code->cadena3d+=temp12+"="+temp11+"+48;\n";
    code->cadena3d+="pool[s]="+temp12+";\n";
    code->cadena3d+="s=s+1;\n";
    code->cadena3d+="if("+temp9+">0) goto "+eti3+";\n";
    code->cadena3d+="goto "+eti4+";\n";

    code->cadena3d+=eti4+":\n";
    code->cadena3d+="pool[s]=0;\n";
    code->cadena3d+="s=s+1;\n";
    code->cadena3d+=temp13+"=s;//puntero cadena completa\n";
    code->cadena3d+=temp14+"="+temp8+";\n";
    code->cadena3d+=eti5+":\n";
    code->cadena3d+=temp15+"=pool["+temp14+"];\n";
    code->cadena3d+="if("+temp15+"!=0) goto "+eti6+";\n";
    code->cadena3d+="goto "+eti7+";\n";
    code->cadena3d+=eti6+":\n";
    code->cadena3d+="pool[s]="+temp15+";\n";
    code->cadena3d+="s+s+1;\n";
    code->cadena3d+=temp14+"="+temp14+"-1;\n";
    code->cadena3d+="goto "+eti5+";\n";
    code->cadena3d+=eti7+":\n";
    code->cadena3d+="pool[s]=46;//punto\n";
    code->cadena3d+="s=s+1;\n";
    code->cadena3d+=temp16+"="+temp8+"+2;\n";

    code->cadena3d+=eti8+":\n";
    code->cadena3d+=temp17+"=pool["+temp16+"];\n";
    code->cadena3d+="if("+temp17+"!=0) goto "+eti9+";\n";
    code->cadena3d+="goto "+eti10+";\n";
    code->cadena3d+=eti9+":\n";
    code->cadena3d+="pool[s]="+temp17+";\n";
    code->cadena3d+="s=s+1;\n";
    code->cadena3d+=temp16+"="+temp16+"+1;\n";
    code->cadena3d+="goto "+eti8+";\n";
    code->cadena3d+=eti10+":\n";
    code->cadena3d+="pool[s]=0;\n";
    code->cadena3d+="s=s+1;\n";

    code->cadena3d+=temp18+"=p+1;//retorno\n";
    code->cadena3d+="stack["+temp18+"]="+temp13+";\n";
    code->cadena3d+="}\n\n";
}

void Nativas3d::concatenarTipo2()
{
    QString temp1=genTemp();
    QString temp2=genTemp();
    QString temp3=genTemp();
    QString temp4=genTemp();
    QString temp5=genTemp();
    QString temp6=genTemp();
    QString temp7=genTemp();
    QString temp8=genTemp();
    QString temp9=genTemp();
    QString temp10=genTemp();
    QString temp11=genTemp();
    QString temp12=genTemp();
    QString temp13=genTemp();
    QString temp14=genTemp();
    QString temp15=genTemp();
    QString temp16=genTemp();
    QString temp17=genTemp();
    QString temp18=genTemp();
    QString temp19=genTemp();
    QString temp20=genTemp();
    QString temp21=genTemp();

    QString eti1=genEti();
    QString eti2=genEti();
    QString eti3=genEti();
    QString eti4=genEti();
    QString eti5=genEti();
    QString eti6=genEti();
    QString eti7=genEti();
    QString eti8=genEti();
    QString eti9=genEti();
    QString eti10=genEti();
    QString eti11=genEti();


    code->cadena3d+="void concatenarTipo2(){\n";

    code->cadena3d+=temp1+"=p+2;\n";
    code->cadena3d+=temp2+"=stack["+temp1+"];//paremetro1\n";
    code->cadena3d+=temp3+"=p+3;\n";
    code->cadena3d+=temp4+"=stack["+temp3+"];//parametro2\n";
    code->cadena3d+=temp5+"=s;//nueva cadena\n";
    code->cadena3d+=temp21+"="+temp5+";\n";
    code->cadena3d+=eti1+" :\n";
    code->cadena3d+=temp6+"=pool["+temp2+"];\n";
    code->cadena3d+="if("+temp6+"==0) goto "+eti2+";\n";
    code->cadena3d+="goto "+eti3+";\n";
    code->cadena3d+=eti3+":\n";

    code->cadena3d+="if("+temp6+"==35) goto "+eti4+";//#\n";
    code->cadena3d+="goto "+eti5+";\n";

    code->cadena3d+=eti4+":\n";
    code->cadena3d+=temp7+"="+temp2+"+1;\n";
    code->cadena3d+=temp8+"=pool["+temp7+"];\n";

    code->cadena3d+="if("+temp8+"==69) goto "+eti6+";//E\n";
    code->cadena3d+="goto "+eti7+";\n";

    code->cadena3d+=eti7+":\n";
    code->cadena3d+="if("+temp8+"==66) goto "+eti8+";//B\n";
    code->cadena3d+="goto "+eti9+";\n";

    code->cadena3d+=eti9+":\n";
    code->cadena3d+="if("+temp8+"==68) goto "+eti10+"//D;\n";
    code->cadena3d+="goto "+eti11+";\n";

    code->cadena3d+=eti5+":\n";
    code->cadena3d+="pool[s]="+temp6+";\n";
    code->cadena3d+="s=s+1;\n";
    code->cadena3d+=temp2+"="+temp2+"+1;\n";
    code->cadena3d+="goto "+eti1+";\n";

    code->cadena3d+=eti6+":\n";
    code->cadena3d+="pool[s]=0;\n";
    code->cadena3d+="s=s+1;\n";

    code->cadena3d+=temp9+"=p+3;//parametro\n";
    code->cadena3d+=temp10+"=stack["+temp9+"];\n";
    code->cadena3d+=temp11+"="+temp10+"%1;\n";
    code->cadena3d+=temp12+"="+temp10+"-"+temp11+";\n";
    code->cadena3d+=temp13+"=p+4;\n";
    code->cadena3d+=temp14+"="+temp13+"+2;\n";
    code->cadena3d+="stack["+temp14+"]="+temp12+";\n";
    code->cadena3d+="p=p+4;\n";
    code->cadena3d+="numeroToCadena();\n";
    code->cadena3d+=temp15+"=p+1;//retorno\n";
    code->cadena3d+=temp16+"=stack["+temp15+"];\n";
    code->cadena3d+="p=p-4;\n";
    code->cadena3d+="pool[s]=0;\n";
    code->cadena3d+="s=s+1;\n";

    code->cadena3d+=temp17+"=p+4;cambio de ambito virtual\n";
    code->cadena3d+=temp18+"="+temp17+"+2;//parametro1\n";
    code->cadena3d+="stack["+temp18+"]="+temp5+";\n";
    code->cadena3d+=temp19+"="+temp17+"+3;//parametro2\n";
    code->cadena3d+="stack["+temp19+"]="+temp16+";\n";
    code->cadena3d+="p=p+4;\n";
    code->cadena3d+="concatenar();\n";
    code->cadena3d+=temp20+"=p+1;//retorno\n";
    code->cadena3d+=temp21+"=stack["+temp20+"];\n";
    code->cadena3d+="p=p-4;\n";
    code->cadena3d+="s=s-1;\n";

    code->cadena3d+=temp2+"="+temp2+"+2;\n";
    code->cadena3d+="goto "+eti1+";\n";

    //-------------------------
    code->cadena3d+=eti8+":\n";
    code->cadena3d+=temp9+"=p+3;parametro\n";
    code->cadena3d+=temp10+"=stack["+temp9+"];\n";
    code->cadena3d+=temp11+"=p+4;\n";
    code->cadena3d+=temp12+"="+temp11+"+2;\n";
    code->cadena3d+="stack["+temp12+"]="+temp10+";\n";
    code->cadena3d+="p=p+4;\n";
    code->cadena3d+="booleanoToCadena();\n";
    code->cadena3d+=temp13+"=p+1;//retorno\n";
    code->cadena3d+=temp14+"=stack["+temp13+"];\n";
    code->cadena3d+="p=p-4;\n";
    code->cadena3d+="s=s-1;\n";
    code->cadena3d+=temp2+"="+temp2+"+2;\n";
    code->cadena3d+="goto "+eti1+";\n";
    //--------------------------

    code->cadena3d+=eti10+":\n";
    code->cadena3d+="pool[s]=0;\n";
    code->cadena3d+="s=s+1;\n";

    code->cadena3d+=temp9+"=p+3;//parametro\n";
    code->cadena3d+=temp10+"=stack["+temp9+"];\n";
    //code->cadena3d+=temp11+"="+temp10+"%1;\n";
    //code->cadena3d+=temp12+"="+temp10+"-"+temp11+";\n";
    code->cadena3d+=temp13+"=p+4;\n";
    code->cadena3d+=temp14+"="+temp13+"+2;\n";
    code->cadena3d+="stack["+temp14+"]="+temp10+";\n";
    code->cadena3d+="p=p+4;\n";
    code->cadena3d+="numeroToCadena();\n";
    code->cadena3d+=temp15+"=p+1;//retorno\n";
    code->cadena3d+=temp16+"=stack["+temp15+"];\n";
    code->cadena3d+="p=p-4;\n";
    code->cadena3d+="pool[s]=0;\n";
    code->cadena3d+="s=s+1;\n";

    code->cadena3d+=temp17+"=p+4;cambio de ambito virtual\n";
    code->cadena3d+=temp18+"="+temp17+"+2;//parametro1\n";
    code->cadena3d+="stack["+temp18+"]="+temp5+";\n";
    code->cadena3d+=temp19+"="+temp17+"+3;//parametro2\n";
    code->cadena3d+="stack["+temp19+"]="+temp16+";\n";
    code->cadena3d+="p=p+4;\n";
    code->cadena3d+="concatenar();\n";
    code->cadena3d+=temp20+"=p+1;//retorno\n";
    code->cadena3d+=temp21+"=stack["+temp20+"];\n";
    code->cadena3d+="p=p-4;\n";
    code->cadena3d+="s=s-1;\n";


    code->cadena3d+=temp2+"="+temp2+"+2;\n";
    code->cadena3d+="goto "+eti1+";\n";


    code->cadena3d+=eti2+"://salida\n";
    code->cadena3d+="pool[s]=0;\n";
    code->cadena3d+="s=s+1;\n";

    code->cadena3d+=temp17+"=p+1;//retorno\n";
    code->cadena3d+="stack["+temp17+"]="+temp21+";\n";

    code->cadena3d+=eti11+": ;\n";

    code->cadena3d+="}\n\n";
}

void Nativas3d::convertirAentero()
{
    QString temp1=genTemp();
    QString temp2=genTemp();
    QString temp3=genTemp();
    QString temp4=genTemp();
    QString temp5=genTemp();
    QString temp6=genTemp();
    QString temp7=genTemp();
    QString temp8=genTemp();
    QString temp9=genTemp();
    QString temp10=genTemp();

    QString eti1=genEti();
    QString eti2=genEti();
    QString eti3=genEti();
    QString eti4=genEti();
    QString eti5=genEti();
    QString eti6=genEti();
    QString eti7=genEti();
    QString eti8=genEti();

    code->cadena3d+="void convertirAentero(){\n";
    code->cadena3d+=temp1+"=p+2;\n";
    code->cadena3d+=temp2+"=stack["+temp1+"];//cadena\n";
    code->cadena3d+=temp3+"=0;//valor numerico real\n";
    code->cadena3d+=temp4+"=0;//valor numerico ascci\n";
    code->cadena3d+=temp5+"=0;//flag\n";

    code->cadena3d+=eti1+":\n";
    code->cadena3d+=temp6+"=pool["+temp2+"];\n";
    code->cadena3d+="if("+temp6+"==0) goto "+eti2+";\n";
    code->cadena3d+="goto "+eti3+";\n";
    code->cadena3d+=eti3+":\n";
    code->cadena3d+=temp7+"="+temp6+"-48;\n";
    code->cadena3d+=temp8+"="+temp3+"*10;\n";
    code->cadena3d+=temp9+"="+temp8+"+"+temp7+";\n";
    code->cadena3d+=temp3+"="+temp9+";\n";
    code->cadena3d+=temp4+"="+temp4+"+"+temp6+";\n";
    code->cadena3d+=temp2+"="+temp2+"+1;\n";
    code->cadena3d+="if("+temp6+">=48) goto "+eti4+";\n";
    code->cadena3d+="goto "+eti5+";\n";
    code->cadena3d+=eti4+":\n";
    code->cadena3d+="if("+temp6+"<=57) goto "+eti1+";\n";
    code->cadena3d+="goto "+eti6+";\n";
    code->cadena3d+=eti5+","+eti6+":\n";
    code->cadena3d+=temp5+"=1;\n";
    code->cadena3d+="goto "+eti1+";\n";
    code->cadena3d+=eti2+":\n";
    code->cadena3d+="if("+temp5+"==1) goto "+eti7+";\n";
    code->cadena3d+="goto "+eti8+";\n";
    code->cadena3d+=eti7+":\n";
    code->cadena3d+=temp10+"=p+1;\n";
    code->cadena3d+="stack["+temp10+"]="+temp4+";\n";
    code->cadena3d+="goto "+eti8+";\n";
    code->cadena3d+=eti7+":\n";
    code->cadena3d+=temp10+"=p+1;\n";
    code->cadena3d+="stack["+temp10+"]="+temp3+";\n";
    code->cadena3d+=eti8+": ;\n";

    code->cadena3d+="}\n\n";

}

void Nativas3d::getPesoCadena()
{
    QString temp1=genTemp();
    QString temp2=genTemp();
    QString temp3=genTemp();
    QString temp4=genTemp();
    QString temp5=genTemp();

    QString eti1=genEti();
    QString eti2=genEti();
    QString eti3=genEti();
    QString eti4=genEti();

    code->cadena3d+="void getPesoCadena(){\n";
    code->cadena3d+=temp1+"=p+2;\n";
    code->cadena3d+=temp2+"=stack["+temp1+"];\n";
    code->cadena3d+=temp3+"=0;\n";
    code->cadena3d+=eti1+":\n";
    code->cadena3d+=temp4+"=pool["+temp2+"];\n";
    code->cadena3d+="if("+temp4+"!=0) goto "+eti2+";\n";
    code->cadena3d+="goto "+eti3+";\n";
    code->cadena3d+=eti2+":\n";
    code->cadena3d+=eti3+"="+eti3+"+"+temp4+";\n";
    code->cadena3d+=temp2+"="+temp2+"+1;\n";
    code->cadena3d+="goto "+eti1+";\n";
    code->cadena3d+=eti3+":\n";
    code->cadena3d+=temp5+"=p+1;\n";
    code->cadena3d+="stack["+temp5+"]="+temp3+";\n";
    code->cadena3d+=eti4+": ;\n";
    code->cadena3d+="}\n\n";

}












