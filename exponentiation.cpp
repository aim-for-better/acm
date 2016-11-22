#include<iostream>
#include<string>
#include<cmath>
using namespace std;

/*
in order to finish exponentiation,
we need to implement the big number multiplication
the big number add function
*/
string add(string a,string b);
string substract(string a,string b);
string convertInt2String(int a);
int convertString2Integer(string a);

string multi(string a,string b){

    string intPartA=a;
    string intPartB=b;
    string dotPartA="";
    string dotPartB="";
    int dotA=a.find('.');
    int dotB=b.find('.');
    int dotLenA=(dotA==-1?0:a.size()-1-dotA);
    int dotLenB=(dotB==-1?0:b.size()-1-dotB);

    if(dotA!=-1){
        intPartA=a.substr(0,dotA);
        if(dotA!=a.size()-1){
            dotPartA=a.substr(dotA+1);
        }
    }
    if(dotB!=-1){
        intPartB=b.substr(0,dotB);
        if(dotB!=b.size()-1){
            dotPartB=b.substr(dotB+1);
        }
    }
    if(dotA!=-1&&a[0]=='0'){
        intPartA="";
        int pos=0;
        for(int i=0;i<dotPartA.size();i++){

            if(dotPartA[i]!='0'){
                break;
            }
            pos++;
        }
        dotPartA=dotPartA.substr(pos);
    }
    if(dotB!=-1&&b[0]=='0'){
        intPartB="";

         int pos=0;
        for(int i=0;i<dotPartB.size();i++){

            if(dotPartB[i]!='0'){
                break;
            }
            pos++;
        }
        dotPartB=dotPartB.substr(pos);
    }

    string tmpA=intPartA+dotPartA;
    string tmpB=intPartB+dotPartB;

    //execute multi operation every operation  operate four chars
    int opLen=4;
    int lenA=tmpA.size();
    int lenB=tmpB.size();
    string result="";
    string zero="0000";
    for(int i=1;i<=ceil(lenA*1.0/opLen);i++){

        string tempA="";
        if(lenA>=i*opLen){
            tempA=tmpA.substr(lenA-opLen*i,opLen);
        }else{
            tempA=tmpA.substr(0,lenA-opLen*i+opLen);
        }

        for(int j=1;j<=ceil(lenB*1.0/opLen);j++){

            string tempB="";

            if(lenB>=j*opLen){

                tempB=tmpB.substr(lenB-opLen*j,opLen);
            }else{
                tempB=tmpB.substr(0,lenB-opLen*j+opLen);
            }

            //convert string to integer and multi,
            //and convert result into string
            // and add result;
            int intResult=convertString2Integer(tempA)*convertString2Integer(tempB);
            string strResult=convertInt2String(intResult);
            for(int k=2;k<i+j;k++){

                strResult+=zero;
            }
            //add
            result=add(result,strResult);
//            cout<<result<<endl;
        }
    }

    //add dot to string result
    //consider the case that  result.size()<= dotLenA+dotLenB
    int tmpLen=result.size();
    if(tmpLen<=dotLenA+dotLenB){
        for(int i=0;i<=dotLenA+dotLenB-tmpLen;i++){

            result="0"+result;
        }
    }
    //combine intPart,dot,and dotPart
    if(dotLenA+dotLenB!=0){

        result=result.substr(0,result.size()-(dotLenA+dotLenB))+"."+result.substr(result.size()-(dotLenA+dotLenB));

        //remove the end 0 the in dotPart
        int k=0;
        for(int i=tmpLen;i>result.find('.');i--){
         if(result[i]!='0'){
            break;
         }
            k++;
        }
        result=result.substr(0,result.size()-k);

    }
    return result;

}

