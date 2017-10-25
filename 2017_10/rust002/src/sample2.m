

% �d�q�@�B�w������ ���d�A�N�`���G�[�^
% MATLAB/Octave �T���v���t�@�C���P
% �킩��Ȃ��֐��̓R�}���h���͉�ʂ�  help �֐���  �Ƃ��Ē��ׂ邱��

% ���[�N�X�y�[�X�̕ϐ��̏���
clear

% �f�[�^�̓_��
Ns=8192

% CSV�t�@�C���̓ǂݍ���, 2�s�ڂ���
data = csvread('sweep.csv',1,0);
t = data(1:Ns,1); %1���
x = -data(1:Ns,2); %2���
y = 0.508*1e+3*data(1:Ns,3); %2���

%�T���v�����O�Ԋu���f�[�^���狁�߂�
Ts =(t(2)-t(1))

% ���n��̃O���t���E�B���h�E(1)�ɕ`��
%figure(3)
%plot(t,x)

% �O���t�̎��̖��O��ݒ肷��D�^�C�g���ɂ͖��O�Ɗw�Дԍ������Ă��������D
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
