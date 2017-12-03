図1に示した回路の伝達関数を導出する．

オペアンプのマイナス端子をバーチャルショートした上で立式すると次のようになる．なお$i_1$，$i_2$はそれぞれオペアンプと並列に接続された抵抗，コンデンサに流れる電流とする．

$$
\begin{alignat}{1}
v_{in}&=R(i_1+i_2)\\
v_{out}&=-Ri_1 \\
v_{out}&=-\frac{1}{C}\int i_2 dt
\end{alignat}
$$

ここでラプラス変換をすると次のようになる．

$$
\begin{alignat}{1}
V_{in}(s)&=R(I_1(s)+I_2(s))\\
I_1(s)&=-\frac{1}{R}V_{out}(s) \\
I_2(s)&=-sCV_{out}(s)
\end{alignat}
$$

これを整理すると，伝達関数がもとまる．
$$
\begin{alignat}{1}
V_{in}(s)&=R(I_1(s)+I_2(s))\\
&=-(1+sCR)V_{out}(s) \\
\therefore　G(s)= \frac{V_{out}(s)}{V_{in}(s)}&=-\frac{1}{1+sCR}
\end{alignat}
$$


## コンデンサ容量によるゲイン特性の変化
次に，コンデンサ容量を増加した場合，伝達関数のゲイン特性はどのように変化するかについて議論する．．


$s=j\omega$として周波数伝達関数$G(j\omega)$を考えると，ゲインは次のようになる．

$$
\begin{alignat}{1}
|G(s)| &=\left|\frac{1}{1+j\omega CR}\right|\\
&=\frac{1}{\sqrt{1+\omega^2C^2R^2}}
\end{alignat}
$$

したがってコンデンサ容量が大きくなるとゲインは小さくなる傾向があることが読み取れる．

## 入力電圧としてサイン波を入力した場合における出力の変化



