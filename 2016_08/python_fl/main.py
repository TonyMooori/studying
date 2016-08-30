#coding:utf-8


"""

このサイトの練習問題をやってみた感じです
例外は考えず，とりあえず本質を捉えていれば良しということで……?

【長編ポエム】関数型言語が分からんお前でもPythonなら分かるやろ：第1回 関数を受け取る関数は便利だよ編 - Qiita
http://qiita.com/kwatch/items/03fd035a955235681577

"""

# 問題1

def map(func,arr):
    newarr = []
    for element in arr:
        newarr.append( func( element ) )
    
    return newarr

def filter(func,arr):
    newarr = []
    for element in arr:
        if func(element):
            newarr.append( element )
    
    return newarr

def reduce(func,arr):
    if len(arr) == 0:
        return
    
    # 初期値は最初にする
    retval = arr[0]
    for element in arr[1:]:
        retval = func( retval , element )
    
    return retval

# 問題2

def parse_version(str):
    # 例外?聞こえませんねぇ……
    return map(int,str.split('.'))

# 問題3

def grep(reg_ex,arr):
    # 正規表現をあまり知らないのであってるのかよくわからない……
    import re
    func = lambda x: re.search(reg_ex,x) != None
    return filter( func, arr )


# 問題4

def max_by(func,members):
    # 2つのうち値の大きい方を返す関数
    f = lambda x,y: x if ord(func(x)) > ord(func(y)) else y
    return reduce(f,members)

if __name__=="__main__":
    
    # 問題1 テスト
    func_double = lambda x: x * 2       # 二倍にする関数
    func_iseven = lambda x: x % 2 == 0  # 偶数ならTrueを返す関数
    func_multi  = lambda x,y: x * y     # 掛け算をしていく関数
    test_arr    = range(1,11)           # テスト用の配列[1,2,...,10]
    
    print( map( func_double , test_arr ))
    print( filter( func_iseven , test_arr ))
    print( reduce( func_multi , test_arr ))
    
    # 問題2 テスト
    print( parse_version("3.4.10"))
    
    # 問題3 テスト
    arr = grep(r'\d+', ["ABC", "F102", "X10Y", "ZZZ"])
    print(arr)   #=> ["F102", "X10Y"]
    
    # 問題4 テスト
    members = [
        ("Haruhi", "C"),   # ハルヒは C
        ("Mikuru", "E"),   # みくるは E
        ("Yuki",   "A"),   # 有希は   A
    ]
    
    def getvalue(x):
        return x[1]
    
    ret = max_by(getvalue, members)
    print(ret)   #=> ("Mikuru", "E")
    
    
    