string bigAdd(string a,string b)
{
    string sum="";
    /*
     there are total six steps to finish the add between two big numbers
     first: find the flag of sum + or -
     second: find the max length after dot
     third: format the two numbers(add 0 at the begin position for left part of dot
                                    and add 0 at end position for right part of dot )
     fourth:convert string into integer
     fifth: do the plus or minus operation every operation operate 9 chars
     sixth: add the flag and dot to sum

    */

    /*
    default the flag is '' that representation the positive number
    as usually we omit + for positive number
    the flags of the a,b,sum are all + as default
    */
    char flagA='+';
    char flagB='+';
    char flagSum='+';
    string tempA="";
    string tempB="";
    switch(a[0]){

    case '+':
        tempA=a.substr(1);
        break;
    case '-':
        flagA='-';
        tempA=a.substr(1);
        break;
    default:
        tempA=a;
    }

    switch (b[0]){

    case '+':
        tempA=b.substr(1);
        break;
    case '-':
        flagB='-';
        tempB=b.substr(1);
        break;
    default:
        tempB=b;
    }

    if(flagA==flagB){

        flagSum=flagA;
        sum=add(tempA,tempB);
    }else if(tempA>tempB){
        flagSum=flagA;
        sum=substract(tempA,tempB);
    }else{
        flagSum=flagB;
        sum=substract(tempB,tempA);
    }
    return  sum;
}

string add(string a,string b){
  /*
    the format of a and b is a number without digit symbol(+,-)
    but a,b may contain the dot like a="12.123" b="23.2342542"
    and not must such as  a="12" ,b="123"
  */
    string result="";
    string intPartA=a;
    string dotPartA="";
    string intPartB=b;
    string dotPartB="";

    int dotA=a.find('.');
    int dotB=b.find('.');
    if(dotA!=-1){

        intPartA=a.substr(0,dotA);
        if(dotA!=a.size()-1){

            dotPartA=a.substr(dotA+1);
        }
    }
    if(dotB!=-1){

        intPartB=b.substr(0,dotB);
        if(dotB!=b.size()-1){

            dotPartB=b.substr(dotB+1);
        }
    }
//    cout<<"dot A :"<<dotA<<"dot B :"<<dotB<<endl;
//    cout<<"int partA:"<<intPartA<<" int partB:"<<intPartB<<endl;
//    cout<<"dot partA:"<<dotPartA<<" dot partB:"<<dotPartB<<endl;
    //make intPartA,intPartB have the same length
    int maxIntLen=intPartA.size()>=intPartB.size()?intPartA.size():intPartB.size();

    int tmpLenA=intPartA.size();
    if(tmpLenA<maxIntLen){
        for(int i=0;i<maxIntLen-tmpLenA;i++){
            intPartA="0"+intPartA;
        }
    }
    int tmpLenB=intPartB.size();
    if(tmpLenB<maxIntLen){
        for(int i=0;i<maxIntLen-tmpLenB;i++){
            intPartB="0"+intPartB;
        }
    }

    // make dotPartA ,dotPartB have the same length
    int maxDotLen=dotPartA.size()>=dotPartB.size()?dotPartA.size():dotPartB.size();

    tmpLenA=dotPartA.size();
    if(tmpLenA<maxDotLen){
        for(int i=0;i<maxDotLen-tmpLenA;i++){
            dotPartA+="0";
        }
    }
    tmpLenB=dotPartB.size();
    if(tmpLenB<maxDotLen){
        for(int i=0;i<maxDotLen-tmpLenB;i++){
            dotPartB+="0";
        }
    }
    // execute add operation :intPartA+intPartB ,dotPartA+dotPartB
    // every operation execute six lengths str
    int opLen=6;
    int addFlag=0;
    string tmpStrA="";
    string tmpStrB="";
    int tmpA=0;
    int tmpB=0;
    int tmpSum=0;
    string dotResult="";
    string intResult="";
    for(int i=1;i<=int(ceil(maxDotLen*1.0/opLen));i++){
        if(maxDotLen>=i*opLen){

            tmpStrA=dotPartA.substr(maxDotLen-opLen*i,opLen);
            tmpStrB=dotPartB.substr(maxDotLen-opLen*i,opLen);

        }else{

            tmpStrA=dotPartA.substr(0,maxDotLen-i*opLen+opLen);
            tmpStrB=dotPartB.substr(0,maxDotLen-i*opLen+opLen);
        }

        tmpA=convertString2Integer(tmpStrA);
        tmpB=convertString2Integer(tmpStrB);

        tmpSum=tmpA+tmpB+addFlag;
        addFlag=tmpSum/(int(pow(10.0,opLen)));
        tmpSum=tmpSum%(int(pow(10.0,opLen)));
        //tmpStr is the result
        string tmpStr=convertInt2String(tmpSum);
        for(int j=tmpStr.size();j<tmpStrA.size();j++){

            tmpStr="0"+tmpStr;
        }
        dotResult=tmpStr+dotResult;
    }

    tmpStrA="";
    tmpStrB="";
    tmpA=0;
    tmpB=0;
    tmpSum=0;
    for(int i=1;i<=int(ceil(maxIntLen*1.0/opLen));i++){

        if(maxIntLen>=i*opLen){

            tmpStrA=intPartA.substr(maxIntLen-opLen*i,opLen);
            tmpStrB=intPartB.substr(maxIntLen-opLen*i,opLen);

        }else{
            tmpStrA=intPartA.substr(0,maxIntLen-i*opLen+opLen);
            tmpStrB=intPartB.substr(0,maxIntLen-i*opLen+opLen);
        }
        tmpA=convertString2Integer(tmpStrA);
        tmpB=convertString2Integer(tmpStrB);
        tmpSum=tmpA+tmpB+addFlag;
        addFlag=tmpSum/int(pow(10.0,opLen));
        tmpSum=tmpSum%(int(pow(10.0,opLen)));

        string tmpStr=convertInt2String(tmpSum);
        for(int j=tmpStr.size();j<tmpStrA.size();j++){

            tmpStr="0"+tmpStr;
        }

        intResult=tmpStr+intResult;
    }
    result=char(addFlag+48)+intResult+"."+dotResult;
    if(result[0]=='0'){

        result=result.substr(1);
    }
    if(result[result.size()-1]=='.'){

        result=result.substr(0,result.size()-1);
    }
    return result;
}


