## 2結合層ニューラルネットワーク

　ニューロンの数が入力層 $L$ 個，中間層 $M$ 個，出力層 $N$ 個であるとする．また，入力信号を $\vec{x} = (x_1,...,x_L)^T$ ，中間層の出力信号を $\vec{y}=(y_1,...,y_M)^T$ ，出力信号を $\vec{z}=(z_1,...,z_N)^T$ とする．
　これら3つのベクトル $\vec{x},\vec{y},\vec{z}$ は，次のようにして関係づけられる．
$$
\begin{eqnarray*}
r_m &=& \sum_{l=1}^L v_{ml} x_l + \theta_m &,& (m=1,..,M)  \\
y_m &=& f(r_m)&,& (m=1,..,M)  \\
s_n &=& \sum_{m=1}^M w_{nm}y_m &,&(n=1,...,N) \\
z_n&=& g(s_n) &,& (n=1,...,N)
\end{eqnarray*}
$$
　新たに出てきた各変数は以下のとおりである．
|変数名|意味|
|:---|:---|
|$v_{ml}$|入力層 $l$ 番目,中間層$m$番目の結合係数|
|$\theta_m$|中間層 $m$ 番目のしきい値 |
|$r_m$|中間層 $m$ 番目の入力信号 |
|$w_{nm}$|中間層 $m$ 番目，出力層 $n$ 番目の結合係数 |
|$s_n$|出力層 $n$ 番目の入力信号 | 
　ここでベクトル $\vec{r} = (r_1,...,r_M)^T$, $\vec{s}=(s_1,...,s_N)^T$, $\theta=(\theta_1,...,\theta_M)^T$
　また次のような行列
$$
V = \left[
    \begin{array}{rrr}
      v_{11} & \cdots & v_{1L} \\
      \vdots & \ddots & \vdots \\
      v_{M1} & \cdots & v_{ML}
    \end{array}
 \right]
$$
$$
W = \left[
    \begin{array}{rrr}
      w_{11} & \cdots & w_{1M} \\
      \vdots & \ddots & \vdots \\
      w_{N1} & \cdots & w_{NM}
    \end{array}
 \right]
$$
　と，ベクトル関数 ${\bf f},{\bf g}$ を用いれば，
$$
\vec{r} = V \vec{x} + \vec{\theta} \\
\vec{y} = {\bf f} ( \vec{r} ) \\
\vec{s} = W \vec{y} \\
\vec{z} = {\bf g}(\vec{s})
$$
　これらをまとめると入力 \vec{x} , 出力 \vec{z} の関係は，
$$
\vec{z} = {\bf g}( W {bf f}(V \vec{x} + \vec{\theta}) )
$$
　と書くことができる．

　関数 $f$ はしばしばシグモイド関数
$$
f(r) = \frac{1}{1+exp(-cr)}
$$
　が用いられる．

　出力層の入出力の関係を表す関数$g$は，出力信号 $z_n ,(n=1,...,N)$ によって利用されるものが変わってくる．
　
1. $ -\infty < z_n  < \infty $ のとき $$g(s) = cs$$
2. $ z_n > 0 $ のとき $$g(s) = e^{cs} $$
3. $ 0 < z_n < 1 $ または $ z=0,1 $ のとき $$g(s) = \frac{1}{1+exp(-cs)}$$

























