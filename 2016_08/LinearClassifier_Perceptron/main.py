#coding:utf-8

"""

オンライン機械学習(講談社)のP24，アルゴリズム3.1
単純パーセプトロンによる2クラス分類器の実装

"""

from sklearn.datasets import load_iris
import numpy as np


class LC:
    """ 単純パーセプトロンによる線形分類器 """
    
    def __init__(self,n_dim):
        """ 
        n_dim:  分類する特徴ベクトルの次元数
        """
        
        self.n_dim = n_dim
        self.weight = np.zeros(n_dim)
        self.weight_old = np.zeros(n_dim)
    
    def fit(self,x,y):
        """
        x:      学習する特徴ベクトル(N x n_dim の行列)
        y:      特徴ベクトルのクラス(-1または1)
        """
        
        N = x.shape[0]
        
        for i in range(N):
            
            # 誤分類である場合
            if self.weight.T.dot(x[i]) * y[i] <= 0:
                self.weight = self.weight + y[i] * x[i]
            else:
                self.weight = self.weight_old
            self.weight_old = self.weight
        
    def predict(self,x):
        """
        x:      予測する特徴ベクトル(N x n_dim の行列)
        """
        mask =  self.weight.dot(x.T) > 0
        ret = np.zeros(len(x),np.int)
        ret[mask == True ] = 1
        ret[mask == False] = -1
        
        return ret
    
if __name__=="__main__":
    # データ読み込み
    iris_data = load_iris()
    target = np.array(iris_data.target) # クラス(0,1,2)のいずれか
    data = np.array(iris_data.data)     # 特徴ベクトル
    
    # データの整形．今回は二値分類器なのでクラスを-1,1にする
    target = target - 1     # クラスを-1,0,1にする
    mask = target != 0      # 0の部分を探して消す
    data = data[mask]      
    target = target[mask]
    
    # シャッフルする．これをしないとうまく行かなかった(経験談)
    # まぁ順番に処理していくから当然といえば当然か……
    index = np.arange(len(data))
    np.random.shuffle(index)
    data = data[index]
    target = target[index]
    
    # 線形分類器を学習させる
    lc = LC(data.shape[1])
    lc.fit(data,target)
    
    # 予測
    pred = lc.predict(data)
    
    # 表示
    print("target:")
    print(target)
    print("prediction:")
    print(pred) 
    print("target == predicton:")
    print(target == pred)
    
    

