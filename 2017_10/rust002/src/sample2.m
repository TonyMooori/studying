

% 電子機械学生実験 圧電アクチュエータ
% MATLAB/Octave サンプルファイル１
% わからない関数はコマンド入力画面で  help 関数名  として調べること

% ワークスペースの変数の消去
clear

% データの点数
Ns=8192

% CSVファイルの読み込み, 2行目から
data = csvread('sweep.csv',1,0);
t = data(1:Ns,1); %1列目
x = -data(1:Ns,2); %2列目
y = 0.508*1e+3*data(1:Ns,3); %2列目

%サンプリング間隔をデータから求める
Ts =(t(2)-t(1))

% 時系列のグラフをウィンドウ(1)に描く
%figure(3)
%plot(t,x)

% グラフの軸の名前を設定する．タイトルには名前と学籍番号を入れてください．
title('INPUT YOUR NAME HERE')


X=fft(x);
Y=fft(y);
G=Y ./ X;
f=[0:1/(Ns*Ts):(Ns-1)/(Ns*Ts)]';
amp=abs(G);
arg=angle(G)*180/pi;

figure(1);
plot(f,amp)
xlim([95 120]);
ylim([0 150]);
xlabel('frequency[Hz]');
ylabel('-[-]');

figure(2)
plot(f, arg)
xlim([95 120]);
ylim([-200 50]);
xlabel('frequency[Hz]');
ylabel('phase[deg]');
