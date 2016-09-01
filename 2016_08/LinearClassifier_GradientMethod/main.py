#coding:utf-8

"""

オンライン機械学習(講談社)  
P30 アルゴリズム3.2  
勾配降下法による線形分類器の学習  

"""

from sklearn.datasets import load_iris
from scipy.optimize import approx_fprime
import numpy as np


class LC:
    """ 単純パーセプトロンによる線形分類器 """
    
    def __init__(self,n_dim):
        """ 
        n_dim:  分類する特徴ベクトルの次元数
        """
        
        self.n_dim = n_dim
        self.weight = np.zeros(n_dim)
    
    def fit(self,x,y,n_loop = 100):
        """
        x:      学習する特徴ベクトル(N x n_dim の行列)
        y:      特徴ベクトルのクラス(-1または1)
        n_loop: 反復回数
        """
        
        N = x.shape[0]
        
        for i in range(n_loop):
            eta = 1.0 - float(i) / n_loop
            self.weight = self.weight - eta * self.grad_loss(self.weight, x, y)
        
        
    def predict(self,x):
        """
        x:      予測する特徴ベクトル(N x n_dim の行列)
        """
        mask =  self.weight.dot(x.T) > 0
        ret = np.zeros(len(x),np.int)
        ret[mask == True ] = 1
        ret[mask == False] = -1
        
        return ret
    
    def grad_loss(self,weight, x, y, eps=1e-8):
        """
        目的関数 loss の勾配を計算する関数
        
        weight: 重みベクトル
        x:      目的関数を計算する特徴ベクトル(N x n_dim の行列)
        y:      特徴ベクトルのクラス(-1または1)
        eps:    微分する際に用いる微小な値
        """
        
        f = lambda a: self.loss(a,x,y)
        return approx_fprime(weight,f,[eps])
    
    def loss(self,weight,x,y):
        """
        目的関数 L に相当する関数
        
        weight: 重みベクトル
        x:      目的関数を計算する特徴ベクトル(N x n_dim の行列)
        y:      特徴ベクトルのクラス(-1または1)
        """
        
        n_dim = len(weight)
        new_x = np.c_[x,y]
        func = lambda a: self.loss_each(weight,  a[:n_dim] , a[n_dim]) 
        return np.sum(map( func, new_x))
    
    def loss_each(self,weight,x_i,y_i):
        """
        個々の目的関数 l に相当する関数
        
        weight: 重みベクトル
        x_i:    目的関数を計算する特徴ベクトル(n_dim のベクトル)
        y_i:    特徴ベクトルのクラス(-1または1)
        """
        
        retval = -y_i * weight.T.dot(x_i) 
        return max(retval,0)
        
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
    
    """
    # 今回はシャッフルしなくても良いという利点がある！！！
    index = np.arange(len(data))
    np.random.shuffle(index)
    data = data[index]
    target = target[index]
    """
    
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
    
    

