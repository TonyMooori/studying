#include <iostream>
#include <vector>
#include <string>
#include <ctype.h>


#ifndef _USEFUL_MACROS_
#define _USEFUL_MACROS_
#define INF 99999999
#define N_PRIME 1000000007
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
#define OUTPUT_DEBUG
#ifdef OUTPUT_DEBUG
#define debug(x) cout<<#x<<": "<<x<<endl
#else
#define debug(x) do{}while(false)
#endif
#endif 

using namespace std;

typedef struct _expr_t{
    bool suc;           // パースに成功したらtrue

    bool is_token;      // 数字or記号ならtrue
    string token;       // 数字or記号の文字列
    
    vector<_expr_t> lists;     // リスト
} expr_t;

bool issymbol(char c){
    char symbols[] = ".*/-+/?><%&";
    int i = 0;
    
    while( symbols[i] !='\0' ){
        if( symbols[i] == c )
            return true;
        i++;
    }
    
    return false;
}

char see_char(string& code){
    if( code.length() == 0 ){
        return '\0';
    }else{
        return code[0];
    }
}

char fetch_char(string& code){
    char c = see_char(code);
    
    if( c != '\0' )
        code = code.substr(1,code.length()-1);
    
    return c;
}

void get_token(string& token,string& code){
    char c;
    
    token = "";
    do{
        c = fetch_char(code);
        if( c == '\0' ){
            return;
        }
    }while(c == ' ' || c == '\r' || c == '\n' );
    
    if(issymbol(c)){
        do{
            token = token + c;
            c = fetch_char(code);
        }while( issymbol(c) );
        
        code = c + code; // 一文字戻す
    }else if(isdigit(c)){
        do{
            token = token + c;
            c = fetch_char(code);
        }while( isdigit(c) );
        
        code = c + code; // 一文字戻す
    }else if( isalpha(c) || c == '_' ){
        do{
            token = token + c;
            c = fetch_char(code);
        }while( isalpha(c) || c == '_' );
        
        code = c + code; // 一文字戻す
    }else{
        token = c;
    }
}

expr_t parseToken(string& token,string& code){
    expr_t ret;
    
    if( token.length() == 0 ){
        ret.suc = false;
    }else if(isalpha(token[0]) || isdigit(token[0]) || issymbol(token[0])){
        ret.suc = true;
        ret.is_token = true;
        ret.token = token;
    }
    
    get_token(token,code);
    return ret;
}

expr_t parseList(string& token,string& code){
    expr_t ret;
    expr_t temp;
    ret.suc = true;
    
    if( token.length() == 0 ){
        ret.suc = false;
    }else if( token == "(" ){
        ret.suc = true;
        ret.is_token = false;
        
        get_token(token,code); // "("を読んだのですすめる
        
        while(token != ")" ){
            temp = parseList(token,code);
            if( temp.suc == false)return temp;
            
            ret.lists.push_back(temp);
        }
        
        get_token(token,code); // ")"を読んだのですすめる
    }else{
        ret = parseToken(token,code);
    }
    
    return ret;
}


vector<expr_t> parse(string code){
    string token;
    vector<expr_t> exprs;
    expr_t temp;
    
    do{
        get_token(token,code);
        temp = parseList(token,code);
        if( temp.suc )
            exprs.push_back(temp);
        else
            break;
    }while(true);
    
    return exprs;
}

void evaluate(expr_t expr){
    if( expr.is_token ){
        cout << "token: " << expr.token << endl;
    }else{
        cout << "(" << endl;
        REP(i,expr.lists.size()){
            evaluate(expr.lists[i]);
        }
        cout << ")" << endl;
    }
}

int main(void){
    string s = "(** ( add 3 23) (- 85 6))";
    string token;
    
    
    vector<expr_t> exprs = parse(s);
    
    evaluate(exprs[0]);
    
    //evaluate(parse(s));
    // (define func (lambda (x y) (+ x y)))
    // (defun factorial (n)
    //  (if (<= n 1)
    //    1
    //    (* n (factorial (- n 1)))))
    return 0;
}