string substract(string a,string b){

    string result="";
    return result;
}
int convertString2Integer(string a){
    /*
        convert string a without dot  to be integer
        note a must be a string that is the literal of integer
    */

    int result=0;
    int len=a.size();
    if(a.find('.')!=-1){

        return -1;
    }
    for(int i=len-1;i>=0;i--){

        result+=int(a[i]-'0')*pow(10,len-1-i);
    }
    return result;
}
string convertInt2String(int a){

//    int quotient=0;
//    int remainder=0;
//    string result="";
//    for(int i=1;i<=9;i++){
//       quotient= a/int(pow(10,i));
//       remainder=a%int(pow(10,i));
//       if (remainder==0&&quotient!=0){
//
//            result+=char(quotient+48);
//            for(int j=0;j<i;j++){
//            result+="0";
//            }
//            break;
//       }else{
//            if(quotient!=0){
//
//                result+=char(quotient+48);
//            }
//            a=remainder;
//            if(i==1){
//                result+=char(remainder+48);
//            }
//       }
//    }
// how stupid the above code is ! The author's head must be kicked by a donkey
// i will never delete the above code
    int remainder=0;
    string result="";
    while(a){

        remainder=a%10;
        result=char(remainder+48)+result;
        a=a/10;
    }

    return result;
}
int main()
{
    string a,result;
    int n;
    while(cin>>a>>n){
        result=a;
//      cout<<add(a,b)<<endl;
        for(int i=1;i<n;i++){

            result=multi(a,result);
        }
        cout<<result<<endl;
    }
//    cout<<(a<b)<<endl;
}
